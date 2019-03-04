#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string CountLetter(string sentence, char searching, int counter)

{
        //char searching = '\0';
        //string sentence ="";
        //int counter = 0;

        //cout<<"Enter a sentence."<<endl;
        //getline (cin, sentence);
        //cout<<"Enter a letter."<<endl;
        //cin>>searching;
        //transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

        for (int i = 0; i < sentence.length(); i++)
        {

                if (sentence [i] == searching)
                {
                        counter++;
                }
        }
        cout<<"The letter "<<searching<<" occurred "<<counter<<" time(s)."<<endl;

        return 0;

}
