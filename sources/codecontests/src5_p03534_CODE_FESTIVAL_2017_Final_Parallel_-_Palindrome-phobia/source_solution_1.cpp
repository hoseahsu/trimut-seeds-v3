#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	int X[3] = {};
	cin >> S;
	for (int i = 0; i < S.size(); i++) X[S[i] - 'a']++;
	sort(X, X + 3);
	if (X[2] - X[0] <= 1) cout << "YES";
	else cout << "NO";
}