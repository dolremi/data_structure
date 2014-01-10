#include "LinkedList.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
  
  int  size, value, index;
  int choose = 1;
  
  while(choose != 2){
    cout << "Please indicate the size of the linked list" << endl;
    cin >> size;

    LinkedList mylist;
    for(int i = 0; i < size; i++){
      cin >> value;
      mylist.append(value);
    }

    mylist.display();

    cout << "Indicate if it is a loop? 1. yes. 2. no" << endl;
    cin >> choose;

    if(choose == 1){
      cout << "Please insert the index to do loop" << endl;
      cin >> index;

      mylist.makeLoop(index);
      
    }

    if(mylist.LoopHead() == NULL){
      cout << "There is no loop " << endl;
    }else{
      cout << "The loop head is " << mylist.LoopHead()->val << endl;
    }

    cout << "Want to continue? 1. Yes, 2. No. " << endl;

    cin >> choose;
  }
  return 0;
}
      
  
