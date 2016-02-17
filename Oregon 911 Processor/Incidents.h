/*
    Author: Brandan Tyler Lasley
    Date:   2/16/2016
    Purpose: Stores and manages all calls.
*/
#pragma once
#include <unordered_map>
#include <functional>
#include "structs.h"
#include <utility>
#include <vector>
#include "Call.h"

class Incidents {
public:
    Incidents();

    void                                                        addOrUpdateIncident(Call & _call);
    bool                                                        doesIncidentExist(Call & _call);

    void                                                        gc();                       // Garbage collects any dead calls.

    // Loops & Stuff
    const Call    *                                             ProcessCallList(const std::function<bool(const class Call & _call)> & f);

private:

    std::vector<struct IncidentHeader>                          lastImport;                 // callNumber, County
    std::unordered_map<int, std::unordered_map<char, Call>>		callList;                   // Key is the call number
};