#include <iostream>
using std::cout;

/* TODO: predict the output of this program *without* running it!
 * Then compile and run it to check your answers and make sure you
 * understand what is going on if any of your guesses were wrong. */

int main(void)
{
	int x = 23;
	int y = 99;
	int* p = &x;
	int* q = &y;
	/* NOTE: while you can't predict the exact memory addresses, for some
	 * of the lines below, you should still have some idea of what it will
	 * look like (in particular, whether or not you will get the same
	 * address twice, or two different ones).
	 * */
	cout << "p  == " << p << "\n&x == " << &x << "\n";
	//Prints same address
	cout << "q  == " << q << "\n&y == " << &y << "\n";
	//Prints same address/different from first
	cout << "x  == " << x << "\n*p == " << *p << "\n";
	//Prints same x value of 23
	cout << "y  == " << y << "\n*q == " << *q << "\n";
	//Prints same y value of 99

	//P now points to y
	p = q;

	cout << "p  == " << p << "\n&x == " << &x << "\n";
	//Address of y, address of x
	cout << "q  == " << q << "\n&y == " << &y << "\n";
	//Same address
	cout << "x  == " << x << "\n*p == " << *p << "\n";
	//X value, Y value
	cout << "y  == " << y << "\n*q == " << *q << "\n";
	//Same Y value

	return 0;
}
