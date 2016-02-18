/*
    Author: Brandan Tyler Lasley
    Date:   2/16/2016
*/
#include "Unit.h"
#include "Utils.h"
#include "DataMaps.h"
Unit::Unit()
{
    for (int i = 0; i < MAX_NUM_UNIT_STATUSES; i++) {
        time[i] = "00:00:00";
    }
}

void Unit::updateUnit(const Unit & obj)
{
    for (int i = 0; i < MAX_NUM_UNIT_STATUSES; i++) {
        if (obj.time[i] != "00:00:00") {
            time[i] = obj.time[i];
        }
    }
}

void Unit::setName(const std::string & _name, const char & county)
{
    name = _name;
    agency = DataCache->getUnitInfo(_name)->agency;
}

void Unit::setAgency(const std::string & _agency)
{
    agency = _agency;
}

void Unit::setStation(const std::string & _station)
{
    station = _station;
}

void Unit::setTime(unitStatus _idx, const std::string & _status)
{
    this->time[(unsigned int)_idx] = _status;
}

const std::string & Unit::getName() const
{
    return name;
}

const std::string & Unit::getAgency() const
{
    return agency;
}

const std::string & Unit::getStation() const
{
    return station;
}

const std::string & Unit::getTime(unitStatus _idx) const
{
    return time[(unsigned int)_idx];
}
