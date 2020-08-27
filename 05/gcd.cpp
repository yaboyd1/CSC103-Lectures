/* simple program to "brute force" the gcd of two positive integers. */
#include <iostream>
using std::cin;
using std::cout;

int main()
{
	int a,b;
	cout << "Enter two integers: ";
	cin >> a >> b;
	/* now compute the gcd.  we will start with the largest possible
	 * value for the gcd and count backwards until we find a common
	 * divisor of a and b. */
	int min;
	if (a > b) {
		min = b;
	} else {
		min = a;
	}
	/* min is now min(a,b).  this is the largest possible value of
	 * the gcd. */
	/* TODO: shorten the above by unconditionally assigning to min
	 * one of the inputs, then checking if you made the right
	 * choice.  (This will eliminate the "else" part.) */
	int d = min;
	while (d != 0) {
		/* check for d being a common divisor of a and b: */
		if (a%d == 0 && b%d == 0) {
			/* then d is the gcd!  so we should stop the loop... */
			break;
		}
		d--; /* move to the next smaller value of d to check. */
	}
	cout << d << " is the gcd of " << a << " and " << b << "\n";
	/* TODO: you don't actually need d.  Rewrite the above to only
	 * use 3 variables.  */
	/* TODO: shorten the while loop by changing the condition
	 * to be the test for being a common divisor.  (The body
	 * of the while loop should be just the statement "d--;") */
	return 0;
}

/* TODO: write a loop that prints the sum of the first n odd cubes. */

/* TODO: write a brute force test for perfect cubes.  Check if
 * n = k^3 for some integer k.  */

/* TODO: sum the squares of all integers from 1..100.
 * I.e., compute 1+4+9+...+10000 */

/* TODO: a slight generalization of an earlier exercise: for integers
 * n and k, determine the largest power of k that divides n.
 * NOTE: see if you can formalize the invariant you used to solve this.
 * (See l2.pdf regarding invariants.)
 * */

/* TODO: write a program that reads (arbitrarily many) integers from
 * stdin and outputs the *second* smallest one.  NOTE: you don't need
 * to store many numbers (all at once, that is) to do this!  You'll
 * only need a few integer variables.  Think about invariants! */

// vim:foldlevel=1
