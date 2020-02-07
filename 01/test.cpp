#include <iostream> /* gives you a way to read/write input/output */
using std::cin;
using std::cout;
#include <climits> /* needed for definition of INT_MIN */

int main() {
	/* this is where your program's instructions begin.
	 * (we'll put some version of the steps of our solution here...) */
	/* analog of our pieces of paper / post-it notes: *variables* */
	int next; /* we'll use this space to store numbers "spoken" to us. */
	int max;  /* this space will always hold the largest one *so far*. */
	max = INT_MIN; /* INT_MIN is sort of like -infinity... */
	cout << "Please enter numbers so I can determine which one is the maximum one.\n";
	while (cin >> next) { /* listen until no more numbers spoken */
		/* if new one is bigger, update max so that it is again the
		 * largest number we've heard so far. */
		if (next > max) {
			max = next;
		}
	}
	cout << "The largest number was "<< max << "\n";
}

/* TODO: read l1.pdf and the first 2 lectures from Prof Li. */
/* TODO: try to complete this tutorial on compiling programs:
 * https://www-cs.ccny.cuny.edu/~wes/CSC103/commandline.html
 * (helpful if you have installed the virtual machine first) */
/* TODO: try to modify the above program so that the output says something
 * like "the largest number was 999" instead of just printing the number as
 * it does now. */
/* TODO: replace "cin >> next" with "cin << next", try to compile again,
 * and take note of the somewhat lengthy error message that results. */

// vim:foldlevel=3
