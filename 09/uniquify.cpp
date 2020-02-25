#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;

/* warm-up: return a new vector */
vector<int> uniquify(const vector<int>& V)
{
	vector<int> U; /* we'll return this later */
	if (V.size() == 0) return U; /* handle special case of empty V */
	/* now we know V is non-empty, so we can add V[0] to U */
	U.push_back(V[0]);
	/* next, scan V for an element that isn't the last thing in U */
	for (size_t i = 1; i < V.size(); i++) {
		if (V[i] != U[U.size()-1]) /* if V[i] different than last element of U */
			U.push_back(V[i]);
	}
	return U;
}

/* TODO: make a version of uniquify which modifies the vector "in-place".
 * It might be a bit challenging, but I think you are prepared. */

int main(void)
{
	vector<int> V;
	int x;
	while (cin >> x) {
		V.push_back(x);
	}
	vector<int> R = uniquify(V);
	for (size_t i = 0; i < R.size(); i++) {
		cout << R[i] << " ";
	}
	cout << "\n";
	return 0;
}
