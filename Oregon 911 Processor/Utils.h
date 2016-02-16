#pragma once
#include "data.h"

namespace util
{
    inline std::string getAgencyByAbbv(std::string abbv) {
        std::string ret;
        knownAgencyList[0].abbv;
        bool stop = false;
        int i = 0;
        while (!stop) {
            if (knownAgencyList[i].abbv == abbv) {
                ret = knownAgencyList[i].name;
                stop = true;
            }
            else if (knownAgencyList[i].abbv == "") stop = true;
            i++;
        }
        return ret;
    }



}