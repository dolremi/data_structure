#include "Unique.h"
#include <map>
#include <iostream>
#include <string>


/* Instead of using array of 256 ASCII characters, a hash table is used,
  Moreover, assume it is a 256 ASCII characters, then the length of the string
  cannot be more than 256 */

using namespace std;

bool uniqueString(string input){ 

  // check the length of the input string with 256 ASCII characters
  if(input.length() > 256)
    return false;

  map<char, int> myMap;
 
  for(int i = 0; i <  input.length(); ++i){
   
    /* If the hash table doesn't find the character, hash the key to 1 otherwise
      return false indicating that it is not unique string */

    if(myMap.find(input[i]) == myMap.end()){
      myMap[input[i]] = 1;
    }
    else{    
      return false;
    }
  }
  return true;
}


/* If only the char from 'a' to 'z' is assumed, a bit vector can be used */
bool uniqueChar(string input){

  if(input.length() > 256)
    return false;

  int checker = 0;

  for(int i = 0; i < input.length(); ++i){

    int value = input[i] - 'a';

    // check if the bit is already set
    if((checker &(1 << value)) > 0){
      return false;
    }

    // set the bit to 1
    checker |= (1 << value);
  }

  return true;
}
