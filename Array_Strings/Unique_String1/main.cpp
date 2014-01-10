#include "Unique.h"
#include <iostream>
#include <string>
#include <sstream>


int main(int argc, char *argv[]){
  string input;
  int choose = 1;
  while(choose != 3){

    cout << "Please input the string to test" << endl;
    getline(cin, input);
   
    if(choose == 1){
     
      if(uniqueString(input))
	cout<< "It is a unique one!" << endl;
      else
	cout << "It has duplicated item!" << endl;
    }
    else{
      if(uniqueChar(input))
	cout <<"It is a unique one!" <<endl;
      else
	cout <<"It has duplicated item!" << endl;
    }
      
    cout << "want to continue? 1 uniqueString, 2 uniqueChar, 3 no" << endl;
    getline(cin, input);
    choose = input[0] - '0';
  }
  return 0;
}
