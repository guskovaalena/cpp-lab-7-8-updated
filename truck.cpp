#include "truck.h"
#include <iostream>
#include <fstream>

using namespace std;

truck::truck() {
    loadCapacity = 0;
}

int truck::getLoadCapacity() const {
    return loadCapacity;
}

void truck::setLoadCapacity(int value) {
    loadCapacity = value;
}

void truck::printAll() const{
    cout<<"ID: "<<id<<endl;
    cout<<"Грузовик"<<endl;
    cout<<"Марка: "<<brand<<endl;
    cout<<"Модель: "<<model<<endl;
    cout<<"Регистрационный номер: "<<number<<endl;
    cout<<"Цвет: "<<color<<endl;
    cout<<wheelDrive<<" привод"<<endl;
    cout<<"Объем двигателя: "<<engineCapacity<<" см3"<<endl;
    cout<<"Мощность двигателя: "<<enginePower<<" л.с."<<endl;
    cout<<"Грузоподъемность: "<<loadCapacity<<endl;
    cout<<"Дата и время регистрации: "<<registrationDateTime<<endl;
}

truck::~truck() = default;

//аренда
void truck::rent(customer &customerObj) const {
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
        fout << "Запись об аренде ТС номер: " << numberOfRent << endl;

        cout << "Грузовик: " << endl;
        fout << "Грузовик: " << endl;

        cout << "№" << id << ' ' << brand << ' ' << model << ' ' << number << endl;
        fout << "№" << id << ' ' << brand << ' ' << model << ' ' << number << endl;

        cout << "Aрендатор: " << endl;
        fout << "Aрендатор: " << endl;

        cout << "Номер регистрации: " << customerObj.getId() << ' ' << customerObj.getName() << ' '
             << customerObj.getSurname() << endl;
        fout << "Номер регистрации: " << customerObj.getId() << ' ' << customerObj.getName() << ' '
             << customerObj.getSurname() << endl;

        cout << "Паспорт: " << customerObj.getPassport() / 1000000 << ' ' << customerObj.getPassport() % 1000000<< endl;
        fout << "Паспорт: " << customerObj.getPassport() / 1000000 << ' ' << customerObj.getPassport() % 1000000<< endl;

        cout << "Водительское удостоверение №" << customerObj.getDriverLicence() << endl;
        fout << "Водительское удостоверение №" << customerObj.getDriverLicence() << endl;

        cout << "Контактный телефон: " << customerObj.getPhone() << endl;
        fout << "Контактный телефон: " << customerObj.getPhone() << endl;

        fout.close();
    }
}

//ТО
void truck::maintenance() const {
    maintenanceRecord recording;
    maintenanceRecord::addRecording(recording);

    ofstream fout;
    fout.open("maintenance.txt", ios::app);

    cout<<"В файле для хранения информации о техническом обслуживании maitenance.txt создана следующая запись: "<<endl;

    cout<<"Запись о тезническом обслуживании грузовика (ID: "<<id<<") №"<<recording.getId()<<endl;
    fout<<"Запись о тезническом обслуживании грузовика (ID: "<<id<<") №"<<recording.getId()<<endl;

    cout<<brand<<' '<<model<<' '<<number<<endl;
    fout<<brand<<' '<<model<<' '<<number<<endl;

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
void truck::registerVehicle() {

    cout<<"РЕГИСТРАЦИЯ ГРУЗОВИКА"<<endl;

    ofstream fout;
    fout.open("vehicles.txt", ios::app);

    if (fout.is_open()){
        fout<<"Транспортное средство №"<< this->getId()<<endl;
        fout<<"Грузовик"<<endl;
    }

    cout<<"Введите марку грузовика: "<<endl;
    char brandValue[100];
    cin>>brandValue;
    this->setBrand(brandValue);
    fout<<"Марка: "<< this->getBrand()<<endl;

    cout<<"Введите модель грузовика: "<<endl;
    char modelValue[100];
    cin>>modelValue;
    this->setModel(modelValue);
    fout<<"Модель: "<<this->getModel()<<endl;

    cout<<"Введите регистрационный номер грузовика в формате X000XX: "<<endl;
    char numberValue[6];
    cin>>numberValue;
    this->setNumber(numberValue);
    fout<<"Регистрационный номер: "<<this->getNumber()<<endl;

    cout<<"Введите цвет грузовика: "<<endl;
    char colorValue[100];
    cin>>colorValue;
    this->setColor(colorValue);
    fout<<"Цвет: "<< this->getColor()<<endl;

    cout<<"Введите тип привода грузовика (передний, задний или полный): "<<endl;
    char wheelDriveValue[9];
    cin>>wheelDriveValue;
    this->setWheelDrive(wheelDriveValue);
    fout<<"Привод: "<< this->getWheelDrive()<<endl;

    cout<<"Введите объем двигателя грузовика в см3: "<<endl;
    int engineCapacityValue;
    cin>>engineCapacityValue;
    this->setEngineCapacity(engineCapacityValue);
    fout<<"Объем двигателя: "<< this->getEngineCapacity()<<endl;

    cout<<"Введите мощность двигателя грузовика в л.с.: "<<endl;
    int enginePowerValue;
    cin>>enginePowerValue;
    this->setEnginePower(enginePowerValue);
    fout<<"Moщность двигателя: "<< this->getEnginePower()<<endl;

    cout<<"Введите грузоподъемность грузовика в килограммах: "<<endl;
    int loadCapacityValue;
    cin>>loadCapacityValue;
    this->setLoadCapacity(loadCapacityValue);
    fout<<"Грузоподъемность: "<<this->getLoadCapacity()<<endl;

    cout<<"Грузовик зарегистрирован. Номер регистрации ТС: "<<this->getId()<<endl;
    cout<<endl;
}