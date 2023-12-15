#ifndef CPP_LAB_7_8_UPDATED_MAINTENANCERECORD_H
#define CPP_LAB_7_8_UPDATED_MAINTENANCERECORD_H

class vehicle;
class car;
class truck;
class motorcycle;


class maintenanceRecord {

private:
    int dateOfMaintenance;
    char* staffName;
    char* staffSurname;
    int maintenanceId;

public:
    int static maintenanceCount;

    maintenanceRecord();
    ~maintenanceRecord();

    int getId() const;
    int getDateOfMaintenance() const;
    char* getStaffName() const;
    char* getStaffSurname() const;

    void setDateOfMaintenance(int value);
    void setStaffName(const char* staffNameValue);
    void setStaffSurname(const char* staffSurnameValue);

    static void addRecording(maintenanceRecord &record);

    static bool check(const car &carObj);
    static bool check(const truck &truckObj);
    static bool check(const motorcycle &motorcycleObj);

    static void fix(const car &carObj);
    static void fix(const truck &truckObj);
    static void fix(const motorcycle &motorcycleObj);

};


#endif //CPP_LAB_7_8_UPDATED_MAINTENANCERECORD_H
