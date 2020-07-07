/* TODO: write down the polynomial evaluation function we did in lecture
 * and write a main function to test it out.  Below is a prototype:
 * */

#include <vector>
using std::vector;
#include <iostream>
using std::cout;

/* evaluate f(x) = a[0] + a[1]x + a[2]x^2 + ... */
/*
int polyEval(const vector<int>& a, int x)
{
 int sum = a[a.size() - 1];
 for (size_t i = 1; i < a.size(); i++) {
  sum = sum * x + a[a.size()-1-i];
 }
	return sum;
}
*/
/*
 * 4
 * x(4)+3
 * x(4x+3)+2
 * x(x(4x+3)+2)+1
 */


int polyEval(const vector<int>& a, int x) {
 int sum;
 for (size_t i = 0; i < a.size(); i++) {
  sum;
 }
 return sum;
}


int main() {
 vector<int> poly = {1,2,3,4};
 int value = 2;
 cout << polyEval(poly, value) << "\n";
 return 0;
}