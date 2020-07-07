#include <iostream>
using std::cin;
using std::cout;
using std::endl;
/* TODO: read the first two sections of l4.pdf, and do the exercises therein.
 * Also look at ../whatstheoutput/{6,7}.cpp
 * */

/* TODO: take the example from class to grow a vector and wrap it in
 * a function, perhaps using the following prototype: */
void growArray(int*& A, size_t cursize, size_t newsize)
{
	/* A initially points to a buffer of cursize integers; your job is
	 * to find A a "new home" of newsize integers. */
  int* B = new int[newsize];
  for (size_t i = 0; i < cursize; i++) {
    B[i] = A[i];
  }
  A = B;
  delete B;
}

/* TODO: write a main program that reads all of stdin into an array
 * of integers by allocating some small number initially, and then
 * growing the array as necessary to accomodate the entire input.
 * Use the function you wrote above to accomplish this. */
int main()
{
  size_t size = 3, i = 0;
  int* A = new int[size];

  int input;
  while (cin >> input) {
    if (i >= size - 1) {
      growArray(A, size, size * 1);
      size++;
    }
    A[i] = input;
  }

  for (size_t j = 0; j < size; j++) {
    cout << A[j] << " ";
  }
}

/* TODO: browse `man 3 malloc` if you want to learn about dynamic allocations
 * in C. */

/* TODO: while your in that man page, also read about "realloc", which is a
 * library function that basically does the same thing as growArray above. */