#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;

/* If t is a substring of s, this function should return the location
 * (index) of the first match.  If t is not a substring of s, return -1. */
size_t find(const string& s, const string& t)
{
	/* TODO: try to re-write this function from scratch (refer to the
	 * notes from lecture as little as possible). */
	return -1;
}

/* TODO: write the following function which converts all lower
 * case letters to upper case.  NOTE: there are library functions
 * that will convert a single character (see 'man 3 toupper'),
 * but it might be more instructive to do it without using those.
 * If doing it without the help of toupper, note that the offset
 * between lower/upper cases is simply 'A' - 'a' (remember, this
 * is a number...).
 * */
void YELL(string& s) {
	/* make all lower case chars upper case. */
}

/* TODO: write a function that takes a string and returns a boolean
 * indicating whether or not it was a palindrome.
 * */

int main()
{
	string s,t;
	cout << "enter larger string: ";
	cin >> s;
	cout << "enter target string: ";
	cin >> t;
	size_t i = find(s,t);
	if (i == size_t(-1)) {
		cout << "target " << t << " not found.\n";
	} else {
		cout << "target " << t << " found at index " << i << ".\n";
	}
	/* TODO: write test code for the other exercises here. */
	return 0;
}
