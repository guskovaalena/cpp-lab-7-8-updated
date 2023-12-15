#include "vehicle.h"
#include <iostream>
#include <ctime>

using namespace std;

int vehicle::count = 0;
int vehicle::numberOfRent = 0;

vehicle::vehicle() {
    count++;
    id = count;
    const char* brandValue = "неизвестный";
    brand = new char [strlen(brandValue)+1];
    strcpy(brand, brandValue);
    const char* modelValue = "неизвестная";
    model = new char [strlen(modelValue)+1];
    strcpy(model, modelValue);
    const char* numberValue = "X000XX";
    number = new char [strlen(numberValue)+1];
    strcpy(number, numberValue);
    const char* colorValue = "неизвестный";
    color = new char [strlen(colorValue)+1];
    strcpy(color, colorValue);
    const char* wheelDriveValue = "Неизвестный";
    wheelDrive = new char [strlen(wheelDriveValue)+1];
    strcpy(wheelDrive, wheelDriveValue);
    engineCapacity = 0;
    enginePower = 0;
    time_t now = time(nullptr);
    const char* registrationDateTimeValue = ctime(&now);
    registrationDateTime = new char [strlen(registrationDateTimeValue)+1];
    strcpy(registrationDateTime, registrationDateTimeValue);
}

vehicle::~vehicle(){
    delete[] brand;
    delete[] model;
    delete[] number;
    delete[] color;
    delete[] wheelDrive;
    delete[] registrationDateTime;
}

int vehicle::getId() const{
    return id;
}
char* vehicle::getBrand() const {
    return brand;
}
char* vehicle::getModel() const {
    return model;
}
char* vehicle::getNumber() const {
    return number;
}
char* vehicle::getColor() const {
    return color;
}
char* vehicle::getWheelDrive() const {
    return wheelDrive;
}
int vehicle::getEngineCapacity() const {
    return engineCapacity;
}
int vehicle::getEnginePower() const {
    return enginePower;
}
char* vehicle::getRegistrationDateTime() const {
    return registrationDateTime;
}

void vehicle::setBrand(const char *brandValue) {
    delete[] brand;
    brand = new char [strlen(brandValue)+1];
    strcpy(brand, brandValue);
}
void vehicle::setModel(const char *modelValue) {
    delete[] model;
    model = new char [strlen(modelValue)+1];
    strcpy(model, modelValue);
}
void vehicle::setNumber(const char *numberValue) {
    delete[] number;
    number = new char[strlen(numberValue)+1];
    strcpy(number, numberValue);
}
void vehicle::setColor(const char *colorValue) {
    delete[] color;
    color = new char [strlen(colorValue)+1];
    strcpy(color, colorValue);
}
void vehicle::setWheelDrive(const char *wheelDriveValue) {
    delete[] wheelDrive;
    wheelDrive = new char [strlen(wheelDriveValue)+1];
    strcpy(wheelDrive, wheelDriveValue);
}
void vehicle::setEngineCapacity(int engineCapacityValue) {
    engineCapacity = engineCapacityValue;
}
void vehicle::setEnginePower(int enginePowerValue) {
    enginePower = enginePowerValue;
}
void vehicle::setId(int idValue) {
    id = idValue;
}