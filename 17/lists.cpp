#include <iostream>
using std::cin;
using std::cout;

struct node {
	int data;
	node* next;
};

/* exercise: read all of stdin into a list (preserving the order) */

int main(void)
{
	int x; /* for input */
	node* L = NULL; /* pointer to beginning of list */
	node* last = NULL; /* invariant: pointer to last node */
	if (cin >> x) {
		L = new node;
		L->data = x;
		last = L;
	}
	/* now the general case; we attach new nodes to last->next */
	while (cin >> x) {
		last->next = new node;
		last = last->next;
		last->data = x;
	}
	last->next = NULL;
	/* print everything back out to make sure it worked: */
	for (node* i = L; i != NULL ; i = i->next) {
		cout << i->data << " ";
	}
	cout << "\n";
	return 0;
}

/* TODO: try to write the above *without* any special case for the
 * first node.  Option 1: use a "dummy" node as the first node. Its
 * value won't be considered part of the list.  Option 2: instead of
 * having last be of type node*, make it of type node** so that it
 * tells you not what node is last, but instead what _pointer_ is
 * the last one in the list.  You might find this approach tricky
 * (and I'm not sure I'd recommend doing things this way), but I
 * think it is good practice! */
/* TODO: check out project 4 and ask questions on piazza if you have
 * them. */
/* TODO: read l4.pdf if you haven't already */
