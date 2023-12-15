#include "car.h"
#include "vehicle.h"
#include "customer.h"
#include "maintenanceRecord.h"
#include <iostream>
#include <fstream>

using namespace std;

car::car() {
    numberOfSeats = 0;
}

int car::getNumberOfSeats() const {
    return numberOfSeats;
}

void car::setNumberOfSeats(int value) {
    numberOfSeats = value;
}

void car::printAll() const {
    cout<<"ID: "<<id<<endl;
    cout<<"Легковой автомобиль"<<endl;
    cout<<"Марка: "<<brand<<endl;
    cout<<"Модель: "<<model<<endl;
    cout<<"Регистрационный номер: "<<number<<endl;
    cout<<"Цвет: "<<color<<endl;
    cout<<wheelDrive<<" привод"<<endl;
    cout<<"Объем двигателя: "<<engineCapacity<<" см3"<<endl;
    cout<<"Мощность двигателя: "<<enginePower<<" л.с."<<endl;
    cout<<"Количество посадочных мест: "<<numberOfSeats<<endl;
    cout<<"Дата и время регистрации: "<<registrationDateTime<<endl;
}

car::~car() = default;

//аренда
void car::rent(customer &customerObj) const {
    if (customerObj.getAge() < 18){
        cout<<"Клиент младше 18 лет. Аренда невозможна"<<endl;
        exit(EXIT_FAILURE);
    }
    else {
        ofstream fout;
        fout.open("rent.txt", ios::app);

        numberOfRent++;

        cout<<"В файле для хранения информации об аренде rent.txt создана следующая запись: "<<endl;

        cout << "Запись об аренде ТС номер: " << numberOfRent << endl;
        if(fout.is_open()) {
            fout << "Запись об аренде ТС номер: " << numberOfRent << endl;
        }

        cout << "Автомобиль: " << endl;
        fout<<"Автомобиль: " << endl;

        cout << "№" << this->getId() << ' ' << this->getBrand() << ' ' << this->getModel() << ' ' << this->getNumber() << endl;
        fout << "№" << this->getId() << ' ' << this->getBrand() << ' ' << this->getModel() << ' ' << this->getNumber() << endl;

        cout << "Aрендатор: " << endl;
        fout << "Aрендатор: " << endl;

        cout << "Номер регистрации: " << customerObj.getId() << ' ' << customerObj.getName() << ' '
             << customerObj.getSurname() << endl;
        fout << "Номер регистрации: " << customerObj.getId() << ' ' << customerObj.getName() << ' '
             << customerObj.getSurname() << endl;

        cout << "Паспорт: " << customerObj.getPassport() / 1000000 << ' ' << customerObj.getPassport() % 1000000 << endl;
        fout << "Паспорт: " << customerObj.getPassport() / 1000000 << ' ' << customerObj.getPassport() % 1000000 << endl;

        cout << "Номер водительское удостоверение: " << customerObj.getDriverLicence() << endl;
        fout << "Номер водительское удостоверение: " << customerObj.getDriverLicence() << endl;

        cout << "Контактный телефон: " << customerObj.getPhone() << endl;
        fout << "Контактный телефон: " << customerObj.getPhone() << endl;

        fout.close();
    }
}

//ТО
void car::maintenance() const {

    maintenanceRecord recording;
    maintenanceRecord::addRecording(recording);

    ofstream fout;
    fout.open("maintenance.txt", ios::app);

    cout<<"В файле для хранения информации о техническом обслуживании maitenance.txt создана следующая запись: "<<endl;

    cout<<"Запись о техническом обслуживании легкового автомобиля (ID: "<<this->getId()<<") №"<<recording.getId()<<endl;

    if(fout.is_open()) {
        fout << "Запись о техническом обслуживании легкового автомобиля (ID: " << this->getId() << ") №"
             << recording.getId() << endl;
    }

    cout<<this->getBrand()<<' '<<this->getModel()<<' '<<this->getNumber()<<endl;
    fout<<this->getBrand()<<' '<<this->getModel()<<' '<<this->getNumber()<<endl;

    if (!maintenanceRecord::check(*this)){
        maintenanceRecord::fix(*this);
    }

    cout<<"Имя и фамилия сотрудника: "<<recording.getStaffName()<<' '<<recording.getStaffSurname()<<endl;
    fout<<"Имя и фамилия сотрудника: "<<recording.getStaffName()<<' '<<recording.getStaffSurname()<<endl;

    cout<<"Дата проведения технического обслуживания: "<<recording.getDateOfMaintenance() / 1000000<<'.'
        <<recording.getDateOfMaintenance() / 10000 % 100<<'.'<<recording.getDateOfMaintenance() % 10000<<endl;
    fout<<"Дата проведения технического обслуживания: "<<recording.getDateOfMaintenance() / 1000000<<'.'
        <<recording.getDateOfMaintenance() / 10000 % 100<<'.'<<recording.getDateOfMaintenance() % 10000<<endl;
    fout.close();
}

//регистрация
void car::registerVehicle() {

    cout<<"РЕГИСТРАЦИЯ ЛЕГКОВОГО АВТОМОБИЛЯ"<<endl;

    ofstream fout;
    fout.open("vehicles.txt", ios::app);

    if (fout.is_open()){
        fout<<"Транспортное средство №"<< this->getId()<<endl;
        fout<<"Легковой автомобиль"<<endl;
    }

    cout<<"Введите марку автомобиля: "<<endl;
    char brandValue[100];
    cin>>brandValue;
    this->setBrand(brandValue);
    fout<<"Марка: "<< this->getBrand()<<endl;

    cout<<"Введите модель автомобиля: "<<endl;
    char modelValue[100];
    cin>>modelValue;
    this->setModel(modelValue);
    fout<<"Модель: "<<this->getModel()<<endl;

    cout<<"Введите регистрационный номер автомобиля в формате X000XX: "<<endl;
    char numberValue[6];
    cin>>numberValue;
    this->setNumber(numberValue);
    fout<<"Регистрационный номер: "<< this->getNumber()<<endl;

    cout<<"Введите цвет автомобиля: "<<endl;
    char colorValue[100];
    cin>>colorValue;
    this->setColor(colorValue);
    fout<<"Цвет: "<< this->getColor()<<endl;

    cout<<"Введите тип привода автомобиля (передний, задний или полный): "<<endl;
    char wheelDriveValue[9];
    cin>>wheelDriveValue;
    this->setWheelDrive(wheelDriveValue);
    fout<<"Привод: "<< this->getWheelDrive()<<endl;

    cout<<"Введите объем двигателя автомобиля в см3: "<<endl;
    int engineCapacityValue;
    cin>>engineCapacityValue;
    this->setEngineCapacity(engineCapacityValue);
    fout<<"Объем двигателя: "<< this->getEngineCapacity()<<endl;

    cout<<"Введите мощность двигателя автомобиля в л.с.: "<<endl;
    int enginePowerValue;
    cin>>enginePowerValue;
    this->setEnginePower(enginePowerValue);
    fout<<"Moщность двигателя: "<< this->getEnginePower()<<endl;

    cout<<"Введите количество посадочных мест в автомобиле: "<<endl;
    int numberOfSeatsValue;
    cin>>numberOfSeatsValue;
    this->setNumberOfSeats(numberOfSeatsValue);
    fout<<"Количество посадочных мест в автомобиле: "<<this->getNumberOfSeats()<<endl;

    fout.close();

    cout<<"Легковой автомобиль зарегистрирован. Номер регистрации ТС: "<<this->getId()<<endl;
    cout<<endl;
}