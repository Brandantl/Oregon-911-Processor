/*
    Author: Brandan Tyler Lasley
    Date:   2/12/2016
    Purpose: To store data for an individual unit.
*/
#pragma once
#include <string>
#include "or911.h"
#include "structs.h"

enum class unitStatus {
    dispatched,
    enroute,
    onscene,
    clear
};

class Unit {
public:
    Unit();

    // Sets
    void        setName(const std::string & _name, const char & county);
    void        setAgency(const std::string & _agency);                     // Not required, should be automatically done by setting the name.
    void        setStation(const std::string & _station);
    void        setTime(unitStatus _idx, const std::string & _status);

    // Gets
    const std::string & getName() const;
    const std::string & getAgency() const;
    const std::string & getStation() const;
    const std::string & getTime(unitStatus _idx) const;

private:
    std::string name;
    std::string agency;
    std::string station;
    std::string time[MAX_NUM_UNIT_STATUSES]; // 4 is the number of statuses. See unitStatus enum.
};
