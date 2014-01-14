#include <iostream>

// The problem is to rotate a N*N matrix by 90 degree, for instance:
//       [ 1, 2, 3              [ 7, 4, 1       
//         4, 5, 6       == >     8, 5, 2      
//         7, 8, 9                9, 6, 3 ]
//   Of course you can create a new matrix, then rotate it one element
//   by one element. As always, we will ask the question: could we do 
//   better meaning a more space-efficient version, or could we do it 
//   in place? The answer is yes. For example, at the four corners of
//   matrix, we can rotate it this way, copy 1 to a temp variable, then 
//   7 -> 1; 9 -> 7; 3 -> 9; temp -> 3. 
//   temp = top[m];
//   top[m] = left[m];
//   left[m] = bottom[m];
//   bottom[m] = right[m];
//   right[m] = temp;
//   then we do all the rest of the matrix in this fashion.

//   Note that the rotation will do row by row, and goes from the first
//   row to the middle row, and each row will rotate the number of elements
//   2 fewer than the previous one. 
using namespace std;

// the parameters of 2D arrays in function definition, the second subscript is required
void  Rotate(int **input, int n){
  cout << "The original matrix is " << endl;
  for(int i = 0; i < n; i++){
    for(int j= 0; j < n; j++){
      cout << input[i][j] << " ";
    }
    cout << "\n";
  }

  for(int i = 0; i < n/2; i++){
    
    //Attention: j should stop at the second to last item!!
    for(int j = i; j < n - i - 1; j++){

      // Save the top left item
      int temp = input[i][j];

      // Bottom left item to top left 
      input[i][j] = input[n-1-j][i];

      // Bottom right item to bottom left
      input[n-1-j][i] = input[n-1-i][n-1-j];

      // Top right item to bottom right
      input[n-1-i][n-1-j] = input[j][n-1-i];

      // Top left item to top right
      input[j][n-1-i] = temp;
    }
  }

  cout << "now the new matrix is " << endl;
  for(int i = 0; i < n; i++){
    for(int j= 0; j < n; j++){
      cout << input[i][j] << " ";
    }
    cout << "\n";
  }
 
}

int main(int argc, char* argv[]){
  
  int **input;
  int n;
  cout << "Please insert the number of the elements n:" << endl;
  cin >> n;

  // Standard way to dynamically allocate 2D arrays or matrix
  input = new int*[n];
  for(int i = 0; i < n ; i++)
    input[i] = new int[n];

  cout << "Please inert the orignal matrix:" << endl;
  for(int i = 0; i < n; i++){
    for(int j = 0 ; j < n; j++){
      cin >>  input[i][j];
    } 
  }

  cout << "\n";
  cout << "Now the new matrix is:" << endl;
  Rotate(input, n);


  //Don't forget delete the allocated memory
  for(int i = 0; i < n; i++)
    delete [] input[i];

  delete [] input;
}
