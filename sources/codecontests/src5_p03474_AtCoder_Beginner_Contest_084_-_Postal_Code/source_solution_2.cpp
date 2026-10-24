#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	string s;
	cin >> a >> b >> s;

	if (s.find("-")==a and s.find("-", a+1)==string::npos) cout << "Yes" << endl;
	else cout << "No" << endl;
}