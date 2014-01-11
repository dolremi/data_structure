#include "LinkedList.h"
#include <iostream>

using namespace std;

// The problem is find the kth to last element of a singly linked list
// There are three versions of solutions to this problem:
//    1. If the linked list size is known, jsut iterate though the list to find the (size-k)th element in the list
//    2. A recursive version to find the kth of the last element
//    3. A iterative version utilized the "runne" technqiue
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
    if(chosen)
      cout << "Now the value of node is " << chosen->val << endl;
    else
      cout << "k is out of the range" << endl;
  }else{
    int m = 0;
    ListNode *chosen = myList.kthlastRecur(myList.currentHead(),m, k);     
    if(chosen)
      cout << "Now the value of node is " << chosen->val << endl;
    else
      cout << "k is out of the range" << endl;
  }
  return 0;
}
  
  

