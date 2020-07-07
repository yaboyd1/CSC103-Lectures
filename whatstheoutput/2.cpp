#include <iostream>
using std::cout;

/* TODO: predict the output of this program *without* running it!
 * Then compile and run it to check your answers and make sure you
 * understand what is going on if any of your guesses were wrong. */

int main()
{
	int x = 16;

	//While x is positive, print and then divide by 2
	while (x > 0) {
		cout << "x == " << x << "\n";
		x /= 2;
	}

	//Print last value
	cout << "x == " << x << "\n";

	// print 16 : 16/2 = 8
	// print 8  :  8/2 = 4
	// print 4  :  4/2 = 2
	// print 2  :  2/2 = 1
	// print 1  :  1/2 = 0
	// print 0

	return 0;
}
