#include <iostream>
using std::cout;

/* TODO: without running this program, predict the output. */

size_t f(size_t m, size_t n)
{
	if (m == 0) return n+1;
	if (n == 0) return f(m-1,1);
	return f(m-1,f(m,n-1));
}

int main()
{
	cout << f(2,2) << "\n";
	/* NOTE: increasing the first parameter from 2 to 3 will result
	 * in hundreds of recursive calls.  Increasing it further to 4
	 * would make it run a long time and produce a value that doesn't
	 * fit in a size_t!  For your amusement, I've attached the call
	 * graph for f(3,2), and the code that I used to make it with.
	 * See the "traces" directory. */
	return 0;
}
