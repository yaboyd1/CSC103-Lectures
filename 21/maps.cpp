#include <iostream>
using std::cin;
using std::cout;
#include <map>
using std::map;
#include <string>
using std::string;

/* motivational example for maps: making a frequency table of strings. */

int main()
{
	map<string,int> F; /* frequency table. */
	string s; /* for input */
	while (cin >> s)
		F[s]++;
	/* NOTE: it is crucial that accessing F[s] will initialize the
	 * value to 0 if we have never before accessed it. */
	/* now we just need to print it! */
	for (map<string,int>::iterator i = F.begin(); i != F.end() ; i++) {
		cout << (*i).first /* index */ << ": "
			<< (*i).second /* value */ << "\n";
	}
	return 0;
}

/* TODO: try to solve this problem *without* maps, and instead just
 * using vectors.  Should you succeed, estimate the number of steps
 * your program takes to process an input of n strings.  */
/* TODO: try to make a histogram (visual display of the frequencies)
 * instead of just a frequency table. */
/* TODO: Compare/contrast vector<int> with map<int,int>.  (This does not
 * involve programming, just thinking.) */
