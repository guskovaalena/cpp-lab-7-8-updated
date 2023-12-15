#ifndef CPP_LAB_7_8_UPDATED_TRUCK_H
#define CPP_LAB_7_8_UPDATED_TRUCK_H

#include "vehicle.h"
#include "customer.h"
#include "maintenanceRecord.h"

class truck : public vehicle {

private:
    int loadCapacity;

public:

    truck();
    ~truck() override;

    int getLoadCapacity() const;

    void setLoadCapacity(int value);

    void printAll() const override;

    void rent(customer &customerObj) const override;

    void maintenance() const override;

    void registerVehicle() override;

};


#endif //CPP_LAB_7_8_UPDATED_TRUCK_H
