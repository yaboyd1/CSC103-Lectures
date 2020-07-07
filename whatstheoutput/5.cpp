#include <iostream>
using std::cout;

/* TODO: predict the output of this program *without* running it!
 * Then compile and run it to check your answers and make sure you
 * understand what is going on if any of your guesses were wrong. */

int fn1(int& a, int b, int& c)
{
    a = b++; //A will equal B, B will NOT change (passed by value)
    b += 10; //B still does not change (passed by value)
    c = ++a; //C will be A+1,
    return b; //Return will be B+11
}

int main()
{
    int x=3, y=5, z=13;
    cout << x << " " << y << " " << z << "\n";
    int r = fn1(x,y,z);
    cout << x << " " << y << " " << z << "\n"; //5, 5, 6

    //Actually printed out 6, 5, 6
    //Most likely because c = ++a does:
    //a=a+1
    //c=a
    //So both a and c change

	  cout << r << "\n"; //11
    return 0;
}
