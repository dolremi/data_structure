#include "LinkedList.h"

using namespace std;

int main(){

  int options = 1;
  
  LinkedList test; 
  while(options != 6)
    {

      cout << "Which options do you want?" << endl;
      cout << "1. Append a linked list." << endl;
      cout << "2. Insert a linked list." << endl;
      cout << "3. Delete a linked list." << endl;
      cout << "4. Is a linked list empty." << endl;
      cout << "5. Copy a linked list." << endl;
      cout << "6. exit." << endl;
      cin >> options;
      
      switch(options){
      case 1:
	cout << "please insert the value:" << endl;
	int val1;
	cin >> val1;
	test.append(val1);
	test.display();
	break;
      case 2:
	cout << "please insert the position and values:" << endl;
	int val2, pos2;
	cin >> pos2 >> val2;
	test.insert(pos2, val2);
	test.display();
	break;
      case 3:
	cout <<  "please the value you want to delete:" << endl;
	int val3;
	cin >> val3;
	if(test.deleteNode(val3) != -9999999)
	  cout << val3 << " is deleted" << endl;
	test.display();
	break;
      case 4:
	cout << "is list empty?" << endl;
	cout << test.isEmpty();
	break;
      case 5:
	cout << "Copy a new linked list" << endl;
	LinkedList test1;			
	test1 = test;
	test1.display();
	break;
      }
    }
      return 0;
}
