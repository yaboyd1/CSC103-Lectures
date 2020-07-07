#include <cstdio>

/* nonsense function to explore recursion... */
void f(int n)
{
	printf("calling f(%i)...\n",n);
	if (n == 0) {
		printf("stopped @ 0\n");
		return;
	}
	f(n-1);
	printf("leaving f(%i)...\n",n);
}

/* TODO: write the recursive factorial function from memory
 * and test it out. */

int factorial(int n) {
	if (n == 1) return 1;
	return n * factorial(n-1);
}

/* TODO: write a recursive function to compute x^n (x to the n power)
 * where n is an integer. */

int pow(int x, int n) {
	if (n == 0) return 1;
	return x * pow(x, n-1);
}

/* TODO: write a recursive function for the fibonacci terms
 * and make sure you realize why it is so inefficient that even
 * your fancy gaming battlestation struggles with n>50. */

int fib(int n) {
	if (n < 2) {
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}

int main(void)
{
	int n = 5;

	f(n);  /* what will happen? */

	printf("%i! is %i\n", n, factorial(n));
	printf("2^%i is %i\n", n, pow(2,n));
	printf("Term %i of the fibonacci sequence is %i\n", n, fib(n));

	return 0;
}


/* TODO: read lecture 5 (l5.pdf) and come to class with questions (or
 * a thorough understanding of the content!). */
