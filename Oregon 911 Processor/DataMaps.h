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

    const struct stationInfoList *                                      getStationInfo(const std::string & key);
    const struct unitInfoList *                                         getUnitInfo(const std::string & key);
    const struct agencyList *                                           getAgencyInfo(const std::string & key);
    const struct callSummeryEventList *                                 getCallSummeryEventsInfo(const std::string & key);
    const struct callSummeryEventList *                                 getFeildsEventsInfo(const std::string & key);
    const std::string *                                                 getCallFeild(const std::string & key);
    const struct callIcon *                                             getIconInfo(const std::string & key);
    bool                                                                isPoliceStation(const std::string & key);
private:
    std::map<std::string, const struct stationInfoList *>		        mapStationList;
    std::map<std::string, const struct unitInfoList *>		            mapUnitList;
    std::map<std::string, const struct agencyList *>		            mapAgencyList;
    std::map<std::string, const struct callSummeryEventList *>		    mapCallSummeryEvents;
    std::map<std::string, const struct callSummeryEventList *>		    mapFeildsEvents;
    std::map<std::string, const std::string *>		                    mapCallFeilds;
    std::map<std::string, const std::string *>		                    mapPoliceStations;
    std::map<std::string, const struct callIcon *>		                mapIcons;
};

extern class DataMaps * DataCache;