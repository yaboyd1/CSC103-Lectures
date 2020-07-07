#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;
#include <cstdio>
using std::printf;

void printVertically(size_t n);

/* TODO: try to re-write this whole thing from scratch.
 * Also, maybe give it a try with vectors instead of arrays. */

/* merge sorted L and R into A (which must be allocated
 * beforehand) */
void merge(int* L, size_t nL, int* R, size_t nR, int* result)
{
	size_t iL = 0; /* location of next candidate in L */
	size_t iR = 0; /* location of next candidate in R */
	size_t i  = 0; /* destination in result */
	/* the above correspond to the underlined cells
	 * from our diagram. */
	/* easy case: neither array has run out of elements: */
	while (iL < nL && iR < nR) {
		/* compare candidates, copy the smaller one
		 * to result. */
		if (L[iL] < R[iR]) result[i++] = L[iL++];
		else               result[i++] = R[iR++];
	}
	/* at this point, one of the arrays has "run out" of
	 * elements.  Copy the rest of the one that hasn't. */
	while (iL < nL) result[i++] = L[iL++];
	while (iR < nR) result[i++] = R[iR++];
}

/* merge sort with arrays.  n ===  #elements of A */
void mergeSort(int* A, size_t n)
{
	/* base case: small arrays are already sorted! */
	if (n < 2) return; /* already sorted */
	/* now divide array in two pieces */
	int* L = A; /* left subarray; A[0...n/2-1] */
	size_t mid = n/2;
	int* R = A+n/2; /* right subarray: A[n/2...n-1] */
	/* NOTE: L and R are strictly smaller than A, so
	 * we can use recursive magic now! */
	mergeSort(L,n/2);
	mergeSort(R,n-n/2);
	/* by our inductive hypothesis, L and R are now
	 * properly sorted.  All that remains is to merge
	 * them back together. */
	int* result = new int[n];
	merge(L,n/2,R,n-n/2,result);
	/* now copy result back to A */
	for (size_t i = 0; i < n; i++) {
		A[i] = result[i];
	}
	/* don't forget to delete the temporary array! */
	delete [] result;
}
/* TODO: read about the "static" keyword in a function context
 * and see if you can avoid allocating / deallocating the array
 * for temporary storage every single time the function is called.
 * */

int main()
{

	/*
	int x;
	vector<int> A;
	while (cin >> x) {
		A.push_back(x);
	}
	/* TODO: try to understand how we ran off with A's array: */

	/*
	mergeSort(&A[0],A.size());
	for (size_t i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
	*/

	printVertically(2358);


	return 0;
}

/* NOTE: we tested this by giving it numbers in random order, like so:
 * $ echo {1..10} | tr ' ' '\n' | sort -R | ./merge-sort
 * TODO: try to make sense out of this command pipeline (only mysteries
 * are probably the 'tr' command, and maybe -R for sort).
 * */

/* TODO: write a recursive function that prints the base 10 digits of n
 * vertically to cout.  for example, printVertically(2358) would print
 * 2
 * 3
 * 5
 * 8
 * Rules: you can't use any loops.  You can't use vectors or arrays.
 * Just let the recursive function calls do the work for you.  */

void printVertically(size_t n) {
	if (n < 10) {
		printf("%i\n", n);
		return;
	}
	printVertically(n / 10);
	printf("%i\n",n % 10);
}
