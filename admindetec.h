#ifndef ADMINDETEC_H
#define ADMINDETEC_H
#include "userdetec.h"

class admindetec: public userdetec
{
    public:
        admindetec():userdetec()
        {

        }
        admindetec(char ss[],char pp[]):userdetec(ss,pp)
        {
        }
        void admin_getdata()
        {
            userdetec::getdata();
        }
        void admin_displaydata()
        {
            userdetec::displaydata();
        }
        void admin_in(int pn)
        {
            ifstream ifile;
            ifile.open("adminlogin.txt",ios::in|ios::out|ios::binary);
            ifile.seekg(pn*sizeof(admindetec));
            ifile.read((char*)this,sizeof(*this));
        }
        void admin_out()
        {
            ofstream ofile;
            ofile.open("adminlogin.txt",ios::app | ios::binary);
            ofile.write((char*)this, sizeof(*this));
        }
        bool operator ==(admindetec uu) const
        {
            if((strcmp(name,uu.name)==0) && (strcmp(password,uu.password)==0)){
        //            cout<<"kaisa"<<endl;
                return true;
            }
            else{
        //            cout<<"na"<<endl;
                return false;
            }
        }

        void welcome()
        {
            cout<<"\nWelcome to our system as admin.\n"<<endl;
        }


    protected:

    private:
};

#endif // ADMINDETEC_H
