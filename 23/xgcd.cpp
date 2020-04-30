#include <iostream>
using std::cin;
using std::cout;

/* return d = gcd(a,b); set x,y such that xa+yb = d */
int xgcd(int a, int b, int& x, int& y)
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int xx,yy,q=a/b,r=a%b;
	int d = xgcd(b,r,xx,yy); /* xx*b + yy*r = d */
	x = yy;
	y = xx - q*yy;
	return d;
}

int main()
{
	int a,b,x,y,d;
	while (cin >> a >> b) {
		d = xgcd(a,b,x,y);
		printf("gcd(%i,%i) = %i = %i*%i + %i*%i\n",a,b,d,x,a,y,b);
	}
	return 0;
}

/* TODO: try to re-write this whole thing from scratch.
 * TODO: finish the project : ) */
