/*
    Author: Brandan Tyler Lasley
    Date:   2/12/2016
    Purpose: To store data for an individual incident.
*/
#include "Unit.h"
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>

#define MAX_NUM_CALL_STATUSES 4

struct gps {
    double lat;
    double lon;

	bool isInit() {
		if (lat > 0 && lon > 0)
			return true;
		return false;
	}
	bool operator== (const gps &loc1) {
		return (lat == loc1.lat && lon == loc1.lon);
	}
	bool operator!= (const gps &loc1) {
		return (!this->operator==(loc1));
	}
};

enum class callTime {
    entry,
    dispatch,
    enroute,
    clear
};

class Call {

public:
    Call();

	// Add
	void							addUnit(Unit thing);

	// Remove
	void							removeUnit(const std::string & name);

	// Exits
	bool							doesUnitExist(const std::string & name);

    // Sets
    void                            setCallNumber(int _callNumber);
    void                            setCounty(char _county);
    void                            setTime(callTime _idx, std::string _status);
    void                            setCallSummery(std::string _callSummery);
    void                            setAgency(std::string _agency);
    void                            setAgencyName(std::string _agencyName);
    void                            setLocation(struct gps _location);
	void							setAddress(std::string _address);

    // Gets
    int			                    getCallNumber();
    char                            getCounty();
    std::string                     getTime(callTime _idx);
    std::string                     getCallSummery();
    std::string                     getAgency();
    std::string                     getAgencyName();
    struct gps                      getLocation();
    int                             getUnitcount();
    std::string                     getUnitsString();
	std::string						setAddress();

	void							clearCallSummeryHistory();
	void							clearAddressHistory();
	void							clearLocationHistory();

    // Processes/Loops
	const class Unit	*			ProcessUnitList(const std::function<bool(const class Unit & _unit)> & f);
    const std::string   *           ProcessCallSummeryHistory(const std::function<bool(const std::string & history)> & f);
    const std::string   *           ProcessAddressHistory(const std::function<bool(const std::string & history)> & f);
    const struct gps    *           ProcessLocationHistory(const std::function<bool(const struct gps & _location)> & f);

private:
    int								callNumber;
    char                            county;
    std::string                     time[MAX_NUM_CALL_STATUSES]; // 4 is the number of statuses. See callTime enum.
    std::string                     callSummery;
    std::string                     address;
    std::string                     agency;
    std::string                     agencyName;
    int                             unitCount;
    std::string                     station;
    std::string                     units;
    struct gps                      location;

	std::unordered_map<std::string, class Unit>		unitList;

	// These operate more like stacks storing data until it's dumped into the database.
    std::vector<std::string>        callSummeryHistory;
    std::vector<std::string>        addressHistory;
    std::vector<struct gps>         locationHistory;
};
