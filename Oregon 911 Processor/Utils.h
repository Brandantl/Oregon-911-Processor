#pragma once
#include "data.h"

namespace util
{

    inline std::string getAgencyByAbbv(const std::string & abbv) {
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