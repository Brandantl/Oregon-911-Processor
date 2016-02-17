#pragma once
#include <string>

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
