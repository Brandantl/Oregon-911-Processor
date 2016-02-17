/*
    Author: Brandan Tyler Lasley
    Date:   2/16/2016
*/
#pragma once
#include "Call.h"
#include "Utils.h"


Call::Call() {
    incidentInfo.callNumber = 0;
    incidentInfo.county = 0;
    incidentInfo.ignoreGC = 0;
    location.lat = 0;
    location.lon = 0;
    unitCount = 0;
    for (int i = 0; i < MAX_NUM_CALL_STATUSES; i++) {
        time[i] = "00:00:00";
    }
    agency = "Unknown";
}

void Call::addUnit(Unit thing)
{
    unitList[thing.getName()] = thing;
}

void    Call::removeUnit(const std::string & name) {
    unitList.erase(name);
}

bool    Call::doesUnitExist(const std::string & name) {
    return (unitList.count(name)>0);
}

// Sets
void Call::setIncidentInfo(const IncidentHeader & _incidentInfo)
{
    incidentInfo = _incidentInfo;
}

void    Call::setTime(callTime _idx, const std::string & _status) {
    time[(unsigned int)_idx] = _status;
}

void    Call::setCallSummery(const std::string & _callSummery) {
    if ((!callSummery.empty()) && (_callSummery != callSummery)) {
        // Add Call Summery to the change log.
        callSummeryHistory.push_back(callSummery);
    }
    callSummery = _callSummery;
}

void    Call::setStation(const std::string & _station) {
    station = _station;
    agency = util::getAgencyByStation(_station);
}

/*void    Call::setAgency(std::string _agencyName) {
    agencyName = _agencyName;
}*/

void    Call::setLocation(const struct gps & _location) {
    // So there is location data already loaded.
    if (location.isInit() && (location.operator!=(_location))) {
        // Lets put this location data in the change log.
        locationHistory.push_back(location);
    }
    location = _location;
}

void Call::setAddress(const std::string & _address)
{
    if ((!address.empty()) && (_address != address)) {
        // Add Call Summery to the change log.
        addressHistory.push_back(callSummery);
    }
    address = _address;
}

// Gets

const IncidentHeader & Call::getIncidentInfo()
{
    return incidentInfo;
}

const std::string &    Call::getTime(callTime _idx) {
    return time[(unsigned int)_idx];
}

const std::string &    Call::getCallSummery() {
    return callSummery;
}

const std::string &    Call::getStation() {
    return station;
}

const std::string &    Call::getAgency() {
    return agency;
}

struct gps    Call::getLocation() {
    return location;
}

int    Call::getUnitcount() {
    return unitCount;
}

std::string    Call::getUnitsString() {
    std::string ret_str;
    for (auto it : unitList) {
        ret_str += it.second.getName();
        ret_str += " ,";
    }
    // Delete the last " ,"
    if (!ret_str.empty())
        ret_str = ret_str.substr(0, ret_str.size() - 2);
    return ret_str;
}

const std::string & Call::setAddress()
{
    return address;
}

void Call::clearCallSummeryHistory()
{
    callSummeryHistory.clear();
}

void Call::clearAddressHistory()
{
    addressHistory.clear();
}

void Call::clearLocationHistory()
{
    locationHistory.clear();
}

// Processes/Loops
const class Unit    *    Call::ProcessUnitList(const std::function<bool(const class Unit & _unit)> & f) {
    class Unit * ret = nullptr;
    for (auto it : unitList) {
        if (!f(it.second)) {
            ret = &it.second;
            break;
        }
    }
    return ret;
}

const std::string    *    Call::ProcessCallSummeryHistory(const std::function<bool(const std::string & history)> & f) {
    std::string  * ret = nullptr;
    for (std::vector<std::string>::iterator it = callSummeryHistory.begin(); it != callSummeryHistory.end(); ++it) {
        if (!f(*it)) {
            ret = &*it;
            break;
        }
    }
    return ret;
}

const std::string    *    Call::ProcessAddressHistory(const std::function<bool(const std::string & history)> & f) {
    std::string* ret = nullptr;
    for (std::vector<std::string>::iterator it = addressHistory.begin(); it != addressHistory.end(); ++it) {
        if (!f(*it)) {
            ret = &*it;
            break;
        }
    }
    return ret;
}

const struct gps    *    Call::ProcessLocationHistory(const std::function<bool(const struct gps & _location)> & f) {
    struct gps* ret = nullptr;
    for (std::vector<struct gps>::iterator it = locationHistory.begin(); it != locationHistory.end(); ++it) {
        if (!f(*it)) {
            ret = &*it;
            break;
        }
    }
    return ret;
}
