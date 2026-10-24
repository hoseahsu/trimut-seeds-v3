#include "bits/stdc++.h"
using namespace std;

int N;

void DFS(int P, int Q, string S) {
	if (P == N) {
		cout << S << endl;
		return;
	}
	for (int i = 0; i <= Q + 1; i++) {
		DFS(P + 1, max(Q, i), S + (char)('a' + i));
	}
}

int main() {
	cin >> N;
	DFS(0, -1, "");
}
