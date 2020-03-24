#include <iostream>
using std::cin;
using std::cout;
/* TODO: read the first two sections of l4.pdf, and do the exercises therein.
 * Also look at ../whatstheoutput/{6,7}.cpp
 * */

/* TODO: take the example from class to grow a vector and wrap it in
 * a function, perhaps using the following prototype: */
void growArray(int*& A, size_t cursize, size_t newsize)
{
	/* A initially points to a buffer of cursize integers; your job is
	 * to find A a "new home" of newsize integers. */
}

/* TODO: write a main program that reads all of stdin into an array
 * of integers by allocating some small number initially, and then
 * growing the array as necessary to accomodate the entire input.
 * Use the function you wrote above to accomplish this. */
int main()
{
	return 0;
}

/* TODO: browse `man 3 malloc` if you want to learn about dynamic allocations
 * in C. */
/* TODO: while your in that man page, also read about "realloc", which is a
 * library function that basically does the same thing as growArray above. */
