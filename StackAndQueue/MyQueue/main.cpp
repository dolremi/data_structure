#include <iostream>
#include <stack>

using namespace std;

class MyQueue{
public:
  MyQueue(){};
  void enqueue(int value);
  int dequeue();
private:
  stack<int> enqueue_stack;
  stack<int> dequeue_stack;
}

void MyQueue::enqueue(int value){
  enqueue_stack.push(value);
}

void MyQueue:dequeue(){
  if(dequeue_stack.empty()){
    while(!enqueue_stack.empty()){
      int val = enqueue_stack.top();
      enqueue_stack.pop();
      dequeue_stack.push(val);
    }
  } 
    if(!dequeue_stack.empty()){
      dequeue_stack.pop();
      return value;
    }
}

    
