/*
    Author: Brandan Tyler Lasley
    Date:   2/16/2016
*/
#include "Incidents.h"

Incidents::Incidents()
{

}

void Incidents::addOrUpdateIncident(Call & _call)
{
    const IncidentHeader & callHead = _call.getIncidentInfo();
    if (doesIncidentExist(_call)) {
        callList[callHead.callNumber][callHead.county].updateCall(_call);
    }
    else {
        Call newCall = _call;
        callList[callHead.callNumber][callHead.county] = newCall;
    }
}

bool Incidents::doesIncidentExist(Call & _call)
{
    const IncidentHeader & callHead = _call.getIncidentInfo();
    if (callList.count(callHead.callNumber) > 0) {
        if (callList[callHead.callNumber].count(callHead.county) > 0) {
            return true;
        }
    }
    return false;
}

void Incidents::gc(int turn)
{
    std::vector<IncidentHeader> toDelete;

    // Search for invalid calls.
    for (auto & callNumber_it : callList) {
        for (auto & county_it : callNumber_it.second) {
            if (county_it.second.getTurn() != turn) {
                toDelete.push_back(county_it.second.getIncidentInfo());
            }
        }
    }

    // Delete things in the vector from the real list.
    for (std::vector<IncidentHeader>::iterator it = toDelete.begin(); it != toDelete.end(); ++it) {
        callList[it->callNumber].erase(it->county);
        if (!callList[it->callNumber].size()) {
            callList.erase(it->callNumber);
        }
    }
}

const Call * Incidents::ProcessCallList(const std::function<bool(const class Call & _call)> & f)
{
    for (auto &  callNumber_it : callList) {
        for (auto & county_it : callNumber_it.second) {
            if (!f(county_it.second)) {
                return &county_it.second;
            }
        }
    }
    return nullptr;
}
