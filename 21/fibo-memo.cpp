#include <iostream>
using std::cin;
#include <cstdio> /* for printf */
#include <map>
using std::map;
#include <cstdio>
using std::printf;

/* let's use maps to make a more efficient fibonacci function
 * (that's still recursive...) */

void increment();
void staticIncrement();

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
	/*
	int n;
	while (cin >> n)
		printf("fib(%i)\t= %lu\n",n,fib(n));
	*/

	printf("Without static: \n");
	size_t n = 5;
	for (size_t i = 0; i < n; i++)
		increment();
	printf("With static: \n");
	for (size_t i = 0; i < n; i++)
		staticIncrement();

	return 0;
}

/* TODO: try to re-write the memoized fibonacci function
 * from scratch. */
/* TODO: write some "proof of concept" code that illustrates
 * what the static keyword does.  E.g., make a function with
 * static and non-static variables, call them a few times, and
 * see what happens when you examine their values.  */

void staticIncrement() {
	static int UwU = 0;
	printf("%i\n", UwU++);
}

void increment() {
	int UwU = 0;
	printf("%i\n", UwU++);
}
