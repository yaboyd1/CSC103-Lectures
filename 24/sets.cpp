#include <set>
using std::set;
#include <iostream>
using std::cin;
using std::cout;

/* TODO: practice with sets.  As a very simple example, try to rewrite
 * `sort -u` with sets (just read all lines into a set, and then print
 * it back out!) */

int main()
{

 set<int> S;

 int x;
 while (cin >> x) {
  S.insert(x);
 }

 for(set<int>::iterator i = S.begin(); i != S.end(); i++) {
  printf("%i ", *i);
 }

 return 0;
}