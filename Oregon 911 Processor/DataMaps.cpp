/*
    Author: Brandan Tyler Lasley
    Date:   2/17/2016
    Purpose: Fast lookups for Data.cpp large tables.
*/
#include "DataMaps.h"
#include "data.h"

class DataMaps * DataCache;

DataMaps::DataMaps() {
    for (int i = 0; !knownStationList[i].abbv.empty(); i++) {
        mapStationList[knownStationList[i].abbv] = &knownStationList[i];
    }
    for (int i = 0; !knownUnitList[i].name.empty(); i++) {
        mapUnitList[knownUnitList[i].name] = &knownUnitList[i];
    }
    for (int i = 0; !knownAgencyList[i].name.empty(); i++) {
        mapAgencyList[knownAgencyList[i].name] = &knownAgencyList[i];
    }
    for (int i = 0; !knownCallSummeryEvents[i].callSummery.empty(); i++) {
        mapCallSummeryEvents[knownCallSummeryEvents[i].callSummery] = &knownCallSummeryEvents[i];
    }
    for (int i = 0; !knownCallSummeryEvents[i].callSummery.empty(); i++) {
        mapCallSummeryEvents[knownCallSummeryEvents[i].callSummery] = &knownCallSummeryEvents[i];
    }
    for (int i = 0; !knownFeildsEvents[i].callSummery.empty(); i++) {
        mapFeildsEvents[knownFeildsEvents[i].callSummery] = &knownFeildsEvents[i];
    }
    for (int i = 0; !knownCallFeilds[i].empty(); i++) {
        mapCallFeilds[knownCallFeilds[i]] = &knownCallFeilds[i];
    }
}

const stationInfoList * DataMaps::getStationInfo(std::string key)
{
    if (mapStationList.count(key))
        return mapStationList[key];
    return nullptr;
}

const unitInfoList * DataMaps::getUnitInfo(std::string key)
{
    if (mapUnitList.count(key))
        return mapUnitList[key];
    return nullptr;
}

const agencyList * DataMaps::getAgencyInfo(std::string key)
{
    if (mapAgencyList.count(key))
        return mapAgencyList[key];
    return nullptr;
}

const callSummeryEventList * DataMaps::getCallSummeryEventsInfo(std::string key)
{
    if (mapCallSummeryEvents.count(key))
        return mapCallSummeryEvents[key];
    return nullptr;
}

const callSummeryEventList * DataMaps::getFeildsEventsInfo(std::string key)
{
    if (mapFeildsEvents.count(key))
        return mapFeildsEvents[key];
    return nullptr;
}

const std::string * DataMaps::getCallFeild(std::string key)
{
    if (mapCallFeilds.count(key))
        return mapCallFeilds[key];
    return nullptr;
}
