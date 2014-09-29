#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class SetOfStacks{
public:
  SetOfStacks(int initial):threshold(initial){};
  void push(int value){
    int size = list_stacks.size();
    if(size == 0){
      list_stacks.push_back(stack<int>());
      list_stacks[0].push(value);
      ++size;
    }else if(list_stacks[size - 1].size() < threshold){
      list_stacks[size - 1].push(value);
    }else{
      list_stacks.push_back( stack<int>());
      list_stacks[size - 1].push(value);
      ++size;
    }
  };

  bool popAt(int index){
    int size = list_stacks.size();
    if(index > size-1 || index < 0){
      cout << "Error! The index should be between 0 and " << size - 1 << endl;
      return false;
    }else{
      list_stacks[index].pop();
      if(list_stacks[index].empty()){
	list_stacks.erase(index);
	--size;
      }
      return true;
    }
  };

  bool pop(){
    if(list_stacks.empty()){
      return false;
    }else {
      int size = list_stacks.size();
      list_stacks[size -1].pop();
      if(list_stacks[size - 1].empty()){
	list_stacks.pop_back();
      }
      return true;
    }
  };

private:
  vector<stack<int>>  list_stacks;
  int threshold;
};

int main(){
  
  SetOfStacks test(5);
  
  int option = 1, val, val1, val2, index, value;
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
    
    if(test.pop()){
      cout << "The stack has been poped." << endl;
    }else{
      cout << "The stack is empty." << endl;
    }
    break;
  case 3:
    cout << "Specify the index of stack to pop:" << endl;
    cin >> index;
    if(test.popAt(index)){
      cout << "The value in stack " << index << "has been poped." << endl;
    }else{
      cout << "Error! Please check your index." << endl;
    }
    break;
  }
  }
  return 0;
}



 
