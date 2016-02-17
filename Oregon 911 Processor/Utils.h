#pragma once
#include "data.h"

namespace util
{
    // Cycles though all of knownAgencyList until it finds what it wants or return a empty string.
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
        return ret;
    }

}