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
#include <iostream>

using namespace std;

int main() {
    DataCache = new DataMaps();

    cout << "Oregon 911 Importer! \n";

    Call thing;
    Unit thing2;

    thing.setStation("ALO");
    thing2.setName("E62", 'W');
    thing.addOrUpdateUnit(thing2);

    const Unit* x = thing.ProcessUnitList([](const Unit & t) { return false; });

    cin.get();
    cin.get();

    delete DataCache;
    return 0;
}
