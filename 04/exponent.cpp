#include <iostream>
using namespace std;

/* TODO: given an integer n, find exponent of the largest power of two that
 * divides n.  Example: if n = r*8 with r odd, then you should output 3
 * since 8 = 2^3.  (You are just recovering the exponent of the 2 in the
 * number's factorization into primes.)
 * (IDEA: keep on dividing n by two until we can't,
 * and keep track of how many times it worked.) */

int main() {

  int num, count = 0;

  cout << "Please enter an integer value: \n";
  cin >> num;

  while (num % 2 == 0) {
    num /= 2;
    count++;
  }

  cout << "The exponent of the largest power of two is " << count << ".\n";

  return 0;
}