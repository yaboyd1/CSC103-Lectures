#include <cstdio>

/* NOTE: if you have the graphviz package, you can render the call graph
 * using a command like this:
 * $ ./9-dot 3>&2 2>&1 1>&3 | dot -Tsvg -o /tmp/call-graph.svg
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

size_t f(size_t m, size_t n)
{
	RTRACE_BEGIN("%lu,%lu",m,n);
	if (m == 0) RTRACE_RET(n+1);
	if (n == 0) RTRACE_RET(f(m-1,1));
	RTRACE_RET(f(m-1,f(m,n-1)));
}

int main()
{
	printf("%lu\n",f(3,2));
	// printf("%lu\n",f(2,2));
	return 0;
}
