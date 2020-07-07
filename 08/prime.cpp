#include <iostream>
#include <cmath>
using namespace std                                         ;

//Testing out weird formatting to see if it works

int main()                                                  {
  unsigned long input                                       ;
  while (cin >> input)                                      {
    bool isPrime = true                                     ;
      if (input % 2 == 0 && input != 2)                     {
        isPrime = false                                     ;}
      for (int i = 3; i < sqrt(input) + 1; i+=2)            {
        if (input % i == 0)
        isPrime = false                                     ;}
    cout << isPrime << endl                                 ;}
  return 0                                                  ;}