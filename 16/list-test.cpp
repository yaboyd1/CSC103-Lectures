#include <iostream>
using std::cin;
using std::cout;

struct node {
	int data;
	node* next;
};

int main(void)
{
	/* read all integers from stdin into a list */
	node* L = NULL;
	int x;
	while (cin >> x) {
		/* do steps 1 -- 4 */
		node* n = new node; /* step 1 */
		n->data = x; /* step 2 */
		n->next = L; /* step 3 */
		L = n; /* step 4 */
	}

	node* p = L;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	return 0;
	/* TODO: make sure you understand all this! */
}

/* TODO: write another program, similar to the above, which reads all
 * of stdin into a list *in the same order* (the above reverses the
 * order). */
/* TODO: make sure you have understood the most recent additions to
 * the ../whatstheoutput/ directory ({6,7}.cpp, I think). */
