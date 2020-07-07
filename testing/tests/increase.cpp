#include<iostream>
using namespace std;

void increase(int);
void increase2(int& x);

//Testing out lecture note 9

int main() {
    int x = 1;
    cout << "Before calling the increase function, x is "
         << x << ".\n";
    increase(x);
    cout << "After calling the increase function, x is "
         << x << ".\n";
  increase2(x);
    cout << "After calling the second increase function, x is "
         << x << ".\n";
    return 0;
}


//This is called by value, not refernce
void increase(int x) {
    x++;
}

//This function is called by reference
void increase2(int& input) {
    input++;
}

//You can't change the value of the variables by ordinary function calls because the values are copied to other local variables. Change in other local variables won't affect the original variables.