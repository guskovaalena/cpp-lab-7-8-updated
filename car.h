#ifndef CPP_LAB_7_8_UPDATED_CAR_H
#define CPP_LAB_7_8_UPDATED_CAR_H

#include "vehicle.h"
#include "customer.h"
#include "maintenanceRecord.h"

class car : public vehicle {

private:
    int numberOfSeats;

public:
    car();
    ~car() override;
    int getNumberOfSeats() const;

    void setNumberOfSeats(int value);

    void printAll() const override;

    void rent(customer &customerObj) const override;

    void maintenance() const override;

    void registerVehicle() override;

};

#endif //CPP_LAB_7_8_UPDATED_CAR_H
