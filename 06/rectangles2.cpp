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
      //If in first and last row and colmn, print *
      if (i == 0 || i == row - 1 || j == 0 || j == column - 1) {
        cout << "* ";
      }
      else {
        cout << "  ";
      }
    }
    cout << "\n";
  }

  return 0;
}