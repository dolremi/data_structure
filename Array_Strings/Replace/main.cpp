#include <iostream>
#include <string>

/* Replace the whitespace of string with "%20", for instance
   input : "Mr John Smith"
   output: "Mr%20John%20Smith"
   the way to solve this problem is two-pass algorithm:
   1st pass: count how many spaces in the original string, then resize the length of the string accordingly
   2nd pass: start from the end backward replace the whitespace.
*/

using namespace std;

void replaceString(string &str){
  
  // count how many white spaces in the string
  int leng = str.length();
  int count = 0;
  for(int i = 0; i < str.length(); i++){
    if(str[i] == ' ')
      count++;
  }
  
  // resize the length of the string accordingly
  str.resize(leng + 2*count);
  int newleng = leng + 2*count;

  // go backward for the second pass
  for(int i = leng - 1; i >= 0 ; i--){  
    if( str[i] == ' '){
      str[ newleng - 1 ] = '0';
      str[ newleng - 2 ] = '2';
      str[ newleng - 3 ] = '%';
      newleng -= 3;
    }else {
      str[ newleng - 1] = str[i];
      newleng --;
    }
  }
}

int main(int argc, char * argv[]){
  int choose = 1;
  string input;
  
  while(choose != 2){
    cout << "please insert the string you want to replace" << endl;
    getline(cin, input);
    
    replaceString(input);
    cout << input << endl;   
       
    cout << " Continue? 1 Yes. 2 No." << endl;
    getline(cin, input);
    choose = input[0] - '0';
  }
}
    
