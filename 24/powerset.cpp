#include <cstdio>
#include <iostream>
using std::cin;
using std::cout;
#include <set>
using std::set;

#if 0
vector<int> V;
V.push_back(1);
V.push_back(1);
V.push_back(1);
V.push_back(1);
V.push_back(1);
V.push_back(1);
V.push_back(1);
/* V now has a bunch of 1's */

set<int> S;
S.insert(1);
S.insert(1);
S.insert(1);
S.insert(1);
S.insert(1);
S.insert(1);
S.insert(1);
S.insert(1);
/* S just has a single element: S = {1} */
/* NOTE: can't do S[i]... wouldn't really make sense. */
#endif

set<set<int>> powerset(set<int> S)
{
	if (S.empty()) {
		set<int> empty; /* it's empty!! */
		set<set<int>> P; /* we'll return this thing. P = {} */
		P.insert(empty); /* now P = {{}} */
		return P; /* NOTE: {} =/= {{}} !!! */
		/* NOTE: we could have also just used S for empty... */
	}
	/* now make S' which is smaller than S by removing an element. */
	set<int> SBar(S); /* start with a copy of S */
	/* NOTE: we KNOW SBar =/= {}, so it has at least one element. */
	int x = *(SBar.begin());
	SBar.erase(x); /* remove x */
	set<set<int>> PBar = powerset(SBar);
	set<set<int>> P(PBar); /* we'll return this thing. */
	/* now duplicate P, but add an x to each subset... */
	/* how to go through all elements of P??? */
	for (set<set<int>>::iterator i = PBar.begin(); i != PBar.end(); i++) {
		/* *i is a set<int> */
		set<int> T = *i;
		/* now add x to T, and that to P! */
		T.insert(x);
		P.insert(T);
	}
	return P;
}

/* TODO: try to re-write the above from scratch. */
/* TODO: practice your gdb-fu by tracing this function.  Remember:
 * use make -B debug before running gdb on it. */

int main()
{
	set<int> S = {1,2,3};
	set<set<int>> P = powerset(S);
	for (set<set<int>>::iterator i = P.begin(); i != P.end(); i++) {
		printf("{");
		for (set<int>::iterator j = i->begin(); j != i->end(); j++) {
			printf("%i ",*j);
		}
		printf("}\n");
	}
	return 0;
}

/* TODO: try to write another version of the power set function
 * that divides the set into two disjoint subsets of equal(ish)
 * size, computes the powersets of those recursively, and then
 * puts them back together.  It is essentially the same idea as
 * the above.  Bonus question: prove your algorithm works, and
 * that it requires approximately the same number of steps as
 * the original. */
