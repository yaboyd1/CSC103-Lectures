#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;

void reverse(vector<int>& V)
{
	size_t n = V.size();
	for (size_t i = 0; i < n/2; i++) {
		/* swap V[i] <--> V[n-i-1] */
		V[i]     ^= V[n-i-1];
		V[n-i-1] ^= V[i];
		V[i]     ^= V[n-i-1];
		/* TODO: make sure you understand this.  See notes for explanation.
		 * Note that the '^' operator performs exclusive or ("xor"). */
	}
}

int main(void)
{
	vector<int> V;
	int x;
	while (cin >> x) {
		V.push_back(x);
	}
	reverse(V);
	for (size_t i = 0; i < V.size(); i++) {
		cout << V[i] << " ";
	}
	cout << "\n";
	return 0;
}

/* TODO: write a function called "push_front(V,x)" for a vector, which
 * adds parameter x to index 0 of vector V by moving all the other values
 * to higher indexes.  (This should show you why inserting elements is only
 * efficient at the *end* of a vector.) */
/* TODO: if you haven't done it already, try to write "binary search" for
 * a sorted vector. */
/* TODO: write a function that takes a vector V (of integers) and a single
 * integer x, and returns a boolean value indicating whether or not x can
 * be expressed as the sum of two elements of V.  (Let's say you can't use
 * the same index twice, so you must find i =/= j such that x = V[i]+V[j].) */
