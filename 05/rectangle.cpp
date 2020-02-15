/* print a rectangle of '*' characters. */
#include <iostream>
using std::cin;
using std::cout;

int main()
{
	int n,m;
	cin >> n >> m;
	/* now print n rows of m stars. */
	int i = 0, j = 0;
	while (i < n) {
		/* print a row of m stars. */
		while (j < m) {
			cout << "* ";
			j++;
		}
		cout << "\n";
		i++;
	}
	return 0;
}

/* TODO: I left the above broken on purpose.  Fix it. */
/* TODO: rewrite this program using for loops instead.
 * (Maybe make a new file named "rectangle2.cpp" for this.) */
