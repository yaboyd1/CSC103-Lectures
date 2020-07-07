#include <iostream>
using std::cin;
using std::cout;

struct node {
	int data;
	node* next;
};

/* L is a pointer to the first node */
void reverse(node*& L)
{
	/* take care of special case for empty list: */
	if (L == NULL) return;
	node* q = NULL;
	node* p = L; /* first node */
	node* r = L->next; /* second node (might be null) */
	while (r) {
		p->next = q; /* step 1 */
		q = p;       /* step 2 */
		p = r;       /* step 3 */
		r = r->next; /* step 4 */
	}
	L = p; /* make L point to the new first node */
	/* reverse final node (p) */
	p->next = q;
	/* TODO: delete this and write it from scratch */
}

int main(void)
{
	/* read stdin into list (forward order), with NO special case
	 * for the first node */
	int y; /* for input */
	node* L = NULL; /* pointer to beginning of list */
	node** x; /* pointer to final arrow where next node would
	             be attached. */
	x = &L;
	while (cin >> y) {
		*x = new node;
		(*x)->data = y;
		x = &(*x)->next;
	}
	*x = NULL;
	/* TODO: turn the above (code for reading stdin into a list)
	 * into a function, and also try the alternative method to
	 * remove special cases: use a "fake" node at the beginning. */

	/* try to reverse it */
	reverse(L);
	/* print everything back out to make sure it worked: */
	for (node* i = L; i != NULL ; i = i->next) {
		cout << i->data << " ";
	}
	cout << "\n";
	return 0;
}

/* TODO: write a function that *copies* a list.  It should allocate
 * a new set of nodes with the same values in the same order, and
 * return a pointer to the start of the new list.  Here's a prototype: */
node* copy(node* L)
{
	node* C = new node();
	node* start = C;
	for (node* i = L; i->next != NULL; i = i->next) {
		C->data = i->data;
		C->next = new node();
		C = C->next;
	}
	return start; /* just so it compiles... */
}
