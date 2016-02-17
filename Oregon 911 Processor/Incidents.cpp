/*
    Author: Brandan Tyler Lasley
    Date:   2/16/2016
*/
#include "Incidents.h"

Incidents::Incidents()
{

}

void Incidents::newImport()
{

}

void Incidents::addOrUpdateIncident(const Call &)
{

}

bool Incidents::doesIncidentExist(const Call &)
{
    return false;
}

void Incidents::gc()
{
}

const Call * Incidents::ProcessCallList(const std::function<bool(const class Call&_call)>& f)
{
    return nullptr;
}
