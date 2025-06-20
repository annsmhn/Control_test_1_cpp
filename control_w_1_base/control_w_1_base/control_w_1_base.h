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
    // ������� ��� ������ ����� � ������ �� �����
    void displayInfo() {
        //�������� �� ������� ���������� ��������
        if (name.empty() || address.empty()) {
            cout << "��� ��� ����� �� ������!" << endl;}
        else {
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;}
    }
};
