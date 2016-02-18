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
        Call * oldCall = &callList[callHead.callNumber][callHead.county];
        *oldCall = _call; 
    }
    else {
        callList[callHead.callNumber][callHead.county] = _call;
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

void Incidents::gc()
{
    deleteQueue.clear();

    std::vector<struct IncidentHeader> & dq = deleteQueue;
    std::vector<struct IncidentHeader> & lastImportVar = lastImport; // std::functions doesn't like private alone.

    // This gets a list of calls that have been deleted by WCCCA.
    auto f = [&dq, &lastImportVar](const Call & _call) {
        bool found = false;
        const IncidentHeader & callHead = _call.getIncidentInfo();

        for (auto imported_list : lastImportVar) {
            if (imported_list.callNumber = callHead.callNumber && imported_list.county == callHead.county)
                found = true;
        }
        if (!found) {
            dq.push_back(callHead);
        }
        return true; 
    };

    this->ProcessCallList(f);

    // Deletes everything in the list populated by the auto function f.
    for (auto deleted_it : deleteQueue) {
        const IncidentHeader & callHead = deleted_it;

        if (callList[callHead.callNumber].count(callHead.county) > 1) {
            callList[callHead.callNumber].erase(callHead.county);
        }
        else {
            callList[callHead.callNumber].clear();
        }

        if (!(callList.count(callHead.callNumber) > 0)) {
            callList.erase(callHead.callNumber);
        }
    }
    lastImport.clear();
}

const Call * Incidents::ProcessCallList(const std::function<bool(const class Call & _call)> & f)
{
    for (auto  callNumber_it : callList) {
        for (auto & county_it : callNumber_it.second) {
            if (!f(county_it.second)) {
                return &county_it.second;
                break;
            }
        }
    }
    return nullptr;
}

const struct IncidentHeader * Incidents::ProcessRecentlyDeleted(const std::function<bool(const struct IncidentHeader&_ih)>& f)
{
    for (auto & deleted_it : deleteQueue) {
        if (!f(deleted_it)) {
            return &deleted_it;
            break;
        }
    }
    return nullptr;
}
