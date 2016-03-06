/*
    Author: Brandan Tyler Lasley
    Date:   2/12/2016
*/
#include "or911.h"
#include "structs.h"
#include "data.h"
#include "Unit.h"
#include "Call.h"
#include "Utils.h"
#include "DataMaps.h"
#include "WCCCAParser.h"
#include <iostream>
#include <string>
#include "Poco/Thread.h"
using namespace std;

bool print_call(const Call & c);
bool print_unit(const Unit & u);

int main() {
    DataCache = new DataMaps();

    cout << "Oregon 911 Importer! \n\n";

    WCCCAParser WCCCA_THING;

    while (true) {
        WCCCA_THING.parse(util::tidyHTML(GET_WCCCA_DATA()));
        WCCCA_THING.ProcessCallList(print_call);
        Poco::Thread::sleep(UPDATE_FREQUENCY);
    }

    delete DataCache;
    return 0;
}

bool print_call(const Call & c) {
    const IncidentHeader & h = c.getIncidentInfo();
    cout << " =========== " << h.county << " - " << h.callNumber << " ======== \n";
    cout << "Callsum: " << c.getCallSummery() << "\n";
    cout << "Type: " << h.type << "\n";
    cout << "Address: " << c.getAddress() << "\n";
    cout << "Agency: " << c.getAgency() << "\n";
    cout << "Station: " << c.getStation() << "\n";
    cout << "Time: " << c.getTime(callTime::entry) << " " << c.getTime(callTime::dispatch) << " " << c.getTime(callTime::enroute) << " " << c.getTime(callTime::onscene) << "\n";
    cout << "Update Turn: " << c.getTurn() << "\n";
    c.ProcessUnitList(print_unit);
    cout << "\n";
    return true;
}

bool print_unit(const Unit & u) {
    cout << "== Unit " << u.getName() << " == \n";
    cout << "Station: " << u.getStation() << "\n";
    cout << "Agency: " << u.getAgency() << "\n";
    cout << "Time: " << u.getTime(unitStatus::dispatched) << " " << u.getTime(unitStatus::enroute) << " " << u.getTime(unitStatus::onscene) << " " << u.getTime(unitStatus::clear) << "\n";
    return true;
}