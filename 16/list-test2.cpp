#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/* TODO: write another program, similar to the above, which reads all
 * of stdin into a list *in the same order* (the above reverses the
 * order). */
/* TODO: make sure you have understood the most recent additions to
 * the ../whatstheoutput/ directory ({6,7}.cpp, I think). */

struct node {
	int data;
	node* next;
};

void insertNext(node*& L, int input) {
	L->next = new node;
	L = L->next;
	L->data = input;
}

void printList(node*& L) {
	for (node* i = L; i != NULL; i = i->next) {
		cout << i->data << " ";
	}
}

int main(void)
{

	node* L = NULL;
	node* start = NULL;
	int x;

	if (cin >> x) {
		L = new node;
		L->data = x;
		start = L;
	}

	while(cin >> x) {
		insertNext(L, x);
	}

	printList(start);
	cout << endl;

	return 0;

}