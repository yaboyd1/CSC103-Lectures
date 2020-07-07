#include <iostream>
using std::cout;

/* TODO: predict the output of this program *without* running it!
 * Then compile and run it to check your answers and make sure you
 * understand what is going on if any of your guesses were wrong. */

int main()
{
	int x = 9;

	// While positive
	//   If x is greater than 6, print x
	//   Subtract x by 2 regardless
	// Print last value of x
	while (x > 0) {
		if (x > 6 || x % 5)
			cout << "x == " << x << "\n";
		x -= 2;

	}

	cout << "x == " << x << "\n";
	return 0;

	// Original Thought Process:
	// 9 > 6: print 9: x=7
	// 7 > 7: print 7: x=5
	// 5    :        : x=3
	// 3    :        : x=1
	// 1    :        : x=-1
	// -1   : print -1

	// Actual:
	// x % 5 is always true, so the values will ALWAYS print
	// 9
	// 7
	// 3
	// 1
	// -1

}
