/*
    Author: Brandan Tyler Lasley
    Date:   2/16/2016
    Purpose: Stores constants and settings.
*/
#pragma once

#define MAX_NUM_CALL_STATUSES   4
#define MAX_NUM_UNIT_STATUSES   4

#define WCCCA_PITS_URL          "http://www.wccca.com/PITSv2/Default.aspx"
#define WCCCA_PITS_POST         "__viewstate="
#define GET_WCCCA_DATA()        (util::http_get(WCCCA_PITS_URL, WCCCA_PITS_POST))
#define VALID_WCCCA_HTML_STR    "Joint CAD Incident Tracking System"
#define WCCCA_LOAD_MARKER       "LoadMarker"