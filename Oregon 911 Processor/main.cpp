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

using namespace std;

int main() {
    DataCache = new DataMaps();

    cout << "Oregon 911 Importer! \n\n";

    WCCCAParser WCCA_THING;

    WCCA_THING.parse(util::tidyHTML(GET_WCCCA_DATA()));

    delete DataCache;
    return 0;
}
