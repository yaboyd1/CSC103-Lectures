#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;

/* NOTE: we assume that V is sorted!  If not, behavior is undefined. */
void uniquify(vector<int>& V)
{
	if (V.size() < 2) return;
	size_t g=1; /* green arrow; stores destination for next unique value */
	size_t b=1; /* blue arrow; stores next place to look for something new */
	while (b < V.size()) {
		if (V[g-1] != V[b])
			V[g++] = V[b];
		b++;
	}
	/* now just need to resize V... */
	V.resize(g);
}

int main(void)
{
	/* add test code... */
	int x;
	vector<int> V;
	while (cin >> x) {
		V.push_back(x);
	}
	uniquify(V);
	for (size_t i = 0; i < V.size(); i++) {
		cout << V[i] << " ";
	}
	cout << "\n";
	return 0;
}
