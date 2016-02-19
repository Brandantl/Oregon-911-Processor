/*
    Author: Brandan Tyler Lasley
    Date:   2/16/2016
*/
#pragma once
#include "data.h"
#include <string>
#include <iterator>
#include <sstream>

#include <Poco/Exception.h>
#include <Poco/StreamCopier.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Path.h>
#include <Poco/URI.h>

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

    inline std::string http_get(const std::string & url, const std::string & data) {
        std::string content;
        try {
            // Initialize session
            Poco::URI uri(url);
            Poco::Net::HTTPClientSession client_session(uri.getHost(), uri.getPort());
            client_session.setKeepAlive(true);

            // Prepare and send request
            std::string path(uri.getPathAndQuery());

            Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_GET, path, Poco::Net::HTTPMessage::HTTP_1_1);

            if (!data.empty()) {
                // Nevermind we want to post.
                req.setMethod(Poco::Net::HTTPRequest::HTTP_POST);

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

}