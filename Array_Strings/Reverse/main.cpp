#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Use two indexes one goes with the first char, the other goes with the last one remember check if the string is empty !
void reverse(char *str){
  char *last = str;

  if(str){
    while(*last != '\0'){
      ++last;
    }
    last--;
    while(str < last){
      char temp = *last;
      *last-- = *str;
      *str++ = temp;
    }
  }
}


// Use additional data structure Stack to handle reverse 
void reverseStack(char *str){
  char *input = str;
  if(str){
    stack<char> mystack;
    //push into the stack
    while(*input != '\0'){
      mystack.push(*input++);
    }
    input = str;
    //pop out the stack
    while(!mystack.empty()){
      *input = mystack.top();
      mystack.pop();
      input++;
    }
  }
}
  
int main(int argc, char *argv[]){
  char str[256];
  int choose = 1;
  while(choose != 3){
    cout << "Please input the string" << endl;
    cin.getline(str,256);
 
    if(choose == 1)   
      reverse(str);
    else
      reverseStack(str);

    cout << str << endl;
    
    cout << "Please tell me if you want to continue? 1 Two indexes 2 Stack 3 No. " << endl;
    cin.getline(str,256);
    choose = str[0] - '0';
  }
}
    
    
