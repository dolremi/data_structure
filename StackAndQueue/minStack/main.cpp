// use two stacks to simulate the stack with min() as O(1) time
// to randomly access to the element of a stack extra stack is needed

#include <iostream>
#include <stack>

using namespace std;


class minStack
{
       
public:
  void push(int value){
    
    // should be <= to take care of equality
    if(value <= min()){
      minor.push(value);
    }
    major.push(value);
  }

  void pop(){
    if(major.top() == minor.top()){
      minor.pop();
    }

    if(!major.empty())
      major.pop();
    else
      cout << "The stack is empty" << endl;
  }

  int min(){
    if(minor.empty())
      return numeric_limits<int>::max();
    return minor.top();
  }

 
private:
  stack<int> major;
  stack<int> minor;

};

int main(){
  int choose = 0;
 
  minStack test;

  while(choose != 4){
    cout << "Which one you want to do? " << endl;
    cout << "1. Push a value in stack " << endl;
    cout << "2. Pop a value in stack " << endl;
    cout << "3. Return the minimum" << endl;
    cout << "4. Exit" << endl;
   
    cin >> choose;
    if(choose == 1){
      cout << "Input the value" << endl;
      int value;
      cin >> value;
      test.push(value);
     }
    else if(choose == 2){
      test.pop();
     }
    else{
      cout << "The min value is " << test.min() << endl;
    }
  }
}
