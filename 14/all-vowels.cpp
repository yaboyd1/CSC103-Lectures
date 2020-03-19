#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;

bool all_vowels(const string& s)
{
	bool T[256];
	for (size_t i = 0; i < 256; i++) T[i] = false;
	for (size_t i = 0; i < s.length(); i++) T[(size_t)s[i]] = true;
	return (T['a'] && T['e'] && T['i'] && T['o'] && T['u']);
}

int main(void)
{
	string s;
	while (cin >> s) {
		if (all_vowels(s))
			cout << s << " contained all vowels.\n";
		else
			cout << s << " did not contain all vowels.\n";
	}
	return 0;
}
