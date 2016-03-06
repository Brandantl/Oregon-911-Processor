/*
Author: Brandan Tyler Lasley
Date:   3/06/2016
Purpose: Processes WCCCAs HTML into something useful.
*/
#include "WCCCAParser.h"
#include "Utils.h"
#include "DataMaps.h"

WCCCAParser::WCCCAParser()
{
    updateTurn = 0;
    parser.setFeature(Poco::XML::XMLReader::FEATURE_NAMESPACES, true);
    parser.setFeature(Poco::XML::XMLReader::FEATURE_NAMESPACE_PREFIXES, true);
    clearData();
}

const Call * WCCCAParser::ProcessCallList(const std::function<bool(Call & _call)>& f)
{
    for (auto & it : callList) {
        if (!f(it)) {
            return &it;
        }
    }
    return nullptr;
}

void WCCCAParser::clearData()
{
    attribute = nullptr;
    attributes = nullptr;
    unit_attributes = nullptr;
    callNumbers.clear();
    counties.clear();
    callSummeries.clear();
    addresses.clear();
    for (int i = 0; i < MAX_NUM_CALL_STATUSES; i++) {
        cTime[i].clear();
    }
    agency.clear();
    station.clear();
    units.clear();
    gpsData.clear();
    callList.clear();

}

void WCCCAParser::parse(const std::string & WCCCA_STR)
{
    clearData();
    updateTurn++;

    if (util::isWCCCAHTMLValid(WCCCA_STR) && getGPSData(WCCCA_STR)) {
        unsigned int i;
        try
        {
            Poco::XML::AutoPtr<Poco::XML::Document> pDoc = parser.parseString(WCCCA_STR);
            Poco::XML::NodeIterator it(pDoc->getNodeByPath(XHTML_BODY_PATH), Poco::XML::NodeFilter::SHOW_ALL);
            Poco::XML::Node* pNode = it.nextNode();

            while (pNode)
            {
                if (pNode->hasAttributes()) {
                    attributes = pNode->attributes();
                    for (i = 0; i < attributes->length(); i++)
                    {
                        attribute = attributes->item(i);
                        nName = attribute->nodeName();
                        nValue = attribute->getNodeValue();
                        checkpNode(pNode, it);
                    }
                }
                pNode = it.nextNode();
            }

            buildCallList();
        }
        catch (Poco::Exception& e)
        {
            std::cerr << e.displayText() << std::endl;
        }
    }
}

bool WCCCAParser::getGPSData(const std::string & WCCCA_STR)
{
    std::string row;
    std::string lat;
    std::string lon;
    std::string callNumber;
    std::string county;
    char const margin = 2;

    // Find GPS Location
    size_t location_start = WCCCA_STR.rfind(HTML_SCRIPT_START);
    size_t location_end = WCCCA_STR.rfind(HTML_SCRIPT_END);
    std::string gps_code = WCCCA_STR.substr(location_start, location_end - location_start);

    // Check if theres any data.
    if (gps_code.find(WCCCA_LOAD_MARKER) == std::string::npos) {
        return false;
    }

    // Reduce further
    location_start = gps_code.find(WCCCA_LOAD_MARKER);
    gps_code = gps_code.substr(location_start, gps_code.length());
    gps_code = gps_code.substr(0, gps_code.find("\n", 0));

    // Ok we reduced enough, lets split the string by ;
    Poco::StringTokenizer rows(gps_code, ";");

    for (size_t i = 0; i < rows.count(); i++) {
        if (0 == rows[i].find(WCCCA_LOAD_MARKER)) {
            // Ok now on this CPU intensive journey we need to remove "LoadMarker(" and the last ")".
            row = rows[i];

            // "LoadMarker(" is 11 characters long with the -1 for the ")" at the end.
            //const int lengthOfLoadMarker = 11;
            // row = row.substr(lengthOfLoadMarker, row.length() - lengthOfLoadMarker - 1);

            // Replace parseFloat() with ' ' so RegEx can read it easier.
            row = Poco::replace(row, "parseFloat(", "'");
            row = Poco::replace(row, "),", "',");

            // Standard Regex
            std::vector<std::string> columns;
            std::regex rgx("'([^']+)'");
            std::sregex_token_iterator iter(row.begin(), row.end(), rgx, 0);
            std::sregex_token_iterator end;
            for (; iter != end; ++iter) {
                columns.push_back(*iter);
            }

            // Strip the "'" 's in all of the vars. 
            lat = columns[0].substr(1, columns[0].length() - margin);
            lon = columns[1].substr(1, columns[1].length() - margin);
            callNumber = columns[3].substr(1, columns[3].length() - margin);
            county = columns[4].substr(1, columns[4].length() - margin);

            struct WCCCA_JSON JSON_DATA;

            // Header
            JSON_DATA.h.callNumber = stoi(callNumber);
            JSON_DATA.h.county = util::getCountyByName(county);
            JSON_DATA.h.type = 0; // We can't determine the type correctly w/ this data
            JSON_DATA.h.ignoreGC = false;

            // Location
            JSON_DATA.location.lat = stod(lat);
            JSON_DATA.location.lon = stod(lon);

            // misc
            JSON_DATA.callSum = Poco::toUpper(columns[2].substr(1, columns[2].length() - margin));

            gpsData.push_back(JSON_DATA);
        }
    }
    if (gpsData.size())
        return true;
    return false;
}

void WCCCAParser::checkpNode(Poco::XML::Node * pNode, Poco::XML::NodeIterator & it)
{
    if (nName == HTML_ID && nValue.find("CallNo") != std::string::npos) {
        // We found a call number!
        callNumbers.push_back(stoi(pNode->innerText()));
        if (nValue.find(C_CCOM) != std::string::npos) {
            counties.push_back(LC);
        }
        else {
            counties.push_back(LW);
        }
    }
    else  if (nName == HTML_ID && nValue.find(HTML_CALLTYPE) != std::string::npos) {
        callSummeries.push_back(Poco::toUpper(pNode->innerText()));
    }
    else  if (nName == HTML_CLASS && nValue.find("address") != std::string::npos) {
        addresses.push_back(Poco::toUpper(pNode->innerText()));
    }
    else  if (nName == HTML_TITLE && nValue == "Call Entry Time") {
        timeTemp = pNode->innerText();
        if (!timeTemp.empty()) {
            if (timeTemp == WCCCA_TIME_NULL) {
                cTime[(int)callTime::entry].push_back(TIME_NULL);
            }
            else {
                cTime[(int)callTime::entry].push_back(timeTemp);
            }
        }
    }
    else  if (nName == HTML_TITLE && nValue == "Dispatch Time") {
        timeTemp = pNode->innerText();
        if (!timeTemp.empty()) {
            if (timeTemp == WCCCA_TIME_NULL) {
                cTime[(int)callTime::dispatch].push_back(TIME_NULL);
            }
            else {
                cTime[(int)callTime::dispatch].push_back(timeTemp);
            }
        }
    }
    else  if (nName == HTML_TITLE && nValue == "En Route Time") {
        timeTemp = pNode->innerText();
        if (!timeTemp.empty()) {
            if (timeTemp == WCCCA_TIME_NULL) {
                cTime[(int)callTime::enroute].push_back(TIME_NULL);
            }
            else {
                cTime[(int)callTime::enroute].push_back(timeTemp);
            }
        }
    }
    else  if (nName == HTML_TITLE && nValue == "On Scene Time") {
        timeTemp = pNode->innerText();
        if (!timeTemp.empty()) {
            if (timeTemp == WCCCA_TIME_NULL) {
                cTime[(int)callTime::onscene].push_back(TIME_NULL);
            }
            else {
                cTime[(int)callTime::onscene].push_back(timeTemp);
            }
        }
    }
    else  if (nName == HTML_CLASS && nValue == "units") {
        // These skips are required because agency cannot be found
        // by name and value as the value constantly changes.

        // Skip node
        pNode = it.nextNode();
        agency.push_back(pNode->innerText());

        // Skip node
        pNode = it.nextNode(); // Skip past Agency node
        pNode = it.nextNode(); // Skip past a / 
        pNode = it.nextNode(); // ???
        station.push_back(pNode->innerText()); // It works.
    }
    else  if (nName == HTML_ID && nValue.find("Units") != std::string::npos) {
        Poco::XML::Element *pUnitRoot = dynamic_cast<Poco::XML::Element*>(pNode);
        std::vector<Unit> callUnitList;
        //Iterate over every child node (non-recursively)
        for (Poco::XML::Node *pUnitNode = pUnitRoot->firstChild(); pUnitNode != 0; pUnitNode = pUnitNode->nextSibling()) {
            auto pUElem = dynamic_cast<Poco::XML::Element*>(pUnitNode);
            if (pUElem) {
                if (pUElem->hasAttributes()) {
                    unit_attributes = pUElem->attributes();
                    // ex. class='onscene' title='On Scene @ 00:12:33'
                    if (unit_attributes->length() == 2) {
                        Unit unit;
                        unit.setName(pUElem->innerText());

                        // Get class='onscene'
                        status = unit_attributes->item(0)->getNodeValue();
                        statusstr = unit_attributes->item(1)->getNodeValue();

                        // Trim everything to the left of the last space.
                        statusstr = statusstr.substr(statusstr.find_last_of(' ') + 1); // Including the space

                        if (status == "dispatched") {
                            unit.setTime(unitStatus::dispatched, statusstr);
                        }
                        else if (status == "enroute") {
                            unit.setTime(unitStatus::enroute, statusstr);
                        }
                        else if (status == "onscene") {
                            unit.setTime(unitStatus::onscene, statusstr);
                        }
                        else if (status == "clear") {
                            unit.setTime(unitStatus::clear, statusstr);
                        }

                        callUnitList.push_back(unit);
                    }
                }
            }
        }
        units.push_back(callUnitList);
    }
}

void WCCCAParser::buildCallList()
{
    int numCalls = callNumbers.size();
    for (int callidx = 0; callidx < numCalls; callidx++) {
        struct IncidentHeader h;
        Call c;
        h.callNumber = callNumbers[callidx];
        h.county = counties[callidx];
        h.ignoreGC = false;

        // Set Type & Icon from Data tables.
        if (DataCache->isPoliceStation(station[callidx])) {
            h.type = 'P';
        }
        else {
            const callIcon * ci = DataCache->getIconInfo(callSummeries[callidx]);
            if (ci) {
                h.type = ci->type;
                c.setIcon(ci->icon);
            }
            else {
                h.type = 'F';
                c.setIcon("general.png"); // Hard coded png.
            }
        }

        c.setIncidentInfo(h);
        c.setAddress(addresses[callidx]);
        c.setCallSummery(callSummeries[callidx]);
        c.setStation(station[callidx]);
        c.setLocation(gpsData[callidx].location);
        for (int i = 0; i < MAX_NUM_CALL_STATUSES; i++)
            c.setTime((callTime)i, cTime[i][callidx]);

        int unitCount = units[callidx].size();
        for (int i = 0; i < unitCount; i++)
            c.addOrUpdateUnit(units[callidx][i]);
        c.setTurn(updateTurn);
        callList.push_back(c);
    }
}