#include <string>
using std::string;
#include <vector>
using std::vector;
/* exercise: write a (probably recursive) function that returns
 * all sequences of length n using characters from a given
 * string.  E.g., if s="abc" and n=2, then the output would
 * be:
 * aa
 * ab
 * ac
 * ba
 * bb
 * bc
 * ca
 * cb
 * cc
 * */

vector<string> seq(string s, int n)
{
	/* base case? */
	if (n == 0) {
		vector<string> R;
		R.push_back("");
		return R;
	}
	if (s == "") return vector<string>(); /* empty vector */
	/* now the general case.  if we had a magic box that
	 * computed this function for smaller inputs, how could
	 * we make use of it?  Let's do induction on n. */
	vector<string> T = seq(s,n-1); /* all n-1 length sequences */
	/* now go through each element of T, and add each character
	 * in s... */
	vector<string> R; /* for the return value */
	for (size_t i = 0; i < T.size(); i++) {
		for (size_t j = 0; j < s.length(); j++) {
			R.push_back(T[i]+s[j]);
			/* NOTE: T[i]+s[j] appends CHARACTER s[j] to STRING T[i] */
		}
	}
	return R;
}

/* TODO: try to re-write this, and also test it out. */
