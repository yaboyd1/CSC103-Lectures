/* problem 5(b) */

void insertFront(node*& L, int x)
{
	// L = new node; // no good -- would lose the list!
	node* n = new node;
	/* set data to x: */
	n->data = x; /* step 1 */
	n->next = L; /* step 2 */
	L = n; /* step 3 */
}

/* # 6 */
int findSubstring(const string& s1, const string& s2)
{
	/* NOTE: possible indexes where a match might begin:
	 * 0...s1.len - s2.len (inclusive) */
	for (int i = 0; i < s1.length() - s2.length(); i++) {
		/* now check for match starting @i */
		bool match = true; /* optimism. */
		for (size_t j = 0; j < s2.length(); j++) {
			if (s2[j] != s1[i+j]) {
				match = false;
				break;
			}
		}
		/* now we know if there was a match @i */
		if (match) return i;
	}
	return -1; /* never found a match */
}
/* NOTE: look up Knuth Morris Pratt if you want to see
 * a smart way to do this. */

/* #7 */
void mergeSort(int* A, size_t n, int* aux)
{
	/* NOTE: aux is the destination for the merge... */
	/* check base case: */
	if (n < 2) return;
	/* compute mid point: */
	size_t m = n/2;
	/* recursively sort the subarrays A[0..m-1] and
	 * A[m,..,n-1] */
	mergeSort(A,m,aux);
	mergeSort(A+m,n-m,aux);
	merge(A,A+m,m,n-m,aux); /* now aux is sorted */
	/* finally copy aux back to A */
	for (size_t i = 0; i < n; i++) {
		A[i] = aux[i];
	}
	/* finally A is sorted :D */
}
