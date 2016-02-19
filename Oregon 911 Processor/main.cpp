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
#include <string>
using namespace std;

int main() {
    DataCache = new DataMaps();

    cout << "Oregon 911 Importer! \n\n";

    const std::string WCCCA_STR  = GET_WCCCA_DATA();

    vector<struct WCCCA_JSON> gpsData = util::getWCCCAGPSFromHTML(WCCCA_STR);



    delete DataCache;
    return 0;
}
