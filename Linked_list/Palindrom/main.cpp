#include  "LinkedList.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
  
  int size, value;
  int choose = 1;
  while(choose != 2){
    
    LinkedList myList;
    
    cout << "The size of the linked list is? " << endl;
    cin >> size;
  
    for(int i = 0; i < size; i++){
      cin >> value;
      myList.append(value);
    }

    myList.display();

    cout << "Check if it is a palindrom... " << endl;

    if(myList.isPalin()){
      cout << "Yes! It is" << endl;
    }else{
      cout << "Sorry! It is not" << endl;
    }
  
    cout << "Want to continue? 1. Yes. 2. No" << endl;
    cin >> choose;
  }
  return 0;
}
