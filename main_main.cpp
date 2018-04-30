#include <bits/stdc++.h>
#include "employeelv.h"
#include "person.h"
#include "Employee.h"
#include "userdetec.h"
#include "admindetec.h"

void starting_heading();
void regis_notresgis();
void all_optionmenu();
void main_operation();

struct choicenumber
{
    int chnum;
};

int adminuser_flag = 40;
char yesno, yesno2;
using namespace std;
int main()
{
    choicenumber cn1;
    int ch1,ch2;
    userdetec u1, ushow, umatch;
    admindetec a1, ashow, amatch;
    char g2;

    char edname[100];
    char pro_name[100];

    Employee employer[1000], employerleave[1000];
    Employee pmatchname;
    employeelv emlv[100], empresen[100];
    int ch, n = 0, nleave = 0, npresen = 0;
    int yesno;

    adminuser_flag = 40;
    all_optionmenu();
    while(cin>>ch)
    {
        switch(ch)
        {
        case 1:
        {
            do
            {
                employer[n].get_data();
                employer[n].efile_out();
                n++;
                cout<<"Do another (1. yes/ 2. no)?: ";
                cin>>yesno;
            }
            while(yesno == 1);
        }
        break;

        case 2:
        {
            ifstream ifile;
            ifile.open("employee.txt",ios::in|ios::binary);
            ifile.seekg(0,ios::end);
            int endp = ifile.tellg();
            //                cout<<endp<<endl;
            int h = endp/sizeof(Employee);
            //                cout<<sizeof(Employee)<<endl;
            if(endp > 0)
            {
                cout<<"\nThere are "<<h<<" employees in file\n\n";
                for(int j=0; j<h; j++)
                {
                    cout<<"Employee No.: "<<j+1<<endl;
                    employer[j].ein(j);
                    employer[j].display_data();
                    cout<<endl;
                }
            }
            else
            {
                cout<<"You have no employee"<<endl;
            }
        }
        break;

        case 3:
        {
            do
            {
                cout<<"Calculate total working days with our company: \n";
                emlv[nleave].get_leavedate(ch);
                emlv[nleave].leaveinfile_out();
                string ename;
                ename = emlv[nleave].em_back_name();
//                cout<<ename<<endl;

                ifstream emfile;
                emfile.open("employee.txt",ios::in|ios::binary);
                emfile.seekg(0,ios::end);
                int emendp = emfile.tellg();
                int emh = emendp/sizeof(Employee);
                string emname;
//                                                    cout<<"\nThere are "<<emh<<" employees in file\n\n";
                int calday = 0, calmonth = 0, calyear = 0, totday = 0, fl = 0;
                for(int j=0; j<emh; j++)
                {
                    employer[j].ein(j);
                    emname = employer[j].back_name(); //To private person class data.
                    if(ename == employer[j].name)
                    {
                        if(employer[j].jday > emlv[nleave].lday)
                        {
                            emlv[nleave].lmonth -= 1;
                            emlv[nleave].lday += 30;
                            calday = emlv[nleave].lday - employer[j].jday;
                            totday += calday;
                            cout<<emlv[nleave].lday - employer[j].jday<<" days"<<endl;
                        }
                        else
                        {
                            calday = emlv[nleave].lday - employer[j].jday;
                            totday += calday;
//                                                                cout<<emlv.lday - employer[j].jday<<" days"<<endl;
                        }

                        if(employer[j].jmonth > emlv[nleave].lmonth)
                        {
                            emlv[nleave].lyear -= 1;
                            emlv[nleave].lmonth += 12;
                            calmonth = emlv[nleave].lmonth - employer[j].jmonth;
                            totday += calmonth * 30;
//                          cout<<emlv.lmonth - employer[j].jmonth<<" months"<<endl;
                        }
                        else
                        {
                            calmonth = emlv[nleave].lmonth - employer[j].jmonth;
                            totday += calmonth * 30;
                        }
                        if(employer[j].jyear < emlv[nleave].lyear | employer[j].jyear > emlv[nleave].lyear)
                        {
                            calyear = emlv[nleave].lyear - employer[j].jyear;
                            totday += calyear * 365;
                        }
                        if(totday > 0)
                        {
                            emlv[nleave].show_leavedate();
                            cout<<"Total working days: ";
                            cout<<calday<<" days "<<calmonth<<" months "<<calyear<<" years.\n"<<endl;
                        }
                        else
                        {
                            cout<<"\nInvalid date.\n"<<endl;
                        }
                        fl = 1;
                        break;
                    }
                    nleave++;
                }
                if(fl == 0)
                {
                    cout<<"Not found in file."<<endl;
                }
                cout<<"Do another (1. yes/ 2. no)?: ";
                cin>>yesno;
            }
            while(yesno == 1);
        }
        break;

        case 4:
        {
            ifstream ifile;
            ifile.open("employeeleave.txt",ios::in|ios::binary);
            ifile.seekg(0,ios::end);
            int endp = ifile.tellg();
            int h = endp/sizeof(employeelv);
            cout<<"\nThere are "<<h<<" employees leave from your company\n\n";
            for(int j=0; j<h; j++)
            {
                cout<<"Employee No.: "<<j+1<<endl;
                emlv[j].leavein(j);
                emlv[j].show_leavedate();
                cout<<endl;
            }
        }
        break;

        case 5:
        {
            do
            {
                empresen[npresen].get_leavedate(ch);
                empresen[npresen].leaveinfile_out();
                string ename;
                ename = empresen[npresen].em_back_name();
                ifstream emfile;
                emfile.open("employee.txt",ios::in|ios::binary);
                emfile.seekg(0,ios::end);
                int emendp = emfile.tellg();
                int emh = emendp/sizeof(Employee);
                string emname;
//                                                cout<<"\nThere are "<<emh<<" employees in file\n\n";
                int calday = 0, calmonth = 0, calyear = 0, totday = 0, fl = 0;
                for(int j=0; j<emh; j++)
                {
                    employer[j].ein(j);
                    emname = employer[j].back_name(); //To private person class data.
                    if(ename == employer[j].name)
                    {
                        if(employer[j].jday > empresen[j].lday)
                        {
                            empresen[j].lmonth -= 1;
                            empresen[j].lday += 30;
                            calday = empresen[j].lday - employer[j].jday;
                            totday += calday;
//                                                                cout<<emlv.lday - employer[j].jday<<" days"<<endl;
                        }
                        else
                        {
                            calday = empresen[j].lday - employer[j].jday;
                            totday += calday;
//                                                                cout<<emlv.lday - employer[j].jday<<" days"<<endl;
                        }

                        if(employer[j].jmonth > empresen[j].lmonth)
                        {
                            empresen[j].lyear -= 1;
                            empresen[j].lmonth += 12;
                            calmonth = empresen[j].lmonth - employer[j].jmonth;
                            totday += calmonth * 30;
//                                                                cout<<emlv.lmonth - employer[j].jmonth<<" months"<<endl;
                        }
                        else
                        {
                            calmonth = empresen[j].lmonth - employer[j].jmonth;
                            totday += calmonth * 30;
//                                                                cout<<emlv.lmonth - employer[j].jmonth<<" months"<<endl;
                        }
                        if(employer[j].jyear < empresen[j].lyear | employer[j].jyear > empresen[j].lyear)
                        {
                            calyear = empresen[j].lyear - employer[j].jyear;
                            totday += calyear * 365;
//                                                                cout<<emlv.lyear - employer[j].jyear<<" years"<<endl;
                        }
                        if(totday > 364)
                        {
                            int salres = totday / 365;
                            double totsal = employer[j].get_salary();
                            double totsalcal;
                            cout<<"Total Salary after "<<salres<<" years: ";
                            cout<<totsal + totsal*(employer[j].get_increment()*0.01) * salres<<endl;
                        }
                        else
                        {
                            cout<<"Invalid date."<<endl;
                        }
                        fl = 1;
                        break;
                    }
                    npresen++;
                }
                if(fl == 0)
                {
                    cout<<"Not found in file."<<endl;
                }
                cout<<"Do another (1. yes/ 2. no)?: ";
                cin>>yesno;
            }
            while(yesno == 1);

        }
        break;

        case 6:
        {
            if(adminuser_flag == 40)
            {
                employer[nleave].get_leavedate();
                employer[nleave].leavefile_out();
                //                    employer[nleave].show_leavedate();
                nleave++;
            }
            else
            {
                cout<<"\nPlease login in as employee mode."<<endl;
            }

        }
        break;

        case 7:
        {
            if(adminuser_flag == 40)
            {
                ifstream emfile;
                emfile.open("employeeleave.txt",ios::in|ios::binary);
                emfile.seekg(0,ios::end);
                int emendp = emfile.tellg();
                int emleave = emendp/sizeof(Person);
                cout<<"\nThere are "<<emleave<<" employees in file in leave now\n\n";
                for(int j=0; j< emleave; j++)
                {
                    cout<<"Employee No.: "<<j+1<<endl;
                    employerleave[j].leavein(j);
                    employerleave[j].show_leavedate();
                    cout<<endl;
                }
            }
            else
            {
                cout<<"\nPlease login in as admin mode."<<endl;
            }

        }
        break;

        case 8:
        {
            if(adminuser_flag == 40)
            {
                cout<<"Enter the name which you want to search: \n";
                scanf("%[^\n]",edname);
//                                                string ename;
//                                                ename = emlv.em_back_name();
                cout<<edname<<endl;
//                                                break;
                ifstream emfile;
                emfile.open("employee.txt",ios::in|ios::binary);
                emfile.seekg(0,ios::end);
                int emendp = emfile.tellg();
                int emh = emendp/sizeof(Employee);
                int fl;

                string editname;

                if(emendp > 0)
                {
                    cout<<"\nThere are "<<emh<<" employees in file\n\n";
                    for(int j=0; j<emh; j++)
                    {
                        cout<<"Employee No.: "<<j+1<<endl;
                        employer[j].ein(j);
                        employer[j].display_data();
                        cout<<endl;
//                                                        cout<<edname<<endl;
                        editname = employer[j].back_emname();
//                                                    emname = employer[j].back_name(); //To private person class data.
//                                                        cout<<editname<<endl;
                        if(edname == editname)
                        {
//                                                            cout<<"duksa222"<<endl;
                            cout<<"Now Enter new Data:\n";
                            employer[j].get_data();
                            employer[j].pfile_out();
                            break;
                        }
                        else
                        {
                            fl = 1;
                        }
                    }
                }
                else
                {
                    cout<<"You have no employee"<<endl;
                }

                if(fl == 0)
                {
                    cout<<"Not found in file."<<endl;
                }
                cout<<"Do another (1. yes/ 2. no)?: ";
                cin>>yesno;
            }
            else
            {
                cout<<"\nPlease login in as employee mode."<<endl;
            }

        }
        break;

        case 9:
        {
            ifstream ifile;
            ifile.open("employee.txt",ios::in|ios::binary);
            ofstream ofile;
            ofile.open("delestoreemploy.txt",ios::app | ios::binary);
            Employee prop;
            ifile.seekg(0,ios::end);
            int endp = ifile.tellg();
            int h = endp/sizeof(Employee);
            int flagd = 1, indexnum;
            char conf;
            string delname;

            if(endp == -1)
            {
                cout<<"No Employee in your Company!"<<endl;
                break;
            }
            else
            {
                cout<<"Delete Employee: "<<endl;
                cout<<"Enter Employee name: ";
                scanf("%[^\n]",pro_name);
//                                                cout<<"endp "<<endp<<endl;
//                                                if(endp = -1) break;
                for(int j=0; j<h; j++)
                {
//                                                    cout<<"duksa"<<endl;
                    employer[j].pin(j);
                    delname = employer[j].name;
                    if(pro_name == delname)
                    {
                        flagd = 0;
                        indexnum = j;
                        cout<<endl;
                        cout<<"Yes! Employee available."<<endl;
                        cout<<"Item is preparing for delete"<<endl;
                        employer[j].display_data();
                        break;
                    }
//                                                    if(j > 2) break;
                }
                for(int j = 0; j < h ; j++)
                {
                    employer[j].pin(j);
                    prop = employer[j];
                    if( j == indexnum)
                    {
                        cout<<"process complete"<<endl;
                    }
                    else
                    {
                        ofile.write((char*)&prop, sizeof(prop));
                    }
                }

                ifile.close();
                remove( "employee.txt" );
                ofile.close();
                char oldname[] ="delestoreemploy.txt";
                char newname[] ="employee.txt";
                rename( oldname, newname );
            }
            if(flagd)
            {
                cout<<"Employee not found "<<endl;
            }

        }
        break;


        case 10:
        {
            cout<<"Thanks to use our software."<<endl;
            exit(1);
        }
        break;
        }
        cout<<"Do you want to select another choice? (1. yes/ 2. no)\n";
//                                    scanf("%c",&yesno);
        cin>>yesno;
        if(yesno == 2) break;
        else if(yesno == 1)
        {
            all_optionmenu();
        }
    }

}

void starting_heading()
{
    cout<<"\t\t|-----------------------------------------------|\n";
    cout<<"\t\t|Welcome to HR Management system of Square Group|\n";
    cout<<"\t\t|-----------------------------------------------|\n";
    cout<<endl;
    cout<<"\t\t\t\tSelect an option:\n";
    cout<<"\t\t\t\t-----------------\n";
    cout<<"\t\t\t\t1. Admin\n";
    cout<<"\t\t\t\t2. Employee\n";
    cout<<"\t\t\t\tEnter choice number: ";
}


void regis_notresgis()
{
    cout<<"\t\t\t\t-----------------\n";
    cout<<"\t\t\t\t\tSelect an option:\n";
    cout<<"\t\t\t\t\t-----------------\n";
    cout<<"\t\t\t\t1. Yet not Registered\n";
    cout<<"\t\t\t\t2. Registered\n";
    cout<<"\t\t\t\tEnter choice number: ";
}


void all_optionmenu()
{
    cout<<"\t\t\tChoose from the following menu:\n\n"
        <<"\t\t\t1. Add new employee information\n"
        <<"\t\t\t2. Show all employees information\n"
        <<"\t\t\t3. Leave any employee.\n"
        <<"\t\t\t4. show leave employee's list\n"
        <<"\t\t\t5. Salary calculation.\n"
        <<"\t\t\t6. Apply for leave of absence day.\n"
        <<"\t\t\t7. Show all leave of absence day.(only for Admin mode)\n"
        <<"\t\t\t8. Update any info of employee.\n"
        <<"\t\t\t9. Delete any info of employee.\n"
        <<"\t\t\t10. Exit these software\n\n";
    cout<<"\t\t\tEnter your choice: ";

}



