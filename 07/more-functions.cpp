#include <iostream>
using std::cin;
using std::cout;

/* exercise: write a function that takes two integers and
 * swaps the values.  That is, after calling swap(x,y),
 * x will have whatever value y had before the call, and y
 * will have whatever value x had before the call. */
void swap(int& x, int& y)
{
	int z = x;
	x = y;
	y = z;
}
/* TODO: delete the above and write it from scratch (if you didn't
 * figure it out in the 90 seconds I gave during lecture). */

/* exercise: write two functions named "max" which return the
 * maximal value of all inputs.  One version should have two
 * parameters, and the other three. */
int max(int x, int y)
{
	if (x<y) return y;
	return x;

	/* Trivia: could also do this with the "ternery" operator: */
	// return (x<y)? y:x;
}

int max(int x, int y, int z)
{
	if (x > y && x > z) return x;
	if (y > x && y > z) return y;
	return z;
}
/* TODO: if you don't completely understand the above, delete them
 * and write them again from scratch. */

int main()
{
	/* TODO: write some test code for each of the above functions. */

	int x, y, z;

	cout << "Please choose a value for x, y and z: \n";
	cin >> x >> y >> z;

	cout << "The maximum of these values is " << max(x,y,z) << ".\n";
	cout << "The maximum of the first two values is " << max(x,y) << ".\n";
	swap(y,z);
	cout << "The second value is " << z << ".\n";

	return 0;
}

/* TODO: write a *function* that takes an integer n and returns the
 * nth term in the Fibonacci sequence. */
/* TODO: take a look at the new additions to ../whatstheoutput/ and make sure
 * you can predict the outputs of those programs. */
/* TODO: if you are feeling ambitious, try the last exercise from l2.pdf */
