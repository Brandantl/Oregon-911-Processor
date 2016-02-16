#pragma once
#include "program.h"

Call::Call() {
    callNumber = 0;
    county = 0;
    unitCount = 0;
    for (int i = 0; i < MAX_NUM_CALL_STATUSES; i++) {
        time[i] = "00:00:00";
    }
    agencyName = "Unknown";
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
void    Call::setCallNumber(int _callNumber) {
    callNumber = _callNumber;
}

void    Call::setCounty(char _county) {
    county = _county;
}

void    Call::setTime(callTime _idx, std::string _status) {
    time[(unsigned int)_idx] = _status;
}

void    Call::setCallSummery(std::string _callSummery) {
    if ((!callSummery.empty()) && (_callSummery != callSummery)) {
        // Add Call Summery to the change log.
        callSummeryHistory.push_back(callSummery);
    }
    callSummery = _callSummery;
}

void    Call::setAgency(std::string _agency) {
    agency = _agency;
    agencyName = util::getAgencyByAbbv(_agency);
}

/*void    Call::setAgencyName(std::string _agencyName) {
    agencyName = _agencyName;
}*/

void    Call::setLocation(struct gps _location) {
    // So there is location data already loaded.
    if (location.isInit() && (_location != location)) {
        // Lets put this location data in the change log.
        locationHistory.push_back(location);
    }
    location = _location;
}

void Call::setAddress(std::string _address)
{
    if ((!address.empty()) && (_address != address)) {
        // Add Call Summery to the change log.
        addressHistory.push_back(callSummery);
    }
    address = _address;
}

// Gets
int    Call::getCallNumber() {
    return callNumber;
}

char    Call::getCounty() {
    return county;
}

std::string    Call::getTime(callTime _idx) {
    return time[(unsigned int)_idx];
}

std::string    Call::getCallSummery() {
    return callSummery;
}

std::string    Call::getAgency() {
    return agency;
}

std::string    Call::getAgencyName() {
    return agencyName;
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

std::string Call::setAddress()
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
