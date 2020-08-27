#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <climits>

/* TODO: write a program that reads (arbitrarily many) integers from
 * stdin and outputs the *second* smallest one.  NOTE: you don't need
 * to store many numbers (all at once, that is) to do this!  You'll
 * only need a few integer variables.  Think about invariants! */

int main() {
  int smallest = INT_MAX;
  int second = INT_MAX;

  int input;
  while(cin >> input) {
    // Input is smaller than absolute minimum
    if(input < smallest) {
      second = smallest;
      smallest = input;
    }
    // Input is smaller than second minimum
    else if(input < second) {
      second = input;
    }
  }

  cout << "Minimum: " << smallest << endl;
  cout << "Second: " << second << endl;

  return 0;
}