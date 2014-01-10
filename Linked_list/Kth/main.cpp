#include "LinkedList.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
  LinkedList myList;
  int val,size, k, select;
  cout << "please insert the size of linked list" << endl;
  cin >> size;
  
  for(int i = 0;i < size ; i++){
    cin >> val;
    myList.append(val);
  }

  cout << "Now the list is " << endl;
  myList.display();
  
  cout << endl;
  cout << "which one you want to see?" << endl;
  cin >> k;

  cout << "which version? 1. iteration 2. recursive" << endl;
  cin >> select;

  if(select == 1){
    ListNode *chosen = myList.kthlastIter(k);
    cout << "Now the value of node is " << chosen->val << endl;
  }else{
    int m = 1;
    ListNode *chosen = myList.kthlastRecur(myList.currentHead(),m, k);     
    cout << "Now the value of node is " << chosen->val << endl;

  }

  return 0;
}
  
  

