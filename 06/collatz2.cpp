#include<iostream>
using namespace std;

int main() {

  int input;

  while (cin >> input) {

    int original = input;
    int count = 0;
    int max = 1;

    //Stop when it reaches 1
    while (input != 1) {

      //Apply collatz rule
      if (input % 2 == 0) {
        input /= 2;
      }
      else {
        input = input * 3 + 1;
      }

      //Record maximum value
      if (input > max) {
        max = input;
      }

      //Increment number of steps
      count++;
    }

    //Print number of steps and maximum value
    cout << count << " steps for " << original << "\n";
    cout << max << " is the maximal intermediate value for " << original << "\n";
  }

  return 0;
}
/*Commands
 *$ echo {1..10000} | ./collatz | less
 *$ echo {1..10000} | ./collatz | sort -rn | less
 *$ echo {1..10000} | ./collatz | sort -rn | head -5
 */
