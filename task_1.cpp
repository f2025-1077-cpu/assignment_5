#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


struct employeeData {
    string ID;
    string name;
    int salary;
};

vector<employeeData> Employees;

void saveHighSalary(){
    ofstream file;
    file.open("high_salary.txt");

    if(!file){
        cout << "High salary file not opening" << endl;
        return;
    }

    
        file << setw(15) << left << "ID" << setw(15) << left << "Name" << "Salary" << endl;

    for (int i = 0; i < Employees.size(); i++){
        int yearlySalary = Employees[i].salary*12;
        if (yearlySalary >= 600000){
            file << setw(15) << left << Employees[i].ID;
            file << setw(15) << left << Employees[i].name;
            file << Employees[i].salary;
        }
        file << endl;
    }
    file.close();
}

int main(){

    int numberOfEmployees;
    cout << "Enter number of employees: ";
    cin >> numberOfEmployees;


    for (int i = 0; i < numberOfEmployees; i++){
        employeeData empl;

        cout << "Enter employee " << i+1 << " ID: ";
        cin >> empl.ID;

        cout << "Enter employee " << i+1 << " name: ";
        cin >> empl.name;

        cout << "Enter employee " << i+1 << " salary: ";
        cin >> empl.salary;

        Employees.push_back(empl);
    }

    saveHighSalary();

    ifstream file("high_salary.txt");

    if (!file){
        cout << "File opening failed\n";
        return 0;
    }
    
    cout << "\n____ High Salary Employee Data ____\n";
    string empData;
    while (getline(file, empData)){

        cout << empData << endl;
    }


    return 0;
}