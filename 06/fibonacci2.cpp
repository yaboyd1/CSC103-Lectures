#include<iostream>
using namespace std;

int main() {

  int input, prev = 0, current = 1;

  cout << "Please enter how many terms of the fibonacci you would like to see: \n";
  cin >> input;

  // Iterate up to input value
  for (int i = 0; i < input; i++) {

    // Store next value by switching between prev and current
    if (i % 2 == 1) {
      prev += current;
      cout << prev << "\n";
    }
    else {
      current += prev;
      cout << current << "\n";
    }

  }

  return 0;
}