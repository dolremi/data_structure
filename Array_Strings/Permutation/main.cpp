#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// To check if one string is a permutation of another one
//   Several questions can be asked: Is it an ASCII string?
//   Does the whitespace matter? ... etc.
//   In general there are two ways to do the problem:
   
//   1. Sort all the characters then compare if they are the same, in C++, opearator== can be used to compare if two strings are equal

//      Running time is O(nlgn)

//   2. Use hash table (map in C++) to check if they have the same table. 
   
//      Running time is O(n) for each character in String the look up time is O(1) in average



bool isPermSorted(string A, string B){
  
  // if the length of two strings are not equal it is false
  if(A.length() != B.length())
    return false;

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  return A == B;
}

bool isPermHash(string A, string B){
  
  if(A.length() != B.length())
    return false;

  map<char, int> mymap;
  
  for(int i = 0; i < A.length(); i++){
    if(mymap.find(A[i]) == mymap.end()){
      // Not found a character
      mymap[A[i]] = 1;
    }
    else{
      mymap[A[i]]++;
    }
  }

  for(int i = 0; i < B.length(); i++){
    if(mymap.find(B[i]) == mymap.end()){
      return false;
    }
   
    // If there are a few characters left, then they are not permutations
    if(--mymap[B[i]] < 0)
      return false;
  }
  
  for(auto it = mymap.begin(); it!= mymap.end(); it++){
    if( it->second > 0)
      return false;
  }
  return true;
}

int main(int argc, char *argv[]){

  int choose = 1;
  string input1, input2;

  while(choose != 3){
    cout << "please input the string1 and string2:" << endl;
   
    getline(cin,input1);
    getline(cin,input2);
    
    if(choose == 1){
      if(isPermSorted(input1, input2))
	cout << "They are permutations!" << endl;
      else
	cout << "They are not permutations!" << endl;
    }
    else{
      if(isPermHash(input1, input2))
	cout << "They are permutations!" << endl;
      else
	cout << "They are not permuations!" << endl;
    }
    
    cout << "Do you want to continue? 1. Sort version of check 2. Hash table version of check 3. No" << endl;
    getline(cin, input1);
    choose = input1[0] - '0';
  }
}
