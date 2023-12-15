#ifndef CPP_LAB_7_8_UPDATED_CUSTOMER_H
#define CPP_LAB_7_8_UPDATED_CUSTOMER_H

#include "vehicle.h"

class customer {

private:

    int customerId;
    char* name;
    char* surname;
    long int passport;
    long int driverLicence;
    int age;
    int rentCount;
    int* rentHistory;
    long int phone;

public:

    int static customerCount;

    customer();
    ~customer();

    int getId() const;
    char* getName() const;
    char* getSurname() const;
    long int getDriverLicence() const;
    long int getPassport() const;
    int getAge() const;
    long int getPhone() const;

    void printRentHistory() const;
    void printInfo() const;

    void setName(const char* nameValue);
    void setSurname(const char* surnameValue);
    void setPassport(long int passportValue);
    void setDriverLicence(long int value);
    void setAge(int ageValue);
    void setPhone(long int phoneValue);
    void setId(int idValue);

    void registerCustomer();

    friend void operator + (customer& customerObj, vehicle& vehicleObj);

};


#endif //CPP_LAB_7_8_UPDATED_CUSTOMER_H
