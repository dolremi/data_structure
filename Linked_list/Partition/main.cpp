#include "LinkedList.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
  int input, value, curSize;
  int choose = 1;

  while(choose != 2){
    LinkedList myList;
    cout << "Please indicate the size of the linked list" <<endl;
    cin >> curSize;

    for(int i = 0; i < curSize; i++){
      cin >> value;
      myList.append(value);
    }
    
    myList.display();
    cout << "Now please insert the number you want to partition with" << endl;
    cin >> input;
    myList.partition(input);
    myList.display();
    
    cout << "Want to continue? 1. Yes. 2. No" << endl;
    cin >> choose;
  }
  return 0;
}
