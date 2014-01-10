#include <iostream>

/* The problem is if an element in an M*N matrix is 0, set its entire row and column to zero
   The initial attempt is to set all the rows and columns zero if one element found zero, then
   all the matrix is zero now. Therefore we should at first record which element is zero in original 
   matrix and which row or column it belongs, then set them zero altogether. 
*/

using namespace std;

void setZero(int **input, int m, int n){

  // Two arrays to record the row and the column the zero element belongs to 
  int *rows = new int[m];
  int *cols = new int[n];

    
  for(int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      if(input[i][j] == 0){
	rows[i] = 1;
	cols[j] = 1;
      }
    }
  }

  // Set all the columns to zero
  for(int i = 0; i < m; i++){
    if(rows[i] == 1){
      for(int j = 0; j < n; j++){
	input[i][j] = 0;
      }
    }
  }

  // Set all the rows to zero
  for(int j = 0; j < n; j++){
    if(cols[j] == 1){
      for(int i = 0; i < m; i++){
	input[i][j] = 0;
      }
    }
  }
}

int main(int argc, char *argv[]){
  
  int **input;
  int m, n;
  cout << "please input the matrix size" << endl;
  cin >> m >> n;
  
  input = new int*[m];
  
  for(int i = 0; i < m; i++){
    input[i] = new int[n];
  }


  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> input[i][j];
    }
  }

  cout << "The original matrix is :" << endl;
  
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout << input[i][j] << " ";
    }
    cout << "\n";
  }

  cout << "\n";

  setZero(input, m, n);
  
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout << input[i][j] << " ";
    }
    cout << "\n";
  }

  cout << "\n";


  // Don't forget deallocate the memory

  for(int i = 0; i < m ;  i++)
    delete [] input[i];
  
  delete [] input;

  return 0;
}
