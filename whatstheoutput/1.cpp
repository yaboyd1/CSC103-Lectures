#include <iostream>
using std::cout;
using std::endl;

/* TODO: predict the output of this program *without* running it!
 * Then compile and run it to check your answers and make sure you
 * understand what is going on if any of your guesses were wrong. */

int main() {
    int x = 10, y = 3;
    double d = 4, e = 2;

    //Subtracts x by 1 and then prints: x = 10 - 1 = 9, print
    cout << --x << endl;

    //Prints and then subtracts x by 1: 9, prints, x = 9 - 1 = 8
    cout << x-- << endl;

    //Integer division: 3/8 = 0 (floored)
    cout << y/x << endl;

    //Double into Integer: y = 2
    y = e;

    //Integer Division: 2/8 = 0
    cout << y/x << endl;

    //Modula: 8 % 2 = 0
    cout << x%y << endl;

    //Type Casting: (8 - 4.0)/2 = 4.0/2 = 2
    cout << (x-d)/y << endl;

    return 0;
}
