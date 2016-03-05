/*
    Author: Brandan Tyler Lasley
    Date:   2/12/2016
*/
#include "or911.h"
#include "structs.h"
#include "data.h"
#include "Unit.h"
#include "Call.h"
#include "Utils.h"
#include "DataMaps.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include <Poco/DOM/NodeIterator.h>
#include <Poco/DOM/NamedNodeMap.h>
#include <Poco/SAX/InputSource.h>
#include <Poco/DOM/NodeFilter.h>
#include <Poco/DOM/DOMParser.h>
#include <Poco/DOM/Document.h>
#include <Poco/DOM/Element.h>
#include <Poco/DOM/AutoPtr.h>
#include <Poco/String.h>

int main() {
    DataCache = new DataMaps();

    cout << "Oregon 911 Importer! \n\n";

    const std::string WCCCA_STR = util::tidyHTML(GET_WCCCA_DATA());

    ofstream myfile;
    myfile.open("wccca.html");
    myfile << WCCCA_STR;
    myfile.close();

    std::string WCCCA_DATA;

    vector<struct WCCCA_JSON> gpsData;
    if (util::isWCCCAHTMLValid(WCCCA_STR)) {

        gpsData = util::getWCCCAGPSFromHTML(WCCCA_STR);

        // If theres GPS data then it's highly likely theres call data too!
        if (gpsData.size() > 0) {
            try
            {
                // HTML Parser
                Poco::XML::DOMParser parser;
                parser.setFeature(Poco::XML::XMLReader::FEATURE_NAMESPACES, true);
                parser.setFeature(Poco::XML::XMLReader::FEATURE_NAMESPACE_PREFIXES, true);
                Poco::XML::AutoPtr<Poco::XML::Document> pDoc = parser.parseString(WCCCA_STR);
                Poco::XML::NodeIterator it(pDoc->getNodeByPath(XHTML_BODY_PATH), Poco::XML::NodeFilter::SHOW_ALL);
                Poco::XML::Node* pNode = it.nextNode();

                Poco::XML::NamedNodeMap* attributes = NULL;
                Poco::XML::Node* attribute = NULL;

                Poco::XML::NamedNodeMap* unit_attributes = NULL;
                Poco::XML::Node* unit_attribute = NULL;

                string nName;
                string nValue;
                string status;
                string statusstr;
                string timeTemp;

                std::vector<int>                   callNumbers;
                std::vector<char>                  counties;
                std::vector<string>                callSummeries;
                std::vector<string>                addresses;
                std::vector<string>                callTime[4];
                std::vector<string>                agency;
                std::vector<string>                station;
                std::vector<std::vector<Unit>>     Units;

                while (pNode)
                {
                    if (pNode->hasAttributes()) {
                        attributes = pNode->attributes();
                        for (unsigned int i = 0; i < attributes->length(); i++)
                        {
                            attribute = attributes->item(i);
                            nName = attribute->nodeName();
                            nValue = attribute->getNodeValue();

                            if (nName == HTML_ID && nValue.find("CallNo") != std::string::npos) {
                                // We found a call number!
                                callNumbers.push_back(stoi(pNode->innerText()));
                                if (nValue.find(C_CCOM) != std::string::npos) {
                                    counties.push_back(LW);
                                }
                                else {
                                    counties.push_back(LC);
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
                                        callTime[(int)callTime::entry].push_back("00:00:00");
                                    }
                                    else {
                                        callTime[(int)callTime::entry].push_back(timeTemp);
                                    }
                                }
                            }
                            else  if (nName == HTML_TITLE && nValue == "Dispatch Time") {
                                timeTemp = pNode->innerText();
                                if (!timeTemp.empty()) {
                                    if (timeTemp == WCCCA_TIME_NULL) {
                                        callTime[(int)callTime::dispatch].push_back("00:00:00");
                                    }
                                    else {
                                        callTime[(int)callTime::dispatch].push_back(timeTemp);
                                    }
                                }
                            }
                            else  if (nName == HTML_TITLE && nValue == "En Route Time") {
                                timeTemp = pNode->innerText();
                                if (!timeTemp.empty()) {
                                    if (timeTemp == WCCCA_TIME_NULL) {
                                        callTime[(int)callTime::enroute].push_back("00:00:00");
                                    }
                                    else {
                                        callTime[(int)callTime::enroute].push_back(timeTemp);
                                    }
                                }
                            }
                            else  if (nName == HTML_TITLE && nValue == "On Scene Time") {
                                timeTemp = pNode->innerText();
                                if (!timeTemp.empty()) {
                                    if (timeTemp == WCCCA_TIME_NULL) {
                                        callTime[(int)callTime::onscene].push_back("00:00:00");
                                    }
                                    else {
                                        callTime[(int)callTime::onscene].push_back(timeTemp);
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
                                Units.push_back(callUnitList);
                            }
                        }
                    }
                    pNode = it.nextNode();
                }
            }
            catch (Poco::Exception& e)
            {
                std::cerr << e.displayText() << std::endl;
            }
        }
    }

    delete DataCache;
    return 0;
}
