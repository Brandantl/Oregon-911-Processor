/*
    Author: Brandan Tyler Lasley
    Date:   2/12/2016
    Purpose: To store data for an individual unit.
*/
#include <string>

#define MAX_NUM_UNIT_STATUSES 4

enum class unitStatus {
    dispatched,
    enroute,
    onscene,
    clear
};

class Unit {
public:
    Unit();

    // Sets
    void        setName(std::string _name);
    void        setAgency(std::string _agency);
    void        setStation(std::string _station);
    void        setTime(unitStatus _idx, std::string _status);

    // Gets
    std::string getName();
    std::string getAgency();
    std::string getStation();
    std::string getTime(unitStatus _idx);

private:
    std::string name;
    std::string agency;
    std::string station;
    std::string time[MAX_NUM_UNIT_STATUSES]; // 4 is the number of statuses. See unitStatus enum.
};
