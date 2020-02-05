/* more about *datatypes*. */

#include <iostream>
using std::cout;
using std::cin;

int main()
{
	/* each variable you declare must have a datatype!  The
	 * datatype is an annotation that describes what kind of
	 * value will be in the variable. Here are some common
	 * ones: */
	int i = 9; /* stores integer data in the range [INT_MIN,INT_MAX].
	              INT_MIN is usually around -2^{31} and INT_MAX is
			      around 2^31-1. */
	char c = 'a'; /* stores a SINGLE character, like 'a' or 'b'. */
	double d = 0.3; /* stores floating point values */
	bool b = true; /* stores true/false values. */

	/* note that variables of different types might require different
	 * amounts of space.  you can find out how much is required using
	 * the 'sizeof()' operator: */
	cout << "int requires " << sizeof(int) << " bytes.\n";
	cout << "char requires " << sizeof(char) << " bytes.\n";
	cout << "double requires " << sizeof(double) << " bytes.\n";
	cout << "bool requires " << sizeof(bool) << " bytes.\n";

	/* some interesting things: be careful with floating point! */
	double e = 0.1;
	if (d == e+e+e) {
		cout << "d == e+e+e\n";
	} else {
		cout << "d was NOT equal to e+e+e\n";
		/* NOTE: the equality fails due to rounding error!
		 * Be careful with floating point in general.  Use
		 * it ONLY WHEN NECESSARY. */
	}
	/* You can also run into other surprises, like situations
	 * where basic algebraic identities fail to hold. E.g., if
	 * d+f = e+f, then... d == e.  Yet even this simple identity
	 * could fail with floating point.  TODO: try to find an example
	 * violating the law above.  That is, declare three doubles,
	 * d,e,f, and give them values such that d != e, and yet
	 * the sum of d+f is equal to e+f. */

	/* NOTE: different numeric types can be combined in arithmetic
	 * expressions.  But what is the type of the result?  */
	cout << "i+d == " << i+d << "\n"; /* type will be double! */
	cout << "i/2 == " << i/2 << "\n"; /* type will again be int! */
	cout << "i/2.0 == " << i/2.0 << "\n"; /* type will now be double. */
	/* You can also get the remainder from integer division: */
	cout << "i%2 == " << i%2 << "\n"; /* this gives the remainder. */

	/* NOTE: behind the scenes, each char is just a number. */
	cout << "c == '" << c << "'\n";
	/* if you are curious as to what the number is, you can consult
	 * an ASCII table, or just *typecast* like this: */
	cout << "c == " << (int)c << "\n";
	/* typecasting can also be useful if you want a floating point
	 * result, say of a fraction of integers: */
	int j = 4;
	cout << "i/(double)j == " << i/(double)j << "\n";


	/* Somewhat new topic: conditional expressions (like "if") */

	/* general form:
	 * if (<boolean expression>) {
	 *     // arbitrary statements...
	 * } else if (<boolean expression>) {
	 *     // arbitrary statements...
	 * } else {
	 *     // arbitrary statements...
	 * }
	 * */
	/* there are at least the following boolean operators:
	 * ==
	 * <
	 * >
	 * <=
	 * >=
	 * !=
	 * */
	/* NOTE: you can also use ANY integer expression as a boolean!
	 * The convention is 0 treated as false, and EVERYTHING ELSE
	 * is treated as true. */
	if (99) {
		cout << "99 is true, I guess.\n";
	}
	/* This has some kind of dangerous consequences...  note that
	 * assignment statements are also expressions with a type
	 * and value!  Why, you ask?  Consider the following "chained"
	 * assignment: */
	// i = j = 99;
	/* the above is the same as this: */
	// i = (j = 99);
	/* The point: the expression "i=j" has a value of whatever
	 * was in j.  Here's how a simple typo can cause trouble: */
	if (i = j) {
		/* statements here will happen whenever j is not 0 :\ */
		cout << "i was equal to j (hmm)\n";
	}

	return 0;
}

/* TODO: write a small program that reads 3 integers (from stdin, using
 * cin), and prints the *average* of the 3 to stdout (using cout).
 * TODO: do the same for 5 integers, but ONLY USE TWO VARIABLES! */

/* TODO: make sure you've done the reading, and make sure you have become
 * reasonably efficient at the edit/compile/run cycle.  Also read the
 * tutorial about git (if you have time leftover).
 * */
