#include<iostream>
using namespace std;

int main() {

  int input, counter = 0, prev = 1, current = 1, next = 2;

  cout << "Please enter how many terms of the fibonacci you would like to see: \n";
  cin >> input;

  while (counter < input) {

    prev = current;
    current = next;
    next = prev + current;

    cout << next << "\n";

    counter++;
  }

  return 0;
}