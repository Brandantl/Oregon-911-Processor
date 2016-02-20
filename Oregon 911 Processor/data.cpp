#include "data.h"

const stationInfoList knownStationList[]{
    "50", 'W', "WAL", "TUALATIN VALLEY FIRE & RESCUE",
    "214", 'C', "MAF", "LAKE OSWEGO F&R&LIFE SAFETY",
    "11", 'W', "GAF", "GASTON RFPD",
    "26", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "56", 'W', "ERD", "TUALATIN VALLEY FIRE & RESCUE",
    "13", 'C', "CLK", "CLACKAMAS CO. DISTRICT #1",
    "10", 'C', "BCK", "CLACKAMAS CO. DISTRICT #1",
    "53", 'W', "PRO", "TUALATIN VALLEY FIRE & RESCUE",
    "18", 'M', "P18", "PORTLAND FIRE & RESCUE",
    "9", 'C', "HOL", "CLACKAMAS CO. DISTRICT #1",
    "61", 'W', "CHS", "TUALATIN VALLEY FIRE & RESCUE",
    "25", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "64", 'W', "RCK", "TUALATIN VALLEY FIRE & RESCUE",
    "31", 'M', "UNK", "PORTLAND/GRESHAM - SHARED",
    "4", 'C', "LKR", "CLACKAMAS CO. DISTRICT #1",
    "8", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "5", 'W', "HJF", "HILLSBORO FIRE DEPT",
    "51", 'W', "TIG", "TUALATIN VALLEY FIRE & RESCUE",
    "436", 'C', "UNK", "SCAPPOOSE RFPD",
    "82", 'C', "MOL", "MOLALLA RFPD #73",
    "4", 'M', "P4", "PORTLAND FIRE & RESCUE",
    "368", 'W', "SKY", "TUALATIN VALLEY FIRE & RESCUE",
    "17", 'C', "SND", "CLACKAMAS CO. DISTRICT #1",
    "12", 'C', "LOG", "CLACKAMAS CO. DISTRICT #1",
    "76", 'M', "UNK", "GRESHAM FIRE & EMERG SRVCS",
    "15", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "103", 'C', "GLA", "GLADSTONE FD",
    "149", 'C', "DAM", "BORING FIRE DISTRICT #59",
    "22", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "72", 'M', "UNK", "GRESHAM FIRE & EMERG SRVCS",
    "129", 'C', "COL", "COLTON RFPD #70",
    "75", 'C', "DVR", "SANDY RFPD #72",
    "28", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "8", 'W', "COF", "CORNELIUS FIRE DEPT",
    "33", 'W', "SHW", "TUALATIN VALLEY FIRE & RESCUE",
    "251", 'C', "WEL", "HOODLAND RFPD #74",
    "52", 'W', "WIL", "TUALATIN VALLEY FIRE & RESCUE",
    "7", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "60", 'W', "CNL", "TUALATIN VALLEY FIRE & RESCUE",
    "6", 'C', "HVA", "CLACKAMAS CO. DISTRICT #1",
    "7", 'W', "FGF", "FOREST GROVE FIRE & RESCUE",
    "ODFT", 'W', "ODF", "OREGON DEPT OF FORESTRY",
    "23", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "14", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "11", 'C', "RDL", "CLACKAMAS CO. DISTRICT #1",
    "13", 'W', "BKF", "BANKS FIRE DISTRICT #13",
    "27", 'M', "P27", "PORTLAND FIRE & RESCUE",
    "71", 'M', "UNK", "GRESHAM FIRE & EMERG SRVCS",
    "14", 'W', "BUX", "BANKS FIRE DISTRICT #13",
    "58", 'W', "BOL", "TUALATIN VALLEY FIRE & RESCUE",
    "15", 'W', "TIM", "BANKS FIRE DISTRICT #13",
    "80", 'M', "UNK", "MULT CO FD #8 PDX (PORT OF PORTLAND)",
    "30", 'M', "UNK", "SAUVIE ISLAND VOL FD #30",
    "1", 'M', "P1", "PORTLAND FIRE & RESCUE",
    "16", 'M', "P16", "PORTLAND FIRE & RESCUE",
    "123", 'C', "ELD", "COLTON RFPD #70",
    "252", 'C', "BRI", "HOODLAND RFPD #74",
    "73", 'M', "UNK", "GRESHAM FIRE & EMERG SRVCS",
    "34", 'W', "TUA", "TUALATIN VALLEY FIRE & RESCUE",
    "19", 'W', "MWF", "WASHINGTON CO FD #2",
    "6", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "66", 'W', "BRR", "TUALATIN VALLEY FIRE & RESCUE",
    "13", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "210", 'C', "WSL", "LAKE OSWEGO F&R&LIFE SAFETY",
    "140", 'C', "BOR", "BORING FIRE DISTRICT #59",
    "20", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "17", 'W', "NPF", "WASHINGTON CO FD #2",
    "17", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "2", 'W', "HWH", "HILLSBORO FIRE DEPT",
    "65", 'W', "WSL", "TUALATIN VALLEY FIRE & RESCUE",
    "2", 'C', "MIL", "CLACKAMAS CO. DISTRICT #1",
    "69", 'W', "CMT", "TUALATIN VALLEY FIRE & RESCUE",
    "67", 'W', "BVM", "TUALATIN VALLEY FIRE & RESCUE",
    "75", 'M', "UNK", "GRESHAM FIRE & EMERG SRVCS",
    "7", 'C', "PVA", "CLACKAMAS CO. DISTRICT #1",
    "24", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "29", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "3", 'C', "OGR", "CLACKAMAS CO. DISTRICT #1",
    "62", 'W', "ALO", "TUALATIN VALLEY FIRE & RESCUE",
    "5", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "14", 'C', "HLD", "CLACKAMAS CO. DISTRICT #1",
    "59", 'W', "WFD", "TUALATIN VALLEY FIRE & RESCUE",
    "9", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "61", 'M', "UNK", "MULTNOMAH CO RFPD 14",
    "2", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "15", 'C', "JAS", "CLACKAMAS CO. DISTRICT #1",
    "3", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "12", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "35", 'W', "KCF", "TUALATIN VALLEY FIRE & RESCUE",
    "10", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "6", 'W', "HCL", "HILLSBORO FIRE DEPT",
    "81", 'C', "MUL", "MOLALLA RFPD #73",
    "3", 'W', "HRA", "HILLSBORO FIRE DEPT",
    "63", 'M', "UNK", "MULTNOMAH CO RFPD 14",
    "71", 'C', "SAN", "SANDY RFPD #72",
    "57", 'W', "MTR", "TUALATIN VALLEY FIRE & RESCUE",
    "19", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "30", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "110", 'C', "EST", "ESTACADA RFD #69",
    "115", 'C', "GEO", "ESTACADA RFD #69",
    "11", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "1", 'W', "HBM", "HILLSBORO FIRE DEPT",
    "62", 'M', "UNK", "MULTNOMAH CO RFPD 14",
    "212", 'C', "SSH", "LAKE OSWEGO F&R&LIFE SAFETY",
    "990", 'C', "UNK", "MONITOR FD #58",
    "74", 'M', "GR4", "GRESHAM FIRE & EMERG SRVCS",
    "4", 'W', "GCF", "FOREST GROVE FIRE & RESCUE",
    "68", 'W', "BTH", "TUALATIN VALLEY FIRE & RESCUE",
    "253", 'C', "GOV", "HOODLAND RFPD #74",
    "65", 'C', "LNE", "CANBY RFPD #62",
    "21", 'M', "UNK", "PORTLAND FIRE & RESCUE",
    "5", 'C', "CAU", "CLACKAMAS CO. DISTRICT #1",
    "8", 'C', "CLA", "CLACKAMAS CO. DISTRICT #1",
    "1", 'C', "TCR", "CLACKAMAS CO. DISTRICT #1",
    "85", 'C', "UNK", "MOLALLA RFPD #73",
    "148", 'C', "ECR", "BORING FIRE DISTRICT #59",
    "62", 'C', "CNB", "CANBY RFPD #62",
    "16", 'C', "HLT", "CLACKAMAS CO. DISTRICT #1",
    "76", 'C', "RLK", "SANDY RFPD #72",
    "70", 'W', "RHL", "TUALATIN VALLEY FIRE & RESCUE",
    "",0, "",""                                       // End, do not remove.
};

const unitInfoList knownUnitList[]{
    "E01", "1", "HBM", 'W', "HILLSBORO FIRE DEPT",
    "R01", "1", "HBM", 'W', "HILLSBORO FIRE DEPT",
    "WT01", "1", "HBM", 'W', "HILLSBORO FIRE DEPT",
    "E02", "2", "HWH", 'W', "HILLSBORO FIRE DEPT",
    "BR02", "2", "HWH", 'W', "HILLSBORO FIRE DEPT",
    "E03", "3", "HRA", 'W', "HILLSBORO FIRE DEPT",
    "BR03", "3", "HRA", 'W', "HILLSBORO FIRE DEPT",
    "TR03", "3", "HRA", 'W', "HILLSBORO FIRE DEPT",
    "E05", "5", "HJF", 'W', "HILLSBORO FIRE DEPT",
    "T05", "5", "HJF", 'W', "HILLSBORO FIRE DEPT",
    "C1", "5", "HJF", 'W', "HILLSBORO FIRE DEPT",
    "E06", "6", "HCL", 'W', "HILLSBORO FIRE DEPT",
    "E104", "6", "HCL", 'W', "HILLSBORO FIRE DEPT",
    "RHB104", "6", "HCL", 'W', "HILLSBORO FIRE DEPT",
    "E17", "17", "NPF", 'W', "WASHINGTON CO FD #2",
    "E173", "17", "NPF", 'W', "WASHINGTON CO FD #2",
    "BR171", "17", "NPF", 'W', "WASHINGTON CO FD #2",
    "HB177", "17", "NPF", 'W', "WASHINGTON CO FD #2",
    "WT17", "17", "NPF", 'W', "WASHINGTON CO FD #2",
    "E19", "19", "MWF", 'W', "WASHINGTON CO FD #2",
    "E194", "19", "MWF", 'W', "WASHINGTON CO FD #2",
    "E196", "19", "MWF", 'W', "WASHINGTON CO FD #2",
    "BR192", "19", "MWF", 'W', "WASHINGTON CO FD #2",
    "WT19", "19", "MWF", 'W', "WASHINGTON CO FD #2",
    "E60", "60", "CNL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "LB60", "60", "CNL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "SQT61", "61", "CHS", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "CAR61", "61", "CHS", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "SQT62", "62", "ALO", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "MED62", "62", "ALO", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "LB62", "62", "ALO", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E62", "62", "ALO", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E362", "62", "ALO", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "V362", "62", "ALO", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "V62", "62", "ALO", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E64", "64", "RCK", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "HB64", "64", "RCK", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E65", "65", "WSL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "WT65A", "65", "WSL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "WT65B", "65", "WSL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E66", "66", "BRR", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "HS66", "66", "BRR", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E67", "67", "BVM", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "T67", "67", "BVM", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "CAR67", "67", "BVM", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "C5", "67", "BVM", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E68", "68", "BTH", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E368", "368", "SKY", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "HB368", "368", "SKY", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "WT368", "368", "SKY", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "V368", "368", "SKY", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E33", "33", "SHW", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "RHB33", "33", "SHW", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E333", "33", "SHW", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "V333", "33", "SHW", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E35", "35", "KCF", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "MED35", "35", "KCF", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "WT35A", "35", "KCF", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "WT35B", "35", "KCF", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E50", "50", "WAL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "CAR50", "50", "WAL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "RHB350", "50", "WAL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "V350", "50", "WAL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "HR51", "51", "TIG", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "T51", "51", "TIG", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E51", "51", "TIG", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "USAR51", "51", "TIG", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E53", "53", "PRO", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "MED53", "53", "PRO", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "HM53", "53", "PRO", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "C7", "53", "PRO", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E69", "69", "CMT", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "HB69", "69", "CMT", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "SQT34", "34", "TUA", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "HM34", "34", "TUA", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "CAR34", "34", "TUA", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "WT34A", "34", "TUA", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "WT34B", "34", "TUA", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "C6", "34", "TUA", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E52", "52", "WIL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "LB52", "52", "WIL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "MED52R", "52", "WIL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "MCC", "52", "WIL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "MED52", "52", "WIL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "CAR56", "56", "ERD", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E56", "56", "ERD", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "T56", "56", "ERD", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E57", "57", "MTR", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "HB57", "57", "MTR", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "HB58", "58", "BOL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E58", "58", "BOL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E59", "59", "WFD", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "WR59", "59", "WFD", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "BOAT59", "59", "WFD", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "ZODIAC 59", "59", "WFD", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "E421", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "E422", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "MED4", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "T4", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "BR418", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "HB4", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "WT4", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "BOAT4", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "C4", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "C400", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "C401", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "E427", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "BR417", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "HB7", "7", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "E813", "8", "COF", 'W', "CORNELIUS FIRE DEPT",
    "E814", "8", "COF", 'W', "CORNELIUS FIRE DEPT",
    "R8", "8", "COF", 'W', "CORNELIUS FIRE DEPT",
    "BR816", "8", "COF", 'W', "CORNELIUS FIRE DEPT",
    "HB8", "8", "COF", 'W', "CORNELIUS FIRE DEPT",
    "WT8", "8", "COF", 'W', "CORNELIUS FIRE DEPT",
    "CAS8", "8", "COF", 'W', "CORNELIUS FIRE DEPT",
    "E13", "13", "BKF", 'W', "BANKS FIRE DISTRICT #13",
    "BE16", "13", "BKF", 'W', "BANKS FIRE DISTRICT #13",
    "R13", "13", "BKF", 'W', "BANKS FIRE DISTRICT #13",
    "BR13", "13", "BKF", 'W', "BANKS FIRE DISTRICT #13",
    "BR14", "13", "BKF", 'W', "BANKS FIRE DISTRICT #13",
    "WT13", "13", "BKF", 'W', "BANKS FIRE DISTRICT #13",
    "WT14", "13", "BKF", 'W', "BANKS FIRE DISTRICT #13",
    "E14", "14", "BUX", 'W', "BANKS FIRE DISTRICT #13",
    "E15", "15", "TIM", 'W', "BANKS FIRE DISTRICT #13",
    "E1171", "11", "GAF", 'W', "GASTON RFPD",
    "E1172", "11", "GAF", 'W', "GASTON RFPD",
    "E1173", "11", "GAF", 'W', "GASTON RFPD",
    "R11", "11", "GAF", 'W', "GASTON RFPD",
    "BR11", "11", "GAF", 'W', "GASTON RFPD",
    "BR1122", "11", "GAF", 'W', "GASTON RFPD",
    "WT11", "11", "GAF", 'W', "GASTON RFPD",
    "BOAT11", "11", "GAF", 'W', "GASTON RFPD",
    "PE16", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "PE4", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "PE27", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "PE22", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "PE3", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "PE5", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "PE18", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "PT4", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "PT22", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "PT3", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "PBR16", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "PBR27", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "PBR22", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "PC1", "0", "", 'M', "PORTLAND FIRE & RESCUE",
    "E423", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "E61", "61", "CHS", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "RHB333", "33", "SHW", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "WT7", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "C64", "62", "ALO", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "C13", "13", "BKF", 'W', "BANKS FIRE DISTRICT #13",
    "E815", "8", "COF", 'W', "CORNELIUS FIRE DEPT",
    "C410", "4", "FGF", 'W', "FOREST GROVE FIRE & RESCUE",
    "E350", "50", "WAL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "C11", "11", "GAF", 'W', "GASTON RFPD",
    "E111", "110", "EST", 'C', "ESTACADA RFD #69",
    "LIFE2", "LF2", "AUR", 'W', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "E110", "110", "EST", 'C', "ESTACADA RFD #69",
    "LIFE6", "LF6", "DAL", 'W', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "MED11", "11", "GAF", 'W', "GASTON RFPD",
    "LIFE10", "LF10", "LAG", 'W', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "AT129", "129", "COL", 'C', "COLTON RFPD #70",
    "LIFE11", "LF11", "RED", 'W', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "BR122", "129", "COL", 'C', "COLTON RFPD #70",
    "LIFE77", "LF77", "BOI", 'W', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "R121", "129", "COL", 'C', "COLTON RFPD #70",
    "LIFE81", "LF81", "POC", 'W', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "WT124", "129", "COL", 'C', "COLTON RFPD #70",
    "LIFE5", "LF5", "EUG", 'W', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "WT126", "123", "ELD", 'C', "COLTON RFPD #70",
    "LIFE7", "LF7", "LON", 'W', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "E123", "123", "ELD", 'C', "COLTON RFPD #70",
    "LIFE74", "LF74", "ONT", 'W', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "E125", "129", "COL", 'C', "COLTON RFPD #70",
    "LIFE12", "LF12", "PEN", 'W', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "E129", "129", "COL", 'C', "COLTON RFPD #70",
    "LIFE79", "LF79", "LEW", 'W', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "R65", "65", "LNE", 'C', "CANBY RFPD #62",
    "LIFE83", "LF83", "SAN", 'W', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "E65", "65", "LNE", 'C', "CANBY RFPD #62",
    "WT62", "62", "CNB", 'C', "CANBY RFPD #62",
    "WT61", "62", "CNB", 'C', "CANBY RFPD #62",
    "SQT62", "62", "CNB", 'C', "CANBY RFPD #62",
    "R62", "62", "CNB", 'C', "CANBY RFPD #62",
    "E63", "62", "CNB", 'C', "CANBY RFPD #62",
    "E61", "62", "CNB", 'C', "CANBY RFPD #62",
    "BR61", "62", "CNB", 'C', "CANBY RFPD #62",
    "BC6", "62", "CNB", 'C', "CANBY RFPD #62",
    "BR149", "149", "DAM", 'C', "BORING FIRE DISTRICT #59",
    "R149", "149", "DAM", 'C', "BORING FIRE DISTRICT #59",
    "E149", "149", "DAM", 'C', "BORING FIRE DISTRICT #59",
    "WT148", "148", "ECR", 'C', "BORING FIRE DISTRICT #59",
    "BR148", "148", "ECR", 'C', "BORING FIRE DISTRICT #59",
    "E148", "148", "ECR", 'C', "BORING FIRE DISTRICT #59",
    "SQ140", "140", "BOR", 'C', "BORING FIRE DISTRICT #59",
    "S140", "140", "BOR", 'C', "BORING FIRE DISTRICT #59",
    "WT141", "140", "BOR", 'C', "BORING FIRE DISTRICT #59",
    "WT140", "140", "BOR", 'C', "BORING FIRE DISTRICT #59",
    "R140", "140", "BOR", 'C', "BORING FIRE DISTRICT #59",
    "E142", "140", "BOR", 'C', "BORING FIRE DISTRICT #59",
    "E141", "140", "BOR", 'C', "BORING FIRE DISTRICT #59",
    "E140", "140", "BOR", 'C', "BORING FIRE DISTRICT #59",
    "BR140", "140", "BOR", 'C', "BORING FIRE DISTRICT #59",
    "C1", "1", "TCR", 'C', "CLACKAMAS CO. DISTRICT #1",
    "T21", "1", "TCR", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E1", "1", "TCR", 'C', "CLACKAMAS CO. DISTRICT #1",
    "SQ17", "17", "SND", 'C', "CLACKAMAS CO. DISTRICT #1",
    "S17", "17", "SND", 'C', "CLACKAMAS CO. DISTRICT #1",
    "BR11", "11", "RDL", 'C', "CLACKAMAS CO. DISTRICT #1",
    "WT11", "11", "RDL", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E11", "11", "RDL", 'C', "CLACKAMAS CO. DISTRICT #1",
    "SQ7", "7", "PVA", 'C', "CLACKAMAS CO. DISTRICT #1",
    "S7", "7", "PVA", 'C', "CLACKAMAS CO. DISTRICT #1",
    "RHGRP7", "7", "PVA", 'C', "CLACKAMAS CO. DISTRICT #1",
    "RH7", "7", "PVA", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E7", "7", "PVA", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E23", "3", "OGR", 'C', "CLACKAMAS CO. DISTRICT #1",
    "R23", "3", "OGR", 'C', "CLACKAMAS CO. DISTRICT #1",
    "R3", "3", "OGR", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E3", "3", "OGR", 'C', "CLACKAMAS CO. DISTRICT #1",
    "HSQ5", "5", "CAU", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E5", "5", "CAU", 'C', "CLACKAMAS CO. DISTRICT #1",
    "RHGRP2", "2", "MIL", 'C', "CLACKAMAS CO. DISTRICT #1",
    "RH2", "2", "MIL", 'C', "CLACKAMAS CO. DISTRICT #1",
    "HR13", "13", "BKF", 'W', "BANKS FIRE DISTRICT #13",
    "WT12", "12", "LOG", 'C', "CLACKAMAS CO. DISTRICT #1",
    "BR12", "12", "LOG", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E12", "12", "LOG", 'C', "CLACKAMAS CO. DISTRICT #1",
    "HR4", "4", "LKR", 'C', "CLACKAMAS CO. DISTRICT #1",
    "B2", "4", "LKR", 'C', "CLACKAMAS CO. DISTRICT #1",
    "T4", "4", "LKR", 'C', "CLACKAMAS CO. DISTRICT #1",
    "B3", "15", "JAS", 'C', "CLACKAMAS CO. DISTRICT #1",
    "T15", "15", "JAS", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E29", "9", "HOL", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E9", "9", "HOL", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E36", "16", "HLT", 'C', "CLACKAMAS CO. DISTRICT #1",
    "RHGRP16", "16", "HLT", 'C', "CLACKAMAS CO. DISTRICT #1",
    "RH16", "16", "HLT", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E16", "16", "HLT", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E14", "14", "HLD", 'C', "CLACKAMAS CO. DISTRICT #1",
    "BR6", "6", "HVA", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E6", "6", "HVA", 'C', "CLACKAMAS CO. DISTRICT #1",
    "BR13", "13", "CLK", 'C', "CLACKAMAS CO. DISTRICT #1",
    "WT13", "13", "CLK", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E13", "13", "CLK", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E28", "8", "CLA", 'C', "CLACKAMAS CO. DISTRICT #1",
    "BT8", "8", "CLA", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E8", "8", "CLA", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E20", "10", "BCK", 'C', "CLACKAMAS CO. DISTRICT #1",
    "BR10", "10", "BCK", 'C', "CLACKAMAS CO. DISTRICT #1",
    "WT10", "10", "BCK", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E10", "10", "BCK", 'C', "CLACKAMAS CO. DISTRICT #1",
    "LF83", "LF83", "SAN", 'C', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "LF79", "LF79", "LEW", 'C', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "LF12", "LF12", "PEN", 'C', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "LF74", "LF74", "ONT", 'C', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "LF7", "LF7", "LON", 'C', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "LF5", "LF5", "EUG", 'C', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "LF81", "LF81", "POC", 'C', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "LF77", "LF77", "BOI", 'C', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "LF11", "LF11", "RED", 'C', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "LF10", "LF10", "LAG", 'C', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "LF6", "LF6", "DAL", 'C', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "R110", "110", "EST", 'C', "ESTACADA RFD #69",
    "R111", "110", "EST", 'C', "ESTACADA RFD #69",
    "WT110", "110", "EST", 'C', "ESTACADA RFD #69",
    "WT111", "110", "EST", 'C', "ESTACADA RFD #69",
    "BR110", "110", "EST", 'C', "ESTACADA RFD #69",
    "BC11", "110", "EST", 'C', "ESTACADA RFD #69",
    "E115", "115", "GEO", 'C', "ESTACADA RFD #69",
    "R115", "115", "GEO", 'C', "ESTACADA RFD #69",
    "WT115", "115", "GEO", 'C', "ESTACADA RFD #69",
    "E103", "101", "GLA", 'C', "GLADSTONE FD",
    "E102", "101", "GLA", 'C', "GLADSTONE FD",
    "E101", "101", "GLA", 'C', "GLADSTONE FD",
    "T106", "101", "GLA", 'C', "GLADSTONE FD",
    "R101", "101", "GLA", 'C', "GLADSTONE FD",
    "S251", "251", "WEL", 'C', "HOODLAND RFPD #74",
    "SQ251", "251", "WEL", 'C', "HOODLAND RFPD #74",
    "R251", "251", "WEL", 'C', "HOODLAND RFPD #74",
    "M82", "82", "MOL", 'C', "MOLALLA RFPD #73",
    "E254", "251", "WEL", 'C', "HOODLAND RFPD #74",
    "WT251", "251", "WEL", 'C', "HOODLAND RFPD #74",
    "BR251", "251", "WEL", 'C', "HOODLAND RFPD #74",
    "SQ252", "252", "BRI", 'C', "HOODLAND RFPD #74",
    "S252", "252", "BRI", 'C', "HOODLAND RFPD #74",
    "E252", "252", "BRI", 'C', "HOODLAND RFPD #74",
    "WT252", "252", "BRI", 'C', "HOODLAND RFPD #74",
    "S253", "253", "GOV", 'C', "HOODLAND RFPD #74",
    "SQ253", "253", "GOV", 'C', "HOODLAND RFPD #74",
    "E253", "251", "WEL", 'C', "HOODLAND RFPD #74",
    "E81", "81", "MUL", 'C', "MOLALLA RFPD #73",
    "R81", "81", "MUL", 'C', "MOLALLA RFPD #73",
    "E82", "82", "MOL", 'C', "MOLALLA RFPD #73",
    "SQ82", "82", "MOL", 'C', "MOLALLA RFPD #73",
    "S82", "82", "MOL", 'C', "MOLALLA RFPD #73",
    "WT82", "82", "MOL", 'C', "MOLALLA RFPD #73",
    "E71", "71", "SAN", 'C', "SANDY RFPD #72",
    "E72", "71", "SAN", 'C', "SANDY RFPD #72",
    "M81", "81", "MUL", 'C', "MOLALLA RFPD #73",
    "R71", "71", "SAN", 'C', "SANDY RFPD #72",
    "R74", "71", "SAN", 'C', "SANDY RFPD #72",
    "WT71", "71", "SAN", 'C', "SANDY RFPD #72",
    "BR71", "71", "SAN", 'C', "SANDY RFPD #72",
    "BT71", "71", "SAN", 'C', "SANDY RFPD #72",
    "E75", "75", "DVR", 'C', "SANDY RFPD #72",
    "R75", "75", "DVR", 'C', "SANDY RFPD #72",
    "WT75", "75", "DVR", 'C', "SANDY RFPD #72",
    "BR75", "75", "DVR", 'C', "SANDY RFPD #72",
    "E76", "76", "RLK", 'C', "SANDY RFPD #72",
    "WT76", "76", "RLK", 'C', "SANDY RFPD #72",
    "E210", "210", "WSL", 'C', "LAKE OSWEGO F&R&LIFE SAFETY",
    "E211", "211", "JRS", 'C', "LAKE OSWEGO F&R&LIFE SAFETY",
    "T211", "211", "JRS", 'C', "LAKE OSWEGO F&R&LIFE SAFETY",
    "E212", "212", "SSH", 'C', "LAKE OSWEGO F&R&LIFE SAFETY",
    "BR2212", "212", "SSH", 'C', "LAKE OSWEGO F&R&LIFE SAFETY",
    "BT212", "212", "SSH", 'C', "LAKE OSWEGO F&R&LIFE SAFETY",
    "E214", "214", "MAF", 'C', "LAKE OSWEGO F&R&LIFE SAFETY",
    "DR214", "214", "MAF", 'C', "LAKE OSWEGO F&R&LIFE SAFETY",
    "B1", "214", "MAF", 'C', "LAKE OSWEGO F&R&LIFE SAFETY",
    "HR140", "140", "BOR", 'C', "BORING FIRE DISTRICT #59",
    "3801", "81", "MUL", 'C', "MOLALLA RFPD #73",
    "1209", "70", "COL", 'C', "COLTON RFPD #70",
    "2501", "251", "WEL", 'C', "HOODLAND RFPD #74",
    "1409", "140", "BOR", 'C', "BORING FIRE DISTRICT #59",
    "D1BC", "2", "MIL", 'C', "CLACKAMAS CO. DISTRICT #1",
    "1402", "140", "BOR", 'C', "BORING FIRE DISTRICT #59",
    "BC2", "4", "LKR", 'C', "CLACKAMAS CO. DISTRICT #1",
    "E2", "2", "MIL", 'C', "CLACKAMAS CO. DISTRICT #1",
    "2502", "251", "WEL", 'C', "HOODLAND RFPD #74",
    "3802", "82", "MOL", 'C', "MOLALLA RFPD #73",
    "E74", "71", "SAN", 'C', "SANDY RFPD #72",
    "BC3", "15", "JAS", 'C', "CLACKAMAS CO. DISTRICT #1",
    "3809", "82", "MOL", 'C', "MOLALLA RFPD #73",
    "2509", "251", "WEL", 'C', "HOODLAND RFPD #74",
    "2504", "251", "WEL", 'C', "HOODLAND RFPD #74",
    "E251", "253", "GOV", 'C', "HOODLAND RFPD #74",
    "BR210", "210", "WSL", 'C', "LAKE OSWEGO F&R&LIFE SAFETY",
    "LF2", "LF2", "AUR", 'C', "LIFEFLIGHT NETWORK AIR AMBULANCE",
    "MED05", "3", "HRA", 'W', "HILLSBORO FIRE DEPT",
    "E92", "62", "ALO", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "T8", "8", "CLA", 'C', "CLACKAMAS CO. DISTRICT #1",
    "HR5", "8", "CLA", 'C', "CLACKAMAS CO. DISTRICT #1",
    "MED70", "70", "RHL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "SQD350", "50", "WAL", 'W', "TUALATIN VALLEY FIRE & RESCUE",
    "", "", "", 0, ""                                       // End, do not remove.
};

const callSummeryEventList knownFeildsEvents[]{
    "SAG", "Second Alarm at", "SAG", "fire.png",
    "2ALMM", "Second Alarm Medical at", "2ALMM", "EMS.png",
    "3ALMM", "Three Alarm Medical at", "2ALMM", "EMS.png",
    "1ALM", "First Alarm at", "2ALMM", "fire.png",
    "2ALM", "Second Alarm at", "2ALMM", "fire.png",
    "3ALM", "Third Alarm at", "3ALMM", "fire.png",
    "4ALM", "Forth Alarm at", "4ALMM", "fire.png",
    "5ALM", "Fifth Alarm+ at", "5ALMM", "fire.png",
    "HM", "Hazmat at", "HAZMAT0", "HAZMAT.png",
    "","","",""                                       // End, do not remove.
};

const callSummeryEventList knownCallSummeryEvents[]{
    "AIR ALERT1:UNIT", "Aircraft is in minor difficulty at", "AR1", "airport.png",
    "AIR ALERT1", "Aircraft is in minor difficulty at", "AR1", "airport.png",
    "AIR ALERT I", "Aircraft is in minor difficulty at", "AR1", "airport.png",
    "AIR ALERTI", "Aircraft is in minor difficulty at", "AR1", "airport.png",
    "AIRCRAFT EMERGENCY - ALERT LEVEL 1", "Aircraft is in minor difficulty at", "AR1", "airport.png",
    "PALRT1", "Aircraft is in minor difficulty at", "AR1", "airport.png",
    "AIR ALERT2", "Aircraft is in major difficulty at", "AR2", "airport.png",
    "AIR ALERT2:TASK", "Aircraft is in major difficulty at", "AR2", "airport.png",
    "AIR ALERT2", "Aircraft is in major difficulty at", "AR2", "airport.png",
    "AIR ALERT II", "Aircraft is in major difficulty at", "AR2", "airport.png",
    "AIR ALERTII", "Aircraft is in major difficulty at", "AR2", "airport.png",
    "AIRCRAFT EMERGENCY - ALERT LEVEL 2", "Aircraft is in major difficulty at", "AR2", "airport.png",
    "PALRT2", "Aircraft is in major difficulty at", "AR2", "airport.png",
    "AIR ALERT3:BOX", "An aircraft has crashed at", "AR3", "airport.png",
    "AIR ALERT 3", "An aircraft has crashed at", "AR3", "airport.png",
    "AIR ALERT3", "An aircraft has crashed at", "AR3", "airport.png",
    "AIR ALERT III", "An aircraft has crashed at", "AR3", "airport.png",
    "AIR ALERTIII", "An aircraft has crashed at", "AR3", "airport.png",
    "AIRCRAFT EMERGENCY - ALERT LEVEL 3", "An aircraft has crashed at", "AR3", "airport.png",
    "PALRT3", "An aircraft has crashed at", "AR3", "airport.png",
    "AIRCRAFT EMERGENCY", "An aircraft is in unknown difficulty at", "AR0", "airport.png",
    "DISASTER", "Disaster at", "DISASTER", "tsunami.png",
    "EXPLOSION", "Explosion at", "EXPLOSION", "avalance.png",
    "HMII", "Hazmat Level 2 (hazardous to health) at", "HAZMAT2", "Hazmat.png",
    "HAZMAT LEVEL 2", "Hazmat Level 2 (hazardous to health) at", "HAZMAT2", "Hazmat.png",
    "HMIII", "Hazmat Level 3 (extremely hazardous to health) at", "HAZMAT3", "Hazmat.png",
    "HAZMAT LEVEL 3", "Hazmat Level 3 (extremely hazardous to health) at", "HAZMAT3", "Hazmat.png",
    "HAZMAT LEVEL 4", "Hazmat Level 4 (too dangerous for human exposure) at", "HAZMAT4", "Hazmat.png",
    "HMIIII", "Hazmat Level 4 (too dangerous for human exposure) at", "HAZMAT4", "Hazmat.png",
    "HAZARDOUS MAT", "Hazmat Level UNK (Unknown Danger lvl) at", "HAZMAT0", "Hazmat.png",
    "HIGH ANGLE RESQ", "Rope rescue at", "ROPERESQ", "avalance.png",
    "TECHNICAL RESCUE", "Rope/Technical rescue at", "ROPERESQ", "avalance.png",
    "INDUSTRIAL ACCID", "Industrial Accident at", "INDUSTACC", "Hazmat.png",
    "BOMB THREAT", "Bomb threat at", "BOMB", "bomb.png",
    "MARINE INCIDENT", "Marine Rescue investigation at", "MR1", "boat.png",
    "MR2", "Marine Rescue (LVL 2) at", "MR2", "boat.png",
    "WATER RESCUE", "Marine Rescue (LVL 2) at", "MR2", "boat.png",
    "TAI-HIGH MECHANI", "Major MVA/Other w/ possible entrapment at", "MMVA", "caraccident.png",
    "MECH ENTRAPMENT", "Major MVA/Other w/ possible entrapment at", "MMVA", "caraccident.png",
    "EMTRAPMENT", "Major MVA/Other w/ possible entrapment at", "MMVA", "caraccident.png",
    "ENTRAPMENT", "Major MVA/Other w/ possible entrapment at", "MMVA", "caraccident.png",
    "SHOTS", "Shots fired/shooting at", "SHOOTING", "crimescene.png",
    "FIRED", "Shots fired/shooting at", "SHOOTING", "crimescene.png",
    "GUN", "Shots fired/shooting at", "SHOOTING", "crimescene.png",
    "SHOOTING", "Shots fired/shooting at", "SHOOTING", "crimescene.png",
    "TRAIN INCIDENT", "Train Incident/Accident at", "TRINCD", "crimescene.png",
    "TRAIN ACCIDENT", "Train Incident/Accident at", "TRINCD", "crimescene.png",
    "AIR ALERT1", "Aircraft is in minor difficulty at", "AR1", "airport.png",
    "MASS CASUALTY", "Mass-casualty incident at", "2ALMM", "fire.png",
    "MARINE RESCUE 2", "Marine Rescue (LVL 2) at ", "MR2", "boat.png",
    "LIGHTNING", "Lightning Strike at", "LIGHTNING", "general.png",
    "AIRCRAFT, SMALL", "Aircraft incident/crash at", "AR0", "airport.png",
    "AIRCRAFT, MEDIUM", "Aircraft incident/crash at", "AR0", "airport.png",
    "AIRCRAFT, LARGE", "Aircraft incident/crash at", "AR0", "airport.png",
    "MULTI PATIENT", "Mass-casualty incident at", "2ALMM", "fire.png",
    "TAI-PT NOT ALERT", "Major MVA/Other w/ possible entrapment at	", "MMVA", "caraccident.png",
    "TAI-TRAPPED VICT", "Major MVA/Other w/ possible entrapment at	", "MMVA", "caraccident.png",
    "BURNS/EXPLOSION", "Explosion at ", "EXPLOSION", "bomb.png",
    "CAVE IN RESCUE", "Cave in rescue at ", "CAVER", "avalance.png",
    "CONFINED ENTRAPM", "Confined entrapment at ", "CENT", "avalance.png",
    "TAI-MAJOR INCIDE", "Major traffic accident at ", "MMVA", "caraccident.png",
    "2ND ALARM TRAUMA", "Second Alarm Medical at", "2ALMM", "fire.png",
    "","","",""                                       // End, do not remove.
};

const struct agencyList knownAgencyList[] =
{
    "CBOC","Tualatin Valley Fire & Rescue",
    "TRS","Tualatin Valley Fire & Rescue",
    "SHW","Tualatin Valley Fire & Rescue",
    "TUA","Tualatin Valley Fire & Rescue",
    "KCF","Tualatin Valley Fire & Rescue",
    "WAL","Tualatin Valley Fire & Rescue",
    "TIG","Tualatin Valley Fire & Rescue",
    "WIL","Tualatin Valley Fire & Rescue",
    "PRO","Tualatin Valley Fire & Rescue",
    "CNL","Tualatin Valley Fire & Rescue",
    "CHS","Tualatin Valley Fire & Rescue",
    "ALO","Tualatin Valley Fire & Rescue",
    "RCK","Tualatin Valley Fire & Rescue",
    "WSL","Tualatin Valley Fire & Rescue",
    "BRR","Tualatin Valley Fire & Rescue",
    "BVM","Tualatin Valley Fire & Rescue",
    "KAI","Tualatin Valley Fire & Rescue",
    "SKY","Tualatin Valley Fire & Rescue",
    "CMT","Tualatin Valley Fire & Rescue",
    "ERD","Tualatin Valley Fire & Rescue",
    "MTR","Tualatin Valley Fire & Rescue",
    "BOL","Tualatin Valley Fire & Rescue",
    "WFD","Tualatin Valley Fire & Rescue",
    "BTH","Tualatin Valley Fire & Rescue",
    "RHL","Tualatin Valley Fire & Rescue",
    "HBM","Hillsboro Fire & Rescue",
    "HWH","Hillsboro Fire & Rescue",
    "HRA","Hillsboro Fire & Rescue",
    "HJF","Hillsboro Fire & Rescue",
    "HCL","Hillsboro Fire & Rescue",
    "FGF","Forest Grove Fire & Rescue",
    "GCF","Forest Grove Fire & Rescue",
    "NPF","Washington County Fire District #2",
    "MWF","Washington County Fire District #2",
    "COF","Cornelius Fire Department",
    "BKF","Banks Fire District #13",
    "BUX","Banks Fire District #13",
    "BUX","Banks Fire District #13",
    "TIM","Banks Fire District #13",
    "GAF","Gaston Rural Fire District #11",
    "CNB","Canby Fire District #62",
    "LNE","Canby Fire District #62",
    "TCR","Clackamas Fire District #1",
    "MIL","Clackamas Fire District #1",
    "OGR","Clackamas Fire District #1",
    "LKR","Clackamas Fire District #1",
    "CAU","Clackamas Fire District #1",
    "HVA","Clackamas Fire District #1",
    "PVA","Clackamas Fire District #1",
    "CLA","Clackamas Fire District #1",
    "HOL","Clackamas Fire District #1",
    "BCK","Clackamas Fire District #1",
    "RDL","Clackamas Fire District #1",
    "LOG","Clackamas Fire District #1",
    "CLK","Clackamas Fire District #1",
    "HLD","Clackamas Fire District #1",
    "JAS","Clackamas Fire District #1",
    "HLT","Clackamas Fire District #1",
    "SND","Clackamas Fire District #1",
    "BOR","Clackamas Fire District #1",
    "ECR","Clackamas Fire District #1",
    "DAM","Clackamas Fire District #1",
    "COL","Colton Fire District #70",
    "EST","Estacada Fire District #69",
    "GEO","Estacada Fire District #69",
    "GLA","Gladstone Fire Department",
    "WEL","Hoodland Fire District #74",
    "BRI","Hoodland Fire District #74",
    "GOV","Hoodland Fire District #74",
    "MOL","Molalla Fire District #73",
    "MUL","Molalla Fire District #73",
    "SAN","Sandy Fire District #72",
    "DVR","Sandy Fire District #72",
    "RLK","Sandy Fire District #72",
    "AUA","Aurora Fire District #63",
    "WCCCA","Oregon Department of Forestry",
    "ODF","Oregon Department of Forestry",
    "P1","Portland Fire Bureau",
    "P3","Portland Fire Bureau",
    "P4","Portland Fire Bureau",
    "P5","Portland Fire Bureau",
    "P7","Portland Fire Bureau",
    "P11","Portland Fire Bureau",
    "P15","Portland Fire Bureau",
    "P16","Portland Fire Bureau",
    "P18","Portland Fire Bureau",
    "P20","Portland Fire Bureau",
    "P25","Portland Fire Bureau",
    "P27","Portland Fire Bureau",
    "P28","Portland Fire Bureau",
    "P29","Portland Fire Bureau",
    "YAM","Yamhill Fire Protection District",
    "NBF","Newberg Fire Department",
    "LCOM","Lake Oswego Fire Department",
    "VER","Vernonia Rural Fire Department",
    "USF","United States Forest Service",
    "HUB","Hubbard Fire District",
    "",""                                       // End, do not remove.
};

const std::string knownCallFeilds[]
{
    "YMAMB",
    "X",
    "WRTEAM",
    "WFCA",
    "WCWR",
    "WASHA",
    "USFS",
    "UPRR",
    "TVTECH",
    "TVPIO",
    "TVINV",
    "TVIMT",
    "TVFR",
    "TVCHAP",
    "TVCFA1",
    "TVCFA",
    "TSKGF",
    "TSKFR1",
    "TSKFOR",
    "TSKFG",
    "TSKD2",
    "TSKCF",
    "TSKBK",
    "TRUCKY",
    "TRNG1",
    "TOW",
    "TIP",
    "TIMERW",
    "TIMERH",
    "TIMERG",
    "TIMERF",
    "TIMERC",
    "TIMERB",
    "TIMER1",
    "TIMER",
    "THPRD",
    "TEST",
    "TECHS",
    "TASKD1",
    "SUP4",
    "STA8",
    "STA7",
    "STA4",
    "STA13",
    "STA11",
    "SQUAD1",
    "SFOR1",
    "SFOR",
    "SAG",
    "ROADS",
    "RH1GRP",
    "REV3",
    "RESCUE",
    "REACH",
    "RCROSS",
    "RANGER",
    "PW",
    "PREV9",
    "PREV8",
    "PREV7",
    "PREV6",
    "PREV4",
    "PREV3",
    "PREV2",
    "PREV11",
    "PREV10",
    "PREV1",
    "PREV",
    "PREV",
    "POAMR",
    "PIO14",
    "PIO1",
    "PGE4",
    "PGE2",
    "PGE1",
    "PGE",
    "PFC3",
    "PFB",
    "PDXOPS",
    "PDONLY",
    "PANDA",
    "PACU",
    "OPS34",
    "ODOTS",
    "ODOTN",
    "ODOTF",
    "ODOTE",
    "ODOTC",
    "ODOT1",
    "ODOT",
    "ODF",
    "NWNAT",
    "NWGAS",
    "MX",
    "MOVOL",
    "MONITR",
    "METWSF",
    "METWF",
    "METWD",
    "METWC",
    "METWB",
    "METWA",
    "METCOM",
    "MEDA",
    "M1",
    "LOG4",
    "LOG3",
    "LOG2",
    "LOG1",
    "LOCOM",
    "LIFE",
    "LFSTBY",
    "LF1",
    "LF",
    "ITS",
    "INFOS",
    "INFOF",
    "INFOE",
    "INFO9",
    "INFO8",
    "INFO7",
    "INFO6",
    "INFO4",
    "INFO3",
    "INFO2",
    "INFO1",
    "INFO",
    "HOLD3",
    "HOLD3",
    "HOLD2",
    "HOLD2",
    "HOLD1",
    "HFTECH",
    "HFPIO",
    "HFINV",
    "HFDTF",
    "HFCHAP",
    "HFC",
    "HBIMT",
    "GLBC",
    "GEN4",
    "FOC",
    "FFINV",
    "FFDUTY",
    "FFCHAP",
    "FDL",
    "FDBC",
    "EVMWT",
    "ETIME3",
    "ETIME2",
    "ETIME",
    "ETIME",
    "ESRRT",
    "EMSMO",
    "EMSES",
    "EMSCA",
    "EMSCA",
    "DAREA",
    "D2VOLN",
    "D2VOLM",
    "D2PIO",
    "D2INV",
    "D2CHAP",
    "D1SUPP",
    "D1RRT",
    "CUB",
    "CRISIS",
    "CPOW",
    "COPW",
    "COMTEK",
    "COMTEK",
    "CLACKA",
    "CHIEF1",
    "CHEIF1",
    "CH6GRP",
    "CH1GRP",
    "CFDUTY",
    "CFCHAP",
    "CCWR",
    "CCFD",
    "CBHQ",
    "CAVOL",
    "CAVOL",
    "CAFD",
    "C1INFO",
    "BREIBR",
    "BOEC",
    "BKFD",
    "AURORA",
    "AMR",
    "AMR",
    "AFCHAP",
    "3ALMV",
    "3ALMF",
    "2ALMV",
    "2ALMM",
    "2ALMH",
    "2ALMF",
    "2ALMC",
    "2ALMB",
    "1ALMW",
    "1ALMV1",
    "1ALMV",
    "1ALMH",
    "1ALMF",
    "1ALMD1",
    "1ALMC",
    "1ALMB",
    ""                                       // End, do not remove.
};

const std::string   knownPoliceStations[]{
    "WX",
    "W81",
    "W80",
    "W71",
    "W70",
    "W61",
    "W60",
    "W51",
    "W50",
    "W41",
    "W40",
    "W31",
    "W30",
    "W21",
    "W20",
    "U4",
    "U3",
    "U2",
    "U1",
    "T5",
    "T4",
    "T3",
    "T2",
    "T1",
    "S3",
    "S2",
    "S1",
    "N1",
    "K1",
    "H5",
    "H4",
    "H3",
    "H2",
    "H1",
    "G1",
    "F2",
    "F1",
    "C3",
    "C2",
    "B4",
    "B3",
    "B2",
    "B1",
    "A3",
    ""                                       // End, do not remove.
};