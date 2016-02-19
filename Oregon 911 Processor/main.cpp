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

    cout << "Oregon 911 Importer! \n\n";

    cout << util::http_get("http://www.wccca.com/PITSv2/Default.aspx", "__viewstate=");

    delete DataCache;
    return 0;
}
