#include "maintenanceRecord.h"
#include "car.h"
#include "truck.h"
#include "motorcycle.h"
#include <iostream>
#include <fstream>

using namespace std;

int maintenanceRecord::maintenanceCount = 0;

maintenanceRecord::maintenanceRecord() {
    maintenanceCount++;
    maintenanceId = maintenanceCount;
    dateOfMaintenance = 0;
    const char* staffNameValue = "Неизвестный";
    staffName = new char [strlen(staffNameValue)+1];
    strcpy(staffName, staffNameValue);
    const char* staffSurnameValue = "Неизвестный";
    staffSurname = new char [strlen(staffSurnameValue)+1];
    strcpy(staffSurname, staffSurnameValue);
}
maintenanceRecord::~maintenanceRecord() {
    delete[] staffName;
    delete[] staffSurname;
}

int maintenanceRecord::getId() const {
    return maintenanceId;
}
int maintenanceRecord::getDateOfMaintenance() const {
    return dateOfMaintenance;
}
char* maintenanceRecord::getStaffName() const {
    return staffName;
}
char* maintenanceRecord::getStaffSurname() const {
    return staffSurname;
}

int digitsCount(long int n);

void maintenanceRecord::setDateOfMaintenance(int value) {
    if (digitsCount(value) == 8) {
        dateOfMaintenance = value;
    }
    else{
        cout<<"Некорректный ввод даты технического обслуживания"<<endl;
        exit(EXIT_FAILURE);
    }
}

void maintenanceRecord::setStaffName(const char *staffNameValue) {
    delete[] staffName;
    staffName = new char [strlen(staffNameValue)+1];
    strcpy(staffName, staffNameValue);
}
void maintenanceRecord::setStaffSurname(const char *staffSurnameValue) {
    delete[] staffSurname;
    staffSurname = new char [strlen(staffSurnameValue)+1];
    strcpy(staffSurname, staffSurnameValue);
}

//новая запись о ТО
void maintenanceRecord::addRecording(maintenanceRecord &record){

    cout<<"СОЗДАНИЕ ЗАПИСИ О ТЕХОБСЛУЖИВАНИИ"<<endl;

    cout<<"Введите имя сотрудника: "<<endl;
    char staffNameValue[100];
    cin>>staffNameValue;
    record.setStaffName(staffNameValue);

    cout<<"Введите фамилию сотрудника: "<<endl;
    char staffSurnameValue[100];
    cin>>staffSurnameValue;
    record.setStaffSurname(staffSurnameValue);

    cout<<"Введите дату технического обслуживания в формате ДДММГГГГ: "<<endl;
    int dateValue;
    cin>>dateValue;
    record.setDateOfMaintenance(dateValue);

}

//перегрузка функций

//диагностика легкового автомобиля
bool maintenanceRecord::check(const car &carObj) {

    ofstream fout;
    fout.open("maintenance.txt", ios::app);

    if (((carObj.getRegistrationDateTime()[20]-'0')*1000 + (carObj.getRegistrationDateTime()[21]-'0')*100 +
         (carObj.getRegistrationDateTime()[22]-'0')*10 + (carObj.getRegistrationDateTime()[23]-'0')) < 2000){
        cout<<"Проведена диагностика легкового автомобиля №"<<carObj.getId()<<". Обноружены проблемы. Требуется ремонт."<<endl;

        if (fout.is_open()) {
            fout << "Проведена диагностика легкового автомобиля №" << carObj.getId()
                 << ". Обноружены проблемы. Требуется ремонт." << endl;
        }
        fout.close();
        return false;
    }
    cout<<"Проведена диагностика легкового автомобиля №"<<carObj.getId()<<". Проблем не обнаружено."<<endl;
    fout<<"Проведена диагностика легкового автомобиля №"<<carObj.getId()<<". Проблем не обнаружено."<<endl;
    fout.close();
    return true;
}

//диагностика грузовика
bool maintenanceRecord::check(const truck &truckObj) {

    ofstream fout;
    fout.open("maintenance.txt", ios::app);

    if (((truckObj.getRegistrationDateTime()[20]-'0')*1000 + (truckObj.getRegistrationDateTime()[21]-'0')*100 +
         (truckObj.getRegistrationDateTime()[22]-'0')*10 + (truckObj.getRegistrationDateTime()[23]-'0')) < 2010){
        cout<<"Проведена диагностика грузовика №"<<truckObj.getId()<<". Обноружены проблемы. Требуется ремонт."<<endl;
        if (fout.is_open()) {
            fout << "Проведена диагностика грузовика №" << truckObj.getId()
                 << ". Обноружены проблемы. Требуется ремонт." << endl;
        }
        fout.close();
        return false;
    }
    cout<<"Проведена диагностика грузовика №"<<truckObj.getId()<<". Проблем не обнаружено."<<endl;
    fout<<"Проведена диагностика грузовика №"<<truckObj.getId()<<". Проблем не обнаружено."<<endl;
    fout.close();
    return true;
}

//диагностика мотоцикла
bool maintenanceRecord::check(const motorcycle &motorcycleObj) {

    ofstream fout;
    fout.open("maintenance.txt");

    if (((motorcycleObj.getRegistrationDateTime()[20]-'0')*1000 + (motorcycleObj.getRegistrationDateTime()[21]-'0')*100 +
         (motorcycleObj.getRegistrationDateTime()[22]-'0')*10 + (motorcycleObj.getRegistrationDateTime()[23]-'0')) < 2015){
        cout<<"Проведена диагностика грузовика №"<<motorcycleObj.getId()<<". Обноружены проблемы. Требуется ремонт."<<endl;
        fout<<"Проведена диагностика грузовика №"<<motorcycleObj.getId()<<". Обноружены проблемы. Требуется ремонт."<<endl;
        fout.close();
        return false;
    }
    cout<<"Проведена диагностика грузовика №"<<motorcycleObj.getId()<<". Проблем не обнаружено."<<endl;
    fout<<"Проведена диагностика грузовика №"<<motorcycleObj.getId()<<". Проблем не обнаружено."<<endl;
    fout.close();
    return true;
}

//ремонт легкового автомобиля
void maintenanceRecord::fix(const car &carObj) {
    ofstream fout;
    fout.open("maintenance.txt");
    cout<<"Выполнен ремонт легкового автомобиля №"<<carObj.getId()<<endl;
    fout<<"Выполнен ремонт легкового автомобиля №"<<carObj.getId()<<endl;
    fout.close();
}
//ремонт грузовика
void maintenanceRecord::fix(const truck &truckObj) {
    ofstream fout;
    fout.open("maintenance.txt");
    cout<<"Выполнен ремонт грузовика №"<<truckObj.getId()<<endl;
    fout<<"Выполнен ремонт грузовика №"<<truckObj.getId()<<endl;
    fout.close();
}
//ремонт мотоцикла
void maintenanceRecord::fix(const motorcycle &motorcycleObj) {
    ofstream fout;
    fout.open("maintenance.txt");
    cout<<"Выполнен ремонт грузовика №"<<motorcycleObj.getId()<<endl;
    fout<<"Выполнен ремонт грузовика №"<<motorcycleObj.getId()<<endl;
    fout.close();
}