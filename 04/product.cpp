#include <iostream>
using namespace std;

/*TODO: if it isn't obvious to you how to do so, write a program that
 * computes the product of all integers given on stdin.  Try to see how
 * our program for max, sum, and now product, are all special cases of
 * a general pattern (see the notes, or read about "folds" in functional
 * programming). */

int main()
{
  int input, product = 1;

  cout << "Please enter some numbers: \n";

  while (cin >> input) {
    product *= input;
  }

  cout << "The product of these numbers is " << product << ".\n";

	return 0;
}