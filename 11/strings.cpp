#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;

/* If t is a substring of s, this function should return the location
 * (index) of the first match.  If t is not a substring of s, return -1. */
size_t find(const string& s, const string& t)
{
	for (size_t i = 0; i < s.length() - t.length() + 1; i++) {
		size_t j;
		for (j = 0; j < t.length(); j++) {
			if (s[i+j] != t[j]) {
				break;
			}
		}
		if (j == t.length()) {
			return i;
		}
	}
	return -1;
}

/* TODO: try to re-write this function from scratch (refer to the
 * notes from lecture as little as possible). */


/* TODO: write the following function which converts all lower
 * case letters to upper case.  NOTE: there are library functions
 * that will convert a single character (see 'man 3 toupper'),
 * but it might be more instructive to do it without using those.
 * If doing it without the help of toupper, note that the offset
 * between lower/upper cases is simply 'A' - 'a' (remember, this
 * is a number...).
 * */
string YELL(string& s) {
	//Makes lowercase letters uppercase
	int offset = 'A' - 'a';
	for (size_t i = 0; i < s.length(); i++) {
		for (int j = 'a'; j <= 'z'; j++) {
			if (s[i] == j) {
				s[i] = s[i] + offset;
			}
		}
	}
	return s;
}

/* TODO: write a function that takes a string and returns a boolean
 * indicating whether or not it was a palindrome.
 * */

bool palindrome(const string& s) {
	//Returns true if palidrome
	for (size_t i = 0; i < s.length() / 2; i++)
		if (s[i] != s[s.length() - 1 - i])
			return false;
	return true;
}

int main()
{
	string s,t;
	cout << "Enter larger string: ";
	cin >> s;
	cout << "Enter target string: ";
	cin >> t;

	size_t i = find(s,t);
	if (i == size_t(-1)) {
		cout << "Target string \"" << YELL(t) << "\" not found in larger string \"" << YELL(s) << "\".\n";
	} else {
		cout << "Target string \"" << YELL(t) << "\" was found in larger string \"" << YELL(s) << "\" at index " << i << ".\n";
	}

	if (palindrome(s)) {
		cout << "\"" << s << "\" is a palindrome.\n";
	}
	if (palindrome(t)) {
		cout << "\"" << t << "\" is a palidrome.\n";
	}

	return 0;
}
