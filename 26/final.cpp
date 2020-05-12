#include <stdio.h>
#include <stdlib.h>
#include <vector>
using std::vector;
#include <cmath>

struct point {
	double x;
	double y;
};

/* #2: brute force max distance between two points */
double maxDist(const vector<point>& V)
{
	/* IDEA: go through all pairs of points, compute
	 * distance; keep track of max. */
	double max = 0; /* smallest possible value for dist. */
	for (size_t i = 0; i < V.size(); i++) {
		for (size_t j = i+1; j < V.size(); j++) {
			/* compute distance^2 between V[i],V[j] */
			double d = (V[i].x - V[j].x)*(V[i].x - V[j].x)
				+ (V[i].y - V[j].y)*(V[i].y - V[j].y);
			if (d > max) max = d;
		}
	}
	return sqrt(max);
}

/* #3 print an integer in octal. */
void printOctal(size_t n)
{
	/* IDEA: induction on number of (base 8) digits */
	if ( n < 8 /* single digit */ ) {
		printf("%lu",n);
		return;
	}
	/* print high order digits via recursive magic: */
	printOctal(n/8);
	/* then print the last digit: */
	printf("%lu",n%8);
}

/* #5 remove last element of a linked list */
void removeLast(node*& L)
{
	/* walk to end of list, but don't go all the way off... */
	node* p = L;
	if (p == NULL) return; /* there is no last node! */
	node* q = NULL; /* make q follow p */
	while (p->next != NULL) { /* issue: might crash! */
		q = p;
		p = p->next;
	}
	delete p;
	if (q) q->next = NULL;
	else L = NULL;
	/* NOTE: if list had length 1, q would be NULL! */
}

/* for testing: */
int main()
{
	printOctal(133);
	printf("\n");
	return 0;
}
