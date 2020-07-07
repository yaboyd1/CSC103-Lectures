#include <iostream>
#include <climits>
using namespace std;

int main() {

  int input, min = INT_MAX, min2 = INT_MAX;

  cout << "Please enter at least 2 numbers: \n";

  while (cin >> input) {

    /* If the user enters a number lower than the current min,
     * current minumum will be stored, and the input will be the
     * new minimum? */

    if (input < min) {
      min2 = min;
      min = input;
    }

  }

  cout << "The second smallest value is " << min2 << ".\n";

  return 0;
}