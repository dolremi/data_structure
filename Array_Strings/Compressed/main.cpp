#include <iostream>
#include <string>

//   There are several comments on this problem, the problem is to compress the string, for instance
//   aabcccccaaa -> a2b1c5a3 and if the "compressed" string is larger than the orignal one, then return
//   the orignal one. 
//   In Java, on each concatenation, a new copy of the string is created. Therefore, the running time is 
//   O(n^2) for n strings concatenation. However, in C++, the running time of the concatentation is linear 
//   time.Thus, the C++ implementation of this problem, the StringBuffer is not needed. 
//  The length of the string can be detected dynamically
using namespace std;

string compressed(string input){
  
  int count = 0;
  char current = input[0];
  string output;
  
  for(int i = 0; i < input.length(); i++){
    if(input[i] == current){
      count++;
    }else{
      output += current;
      output += count + '0';
      // initialize the number of new character to 1 not 0!
      count = 1;
      current = input[i];
    }
  }

  // Don't forget to add the last character !!
  output += current;
  output += count +'0';
  
  if(output.length() > input.length())
    return input;
  else
    return output;
}

int main(int argc, char* argv[]){
  string input;
  int choose = 1;
  
  while(choose != 2){
    cout << "Please input the string you want to compress:" << endl;
    getline(cin, input);
    input = compressed(input);
    cout << "Now the compressed string is " << input << endl;
    cout << "Want to continue? 1 Yes. 2 No." << endl;
    getline(cin, input);
    choose = input[0] - '0';
  }
}
    
  
