#ifndef PERSON_H
#define PERSON_H
#include <bits/stdc++.h>

using namespace std;
class Person
{
public:
    char name[100], address[100], phonenumber[100], position[100], entered_date[100];
    int salary, year, month, day, jyear, jmonth, jday;
    int lvsday, lvsmonth, lvsyear, lveday, lvemonth, lveyear;
public:
    Person()
    {
        strcpy(name," ");
        strcpy(address," ");
        strcpy(phonenumber," ");
        strcpy(position," ");
        strcpy(entered_date," ");
        salary = 0, year = 0, month = 0, day = 0, jyear = 0, jmonth = 0, jday = 0;
    }
    void get_data()
    {
        getchar();
        cout<<"Name: ";
        scanf("%[^\n]",name);
        cout<<"Phone Number: ";
        cin>>phonenumber;
        getchar();
        cout<<"Employer Position: ";
        scanf("%[^\n]",position);
        cout<<"Joining Date (Please provide in day/month/year format):";
        scanf("%d / %d / %d",&jday,&jmonth,&jyear);
    }


    void get_leavedate()
    {
        cout<<"Employee Name: ";
        scanf("%[^\n]",name);
        cout<<"Leave start Date (Please provide in day/month/year format):";
        scanf("%d / %d / %d",&lvsday,&lvsmonth,&lvsyear);
        cout<<"Leave end Date (Please provide in day/month/year format):";
        scanf("%d / %d / %d",&lveday,&lvemonth,&lveyear);
    }

    void show_leavedate()
    {
        cout<<"\nEmployee Name: ";
        cout<<name<<endl;
        cout<<"Leave start Date (Please provide in day/month/year format):\n";
        cout<<lvsday<<"/"<<lvsmonth<<"/"<<lvsyear<<endl;
        cout<<"Leave end Date (Please provide in day/month/year format):\n";
        cout<<lveday<<"/"<<lvemonth<<"/"<<lveyear<<endl;
    }



    void leavefile_out()
    {
        ofstream ofile;
        ofile.open("employeeleave.txt",ios::app | ios::binary);
        ofile.write((char*)this, sizeof(*this));
    }

    void leavein(int pn)
    {
        ifstream ifile;
        ifile.open("employeeleave.txt",ios::in|ios::out|ios::binary);
        ifile.seekg(pn*sizeof(Person));
        ifile.read((char*)this,sizeof(*this));
    }

    string back_name()
    {
        return name;
    }

    void display_data()
    {
        cout<<"Name: ";
        cout<<name<<endl;
        cout<<"Phone Number: ";
        cout<<phonenumber<<endl;
        cout<<"Employer Position: ";
        cout<<position<<endl;
        cout<<"Joining Date (Please provide in day/month/year format): ";
        cout<<jday<<"/"<<jmonth<<"/"<<jyear<<endl;
    }

    void pfile_out()
    {
        ofstream ofile;
        ofile.open("employee.txt",ios::app | ios::binary);
        ofile.write((char*)this, sizeof(*this));
    }

    void pin(int pn)
    {
        ifstream ifile;
        ifile.open("employee.txt",ios::in|ios::out|ios::binary);
        ifile.seekg(pn*sizeof(Person));
        ifile.read((char*)this,sizeof(*this));
    }
};

#endif // PERSON_H
