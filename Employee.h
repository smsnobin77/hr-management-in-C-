#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <bits/stdc++.h>
#include "person.h"
#include <ctime>

using namespace std;

class Employee: public Person
{
protected:
    int increment, salary, per_year_bonus;
public:
    void get_data()
    {
        Person::get_data();
        cout<<"Salary: ";
        cin>>salary;
        cout<<"Increment: ";
        cin>>increment;

    }

    int get_increment()
    {
        return increment;
    }

    int get_salary()
    {
        return salary;
    }

    void display_data()
    {
        Person::display_data();
        cout<<"Salary: ";
        cout<<salary<<endl;
        cout<<"Increment: ";
        cout<<increment<<endl;
    }

    void ein(int pn)
    {
        ifstream ifile;
        ifile.open("employee.txt",ios::in|ios::out|ios::binary);
        ifile.seekg(pn*sizeof(Employee));
        ifile.read((char*)this,sizeof(*this));
    }

    void efile_out()
    {
        ofstream ofile;
        ofile.open("employee.txt",ios::app | ios::binary);
        ofile.write((char*)this, sizeof(*this));
    }

    string back_emname()
    {
        return name;
    }



};

#endif // EMPLOYEE_H
