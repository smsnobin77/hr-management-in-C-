#ifndef EMPLOYEELV_H
#define EMPLOYEELV_H
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

class employeelv
{
    protected:
        char name[100], position[100];
    public:
        int  lyear, lmonth, lday, lb;
    public:
        //void getleavedate(int cn)
        void getleavedate()
        {
            getchar();
            cout<<"Name: ";
            scanf("%[^\n]",name);
            int cn = 3;
            if(cn == 3)
            {
                cout<<"Leave date: (please provide in day/month/year format) ";
            }
            else
            {
                cout<<"Today's Date: (please provide in day/month/year format) ";
            }
            time_t t = time(0);   // get time now
            struct tm * now = localtime( & t );
            lyear = (now->tm_year + 1900);
            lmonth = (now->tm_mon + 1);
            lday = now->tm_mday;
            cout<<lday<<"/"<<lmonth<<"/"<<lyear<<endl;
            getchar();
        }

        void show_leavedate()
        {
            cout<<endl;
            cout<<"Leaved employer Name: ";
            cout<<name<<endl;
            cout<<"Leaving Date (Show in day/month/year format): ";
            cout<<lday<<"/"<<lmonth<<"/"<<lyear<<endl;
        }

        void leavein(int pn) //file read
        {
            ifstream ifile;
            ifile.open("employeeleave.txt",ios::in|ios::out|ios::binary);
            ifile.seekg(pn*sizeof(employeelv));
            ifile.read((char*)this,sizeof(*this));
        }

        void leaveinfile_out()//file write
        {
            ofstream ofile;
            ofile.open("employeeleave.txt",ios::app | ios::binary);
            ofile.write((char*)this, sizeof(*this));
        }

        string em_back_name()
        {
            return name;
        }

    private:
};

#endif // EMPLOYEELV_H
