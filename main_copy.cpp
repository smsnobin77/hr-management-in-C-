#include <bits/stdc++.h>
#include "employeelv.h"
#include "person.h"
#include "Employee.h"

void all_optionmenu();

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
    char g2;

    char edname[100];
    char pro_name[100];

    Employee employer[1000], employerleave[1000];
    Employee pmatchname;
    employeelv emplv;
    int ch, n = 0, nleave = 0;
    int yn;
    all_optionmenu();
    cin>>cn1.chnum;
    ch1 = cn1.chnum;
    while(ch1){
        switch(ch1)
        {
            case 1:
                employer[n].get_data();
                employer[n].efile_out();
                n++;
                cout<<"Do another (1. yes / 2. no)?: ";
                cin>>yn;
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


        }
    }

}

void all_optionmenu(){
    cout<<"\t\t\tChoose from the following menu:\n\n"
        <<"\t\t\t1. Add new employee information\n"
        <<"\t\t\t2. Show all employees information\n"
        <<"\t\t\t3. Leave any employee.\n"
        <<"\t\t\t4. show leave employee's list\n"
        <<"\t\t\t5. Salary calculation.\n"
        <<"\t\t\t6. Apply for leave of absence day.\n"
        <<"\t\t\t7. Show all employers leave of absence day.\n"
        <<"\t\t\t8. Update any info of employee.\n"
        <<"\t\t\t9. Delete any info of employee.\n"
        <<"\t\t\t10. Exit these software\n\n";
    cout<<"\t\t\tEnter your choice: ";

}


