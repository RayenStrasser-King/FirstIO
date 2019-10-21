#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <ostream>
#include "hash.h"
/*
 * @brief Hash fucntion constructor
 */

Hash::Hash()
{   
    collisions = 0;
    longestList = 0;
    runningAvgListLength = 0;
    CALL = 0;
}

/*
 * @brief removes specifc user inputed word from hash function
 * @param specifc user inputed word = 'word'
 */

void Hash::remove (string word)
{
    int i = hf(word);
    double empty = 0.0;
    for (std::list<string>::iterator iword = hashTable[i].begin();
            iword != hashTable[i].end(); iword++) //for loop iterator
    {
        if (*iword == word) //if it finds word within hashfunction
        {
            hashTable[i].remove(word);
            iword = hashTable[i].end();
            for (int j = 0; j < HASH_TABLE_SIZE; j++)
            {
                if (!hashTable[j].empty()) //if hashtable is empty
                {
                    empty++; // increment empty
                }
            }
            CALL = chain() / empty; //calculate CALL
            runningAvgListLength = (CALL + runningAvgListLength) / 2.0;
        }
    }
}

/*
 * @brief prints everything to standard output
 */
void Hash::print ()
{
    int j = HASH_TABLE_SIZE;
    for (int i = 0; i < j; i++) //for loop to reach hash table size
    {
        std::cout << i << ":" << "\t"; //beginning of cout statement 
        for (std::list<string>::iterator count = hashTable[i].begin();
                count != hashTable[i].end(); count++) //for loop iterator
        {
            std::cout << *count << ", "; //cout count 
        }
        std::cout << "\n"; //end of cout loop
    }
}

/*
 * @breif processes the file as well as gives values for printstats function
 * @param filename, writes output to a file named 'filename'
 */

void Hash::processFile (string filename)
{
    std::ifstream myfile; //reading file myfile
    myfile.open(filename); //open filename
    string name;
    do{
        myfile >> name;
        int i = hf(name);
        double empty = 0.0;
        if (!hashTable[i].empty()) //if the hashtable isnt empty
        {
            collisions++; //add to collisions
            hashTable[i].push_back(name); //push into hash function
            longestList = largest(); //figure out what is largest
            for (int j = 0; j < HASH_TABLE_SIZE; j++)
            {
                if (!hashTable[j].empty()) //if isnt empty
                {
                    empty++; //increment empty
                }
            }
            CALL = chain() / empty; //calculate CALL
            runningAvgListLength = (CALL + runningAvgListLength) / 2.0;
                //calculating avg list length
            myfile.ignore(); //ignore end line
        }
        else //if it is empty
        {
            hashTable[i].push_back(name);  //push into hash table
            longestList = largest();
            for (int j = 0; j < HASH_TABLE_SIZE; j++)
            {
                if (!hashTable[j].empty()) //if it is empty
                {
                    empty++; //increment empty
                }
            }
            CALL = chain() / empty; //calculate CALL
            runningAvgListLength = (CALL + runningAvgListLength) / 2.0;
            myfile.ignore(); //ignore end line
        }
    }while(myfile.peek() != EOF);
}

/*
 * @brief searches through hash table to find a specific, user inputed word
 * @param word, string that user is looking for within hash table
 * @return true or false whether the word is found
 */
bool Hash::search (string word)
{
    int i = hf(word);
    for (std::list<string>::iterator iword = hashTable[i].begin();
            iword != hashTable[i].end(); iword++) //for loop iterator
    {
        if ( *iword == word) //if it finds word within hashfunction
        {
            return true;
        }
    }//once we've iterated threw whole hash function with without finding word
    return false;
}

/*
 * @brief outputs contents of hash table to a file using ofstream
 * @param filename, outputs to a file named 'filename'
 */
void Hash::output (string filename)
{
    std::ofstream myfile; //inintializing ofstream
    myfile.open(filename); //opens file 
    int j = HASH_TABLE_SIZE;
    for (int i = 0; i < j; i++)
    {
        myfile << i << ":" << "\t"; //start to every write
        for (std::list<string>::iterator count = hashTable[i].begin();
                count != hashTable[i].end(); count++) //for loop iterator
        {
            myfile << *count << ", "; //writes every string to file
        }
        myfile << "\n"; //end of write
        myfile.close(); //close file
    }
}

/*
 * @brief prints the statistics of the hash function
 */
void Hash::printStats ()
{
    std::cout << "Total Collisions = " << collisions << std::endl;
    //outputs total collisions
    std::cout << "Longest List Ever = " << longestList << std::endl;
    //outputs longest list 
    std::cout << "Average List Length Over Time = "
        << runningAvgListLength << std::endl;
    //outputs averlist list length over time
    std::cout << "Load Factor = " << chain() / HASH_TABLE_SIZE << std::endl;
    //outputs load factor
}

/*
 * @brief helper function used in calculating load factor
 * @return z, double that is used to continually add to hashtable size
 */
double Hash::chain ()
{
    double z = 0.0;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) //for loop counting hash size
    {
        z = z + hashTable[i].size(); // getting current size
    }
    return z; //returning 
}

/*
 * @breif helper function to determine what is the largest list
 * @return l, which is 'hashTable.size'
 */
unsigned int Hash::largest ()
{
    unsigned int l = 0;
    for (int j = 0; j < HASH_TABLE_SIZE; j++)
    {
        if (l < hashTable[j].size())
        {
            l = hashTable[j].size();
        }
    }
    return l;
}
