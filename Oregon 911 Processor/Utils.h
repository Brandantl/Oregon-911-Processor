/*
    Author: Brandan Tyler Lasley
    Date:   2/16/2016
*/
#pragma once
#include "data.h"

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
}