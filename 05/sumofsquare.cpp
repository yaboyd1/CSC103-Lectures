#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/* TODO: sum the squares of all integers from 1..100.
 * I.e., compute 1+4+9+...+10000 */

// Answer: 338350

size_t sumOfSquaresUntil(const size_t& n);

int main() {

  int n;
  cout << "Please enter a number" << endl;

  while (cin >> n) {
    cout << "The sum of squares of all integers from 1.." << n << " is " << sumOfSquaresUntil(n) << endl;
  }

  return 0;
}

size_t sumOfSquaresUntil(const size_t& n) {
  size_t sum = 0;
  for(size_t i = 1; i <= n; ++i) {
    sum += i * i;
  }
  return sum;
}