#pragma once
#include "program.h"

namespace util
{
    inline std::string getAgencyByAbbv(std::string abbv) {
        std::string ret;
        bool stop = false;
        int i = 0;
        while (!stop) {
            if (agencies[i].abbv == abbv) {
                ret = agencies[i].name;
                stop = true;
            }
            else if (agencies[i].abbv == "") stop = true;
            i++;
        }
        return ret;
    }



}