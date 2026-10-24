#include "bits/stdc++.h"
using namespace std;
bool valid(int x, int y, int n) {
	return x >= 0 && x < n&&y >= 0 && y < n;
}
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
void fi(vector<vector<int>>&field, int x, int y) {
	int uad = 0;
	const int uy = y - 1;
	const int ux = x;
	for (int way = 0; way < 3; ++way) {
		if (valid(ux + dx[way], uy + dy[way], field.size()) &&
			field[uy][ux] == field[uy + dy[way]][ux + dx[way]])uad++;
	}
	if (uad == 0 || uad == 3)assert(false);
	else if (uad == 1) {
		field[y][x] = field[uy][ux];
	}
	else {
		field[y][x] = !field[uy][ux];
	}
}
void solve(vector<vector<int>>&field) {
	for (int n = 0; n < field.size(); ++n) {
		for (int k = 1; k <= n-1; ++k) {
			int nowy = k;
			int nowx = n - k;
			fi(field, nowx, nowy);
		}
	}
	for (int n = field.size(); n < 2 * field.size()-1; ++n) {
		for (int k = 1; k < 2*field.size()-n; ++k) {
			int nowy = k+n-field.size();
			int nowx = field.size()-k;
			fi(field, nowx, nowy);
		}
	}
}

int main() {
	while (1) {
		int N; cin >> N;
		long long int K; cin >> K;
		K--;
		if (!N)break;
		if (1ll << (N/2) <= K||N%2)cout << "No" << endl;
		else {
			bitset<64>bs(K);
			vector<vector<int>>field(N, vector<int>(N,-1));
			for (int i = 0; i < N/2; ++i) {
				for (int j = 0; j < 2; ++j) {
					field[0][i * 2+j ] = bs[N/2-1-i];
					field[i*2+j][0] = bs[N/2-1-i];
				}
			}
			solve(field);
			for (int y = 0; y < N; ++y) {
				for (int x = 0; x < N; ++x) {
					if (!field[y][x])cout << '.';
					else cout << 'E';
				}
				cout << endl;
			}
		}
		cout << endl;
	}
	return 0;
}