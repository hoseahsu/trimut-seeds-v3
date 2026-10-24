#include<iostream>
#include<string>
using namespace std;
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size() - 1; j++) {
			if (s[j] == s[j + 1]) {
				cout << "No\n";
				goto end;
			}
		}
		cout << "Yes\n";
	end:;
	}
}