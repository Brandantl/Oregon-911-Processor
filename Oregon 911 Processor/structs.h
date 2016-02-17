/*
    Author: Brandan Tyler Lasley
    Date:   2/16/2016
    Purpose: Holds all structs in the entire program.
*/
#pragma once
#include <string>

struct IncidentHeader {
    int callNumber;
    char county;
    bool ignoreGC;
    bool operator<(const IncidentHeader & n) const {
        return this->callNumber < n.callNumber && this->county < n.county;   // for example
    }
};

struct agencyList {
    std::string abbv;
    std::string name;
};

struct callSummeryEventList {
    std::string callSummery;
    std::string Responce;
    std::string EventID;
    std::string Icon;
};

struct unitInfoList {
    std::string name;
    std::string station;
    std::string abbv;
    char county;
    std::string agency;
};

struct stationInfoList {
    std::string station;
    char county;
    std::string abbv;
    std::string agency;
};

struct gps {
    double lat;
    double lon;

    bool isInit() {
        if (lat > 0 && lon > 0)
            return true;
        return false;
    }
    bool operator== (const gps & loc1) {
        return (lat == loc1.lat && lon == loc1.lon);
    }
    bool operator!= (const gps & loc1) {
        return (!this->operator==(loc1));
    }
};
