#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

void printVector(const vector<int> V);
void reverse(vector<int>& V);
vector<int> uniquify(const vector<int>& V);
void push_front(vector<int>& V, int input);
bool exprSum(const vector<int> V, int input);
bool search(const vector<int> V, int input);

int main() {
  vector<int> vector = {3,3,3,2,2,1};
  push_front(vector, 4);
  push_front(vector, 5);

  cout << "The original vector is: " << endl;
  printVector(vector);
  cout << endl;

  cout << "Reversing the vector: " << endl;
  reverse(vector);
  printVector(vector);
  cout << endl;

  cout << "Unqifying the vector: " << endl;
  printVector(uniquify(vector));
  cout << endl;

  cout << "Are there two elements that add up to 6?" << endl;
  cout << exprSum(vector, 6);
  cout << endl;

  cout << "Is there an element that is 4?" << endl;
  cout << exprSum(vector, 4);
  cout << endl;

	return 0;
}

void printVector(const vector<int> V) {
  //Prints the given vector
  for (size_t i = 0; i < V.size(); i++) {
    cout << V[i] << " ";
  }
}

void reverse(vector<int>& V) {
  //Reverses the given vector (CLASS)
	size_t n = V.size();
	for (size_t i = 0; i < n/2; i++) {
		//Swap V[i] with V[n-i-1]
		V[i]     ^= V[n-i-1];
		V[n-i-1] ^= V[i];
		V[i]     ^= V[n-i-1];
    // ^= is xor
	}
}

vector<int> uniquify(const vector<int>& V) {
  //Returns unique values of vector (CLASS)
	vector<int> U;
  //If empty, return itself
	if (V.size() == 0)
    return U;
  //Set first value
	U.push_back(V[0]);
	//Iterate and scan
	for (size_t i = 1; i < V.size(); i++) {
    //If V is different from last, put it in U
		if (V[i] != U[U.size()-1])
			U.push_back(V[i]);
	}
	return U;
}

void push_front(vector<int>& V, int input) {
  //Pushes a value into the front of a vector
  V.push_back(input);
  size_t n = V.size();
  //Swap with the last element
  for (size_t i = 0; i < n; i++) {
    int temp = V[i];
    V[i] = V[V.size() - 1];
    V[V.size() - 1] = temp;
  }
}

bool exprSum(const vector<int> V, int input) {
  //Can given value be expressed as a sum of two elements
  for (size_t i = 0; i < V.size(); i++) {
    for (size_t j = i; j < V.size(); j++) {
      if (i != j && V[i] + V[j] == input) {
        return true;
      }
    }
  }
  return false;
}

bool search(const vector<int> V, int input) {
  //Linearly searches for a value
  for (size_t i = 0; i < V.size(); i++) {
    if (V[i] == input) {
      return true;
    }
  }
  return false;
}

void unique(vector<int>& V) {
  //Uniquify but modifies in place
  for (size_t i = 1; i < V.size(); i++) {
    //If equal to the previous term...
    if (V[i] == V[i-1]) {
    }
  }

}