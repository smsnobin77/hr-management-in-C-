#include<bits/stdc++.h>

using namespace std;
class user
{
private:
    char name[100];
    char password[100];
public:
    user()
    {
        strcpy(name," ");
        strcpy(password," ");
    }
    user(char s[],char p[])
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
        ifile.open("t.txt",ios::in|ios::out|ios::binary);
        ifile.seekg(pn*sizeof(user));
        ifile.read((char*)this,sizeof(*this));
    }
    void out()
    {
        ofstream ofile;
        ofile.open("t.txt",ios::app | ios::binary);
        ofile.write((char*)this, sizeof(*this));
    }
    bool operator ==(user uu) const
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
};
int main()
{
    user u1,ushow, umatch;
    char g2;
    do
    {
        cout<<"Enter data for user\n";
        u1.getdata();
        u1.out();
        cout<<"Do another (y/n)?: ";
        cin>>g2;
    }
    while(g2=='y');

    ifstream ifile;
    ifile.open("t.txt",ios::in|ios::out|ios::binary);
    ifile.seekg(0,ios::end);
    int endp = ifile.tellg();
    int h = endp/sizeof(user);
    cout<<"\nThere are "<<h<<" Users in file\n";
    for(int j=0; j<h; j++)
    {
        cout<<"User accounts: "<<j+1<<endl;
        ushow.in(j);
        ushow.displaydata();
    }
    user u2;
    u2.getdata();
    bool flag = false;
    for(int j=0; j<h; j++)
    {
        umatch.in(j);
//        umatch.displaydata();
        if(umatch==u2){
            cout<<"Matched\n";
            flag = true;
            break;
        }
        else{
            flag = false;
        }
    }
    if(!flag) cout<<"Not matched\n";
    return 0;
}
