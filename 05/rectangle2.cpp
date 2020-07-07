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
      cout << "* ";
    }
    cout << "\n";
  }

  return 0;
}