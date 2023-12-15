#ifndef CPP_LAB_7_8_UPDATED_MOTORCYCLE_H
#define CPP_LAB_7_8_UPDATED_MOTORCYCLE_H

#include "vehicle.h"
#include "customer.h"
#include "maintenanceRecord.h"

class motorcycle : public vehicle {

private:
    int weight;
    int load;
public:

    motorcycle();
    ~motorcycle() override;

    int getWeight() const;
    int getLoad() const;

    void setWeight(int weightValue);
    void setLoad(int loadValue);

    void printAll() const override;

    void rent(customer &customerObj) const override;

    void maintenance() const override;

    void registerVehicle() override;

};


#endif //CPP_LAB_7_8_UPDATED_MOTORCYCLE_H
