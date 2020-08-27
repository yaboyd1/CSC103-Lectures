#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/* TODO: write a loop that prints the sum of the first n odd cubes. */

int main() {

  int n;
  cout << "Please enter how many odd cubes you would like: " << endl;
  cin >> n;

  for(size_t i = 0; n != 0; ++i) {
    if(i * i * i % 2 == 1) {
      cout << i * i * i << endl;
      n--;
    }
  }

  return 0;
}