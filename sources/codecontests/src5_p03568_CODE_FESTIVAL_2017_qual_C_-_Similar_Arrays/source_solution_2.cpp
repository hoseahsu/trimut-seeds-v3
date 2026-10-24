#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,x;
	long long a=1,b=1;
	cin >> n;
	while (n--) {
		a *= 3;
		cin >> x;
		if (x%2==0) b *= 2;
	}
	cout << a-b << endl;
	return 0;
}