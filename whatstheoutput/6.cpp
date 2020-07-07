#include <iostream>
using std::cout;
using std::endl;

/* TODO: predict the output of this program *without* running it!
 * Then compile and run it to check your answers and make sure you
 * understand what is going on if any of your guesses were wrong. */

int main()
{
    int A[5] = {0,2,4,6,8};
    cout << A[1] << endl; //Prints second element:
    cout << ++A[2] << endl; //Prints third element+1
    cout << *A << endl; //Prints first element
    int* p = &A[3];
    cout << *(p--) << endl; //Prints fourth element
    cout << *p << endl; //Prints third element

    //2
    //5
    //0
    //6
    //4

    //Actually printed a 5 instead of a 4
    //Most likely because the third element was changed ++A[2]
    return 0;
}
