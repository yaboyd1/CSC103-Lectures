#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

/* TODO: finish writing this example from class.  Ideally, try to
 * write it from scratch using the ideas from lecture.  Also, try
 * to extend it to account for newlines (in addition to space and
 * tab characters for white space). */
size_t wordcount(const string& s)
{
  bool space = true;
  size_t count = 0;
  for (size_t i = 0; i < s.length(); i++) {
    if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
      space = true;
    }
    else if (space == true) {
      space = false;
      count++;
    }
  }
	return count;
}

/* TODO: write this modified version of wordcount, which stores the
 * words in a vector in addition to returning the count.  */
/*
size_t wordcount(const string& s, vector<string>& l)
{
  bool space = true;
  size_t count = 0;
  string word;
  for (size_t i = 0; i < s.length(); i++) {
    if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
      space = true;
      l.push_back(word);
      word = "";
    }
    else if (space == true) {
      space = false;
      count++;
    }
    else if (space == false) {
      word += s[i];
    }
  }
	return count;
}
*/


size_t wordcount(const string& s, vector<string>& l)
{
  bool justReadSpace = true;
  size_t count = 0;
  string currentWord;
  for (size_t i = 0; i < s.length(); i++) {
    if (justReadSpace) {
      if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t') {
        justReadSpace = false;
        currentWord += s[i];
        count++;
      }
    } else {
      if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
        justReadSpace = true;
        l.push_back(currentWord);
        currentWord = "";
      } else {
        currentWord += s[i];
      }
    }
  }

  if (currentWord.length() > 0) {
    l.push_back(currentWord);
  }

	return count;
}


int main()
{
	/* TODO: test code for the above goes here. */
  vector<string> words;
  string s = "please count   the      correct  number of  words";

  size_t count = wordcount(s, words);

  cout << "There are "<< count << " words in this string: " << endl;
  for (size_t i = 0; i < words.size(); i++) {
    cout << words[i] << endl;
  }
	return 0;
}

/* TODO: (this could be a little challenging...) Try to write
 * a program that reads C/C++ source and removes the comments.
 * Look at the last diagram from lecture for inspiration.
 * */
