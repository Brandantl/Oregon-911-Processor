#pragma once
/*
    Author: Brandan Tyler Lasley
    Date:   2/17/2016
    Purpose: Fast lookups for Data.cpp large tables.
*/
#include "structs.h"
#include <map>
#include <string>

class DataMaps {
public:
    DataMaps();

private:
    std::map<std::string, const struct stationInfoList *>		        mapStationList;
    std::map<std::string, const struct unitInfoList *>		            mapUnitList;
    std::map<std::string, const struct agencyList *>		            mapAgencyList;
    std::map<std::string, const struct callSummeryEventList *>		    mapCallSummeryEvents;
    std::map<std::string, const struct callSummeryEventList *>		    mapFeildsEvents;
    std::map<std::string, const std::string *>		                    mapCallFeilds;
};

extern class DataMaps * DataCache;