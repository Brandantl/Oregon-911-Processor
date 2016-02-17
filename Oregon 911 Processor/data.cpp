#include "data.h"

extern const callSummeryEventList knownFeildsEvents[] {
    "SAG", "Second Alarm at", "SAG", "fire.png",
    "2ALMM", "Second Alarm Medical at", "2ALMM", "EMS.png",
    "3ALMM", "Three Alarm Medical at", "2ALMM", "EMS.png",
    "1ALM", "First Alarm at", "2ALMM", "fire.png",
    "2ALM", "Second Alarm at", "2ALMM", "fire.png",
    "3ALM", "Third Alarm at", "3ALMM", "fire.png",
    "4ALM", "Forth Alarm at", "4ALMM", "fire.png",
    "5ALM", "Fifth Alarm+ at", "5ALMM", "fire.png",
    "HM", "Hazmat at", "HAZMAT0", "HAZMAT.png"
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
    "Entrapment", "Major MVA/Other w/ possible entrapment at", "MMVA", "caraccident.png",
    "BOMB THREAT", "Bomb threat at", "BOMB", "bomb.png",
    "MARINE INCIDENT", "Marine Rescue investigation at", "MR1", "boat.png",
    "MR2", "Marine Rescue (LVL 2) at", "MR2", "boat.png",
    "WATER RESCUE", "Marine Rescue (LVL 2) at", "MR2", "boat.png",
    "TAI-HIGH MECHANI", "Major MVA/Other w/ possible entrapment at", "MMVA", "caraccident.png",
    "MECH ENTRAPMENT", "Major MVA/Other w/ possible entrapment at", "MMVA", "caraccident.png",
    "EMTRAPMENT", "Major MVA/Other w/ possible entrapment at", "MMVA", "caraccident.png",
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
    "2nd Alarm Trauma", "Second Alarm Medical at", "2ALMM", "fire.png",
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