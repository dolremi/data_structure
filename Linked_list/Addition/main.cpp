#include "LinkedList.h"
#include <iostream>

using namespace std;

int main(int argc, char *argvp[]){
  
  int size, value;
  int choose = 1;

  while(choose != 2){
    cout << "Please insert the size of the input list 1" << endl;
    cin >> size;

    LinkedList myleft;
    for(int i = 0; i < size; i++){
      cin >> value;
      myleft.append(value);
    }

    myleft.display();

    cout << "Please insert the size of the input list 2" << endl;
    cin >> size;

    LinkedList myright;
    for(int i = 0; i < size; i++){
      cin >> value;
      myright.append(value);
    }

    myright.display();

    cout << "Choose the version: 1. Reverse 2. Forward" << endl;
    cin >> choose;
    
    cout << "Now add them together... " << endl;

    LinkedList result;
    if(choose == 1){
      result.addRInPlace(myleft, myright);
    }else{
      result.addForward(myleft, myright);
    }
    result.display();
    cout << "Want to continue? 1. Yes. 2. No." << endl;

    cin >> choose;
  }

  return 0;
}
