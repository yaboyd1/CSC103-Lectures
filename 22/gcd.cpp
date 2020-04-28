#include <iostream>
using std::cin;
using std::cout;
#include <cstdio>

size_t gcd(size_t a, size_t b)
{
	/* TODO: write me (without looking at the notes if possible) */
}

/* TODO: write the *extended* GCD algorithm, which returns gcd(a,b), but
 * also sets u and v such that ua + vb = gcd(a,b) Warning: this might take a
 * little bit of thinking (if you don't just look up the answer online).  Save
 * it for last. */
int xgcd(int a, int b, int& u, int& v)
{
	return 0;
}

int main(void)
{
	size_t a,b;
	cin >> a >> b;
	printf("gcd(%lu,%lu) = %lu\n",a,b,gcd(a,b));
	return 0;
}

/* TODO: remind me to setup a schedule for interviews! */
