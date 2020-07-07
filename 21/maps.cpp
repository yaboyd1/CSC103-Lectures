#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <map>
using std::map;
#include <string>
using std::string;
#include <vector>
using std::vector;

/* motivational example for maps: making a frequency table of strings. */

void printHistogram(map<string,int> F);
void printVisualHistogram(map<string,int> F);
void frequencyWithMaps();
void frequencyWithVectors();

int main()
{

	//frequencyWithMaps();
	frequencyWithVectors();

	return 0;
}

void frequencyWithMaps() {
	map<string,int> F; /* frequency table. */
	string s; /* for input */
	while (cin >> s)
		F[s]++;
		/* NOTE: it is crucial that accessing F[s] will initialize the
		 * value to 0 if we have never before accessed it. */
		/* now we just need to print it! */

	printHistogram(F);
	printVisualHistogram(F);
}

void printHistogram(map<string,int> F) {
	for (map<string,int>::iterator i = F.begin(); i != F.end() ; i++) {
			cout << (*i).first /* index */ << ": "
				<< (*i).second /* value */ << "\n";
		}
}

/* TODO: try to solve this problem *without* maps, and instead just
 * using vectors.  Should you succeed, estimate the number of steps
 * your program takes to process an input of n strings.  */

void frequencyWithVectors() {
	vector<string> newWords;
	vector<int> freq;

	string s;
	while (cin >> s) {

		//search entire words list
		bool found = false;
		for (size_t i = 0; i < newWords.size(); i++) {
			//if found, add to freq
			if (newWords[i] == s) {
				freq[i]++;
				found = true;
				break;
			}
		}

		//if not found add to newWords list and make new freq
		if (!found) {
			newWords.push_back(s);
			freq.push_back(1);
		}
	}
	//print histogram
	for (size_t i = 0; i < newWords.size(); i++) {
		cout << newWords[i] << " : " << freq[i] << endl;
	}
}


/* TODO: try to make a histogram (visual display of the frequencies)
 * instead of just a frequency table. */

void printVisualHistogram(map<string,int> F) {
	for (map<string,int>::iterator i = F.begin(); i != F.end() ; i++)
	{
		for (int j = 0; j < (*i).second; j++) {
			cout << "*";
		}
		cout << " : " << (*i).first << endl;
	}
}

/* TODO: Compare/contrast vector<int> with map<int,int>.  (This does not
 * involve programming, just thinking.) */
