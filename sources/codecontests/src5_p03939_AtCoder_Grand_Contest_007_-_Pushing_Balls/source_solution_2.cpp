#include <iostream>
#include <cstdio>
using namespace std; 
int main()
{
	double n, d1, x, ans = 0; 
	scanf("%lf%lf%lf", &n, &d1, &x); 
	while (n)
	{
		ans += d1 + (n - 0.5) * x; 
		d1 = ((n + 1) * d1 + 2.5 * x) / n; 
		x *= 2.0 / n + 1; 
		n--; 
	}
	printf("%.12lf\n", ans); 
	return 0; 
}
