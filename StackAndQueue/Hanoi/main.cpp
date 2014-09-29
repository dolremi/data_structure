#include <iostream>
#include <stack>

using namespace std;

class Towers{
public:
  Towers(int number):num_plates(number){initialize()};   
  void MoveTowers(int size , int origin, int destin, int buffer);
  void MoveTop(int origin, int destin);
private:
  stack<int> tower[3];
  int num_plates;
  void initialize(){
    for(int i = 0; i < num_plates; ++i){
      tower[0].push(num_plates - i- 1);
    }
  }
}

void Towers::MoveTowers(int size, int origin, int destin, int buffer){
  if(size > 0){
    MoveTowers(size - 1, origin, buffer, destin);
    MoveTop(origin, destin);
    MoveTowers(size - 1, buffer, destin, origin);
  }
}

void Towers::MoveTop(int origin, int destin){
  if(!tower[origin].empty()){
    int val = tower[origin].top();
    tower[origin].pop();
    tower[destin].push(val);
  }
}

int main(){
  Towers test;

  return 0;
}
