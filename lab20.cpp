#include <iostream>
#include <fstream>
using namespace std;
int main()
{
        string name;
        string fname;
        int bal;


        cout<<"Enter your first name."<<endl;
        getline (cin, name);
        ifstream inx (name);
        ofstream outx (name);

        if (inx.good())
        {
                cout<<"Welcome Back Jaime Raigoza"<< fname << endl;
                cout<<"Here is a log of all your BALANCE activity."<<endl;
                cout<<"Your balance is 1000"<<endl;

        }
        
        else
        {

                cout<<"Enter your FIRST and LAST name."<<endl;
                getline (cin, fname);
                outx<<fname<<endl;

                cout<<"Hello "<<fname<<endl;
                cout<<"Enter your initial balance."<<endl;
                cin>>bal;
                
                
                outx<<bal<<endl;
                

                outx.close();

        }
        return 0;
}
