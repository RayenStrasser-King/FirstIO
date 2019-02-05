#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
        int bodies;
        double wage1;
        int hours;
        string name;
        cout<<fixed<<setprecision(2);



        cout<<"Enter your name."<< endl;
        getline (cin, name);
        cout<<"Enter the number of hours worked."<<endl;
        cin>>hours;
        cout<<"Enter the number of people who work for your company."<<endl;
        cin>>bodies;

        if (bodies <= 50)
        {
                cout<<"Hours = "<<hours<<".00"<<" People = "<<bodies<<" Rate = 11.00"<<endl;
                cout<<"Your gross wage amount is $"<<hours * 11.00<<endl;
                cout<<"Good Bye "<<name<<endl;
                
        }

        if (bodies > 50)
        {
                cout<<"Hours = "<<hours<<".00"<<" People = "<<bodies<<" Rate = 11.50"<<endl;
                cout<<"Your gross wage amount is $"<<hours * 11.5<<endl;
                cout<<"Good Bye "<<name<<endl;
                
        }





        
}

