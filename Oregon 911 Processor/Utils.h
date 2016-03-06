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
        std::string ret = DEFAULT_STATION_ABBV;
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
        std::ostringstream oss;
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

            req.set("User-Agent", USER_AGENT);

            // Get response
            Poco::Net::HTTPResponse res;
            std::istream& is = client_session.receiveResponse(res);

            // Set return string
            oss << is.rdbuf();
           // content = { std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>() };
        }
        catch (Poco::Exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        return oss.str();
    }

    inline char getCountyByName(const std::string & county) {

        if (Poco::toLower(county) == WCCCA) {
            return LW;
        }
        else if (Poco::toLower(county) == CCOM) {
            return LC;
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