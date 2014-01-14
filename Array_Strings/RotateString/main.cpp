#include <iostream>
#include <string>

using namespace std;
// Given a method isSubstring (in this case find() for string class in C++), call this method once to determine 
//   one string is a rotation of another, e.g. "waterbottle" is a rotation of "erbootlewat". The idea is at first
//   check the length of two strings are same, then bombine two strings into one, to check one of string is substring
//   of the combined one. 
bool isRotate(string s1, string s2){
  if(s1.length() == s2.length() && s1.length() > 0){
    string s3 = s1 + s2;
    return (s3.find(s1) != string::npos);
  }
  return false;
}

int main(int argc, char* argv[]){
  string s1, s2;
  cout << "please insert two string: " << endl;
  getline(cin, s1);
  getline(cin, s2);
  if(isRotate(s1,s2))
    cout << "They are rotations!" << endl;
  else
    cout << "No, they are not rotations." << endl;  
  return 0;
}
