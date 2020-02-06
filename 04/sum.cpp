#include <iostream>
using std::cout;
using std::cin;

int main()
{
	/* step 1: */
	int input; /* blue note */
	int sum_so_far; /* green note */
	int temp; /* orange note */
	sum_so_far = 0; /* step 2 */
	while (cin >> input) { /* step 3 */
		temp = input + sum_so_far;
		sum_so_far = temp;
		/* NOTE: we could shorten this to "sum_so_far = input + sum_so_far"
		 * or there is an even shorter way: "sum_so_far += input"
		 * Then we wouldn't need the "temp" variable at all. */
	} /* step 6: (go back to beginning of loop) */
	cout << "Sum was " << sum_so_far << "\n";
	return 0;
}

/* TODO: if it isn't obvious to you how to do so, write a program that
 * computes the product of all integers given on stdin.  Try to see how
 * our program for max, sum, and now product, are all special cases of
 * a general pattern (see the notes, or read about "folds" in functional
 * programming). */
/* TODO: given an integer n, find exponent of the largest power of two that
 * divides n.  Example: if n = r*8 with r odd, then you should output 3
 * since 8 = 2^3.  (You are just recovering the exponent of the 2 in the
 * number's factorization into primes.)
 * (IDEA: keep on dividing n by two until we can't,
 * and keep track of how many times it worked.) */
/* TODO: try the exercises at the end of l1.pdf, and start reading l2.pdf,
 * as well as lectures 5-8 from Prof. Li. */
/* TODO: I left you with a makefile this time.  Instead of running g++
 * manually, just run the command "make" and it will run g++ with some
 * nice flags for you.  (NOTE: binary will be named "sum" and not "a.out"
 * in this case.)
 * */

#if 0
NOTE: here are some ways you can test out the program:

Type in numbers manually:
+[04]$ ./sum
3
7
5
10
Sum was 25

Use the `echo` command:
+[04]$ echo 3 7 5 10
3 7 5 10
+[04]$ echo 3 7 5 10 | ./sum
Sum was 25

`echo` a range of numbers:
+[04]$ echo {1..10}
1 2 3 4 5 6 7 8 9 10
+[04]$ echo {1..10} | ./sum
Sum was 55

Make a test file:
+[04]$ echo {1..10} > numbers
+[04]$ cat numbers
1 2 3 4 5 6 7 8 9 10
+[04]$ ./sum < numbers
Sum was 55

TODO: try to understand the above shell commands.
#endif

// vim:foldlevel=2
