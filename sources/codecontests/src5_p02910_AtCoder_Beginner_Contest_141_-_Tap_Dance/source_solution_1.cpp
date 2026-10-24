#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	for (int i = 0; i < (int) s.size(); i++) {
		if ((i % 2 && s[i] == 'R') || (i % 2 == 0 && s[i] == 'L')) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}
