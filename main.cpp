#include <iostream>
#include <fstream>
#include "car.h"
#include "truck.h"
#include "motorcycle.h"
#include "customer.h"

using namespace std;

//команды
int menu(){
    int command;
    cout<<"Выберите команду: "<<endl;
    cout<<"1 - зарегистрировать легковой автомобиль"<<endl;
    cout<<"2 - зарегистрировать грузовик"<<endl;
    cout<<"3 - зарегистрировать мотоцикл"<<endl;
    cout<<"4 - зарегистрировать клиента"<<endl;
    cout<<"5 - сделать запись об аренде транспортного средства"<<endl;
    cout<<"6 - сделать запись о техническом обслуживании транспортного средства"<<endl;
    cout<<"7 - завершить работу"<<endl;
    cin>>command;
    if (command < 1 || command > 7){
        cout<<"Некорректный ввод команды"<<endl;
        exit(EXIT_FAILURE);
    }
    return command;
}

void GetMaintenance(int id);
void GetRent(int id, int id_customer);

//основная функция, проверяющая команды
void start(){
    int command = menu();
    if (command == 1){
        car carObj;
        carObj.registerVehicle();
        start();
    }
    if (command == 2){
        truck truckObj;
        truckObj.registerVehicle();
        start();
    }
    if (command == 3){
        motorcycle motorcycleObj;
        motorcycleObj.registerVehicle();
        start();
    }
    if (command == 4){
        customer customerObj;
        customerObj.registerCustomer();
        start();
    }
    if (command == 5){
        cout<<"Введите номер регистрации транспортного средства: "<<endl;
        int id;
        cin>>id;
        cout<<"Введите номер регистрации клиента: "<<endl;
        int id_customer;
        cin>>id_customer;

        GetRent(id, id_customer);
        start();
    }
    if (command == 6){
        cout<<"Введите номер регистрации транспортного средства: "<<endl;
        int id;
        cin>>id;

        GetMaintenance(id);
        start();
    }
    if (command == 7){
        exit(0);
    }
}

//ТО зарегистрированного транспортного средства с данным регистрационным номером
void GetMaintenance(int id){
    ifstream fin;
    fin.open("vehicles.txt");

    //найдем нужное ТС по id в файле с зарегистрированными ТС
    string line;
    if (fin.is_open()){
        while(getline(fin, line)){
            if (line.find("№") != std::string::npos) {
                char a = line[line.size() - 1];
                if (a-'0' == id){
                    break;
                }
            }
        }
    }
    string str;
    getline(fin, line);
    //проверим тип ТС, создадим прототип и выполним ТО
    if (line == "Легковой автомобиль"){
        car carObj;
        carObj.setId(id);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        carObj.setBrand(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        carObj.setModel(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        carObj.setNumber(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        carObj.setColor(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        carObj.setWheelDrive(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val = stoi(str);
        carObj.setEngineCapacity(val);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val1 = stoi(str);
        carObj.setEnginePower(val1);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val2 = stoi(str);
        carObj.setNumberOfSeats(val2);

        carObj.maintenance();
    }
    else if (line == "Грузовик"){
        truck truckObj;
        truckObj.setId(id);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        truckObj.setBrand(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        truckObj.setModel(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        truckObj.setNumber(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        truckObj.setColor(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        truckObj.setWheelDrive(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val = stoi(str);
        truckObj.setEngineCapacity(val);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val1 = stoi(str);
        truckObj.setEnginePower(val1);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val2 = stoi(str);
        truckObj.setLoadCapacity(val2);

        truckObj.maintenance();
    }
    else if (line == "Мотоцикл"){
        motorcycle motorcycleObj;
        motorcycleObj.setId(id);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        motorcycleObj.setBrand(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        motorcycleObj.setModel(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        motorcycleObj.setNumber(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        motorcycleObj.setColor(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        motorcycleObj.setWheelDrive(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val = stoi(str);
        motorcycleObj.setEngineCapacity(val);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val1 = stoi(str);
        motorcycleObj.setEnginePower(val1);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val2 = stoi(str);
        motorcycleObj.setWeight(val2);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val3 = stoi(str);
        motorcycleObj.setLoad(val3);

        motorcycleObj.maintenance();
    }
    fin.close();
}

//аренда
void GetRent(int id, int id_customer){

    //создадим прототип клиента с данным id
    customer customerObj;
    customerObj.setId(id_customer);

    ifstream fin;
    fin.open("customers.txt");
    string line1;
    if (fin.is_open()){
        while(getline(fin, line1)){
            if (line1.find("№") != std::string::npos) {
                char a = line1[line1.size() - 1];
                if (a-'0' == id_customer){
                    break;
                }
            }
        }
    }

    string str1;
    getline(fin, line1);
    str1 = line1.substr(line1.find(": ")+2);
    string name = str1.substr(0, str1.find(' '));
    customerObj.setName(name.c_str());
    string surname = str1.substr(str1.find(' ')+1);
    customerObj.setSurname(surname.c_str());

    getline(fin, line1);
    str1 = line1.substr(line1.find(": ")+2);
    int seria = stoi(str1.substr(0, str1.find(' ')));
    int number = stoi(str1.substr(str1.find(' ')+1));
    long int value = seria * 10000;
    long int passport = value*100 + number;
    customerObj.setPassport(passport);

    getline(fin, line1);
    str1 = line1.substr(line1.find(": ")+2);
    int age = stoi(str1);
    customerObj.setAge(age);

    getline(fin, line1);
    str1 = line1.substr(line1.find(": ")+2);
    int value1 = stoi(str1.substr(0, str1.find(' ')));
    int value2 = stoi(str1.substr(str1.find(' ')+1, str1.find(' ')));
    int value3 = stoi(str1.substr(str1.find(' ', 5)));
    int dl1 = value1*100+value2;
    long int dl2 = dl1*10000;
    customerObj.setDriverLicence(dl2*100+value3);

    getline(fin, line1);
    str1 = line1.substr(line1.find(": ")+2);
    long int p1 = stoi(str1.substr(0, 5));
    long int p2 = stoi(str1.substr(5));
    long int phone = p1*1000000+p2;
    customerObj.setPhone(phone);

    fin.close();

    //найдем нужное ТС в файле, создадим прототип и выполним операцию аренды
    fin.open("vehicles.txt");
    string line;
    if (fin.is_open()){
        while(getline(fin, line)){
            if (line.find("№") != std::string::npos) {
                char a = line[line.size() - 1];
                if (a-'0' == id){
                    break;
                }
            }
        }
    }
    string str;
    getline(fin, line);
    if (line == "Легковой автомобиль"){
        car carObj;
        carObj.setId(id);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        carObj.setBrand(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        carObj.setModel(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        carObj.setNumber(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        carObj.setColor(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        carObj.setWheelDrive(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val = stoi(str);
        carObj.setEngineCapacity(val);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val1 = stoi(str);
        carObj.setEnginePower(val1);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val2 = stoi(str);
        carObj.setNumberOfSeats(val2);

        carObj.rent(customerObj);
    }
    else if (line == "Грузовик"){
        truck truckObj;
        truckObj.setId(id);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        truckObj.setBrand(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        truckObj.setModel(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        truckObj.setNumber(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        truckObj.setColor(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        truckObj.setWheelDrive(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val = stoi(str);
        truckObj.setEngineCapacity(val);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val1 = stoi(str);
        truckObj.setEnginePower(val1);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val2 = stoi(str);
        truckObj.setLoadCapacity(val2);

        truckObj.rent(customerObj);
    }
    else if (line == "Мотоцикл"){
        motorcycle motorcycleObj;
        motorcycleObj.setId(id);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        motorcycleObj.setBrand(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        motorcycleObj.setModel(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        motorcycleObj.setNumber(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        motorcycleObj.setColor(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        motorcycleObj.setWheelDrive(str.c_str());

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val = stoi(str);
        motorcycleObj.setEngineCapacity(val);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val1 = stoi(str);
        motorcycleObj.setEnginePower(val1);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val2 = stoi(str);
        motorcycleObj.setWeight(val2);

        getline(fin, line);
        str = line.substr(line.find(": ")+2);
        int val3 = stoi(str);
        motorcycleObj.setLoad(val3);

        motorcycleObj.rent(customerObj);
    }

    fin.close();
}

int main() {

    setlocale(LC_ALL, "ru");

    start();

    return 0;
}

