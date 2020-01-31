/* goal: read name from standard input, and print
 * message containing name to standard output. */

#include <iostream>
using std::cout;
using std::cin;
#include <string>
using std::string;
/* NOTE: use string to store strings of characters. */

int main()
{
	string name; /* NOTE: string is not a built-in type.  We have
	                to #include <string> to use it. */
	cout << "enter name: ";
	cin >> name;
	cout << "hello " << name << "!!!\n";
	return 0;
	/* TODO: reverse the arrows in a cin or cout statement, and take note
	 * of the lengthy error message. */
	/* TODO: go finish project 1! */
}
