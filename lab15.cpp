#include <iostream>
using namespace std;
int main()
{
        char a, s, m, d, x;
        int first, second;
        char answer;




        cout<<"What action do you want to perform? (a=add, s=subtract, m=multiply, d=divide, x=mod)"<<endl;
        cin>>answer;
        cout<<"Enter first number"<<endl;
        cin>>first;
        cout<<"Enter second number"<<endl;
        cin>>second;

        if(answer == 'a')
        {
                cout<<"The result is "<<first + second<<endl;

        }

        if(answer == 's')
        {
                cout<<"The result is "<<first - second<<endl;

        }

        if(answer == 'm')
        {
                cout<<"The result is "<<first * second<<endl;

        }

        if(answer == 'd')
        {
                cout<<"The result is "<<first / second<<endl;

        }

        if(answer == 'x')
        {
                cout<<"The result is "<<first% second<<endl;

        }

        if(answer != 'a' && answer != 's' && answer != 'm' && answer != 'd' && answer != 'x')
        {
                cout<<"Wrong choice. I am returning zero"<<endl;
                cout<<"The result is 0"<<endl;
        }

}
