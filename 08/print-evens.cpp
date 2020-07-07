/* testing out vectors... */
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;

/* write a function that takes a vector of integers as input and
 * returns another vector containing only the *even* elements. */
vector<int> evens(vector<int> V)
{
	vector<int> output; /* we'll return this vector */
	for (size_t i = 0; i < V.size(); i++) {
		if (V[i] % 2 == 0) {
			output.push_back(V[i]);
		}
	}
	return output;
}

/* NOTE: a better prototype for the above would have been this:
 * vector<int> evens(const vector<int>& V);
 * TODO: can you guess why?  (Hint: it is about efficiency...)
 * */

int main()
{

	vector<int> test;

	for (int i = 0; i < 11; i++) {
		test.push_back(i);
	}

	test = evens(test);

	for (size_t i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}

	return 0;
}
