/* TODO: write a program that reads two integers n,m and draws an n x m
 * hollow rectangle of '*' characters.  E.g., on input n=4,m=7, the result
 * would look like this: */

// * * * * * * *
// *           *
// *           *
// * * * * * * *

/* NOTE: place spaces between the characters to compensate for the fact that
 * most terminal fonts are taller than they are wide.
 * */
#include<iostream>
using namespace std;

int main() {

  int row, column;
  cout << "Please enter the amount of rows: \n";
  cin >> row;

  cout << "Please enter the amount of columns: \n";
  cin >> column;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
     //Print a full row for the first and last row
     if (i == 0 || i == row - 1) {
      cout << "* ";
     }
     //Print a hollow row for the rest
     else {
      if (j == 0 || j == column - 1) {
       cout << "* ";
      }
      else {
       cout << "  ";
      }
     }
    }
    cout << "\n";
  }

  return 0;
}