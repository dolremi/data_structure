#include <iostream>
#include <stack>
#include <list>
#include <vector>

using namespace std;

class SetOfStacks{
public:
  SetOfStacks(int initial):threshold(initial){};
  void push(int value){
    int size = list_stacks.size();
    if(size == 0){
      list_stacks.push_back(new stack<int>());
      list_stacks.begin()->push(value);
      ++size;
    }else if(list_stacks.end().size() < threshold){
      list_stacks.end()->push(value);
    }else{
      list_stacks.push_back(new stack<int>());
      list_stacks.end()->push(value);
      ++size;
    }
  };

  int popAt(int index){
    int size = list_stacks.size();
    if(index > size-1 || index < 0){
      cout << "Error! The index should be between 0 and " << size - 1 << endl;
      return -99999999;
    }else{
      int value = list_stacks[index].pop();
      if(list_stacks[index].empty()){
	list_stacks.erase(list_stacks.begin() + index);
	--size;
      }
      return value;
    }
  };

  int pop(){
    if(list_stacks.empty()){
      return -999999999;
    }else {
      int size = list_stacks.size();
      int value = list_stacks.end()->pop();
      if(list_stacks.end()->empty()){
	list_stacks.pop_back();
      }
      return value;
    }
  };

private:
  list<stack<int>>  list_stacks;
  int threshold;
};

int main(){
  
  SetOfStacks test(5);
  
  int option = 1, val, val1, val2;
  while(option != 4){
  cout << "Please select which option you want:" << endl;
  cout << "1. push a variable in the set of stack." << endl;
  cout << "2. pop a variable in the set of stack." << endl;
  cout << "3. pop a variable at the specific stack." << endl;
  cout << "4. Exit. " << endl;

  cin >> option;

  switch(option){
  case 1:
    cout << "Insert the value to push:" << endl;
    cin >> value;
    test.push(value);
    break;
  case 2:
     val1 = test.pop();
    if(val1 != -99999999){
      cout << val1 << " has been poped." << endl;
    }else{
      cout << "The stack is empty." << endl;
    }
    break;
  case 3:
    cout << "Specify the index of stack to pop:" << endl;
     val2 = test.popAt(index);
    if(val2 != -99999999){
      cout << val2 << "in stack " << index << "has been poped." << endl;
    }else{
      cout << "Error! Please check your index." << endl;
    }
    break;
  }
  return 0;
}



 
