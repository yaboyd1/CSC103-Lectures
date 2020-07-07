#include <iostream>
#include <string>
using namespace std;

/* TODO: write a small program that reads 3 integers (from stdin, using
 * cin), and prints the *average* of the 3 to stdout (using cout).
 * TODO: do the same for 5 integers, but ONLY USE TWO VARIABLES! */

int main() {

  int input, amount = 5, sum = 0;

  cout << "Please enter " << amount << " integers: \n";

  for (int i = 0; i < amount; i++) {
    cin >> input;
    sum += input;
  }

  cout << "The average of these three numbers is " << sum/5.0 << ".\n";

}