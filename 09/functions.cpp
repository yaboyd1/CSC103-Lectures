#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

vector<int> push_front(vector<int> V, int x);
bool expSum(vector<int> V, int x);
vector<int> unique(vector<int> V);

int main(void)
{
	vector<int> V = {2,2,3,3,3,4,5,5,7};

  /*
	int x;
	while (cin >> x) {
		V.push_back(x);
	}
  */

  vector<int> R = push_front(V, 1);
  bool found = expSum(R, 3);

	for (size_t i = 0; i < R.size(); i++) {
		cout << R[i] << " ";
	}

  cout << endl;

  vector<int> S = unique(R);

  for (size_t i = 0; i < S.size(); i++) {
		cout << S[i] << " ";
	}

	cout << endl;

  cout << found << endl;
	return 0;
}

/* TODO: write a function called "push_front(V,x)" for a vector, which
 * adds parameter x to index 0 of vector V by moving all the other values
 * to higher indexes.  (This should show you why inserting elements is only
 * efficient at the *end* of a vector.) */

vector<int> push_front(vector<int> V, int x) {
  V.push_back(x);
  size_t n = V.size();
  //Swap with last element
  for (size_t i = 0; i < n; i++) {
    int temp = V[i];
    V[i] = V[V.size() - 1];
    V[V.size() - 1] = temp;
  }
  return V;
}

/* TODO: write a function that takes a vector V (of integers) and a single
 * integer x, and returns a boolean value indicating whether or not x can
 * be expressed as the sum of two elements of V.  (Let's say you can't use
 * the same index twice, so you must find i =/= j such that x = V[i]+V[j].) */

bool expSum(vector<int> V, int x) {
  for (size_t i = 0; i < V.size(); i++) {
    for (size_t j = 0; j < V.size(); j++) {
      if (i != j) {
        if (x == V[i] + V[j]) {
          return true;
        }
      }
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

vector<int> unique(vector<int> V) {

  size_t n = V.size();

  for (size_t i = 1; i < n; i++) {
    //If equal to prev term
    if (V[i] == V[i-1]) {
      //Swamp and delete
      for (size_t j = i; j < n; j++) {
        int temp = V[j];
        V[j] = V[j-1];
        V[j-1] = temp;
      }
      V.pop_back();
    }
  }
  return V;
}

/* TODO: write a *binary search* on a sorted vector.  The idea is to
 * kind of emulate the process you use to find a particular page in a book:
 * 1. open the book to some page in the middle.
 * 2. if the page number was too high, open to the middle of the pages to the
 *    left; if it was too low, open to the middle of the pages to the right
 * 3. continue as above until you found the right page.
 *
 * This might be a little challenging.  Ask questions if you get stuck.
 * */