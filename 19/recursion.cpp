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

/* TODO: write a recursive function for the fibonacci terms
 * and make sure you realize why it is so inefficient that even
 * your fancy gaming battlestation struggles with n>50. */

int main(void)
{
	f(5);  /* what will happen? */
	return 0;
}

/* TODO: write a recursive function to compute x^n (x to the n power)
 * where n is an integer. */
/* TODO: read lecture 5 (l5.pdf) and come to class with questions (or
 * a thorough understanding of the content!). */
