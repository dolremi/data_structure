#include <iostream>
#include "LinkedList.h"


// Remove the duplicates from an unsorted linked list 
// There are two versions for this implements of algorithms
//    1 with hash table to check duplications
//    2 without hash table to go through whole list 
// The first implementation is time efficient O(n) 
// The second one is O(n^2) running time but space efficient O(1)

using namespace std;

int main(int argc, char * argv[]){
  LinkedList test;
  int size;

  cout << "How many number you want to insert?" << endl;
  cin >> size;

  for(int i = 0 ; i < size; i++){
    int value ;
    cin >> value;
    test.append(value);
  }
  
  cout << " Now the linked list is " << endl;
  test.display();
  
  int choose;
  cout << " Which version you want to remove the duplicated item? " << endl;
  cout << " 1. hash table version" << endl;
  cout << " 2. non hash table version" << endl;
  
  cin >> choose;
  
  if(choose == 1){
    test.removedDuplicated1();
    test.display();
  }else{
    test.removedDuplicated2();
    test.display();
  }
  return 0;

}
  
  


