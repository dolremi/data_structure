#include <iostream>
#include <stack>

using namespace std;

class Towers{
public:
  Towers(int number):num_plates(number){initialize()};   
  
private:
  stack<int> tower[3];
  int num_plates;
  void initialize(){
    for(int i = 0; i < num_plates; ++i){
      tower[0].push(num_plates - i- 1);
    }
  }
}
