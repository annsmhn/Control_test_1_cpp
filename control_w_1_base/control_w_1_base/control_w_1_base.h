#pragma once
#include <iostream>
using namespace std;

class Person {
private:
    string name;
    string address;

public:
    void setInfo(const string& newName, const string& newAddress) {
        name = newName;
        address = newAddress;
    }
    // Функция для вывода имени и адреса на экран
    void displayInfo() {
        //проверка на наличие переданных значений
        if (name.empty() || address.empty()) {
            cout << "Имя или адрес не заданы!" << endl;}
        else {
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;}
    }
};
