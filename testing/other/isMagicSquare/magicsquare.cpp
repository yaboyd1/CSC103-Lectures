#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

bool isMagicSquare(vector<vector<int> > A);

int main() {
  vector<vector<int> > A = {
    {2,7,6},
    {9,5,1},
    {4,3,8}
  };

  vector<vector<int> > B = {
    {1,1},
    {1,1}
  };

  if (isMagicSquare(A)) cout << "A is a magic square!\n";
  else cout << "A is not a magic square\n";

  if (isMagicSquare(B)) cout << "B is a magic square!\n";
  else cout << "B is not a magic square\n";

}

bool isMagicSquare(vector<vector<int> > A) {

  size_t size = A.size();

  int magicSum = 0;
  for (size_t i = 0; i < size; i++) {
    magicSum += A[0][i];
  }

  int rowSum = 0, colSum = 0, diagnolSum1 = 0, diagnolSum2 = 0;
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      rowSum += A[i][j];
      colSum += A[j][i];
    }
    if (rowSum != magicSum || colSum != magicSum)
      return false;
    rowSum = 0;
    colSum = 0;
    diagnolSum1 += A[i][i];
    diagnolSum2 += A[size-1-i][size-1-i];
  }

  if (diagnolSum1 != magicSum || diagnolSum2 != magicSum)
    return false;

  return true;
}