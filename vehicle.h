#ifndef CPP_LAB_7_8_UPDATED_VEHICLE_H
#define CPP_LAB_7_8_UPDATED_VEHICLE_H

class customer;
class maintenanceRecord;

class vehicle {

protected:
    int id;
    char* brand;
    char* model;
    char* number;
    char* color;
    char* wheelDrive;
    int engineCapacity;
    int enginePower;
    char* registrationDateTime;
    static int numberOfRent;

public:
    static int count;

    vehicle();
    virtual ~vehicle();

    int getId() const;
    char* getBrand() const;
    char* getModel() const;
    char* getNumber() const;
    char* getColor() const;
    char* getWheelDrive() const;
    int getEngineCapacity() const;
    int getEnginePower() const;
    char* getRegistrationDateTime() const;

    void setBrand(const char* brandValue);
    void setModel(const char* modelValue);
    void setNumber(const char* numberValue);
    void setColor(const char* colorValue);
    void setWheelDrive(const char* wheelDriveValue);
    void setEngineCapacity(int engineCapacityValue);
    void setEnginePower(int enginePowerValue);
    void setId(int idValue);

    virtual void registerVehicle() = 0;
    virtual void printAll() const = 0;
    virtual void rent(customer &customerObj) const = 0;
    virtual void maintenance() const = 0;
};

#endif //CPP_LAB_7_8_UPDATED_VEHICLE_H
