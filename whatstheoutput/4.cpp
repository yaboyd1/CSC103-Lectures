#include <iostream>
using std::cout;

/* TODO: predict the output of this program *without* running it!
 * Then compile and run it to check your answers and make sure you
 * understand what is going on if any of your guesses were wrong. */

int main()
{
	int i;

	//Iterate from 0 to 14
	for (i=0; i<15; i++) {
		//Print if a value is even and divisible by 3
		if (i % 2 == 0 && i % 3 == 0)
			cout << "i == " << i << "\n";
	}

	//Last known value of i
	cout << "i == " << i << "\n";
	return 0;
}


