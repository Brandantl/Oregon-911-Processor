/*
    Author: Brandan Tyler Lasley
    Date:   2/16/2016
    Purpose: Stores constants and settings.
*/
#pragma once

#define READABLE_DEBUG          1

#define MAX_NUM_CALL_STATUSES   4
#define MAX_NUM_UNIT_STATUSES   4

#define UPDATE_FREQUENCY        5000 // MS

#define WCCCA_PITS_URL          "http://www.wccca.com/PITSv2/Default.aspx"
#define WCCCA_PITS_POST         "__viewstate="
#define GET_WCCCA_DATA()        (util::http_get(WCCCA_PITS_URL, WCCCA_PITS_POST))
#define USER_AGENT              "Oregon 911 Processor"
#define DEFAULT_STATION_ABBV    "UNK"

// Capitaliced
#define C_CCOM                  "CCOM"
#define C_WCCCA                 "WCCCA"

// Normal
#define CCOM                    "ccom"
#define WCCCA                   "wcca"

#define LW                      'W'
#define LC                      'C'

// Html stuff
#define VALID_WCCCA_HTML_STR     "Joint CAD Incident Tracking System"
#define XHTML_BODY_PATH          "html/body/form/div"
#define HTML_TITLE               "title"
#define HTML_CLASS               "class"
#define HTML_ID                  "id"
#define HTML_SCRIPT_START        "<script type=\"text/javascript\">"
#define HTML_SCRIPT_END          "</script>"
#define HTML_CALLTYPE            "CallType"

// Misc stuff
#define WCCCA_LOAD_MARKER       "LoadMarker"
#define WCCCA_TIME_NULL         "--:--:--"