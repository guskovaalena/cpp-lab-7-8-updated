#include "motorcycle.h"
#include <iostream>
#include <fstream>

using namespace std;

motorcycle::motorcycle() {
    weight = 0;
    load = 0;
}

int motorcycle::getWeight() const {
    return weight;
}
int motorcycle::getLoad() const {
    return load;
}

void motorcycle::setWeight(int weightValue) {
    weight = weightValue;
}
void motorcycle::setLoad(int loadValue) {
    load = loadValue;
}

void motorcycle::printAll() const {
    cout<<"ID: "<<id<<endl;
    cout<<"Мотоцикл"<<endl;
    cout<<"Марка: "<<brand<<endl;
    cout<<"Модель: "<<model<<endl;
    cout<<"Регистрационный номер: "<<number<<endl;
    cout<<"Цвет: "<<color<<endl;
    cout<<wheelDrive<<" привод"<<endl;
    cout<<"Объем двигателя: "<<engineCapacity<<" см3"<<endl;
    cout<<"Мощность двигателя: "<<enginePower<<" л.с."<<endl;
    cout<<"Вес: "<<weight<<endl;
    cout<<"Максимальная нагрузка: "<<load<<endl;
    cout<<"Дата и время регистрации: "<<registrationDateTime<<endl;
}

motorcycle::~motorcycle() = default;

//аренда
void motorcycle::rent(customer &customerObj) const {
    if (customerObj.getAge() < 16){
        cout<<"Клиент младше 16 лет. Аренда невозможна"<<endl;
        exit(EXIT_FAILURE);
    }
    else {
        ofstream fout;
        fout.open("rent.txt", ios::app);
        numberOfRent++;

        cout<<"В файле для хранения информации об аренде rent.txt создана следующая запись: "<<endl;

        cout << "Запись об аренде ТС номер: " << numberOfRent << endl;
        fout << "Запись об аренде ТС номер: " << numberOfRent << endl;

        cout << "Мотоцикл: " << endl;
        fout << "Мотоцикл: " << endl;

        cout << "№" << id << ' ' << brand << ' ' << model << ' ' << number << endl;
        fout << "№" << id << ' ' << brand << ' ' << model << ' ' << number << endl;

        cout << "Aрендатор: " << endl;
        fout << "Aрендатор: " << endl;

        cout << "Номер регистрации: " << customerObj.getId() << ' ' << customerObj.getName() << ' '
             << customerObj.getSurname() << endl;
        fout << "Номер регистрации: " << customerObj.getId() << ' ' << customerObj.getName() << ' '
             << customerObj.getSurname() << endl;

        cout << "Паспорт: " << customerObj.getPassport() / 1000000 << ' ' << customerObj.getPassport() % 1000000 << endl;
        fout << "Паспорт: " << customerObj.getPassport() / 1000000 << ' ' << customerObj.getPassport() % 1000000 << endl;

        cout << "Водительское удостоверение №" << customerObj.getDriverLicence() << endl;
        fout << "Водительское удостоверение №" << customerObj.getDriverLicence() << endl;

        cout << "Контактный телефон: " << customerObj.getPhone() << endl;
        fout << "Контактный телефон: " << customerObj.getPhone() << endl;
    }
}

//ТО
void motorcycle::maintenance() const {
    maintenanceRecord recording;
    maintenanceRecord::addRecording(recording);

    ofstream fout;
    fout.open("maintenance.txt", ios::app);

    cout<<"В файле для хранения информации о техническом обслуживании maitenance.txt создана следующая запись: "<<endl;

    cout<<"Запись о тезническом обслуживании мотоцикла (ID: "<<id<<") №"<<recording.getId()<<endl;
    fout<<"Запись о тезническом обслуживании мотоцикла (ID: "<<id<<") №"<<recording.getId()<<endl;

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
void motorcycle::registerVehicle() {

    fstream fout;
    fout.open("vehicles.txt", ios::app);
    if (fout.is_open()) {
        fout << "Транспортное средство №" << this->getId() << endl;
        fout << "Мотоцикл" << endl;
    }

    cout<<"Введите марку мотоцикла: "<<endl;
    char brandValue[100];
    cin>>brandValue;
    this->setBrand(brandValue);
    fout<<"Марка: "<< this->getBrand()<<endl;

    cout<<"Введите модель мотоцикла: "<<endl;
    char modelValue[100];
    cin>>modelValue;
    this->setModel(modelValue);
    fout<<"Модель: "<<this->getModel()<<endl;

    cout<<"Введите регистрационный номер мотоцикла в формате X000XX: "<<endl;
    char numberValue[6];
    cin>>numberValue;
    this->setNumber(numberValue);
    fout<<"Регистрационный номер: "<< this->getNumber()<<endl;

    cout<<"Введите цвет мотоцикла: "<<endl;
    char colorValue[100];
    cin>>colorValue;
    this->setColor(colorValue);
    fout<<"Цвет: "<< this->getColor()<<endl;

    cout<<"Введите тип привода мотоцикла (цепной или карданный): "<<endl;
    char wheelDriveValue[10];
    cin>>wheelDriveValue;
    this->setWheelDrive(wheelDriveValue);
    fout<<"Привод: "<< this->getWheelDrive()<<endl;

    cout<<"Введите объем двигателя мотоцикла в см3: "<<endl;
    int engineCapacityValue;
    cin>>engineCapacityValue;
    this->setEngineCapacity(engineCapacityValue);
    fout<<"Объем двигателя: "<< this->getEngineCapacity()<<endl;

    cout<<"Введите мощность двигателя мотоцикла в л.с.: "<<endl;
    int enginePowerValue;
    cin>>enginePowerValue;
    this->setEnginePower(enginePowerValue);
    fout<<"Moщность двигателя: "<< this->getEnginePower()<<endl;

    cout<<"Введите вес мотоцикла в кг: "<<endl;
    int weightValue;
    cin>>weightValue;
    this->setWeight(weightValue);
    fout<<"Вес мотоцикла: "<<this->getWeight()<<endl;

    cout<<"Введите максимальную нагрузку мотоцикла: "<<endl;
    int loadValue;
    cin>>loadValue;
    this->setLoad(loadValue);
    fout<<"Максимальная нагрузка: "<< this->getLoad()<<endl;

    cout<<"Мотоцикл зарегистрирован. Номер регистрации ТС: "<<this->getId()<<endl;
    cout<<endl;
}