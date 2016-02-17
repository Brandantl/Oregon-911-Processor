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

    void                                                        newImport();                // Clears last import vector.

    void                                                        addOrUpdateIncident(const class Call &);
    bool                                                        doesIncidentExist(const class Call &);

    void                                                        gc();                       // Garbage collects any dead calls.

    // Loops & Stuff
    const class Call    *                                       ProcessCallList(const std::function<bool(const class Call & _call)> & f);

private:
    std::vector<struct IncidentHeader>                          lastImport;                 // callNumber, County
    std::unordered_map<int, Call>		                        callList;                   // Key is the call number
};