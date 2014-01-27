// It is a simple implementation of the fixed size 3 stacks simulation
// The flexible version will be more complex

#include <iostream>
#include <vector>

using namespace std;

class threeStack
{
  friend ostream & operator<<(ostream &out, threeStack input){
    
    out << "The whole array is printing ..." << endl;
    for(auto element: input.wholeArray)
      out << element << " ";

    out << endl;
    return out;
  }

public:
  threeStack(int size): stackSize(size){
    vector<int> wholeStack(size*3);
    wholeArray = wholeStack;
    vector<int> topStack(3,-1);
    topArray = topStack;
  }
  
  bool push(int StackNumber, int inputValue){
    if(topArray[StackNumber] + 1 >= stackSize)
      {
	cout << "The stack " << StackNumber << " is full! push() failed." << endl;
	return false;
      }
    else{
      topArray[StackNumber]++;
      wholeArray[topOfStack(StackNumber)] = inputValue;
      return true;
    }
  }

  int pop(int StackNumber){
    if(topArray[StackNumber] == -1)
      {
	cout << "The stack " << StackNumber << " is empty!" << endl;
	return 0;
      }
    else{
      int temp =wholeArray[ topOfStack(StackNumber)];
      wholeArray[topOfStack(StackNumber)] = 0;
      topArray[StackNumber]--;
      return temp;
    }
  }

  // return the index of the top of stack number
  int topOfStack(int StackNumber){
    return stackSize * StackNumber + topArray[StackNumber];
  }

  int peek(int StackNumber){
    return wholeArray[topOfStack(StackNumber)];
  }


private:
       vector<int> wholeArray;
       vector<int> topArray;
       int stackSize;
};


int main(){
  int choose = 0;
  int size;
  cout << " Please insert the size of stack " << endl;
  cin >> size;
  threeStack test(size);
  while(choose != 4){
    cout << "Please insert what you want to do with the three stack array?" << endl;
    cout << " 1. Push a number in one of those stacks " << endl;
    cout << " 2. Pop a number from one of those stacks " << endl;
    cout << " 3. Show the top of one of those stacks " << endl;
    cout << " 4. Exit " << endl;
    
    cin >> choose;
    
    if(choose == 1){
      cout << " Please insert your stack number and input value " << endl;
      int stackNo, inputValue;
      cin >> stackNo >> inputValue;
      test.push(stackNo, inputValue);
      cout << test;
    }
    else if (choose == 2){
      cout << " Please insert your stack number " << endl;
      int stackNo;
      cin >> stackNo;
      test.pop(stackNo);
      cout << test;
    }
    else if (choose == 3){
      cout << " Please insert your stack number " << endl;
      int stackNo;
      cin >> stackNo;
      cout << "The top of the stack " << stackNo << " is " << test.peek(stackNo) << endl;
      cout << test;
    }
  }

}
