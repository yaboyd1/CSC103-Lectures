#include <iostream>
using std::cin;
using std::cout;

/* program to test the collatz conjecture.  read integers from stdin,
 * and print the number of steps before the sequence ended. */

int main()
{
	int n;
	while (cin >> n) {
		int original = n;
		int count = 0; /* record number of steps before sequence stops. */
		while (n != 1) {
			/* apply rules to modify n. */
			if (n % 2 == 0) n /= 2; /* same as n = n / 2; */
			else n = 3*n + 1;
			count++;
		}
		cout << count << " steps for " << original << "\n";
	}
	return 0;
}

/* TODO: delete the above and write it from scratch */
/* TODO: keep track of the maximal intermediate value of n and print
 * that out along with the result. */
/* TODO: try out (and try to understand) these shell commands:
 * $ echo {1..10000} | ./collatz | less
 * $ echo {1..10000} | ./collatz | sort -rn | less
 * $ echo {1..10000} | ./collatz | sort -rn | head -5
 * */

// vim:foldlevel=2
