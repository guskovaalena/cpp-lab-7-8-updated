#include "customer.h"
#include "vehicle.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int customer::customerCount = 0;

customer::customer(){
    customerCount++;
    customerId = customerCount;
    const char* nameValue = "Неизвестное";
    name = new char [strlen(nameValue)+1];
    strcpy(name, nameValue);
    const char* surnameValue = "Неизвестное";
    surname = new char [strlen(surnameValue)];
    strcpy(surname, surnameValue);
    passport = 0;
    driverLicence = 0;
    age = 0;
    rentCount = 0;
    rentHistory = new int [1];
    rentHistory[0] = 0;
    phone = 0;
}

customer::~customer(){
    delete[] name;
    delete[] surname;
    if (rentCount != 0){
        delete[] rentHistory;
    }
}

int customer::getId() const{
    return customerId;
}
char* customer::getName() const{
    return name;
}
char* customer::getSurname() const{
    return surname;
}
long int customer::getPassport() const{
    return passport;
}
long int customer::getDriverLicence() const {
    return driverLicence;
}
int customer::getAge() const{
    return age;
}
long int customer::getPhone() const {
    return phone;
}

void customer::printRentHistory() const{
    for (int i = 0; i < rentCount; ++i){
        cout<<rentHistory[i]<<' ';
    }
    cout<<endl;
}

int digitsCount(long int n) {
    if (n < 0) {
        n = -n;
    }
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

void customer::setName(const char *nameValue) {
    delete [] name;
    name = new char [strlen(nameValue)+1];
    strcpy(name, nameValue);
}
void customer::setSurname(const char *surnameValue) {
    delete [] surname;
    surname = new char [strlen(surnameValue)+1];
    strcpy(surname, surnameValue);
}
void customer::setPassport(long int passportValue) {
    if (digitsCount(passportValue) == 10) {
        passport = passportValue;
    }
    else{
        cout<<"Некорректный ввод паспортных данных клиента"<<endl;
        exit(EXIT_FAILURE);
    }
}
void customer::setDriverLicence(long int value) {
    if (digitsCount(value) == 10) {
        driverLicence = value;
    }
    else{
        cout<<"Некорректный ввод номера водительского удостоверения клиента"<<endl;
        exit(EXIT_FAILURE);
    }
}
void customer::setAge(int ageValue) {
    age = ageValue;
}
void customer::setPhone(long int phoneValue) {
    if (digitsCount(phoneValue) == 11){
        phone = phoneValue;
    }
    else{
        cout<<"Некорректный ввод номера телефона клиента"<<endl;
        exit(EXIT_FAILURE);
    }
}
void customer::setId(int idValue) {
    customerId = idValue;
}

void customer::printInfo() const {
    cout<<"Информация о клиенте №"<<this->getId()<<':'<<endl;
    cout<<"Имя и фамилия: "<<name<<' '<<surname<<endl;
    cout<<"Возраст: "<<age<<endl;
    cout<<"Серия и номер паспорта: "<<this->getPassport() / 1000000<<' '<<this->getPassport() % 1000000<<endl;
    cout<<"Номер водительского удостоверения: "<<driverLicence<<endl;
    cout<<"Контактный телефон: "<<phone<<endl;
}

//регистрация
void customer::registerCustomer() {

    cout<<"РЕГИСТРАЦИЯ КЛИЕНТА"<<endl;

    ofstream fout;
    fout.open("customers.txt", ios::app);

    if (fout.is_open()) {
        fout << "Клиент №" << this->getId() << endl;
    }

    cout<<"Введите имя клиента: "<<endl;
    char nameValue[100];
    cin>>nameValue;
    this->setName(nameValue);

    cout<<"Введите фамилию клиента: "<<endl;
    char surnameValue[100];
    cin>>surnameValue;
    this->setSurname(surnameValue);

    fout<<"Имя и фамилия: "<<this->getName()<<' '<<this->getSurname()<<endl;

    cout<<"Введите серию и номер паспорта клиента без пробелов: "<<endl;
    long int passportValue;
    cin>>passportValue;
    this->setPassport(passportValue);

    fout<<"Серия и номер паспорта: "<<this->getPassport() / 1000000<<' '<<this->getPassport() % 1000000<<endl;

    cout<<"Введите возраст клиента: "<<endl;
    int ageValue;
    cin>>ageValue;
    this->setAge(ageValue);

    fout<<"Возраст: "<<this->getAge()<<endl;

    cout<<"Введите номер водительского удостоверения клиента: "<<endl;
    long int driverLicenceValue;
    cin>>driverLicenceValue;
    this->setDriverLicence(driverLicenceValue);

    fout<<"Водительское удостоверение: "<< this->getDriverLicence() / 100000000<<' '
        <<this->getDriverLicence() / 1000000 % 100 << ' ' << this->getDriverLicence() % 1000000<<endl;

    cout<<"Введите контактный телефон клиента в формате 89XXXXXXXXX: "<<endl;
    long int phoneValue;
    cin>>phoneValue;
    this->setPhone(phoneValue);

    fout<<"Контактный телефон: "<< this->getPhone()<<endl;
    fout.close();

    cout<<"Клиент зарегистрирован. Номер регистрации клиента: "<<this->getId()<<endl;
    cout<<endl;
}

//перегрузка оператора + для обновления истории аренды
void operator + (customer& customerObj, vehicle& vehicleObj) {

    if (customerObj.rentCount == 0){
        delete[] customerObj.rentHistory;
        customerObj.rentCount++;
        customerObj.rentHistory = new int [customerObj.rentCount];
        customerObj.rentHistory[0] = vehicleObj.getId();
    }
    else {
        int* tmp;
        tmp = new int [customerObj.rentCount+1];
        for (int i = 0; i < customerObj.rentCount; i++){
            tmp[i] = customerObj.rentHistory[i];
        }
        tmp[customerObj.rentCount] = vehicleObj.getId();

        delete[] customerObj.rentHistory;
        customerObj.rentHistory = new int [customerObj.rentCount+1];
        for (int i = 0; i < customerObj.rentCount+1; i++){
            customerObj.rentHistory[i] = tmp[i];
        }
        delete[] tmp;
        customerObj.rentCount++;
    }
}