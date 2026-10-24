#include <iostream>
using namespace std;

int main() {
	string s;
	int ns = 0, np = 0;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'S') ns++;
		if(s[i] == 'T') {
			if(ns > 0) {
				ns--;
				np++;
			}
		}
	}
	cout << (s.size() - 2 * np) << endl;
}