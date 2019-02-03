//Rayen Strasser-King
#include <iostream>
using namespace std;
int main()
{
        int var1;
        int var2;
        int math;

        cout << "Enter your first number" << endl;
        cin >> var1;

        cout << "Enter your second number" << endl;
        cin >> var2;

        cout << "Enter 1=add 2=subtract 3=multiply 4=divide" << endl;
        cin >> math;

        if (math == 1)
        {
                cout << "Adding " << var1 << " and " << var2  << endl;
                cout << "The answer is > " << var1 + var2 << endl;
        }

        if (math == 2)
        {
                cout << "Subtracting " << var1 << " and " << var2 << endl;
                cout << "The answer is > " << var1 - var2 << endl;
        }

        if (math == 3)
        {
                cout << "Multiplying " << var1 << " and " << var2 << endl;
                cout << "The answer is > " << var1 * var2 << endl;

        }

        if (math == 4)
        {
                cout << "Dividing " << var1 << " and " << var2 << endl;
                cout << "The answer is > " << var1 / var2 << endl;

        }

  return 0;
}
