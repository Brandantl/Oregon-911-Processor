/*
    Author: Brandan Tyler Lasley
    Date:   2/17/2016
    Purpose: Fast lookups for Data.cpp large tables.
*/
#include "DataMaps.h"
#include "data.h"

class DataMaps * DataCache;

DataMaps::DataMaps() {
    // Adds data from data.h to the maps by reference so no memory is copied.
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
    for (int i = 0; !knownFeildsEvents[i].callSummery.empty(); i++) {
        mapFeildsEvents[knownFeildsEvents[i].callSummery] = &knownFeildsEvents[i];
    }
    for (int i = 0; !knownCallFeilds[i].empty(); i++) {
        mapCallFeilds[knownCallFeilds[i]] = &knownCallFeilds[i];
    }
    for (int i = 0; !knownPoliceStations[i].empty(); i++) {
        mapPoliceStations[knownPoliceStations[i]] = &knownPoliceStations[i];
    }
    for (int i = 0; !knownCallIcons[i].callSummery.empty(); i++) {
        mapIcons[knownCallIcons[i].callSummery] = &knownCallIcons[i];
    }
}

bool DataMaps::isPoliceStation(const std::string & key) {
    if (mapPoliceStations.count(key))
        return true;
    return false;
}

const stationInfoList * DataMaps::getStationInfo(const std::string & key)
{
    if (mapStationList.count(key))
        return mapStationList[key];
    return nullptr;
}

const unitInfoList * DataMaps::getUnitInfo(const std::string & key)
{
    if (mapUnitList.count(key))
        return mapUnitList[key];
    return nullptr;
}

const agencyList * DataMaps::getAgencyInfo(const std::string & key)
{
    if (mapAgencyList.count(key))
        return mapAgencyList[key];
    return nullptr;
}

const callSummeryEventList * DataMaps::getCallSummeryEventsInfo(const std::string & key)
{
    if (mapCallSummeryEvents.count(key))
        return mapCallSummeryEvents[key];
    return nullptr;
}

const callSummeryEventList * DataMaps::getFeildsEventsInfo(const std::string & key)
{
    if (mapFeildsEvents.count(key))
        return mapFeildsEvents[key];
    return nullptr;
}

const std::string * DataMaps::getCallFeild(const std::string & key)
{
    if (mapCallFeilds.count(key))
        return mapCallFeilds[key];
    return nullptr;
}

const callIcon * DataMaps::getIconInfo(const std::string & key)
{
    if (mapIcons.count(key))
        return mapIcons[key];
    return nullptr;
}
