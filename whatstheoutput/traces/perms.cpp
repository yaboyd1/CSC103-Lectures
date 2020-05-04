#include <iostream>
using std::cout;
using std::cin;
#include <vector>
using std::vector;

/* NOTE: if you have the graphviz package, you can render the call graph
 * using a command like this:
 * echo 1 2 3 4 | ./perms 3>&2 2>&1 1>&3 | dot -Tsvg -o /tmp/perms.svg
 * (The strange redirections are to swap stdout and stderr so that normal
 * program output still shows up in your terminal, while the output from
 * the macros goes to the dot program.)
 * */

#define RTRACE_BEGIN(format,...) \
	static size_t id=0; \
	static size_t p=-1; \
	size_t t = id++; \
	if (p == (size_t)-1) { \
		fprintf(stderr,"digraph rtree {\n"); \
		fprintf(stderr,"  bgcolor=white;\n"); \
		fprintf(stderr,"  edge [color=black fontcolor=black];\n"); \
		fprintf(stderr,"  node [style=filled color=black fillcolor=slateblue1 shape=circle];\n"); \
	} \
	fprintf(stderr,"%lu [label=\"" format "\"]\n",t,__VA_ARGS__); \
	if (p != (size_t)-1) fprintf(stderr,"%lu -> %lu\n",p,t); \
	size_t op = p; /* save old value */ \
	p = t;

#define RTRACE_RET(x) \
{ \
	auto __rtrace_rv = x; \
	p = op; /* restore for next call */ \
	if (p == (size_t)-1) { \
		fprintf(stderr,"}\n"); \
	} \
	return __rtrace_rv; \
}

vector<vector<int> > perms(vector<int> V)
{
	/* XXX only works for single digit entries */
	char label[128];
	for (size_t i = 0; i < V.size(); i++) {
		label[i] = V[i]+'0';
	}
	label[V.size()] = 0;
	RTRACE_BEGIN("%s",label);
	vector<vector<int> > R; /* return value */
	if (V.size() == 1) RTRACE_RET(vector<vector<int> >(1,V));
	for (size_t i = 0; i < V.size(); i++) {
		int last = V[i];
		V[i] = V[V.size()-1];
		V.pop_back();
		vector<vector<int> > T = perms(V);
		for (size_t j = 0; j < T.size(); j++) {
			T[j].push_back(last);
			R.push_back(T[j]);
		}
		V.push_back(V[i]);
		V[i] = last;
	}
	RTRACE_RET(R);
}

int main()
{
	vector<int> V;
	int n;
	while (cin >> n) {
		V.push_back(n);
	}
	vector<vector<int> > R = perms(V);
	for (size_t i = 0; i < R.size(); i++) {
		for (size_t j = 0; j < R[i].size(); j++) {
			cout << R[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
