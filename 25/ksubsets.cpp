#include <iostream>
using std::cin;
using std::cout;
#include <set>
using std::set;
#include <cstdio>

set<set<int>> ksubsets(set<int> S, size_t k)
{
	if (k == 0) { // answer should be {{}}
		/* TODO: find a nicer way to do this using
		 * constructors for set. */
		set<int> E; /* it's empty! */
		set<set<int>> P;
		P.insert(E); /* now P = {{}} */
		return P;
	}
	if (S.size() < k) {
		return set<set<int>>(); /* {}, as a set of sets */
	}
	int x = *(S.begin()); /* let x be an arbitrary element. */
	/* NOTE: are we sure S is not empty?  Sure we're sure:
	 * we would have hit one of the base cases otherwise. */
	S.erase(x); /* S is now S'... */
	set<set<int>> P = ksubsets(S,k);
	set<set<int>> R = ksubsets(S,k-1);
	/* now add x back to each element of R, and
	 * union together with P for the final result. */
	for (auto i = R.begin(); i != R.end(); i++) {
		set<int> T = *i; /* size of T is k-1 */
		T.insert(x); /* add x; now |T| = k */
		P.insert(T); /* add to union */
	}
	return P;
}

/* TODO: as with the powerset function from last time, try to write
 * this again from scratch, and maybe trace the calls under gdb on
 * a small input, or just draw the recursion tree by hand. */

int main(void)
{
	int x;
	set<int> S;
	while (cin >> x) {
		S.insert(x);
	}
	/* compute all subsets of approx. half the size of S: */
	set<set<int>> P = ksubsets(S,S.size()/2);
	for (auto i = P.begin(); i != P.end(); i++) {
		printf("{");
		for (auto j = i->begin(); j != i->end(); j++) {
			printf("%i ",*j);
		}
		printf("}\n");
	}
	return 0;
}

/* TODO: try to write a recursive function that computes all
 * n-sequences of a set of characters.  E.g., if S={a,b} and
 * n = 3, you would have:
 * aaa
 * aab
 * aba
 * abb
 * baa
 * bab
 * bba
 * bbb
 * */
