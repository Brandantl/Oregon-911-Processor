#include "Unit.h"
#include "Utils.h"
Unit::Unit()
{
    for (int i = 0; i < MAX_NUM_UNIT_STATUSES; i++) {
        time[i] = "00:00:00";
    }
}

void Unit::setName(const std::string & _name, const char & county)
{
    name = _name;
    agency = util::getAgencyByUnitName(_name, county);
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

const std::string & Unit::getName()
{
    return name;
}

const std::string & Unit::getAgency()
{
    return agency;
}

const std::string & Unit::getStation()
{
    return station;
}

const std::string & Unit::getTime(unitStatus _idx)
{
    return time[(unsigned int)_idx];
}
