#include <iostream>
using std::cin;
#include <cstdio> /* for printf */
#include <map>
using std::map;

/* let's use maps to make a more efficient fibonacci function
 * (that's still recursive...) */

size_t fib(int n)
{
	static map<int,size_t> A; /* "memory" for the answers */
	/* NOTE: "static" in this context means the function only
	 * gets ONE of these, which will be preserved across calls. */
	if (n < 2) return 1; /* base case. */
	if (A.find(n) != A.end()) { /* we found an entry for n */
		return A[n]; /* return our already-computed answer */
	}
	/* else, compute it using recursive calls. */
	size_t result = fib(n-1) + fib(n-2);
	A[n] = result;
	return result;
}

/* NOTE: the above technique is usually called "memoization". */

int main()
{
	int n;
	while (cin >> n)
		printf("fib(%i)\t= %lu\n",n,fib(n));
	return 0;
}

/* TODO: try to re-write the memoized fibonacci function
 * from scratch. */
/* TODO: write some "proof of concept" code that illustrates
 * what the static keyword does.  E.g., make a function with
 * static and non-static variables, call them a few times, and
 * see what happens when you examine their values.  */
