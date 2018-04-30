#ifndef USERDETEC_H
#define USERDETEC_H


class userdetec
{
    public:
        char name[100];
        char password[100];
    public:
        userdetec(){
            strcpy(name," ");
            strcpy(password," ");
        }
        userdetec(char s[],char p[])
        {
            strcpy(name,s);
            strcpy(password,p);
        }
        void getdata()
        {
            cout<<"Enter your name: ";
            cin>>name;
            cout<<"Enter your password: ";
            cin>>password;
        }
        void displaydata()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Password: "<<password<<endl;
        }
        void in(int pn)
        {
            ifstream ifile;
            ifile.open("userlogin.txt",ios::in|ios::out|ios::binary);
            ifile.seekg(pn*sizeof(userdetec));
            ifile.read((char*)this,sizeof(*this));
        }
        void out()
        {
            ofstream ofile;
            ofile.open("userlogin.txt",ios::app | ios::binary);
            ofile.write((char*)this, sizeof(*this));
        }
        bool operator ==(userdetec uu) const
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

        virtual void welcome()
        {
            cout<<"\nWelcome to our system as employee.\n"<<endl;
        }




    protected:


};



#endif // USERDETEC_H
