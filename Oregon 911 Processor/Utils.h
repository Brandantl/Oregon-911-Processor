/*
    Author: Brandan Tyler Lasley
    Date:   2/16/2016
*/
#pragma once
#include "data.h"
#include <string>
#include <iterator>
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/RegularExpression.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StringTokenizer.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/StreamCopier.h>
#include <Poco/Exception.h>
#include <Poco/String.h>
#include <Poco/Path.h>
#include <Poco/URI.h>

#include <tidyplatform.h>
#include <tidybuffio.h>
#include <tidy.h>
namespace util
{
    // Cycles though all of knownAgencyList until it finds what it wants or returns an empty string.
    inline std::string getAgencyByStation(const std::string & abbv) {
        std::string ret = "UNK";
        bool stop = false;
        int i = 0;
        while (!stop) {
            if (knownAgencyList[i].abbv == abbv) {
                ret = knownAgencyList[i].name;
                stop = true;
            }
            else if (knownAgencyList[i].abbv.empty()) stop = true;
            i++;
        }

        // Last resort SLOW!
        // We couldn't find this agency in the known agency lookup table.
        // Lets check the stations list which has its own copy of stations.
        i = 0;
        stop = false;
        if (ret.empty()) {
            while (!stop) {
                if (knownStationList[i].abbv == abbv) {
                    ret = knownStationList[i].agency;
                    stop = true;
                }
                else if (knownStationList[i].station.empty()) stop = true;
                i++;
            }
        }
        return ret;
    }

    inline std::string http_get(const std::string & url, const std::string & data = "") {
        std::string content;
        try {
            // Initialize session
            Poco::URI uri(url);
            Poco::Net::HTTPClientSession client_session(uri.getHost(), uri.getPort());

            // Prepare and send request
            std::string path(uri.getPathAndQuery());

            Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_GET, path, Poco::Net::HTTPMessage::HTTP_1_1);

            if (!data.empty()) {
                // Nevermind we want to post.
                req.setMethod(Poco::Net::HTTPRequest::HTTP_POST);

                client_session.setKeepAlive(true);

                // Set Expect 100 continue
                req.set("Expect", "100-continue");

                req.setContentType("application/x-www-form-urlencoded");
                req.setKeepAlive(true); // notice setKeepAlive is also called on client_session (above)
                req.setContentLength(data.length());
                std::ostream& os = client_session.sendRequest(req);

                std::stringstream ss;
                ss << data;
                Poco::StreamCopier::copyStream(ss, os);
            }
            else {
                client_session.sendRequest(req);
            }

            req.set("User-Agent", "Oregon 911 Processor");

            // Get response
            Poco::Net::HTTPResponse res;
            std::istream& is = client_session.receiveResponse(res);

            // Set return string
            content = { std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>() };
        }
        catch (Poco::Exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        return content;
    }

    inline char getCountyByName(const std::string & county) {

        if (Poco::toLower(county) == "wccca") {
            return 'W';
        }
        else if (Poco::toLower(county) == "ccom") {
            return 'C';
        }
        return 0;
    }

    inline bool isWCCCAHTMLValid(const std::string & WCCCA_HTML) {

        if (WCCCA_HTML.empty()) {
            return false;
        }


        if (WCCCA_HTML.find(VALID_WCCCA_HTML_STR) == std::string::npos) {
            return false;
        }

        return true;
    }

    inline std::vector<struct WCCCA_JSON> getWCCCAGPSFromHTML(const std::string & WCCCA_HTML) {
        std::vector<struct WCCCA_JSON> WCCCA_GPS_DATA;

        // Find GPS Location
        size_t location_start = WCCCA_HTML.rfind("<script type=\"text/javascript\">");
        size_t location_end = WCCCA_HTML.rfind("</script>");
        std::string gps_code = WCCCA_HTML.substr(location_start, location_end - location_start);

        // Check if theres any data.
        if (gps_code.find(WCCCA_LOAD_MARKER) == std::string::npos) {
            return WCCCA_GPS_DATA;
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
                std::string row = rows[i];

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
                char const margin = 2;
                std::string lat = columns[0].substr(1, columns[0].length() - margin);
                std::string lon = columns[1].substr(1, columns[1].length() - margin);
                std::string callNumber = columns[3].substr(1, columns[3].length() - margin);
                std::string county = columns[4].substr(1, columns[4].length() - margin);

                struct WCCCA_JSON gpsData;

                // Header
                gpsData.h.callNumber = stoi(callNumber);
                gpsData.h.county = util::getCountyByName(county);
                gpsData.h.type = 0; // We can't determine the type correctly w/ this data
                gpsData.h.ignoreGC = false;

                // Location
                gpsData.location.lat = stod(lat);
                gpsData.location.lon = stod(lon);

                // misc
                gpsData.callSum = Poco::toUpper(columns[2].substr(1, columns[2].length() - margin));

                WCCCA_GPS_DATA.push_back(gpsData);
            }
        }
        return WCCCA_GPS_DATA;
    }

    inline std::string tidyHTML(const std::string & HTML) {
        TidyDoc tidyDoc = tidyCreate();
        TidyBuffer tidyOutputBuffer = { 0 };

        bool configSuccess = tidyOptSetBool(tidyDoc, TidyXmlOut, yes)
            && tidyOptSetInt(tidyDoc, TidyWrapLen, 1200)
            && tidyOptSetBool(tidyDoc, TidyQuiet, yes)
            && tidyOptSetBool(tidyDoc, TidyQuoteNbsp, no)
            && tidyOptSetBool(tidyDoc, TidyXmlDecl, yes) //XML declaration on top of the content
            && tidyOptSetBool(tidyDoc, TidyForceOutput, yes)
            && tidyOptSetValue(tidyDoc, TidyInCharEncoding, "utf8") // Output from here should be UTF-8
            && tidyOptSetValue(tidyDoc, TidyOutCharEncoding, "utf8") // Output from CURL is UTF-8
            && tidyOptSetBool(tidyDoc, TidyNumEntities, yes)
            && tidyOptSetBool(tidyDoc, TidyShowWarnings, no)
            && tidyOptSetInt(tidyDoc, TidyDoctypeMode, TidyDoctypeOmit); //Exclude DOCTYPE

        int tidyResponseCode = -1;

        if (configSuccess) {
            std::vector<unsigned char> bytes(HTML.begin(), HTML.end());
            TidyBuffer buf;
            tidyBufInit(&buf);
            size_t byteSize = bytes.size();
            for (size_t i = 0; i < byteSize; i++) {
                tidyBufAppend(&buf, &bytes[i], 1);
            }
            tidyResponseCode = tidyParseBuffer(tidyDoc, &buf);
        }

        if (tidyResponseCode >= 0) {
            tidyResponseCode = tidySaveBuffer(tidyDoc, &tidyOutputBuffer);
        }

        if (tidyResponseCode < 0) {
            throw ("Tidy encountered an error while parsing an HTML response. Tidy response code: " + tidyResponseCode);
        }
        std::string ret = (char*)tidyOutputBuffer.bp;
        tidyBufFree(&tidyOutputBuffer);
        tidyRelease(tidyDoc);
        return ret;
    }

}