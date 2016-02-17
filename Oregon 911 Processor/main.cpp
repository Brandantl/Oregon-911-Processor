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

#include <iostream>

using namespace std;

int main() {
    cout << "Oregon 911 Importer! \n";

    Call thing;
    Unit thing2;

    thing.setStation("ALO");
    thing2.setName("E62");
    thing.addUnit(thing2);

    cin.get();
    cin.get();
    return 0;
}
