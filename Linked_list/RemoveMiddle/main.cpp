#include "LinkedList.h"
#include <iostream>

using namespace std;

int main(int argc, char*argv[]){
  
  LinkedList mylist;
  int size,value;
  cout << "Please tell me how many items in the list" <<endl;
  cin >> size;

  for(int i = 0; i < size; i++){
    cin >> value;
    mylist.append(value);
  }

  cout  << "Now the linked list is " << endl;
  mylist.display();

  cout << "The middle value is " << mylist.middle()-> val << endl;
  mylist.removeMiddle(mylist.middle());
  
  cout <<" Then the linked list is " << endl;
  mylist.display();

  return 0;
}
