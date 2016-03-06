/*
    Author: Brandan Tyler Lasley
    Date:   2/12/2016
    Purpose: To store data for an individual incident.
*/
#pragma once
#include <vector>
#include <unordered_map>
#include <functional>
#include "or911.h"
#include "structs.h"
#include "Unit.h"

enum class callTime {
    entry,
    dispatch,
    enroute,
    onscene
};

class Call {

public:
    Call();

    // Add
    void                                                addOrUpdateUnit(const Unit & thing);

    // Remove
    void                                                removeUnit(const std::string & name);

    // Exits
    bool                                                doesUnitExist(const std::string & name);
    bool                                                doesFlagExist(const std::string & _flag);

    void updateCall(const Call &obj);


    // Sets
    void                                                setIncidentInfo(const IncidentHeader& _incidentInfo);
    void                                                setTime(callTime _idx, const std::string & _status);
    void                                                setCallSummery(const std::string & _callSummery);
    void                                                setStation(const std::string & _station);
    //void                                              setAgency(const std::string & _agencyName); // This should be set automatically.
    void                                                setLocation(const struct gps & _location);
    void                                                setAddress(const std::string & _address);
    void                                                addFlag(const struct callSummeryEventList & _flag);
    void                                                setTurn(const int & num);
    void                                                setIcon(const std::string & ico);

    // Gets
    const IncidentHeader&                               getIncidentInfo() const;
    const std::string &                                 getTime(callTime _idx) const;
    const std::string &                                 getCallSummery() const;
    const std::string &                                 getStation() const;
    const std::string &                                 getAgency() const;
    struct gps                                          getLocation() const;
    int                                                 getUnitcount() const;
    std::string                                         getUnitsString() const;
    const std::string &                                 getAddress() const;
    std::string                                         getFlagsString() const;
    const int &                                         getTurn();
    const std::string &                                 getIcon();

    void                                                clearCallSummeryHistory();
    void                                                clearAddressHistory();
    void                                                clearLocationHistory();

    // Processes/Loops
    const class Unit    *                               ProcessUnitList(const std::function<bool(const class Unit & _unit)> & f);
    const std::string   *                               ProcessCallSummeryHistory(const std::function<bool(const std::string & history)> & f);
    const std::string   *                               ProcessAddressHistory(const std::function<bool(const std::string & history)> & f);
    const struct gps    *                               ProcessLocationHistory(const std::function<bool(const struct gps & _location)> & f);
private:
    IncidentHeader                                      incidentInfo;
    std::string                                         time[MAX_NUM_CALL_STATUSES]; // 4 is the number of statuses. See callTime enum.
    std::string                                         callSummery;
    std::string                                         address;
    std::string                                         station;
    std::string                                         agency;
    int                                                 unitCount;
    std::string                                         units;
    struct gps                                          location;
    std::unordered_map<std::string, 
    struct callSummeryEventList>                        Flags; //I didn't want to resize the whole file to fit that long name.
    int                                                 Turn;
    std::string                                         Icon;

    std::unordered_map<std::string, class Unit>         unitList;

    // These operate more like stacks storing data until it's dumped into the database.
    std::vector<std::string>                            callSummeryHistory;
    std::vector<std::string>                            addressHistory;
    std::vector<struct gps>                             locationHistory;
};
