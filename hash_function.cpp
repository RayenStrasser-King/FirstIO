/* This assignment originated at UC Riverside.*/
  
#include <string>
#include "hash.h"

using std::string;

// This is only a sample hash function (and a bad one at that). You will
// need to replace the contents of this hash function with your own 
// hash function

/*
 * @hash  This hash function is good because it manipulates the numbers
 *        such that when the elements go threw it, they are spread out
 *        to minimize collision. I got inspiration mainly from stackoverflow.
 */
int
Hash::hf ( string ins ) {
  int total = 0;
  for (int i = 0; i < 5 ; i++)
  {
    total += (int) ins[i];
  }
  int random = total + 1;
  total = total + random;
  return total;


  //return ( ( (int) ins[0] )  )  % HASH_TABLE_SIZE;

}
