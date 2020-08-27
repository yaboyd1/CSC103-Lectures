#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>
using std::cbrt;
using std::pow;

/* TODO: write a brute force test for perfect cubes.  Check if
 * n = k^3 for some integer k. */

bool isPerfectCube2(const int& n); // Using math libraries
bool isPerfectCube(const int& n); // Bruteforce to test

int main() {

  int n;
  cout << "Please enter a number: " << endl;
  while(cin >> n) {

    cout << n << " is ";
    isPerfectCube2(n) ? cout << "Perfect Cube!" << endl : cout << "Not a Perfect Cube :(" << endl;
  }

  return 0;
}

bool isPerfectCube2(const int& n) {
  return pow((int)cbrt(n), 3) == n;
}

bool isPerfectCube(const int& n) {
  for(int k = 0; k < n; ++k) {
    if(k * k * k == n) {
      return true;
    }
  }
  return false;
}