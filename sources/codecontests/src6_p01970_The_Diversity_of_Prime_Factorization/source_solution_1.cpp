#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

list<int> Prime(int num) {
	list<int>P;
	for (int i = 5; i <= num; i += 6) {
		bool flag = true;
		for (auto j : P) {
			if (j*j > i) {
				break;
			}
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i);
		flag = true;
		for (auto j : P) {
			if (j*j > i + 2) {
				break;
			}
			if ((i + 2) % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i + 2);
	}
	P.push_front(3);
	P.push_front(2);
	return P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	list<int>P = Prime(1000000);
	vector<bool>flag(1000001);
	for (auto i : P) {
		if (i > 1000000) {
			break;
		}
		flag[i] = true;
	}
	cin >> N;
	vector<int>v(N + 4);
	v[0] = 0;
	v[N + 1] = MOD;
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	vector<long long int>dp(N + 4);
	dp[0] = 1;
	for (int i = 0; i <= N; i++) {
		if (!i){
			if (flag[v[1]]) {
				dp[1] = 1;
			}
			continue;
		}
		if (v[i] < v[i + 1]) {
			if (v[i + 1] == MOD || flag[v[i + 1]]) {
				dp[i + 1] += dp[i];
				dp[i + 1] %= MOD;
			}
		}
		if (v[i] < v[i + 2]) {
			if (v[i + 2] == MOD || flag[v[i + 2]]) {
				dp[i + 2] += dp[i];
				dp[i + 2] %= MOD;
			}
		}
	}
	cout << dp[N + 1] << endl;
	return 0;
}
