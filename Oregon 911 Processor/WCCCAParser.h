/*
Author: Brandan Tyler Lasley
Date:   3/06/2016
Purpose: Processes WCCCAs HTML into something useful.
*/
#pragma once
#include <string>
#include "Unit.h"
#include "Call.h"

#include <Poco/DOM/NodeIterator.h>
#include <Poco/DOM/NamedNodeMap.h>
#include <Poco/SAX/InputSource.h>
#include <Poco/DOM/NodeFilter.h>
#include <Poco/DOM/DOMParser.h>
#include <Poco/DOM/Document.h>
#include <Poco/DOM/Element.h>
#include <Poco/DOM/AutoPtr.h>
#include <Poco/String.h>


class WCCCAParser {
public:
    WCCCAParser();

    void parse(const std::string & WCCCA_STR);

    const Call    *  ProcessCallList(const std::function<bool(const class Call & _call)> & f);
private:
    int updateTurn;
    void clearData();
    bool getGPSData(const std::string & WCCCA_STR);

    void checkpNode(Poco::XML::Node* pNode, Poco::XML::NodeIterator & it);

    void buildCallList();

    Poco::XML::DOMParser parser;

    Poco::XML::Node* attribute;
    Poco::XML::NamedNodeMap* attributes;

    Poco::XML::NamedNodeMap* unit_attributes;

    std::string nName;
    std::string nValue;
    std::string status;
    std::string statusstr;
    std::string timeTemp;
     
    std::vector<int>                        callNumbers;
    std::vector<char>                       counties;
    std::vector<std::string>                callSummeries;
    std::vector<std::string>                addresses;
    std::vector<std::string>                cTime[MAX_NUM_CALL_STATUSES];
    std::vector<std::string>                agency;                         // Not Used
    std::vector<std::string>                station;
    std::vector<std::vector<Unit>>          units;

    std::vector<struct WCCCA_JSON>          gpsData;

    std::vector<Call>                       callList;
};