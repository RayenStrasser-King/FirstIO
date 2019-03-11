#include <iostream>
#include <fstream>
using namespace std;
int main()
{
        string name;
        string fname;
        string string1;
        int bal = 0;


        cout<<"Enter your first name."<<endl;
        getline (cin, name);
        ifstream inx (name);
        int numvalue;

        if (inx.good())
        {
                getline (inx, string1);
                inx>>numvalue;
                cout<<"Welcome Back "<<string1 << endl;
                cout<<"Here is a log of all your BALANCE activity."<<endl;
                cout<<"Your balance is "<<numvalue<<endl;

        }
        
        else
        {
                ofstream outx(name);

                cout<<"Enter your FIRST and LAST name."<<endl;
                getline (cin, fname);
                outx<<fname<<endl;

                cout<<"Hello "<<fname<<endl;
                cout<<"Enter your initial balance."<<endl;
                cin>>bal;
                
                outx<<bal<<endl;
                outx.close();

        }
        inx.close();
        return 0;
}
