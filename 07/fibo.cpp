#include<iostream>
using namespace std;

int fib(int input);

int main() {

  int input;

  cout << "Which term of the fibonacci sequence do you want?\n";
  cin >> input;

  cout << "The fibonacci number for that term is " << fib(input) << ".\n";

  return 0;
}

int fib(int input) {
  int prev = 0, current = 1;

  // Switch between prev and current to hold the next value
  for (int i = 0; i < input; i++) {
    if (i % 2 == 1) {
      prev += current;
    }
    else {
      current += prev;
    }
  }

  // Since I don't know where the next value is stored:
  if (current > prev) {
    return current;
  }
  else {
    return prev;
  }
}