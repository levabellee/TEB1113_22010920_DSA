/* Name: Lez Evabelle Kennedy
Student ID: 22010920
Lab No.: 1*/

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int id;
    string email;
    string phone;
};

int main() {
    Student student[5];

    for (int i=0; i<5; i++) {
        cout << "Enter ID for Student #" << i+1 << ": ";
        cin >> student[i].id;
        cout << "Enter Name for Student #" << i+1<< ": ";
        cin >> student[i].name;
        cout << "Enter Email for Student #" << i+1<< ": ";
        cin >> student[i].email;
        cout << "Enter Phone for Student #" << i+1 << ": ";
        cin >> student[i].phone;
        cout <<"============================" << endl;
    }

    for (int i=0; i<5; i++) {
        cout <<"\n========Student Info========"<<endl;
        cout << "ID: "<< student[i].id << endl;
        cout << "Name: "<< student[i].name << endl;
        cout << "Contact Num.: "<< student[i].name << endl;
        cout << "Email: "<< student[i].name << endl;
        cout << "============================" << endl;
    }
    return 0;
}
