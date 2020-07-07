#include<iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

bool search(vector<int> vector, int n);
vector<int> unique(vector<int> vector);

int main() {

  vector<int> test;

	for (int i = 0; i < 11; i++) {
		test.push_back(i);
    test.push_back(i);
	}

  bool is5here = search(test, 5);

  cout << is5here << endl;

  test = unique(test);

  for (size_t i = 0; i < test.size(); i++) {
    cout << test[i] << " ";
  }

  return 0;
}

/* TODO: write a function that takes a vector and searches for
 * a particular value x, returning true if and only if x is found. */
bool search(vector<int> vector, int n) {
  //Iterate, if found, true
  for (size_t i = 0; i < vector.size(); i++) {
    if (vector[i] == n) {
      return true;
    }
  }
  return false;
}

/* TODO: write a function that takes a vector V of integers which
 * is *sorted*, and produces a vector of the unique integers from V.
 * E.g., if V = {1,2,2,3,3,3,4}, then the result should
 * be {1,2,3,4}.  Ideally, modify the vector *in-place*.
 * That is, modify the vector V that is given to the function directly,
 * and don't create any new vectors.  As a warm up: return a new vector with
 * the
 * result.
 * */

vector<int> unique(vector<int> vector) {
  //set first value
  //if next value is equal to dif
  //swap with last and popback
  int dif = vector[0];
  for (size_t i = 1; i < vector.size(); i++) {
    if (vector[i] == dif) {
      vector.push_back(vector[i]);
    }
  }
  return vector;
}
