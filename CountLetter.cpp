#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int CountLetter(string sentence, char let)

{
        char L1;
        int x = 0;
        locale loc;


        for (int i = 0; i < sentence.length(); i++)
        {
                L1 = tolower(sentence[i],loc);

                if (L1 == let)
                {
                        x = x =1;
                }
                }

        return 0;

        }

