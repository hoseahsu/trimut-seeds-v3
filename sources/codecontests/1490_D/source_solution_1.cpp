#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " = " << (x) << endl
#define ll long long
#define mp make_pair
#define fi first
#define se second

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF INT_MAX

int tests;
int arrSize;
unordered_map<int, int> permutation, revn;
int depth[100];
int curIndex, curNum;

void build(int tl, int tr, int curDepth) {
	if (tl > tr || tl < 0 || tr >= arrSize) {
		return;
	}
	int curMax = 0;
	int maxIndex;
	for (int i = tl; i <= tr; ++i) {
		if (revn[i] > curMax) {
			curMax = revn[i];
			maxIndex = i;
		}
	}
	depth[maxIndex] = curDepth;
	build(tl, maxIndex-1, curDepth+1);
	build(maxIndex+1, tr, curDepth+1);
	return;
}

int main(void) {
	unordered_map<int, int>::iterator it;
	cin >> tests;
	while (tests--) {
		permutation.clear(); revn.clear();
		fill(depth, depth+100, 0);
		curIndex = 0;

		cin >> arrSize;
		for (int i = 0; i < arrSize; ++i) {
			cin >> curNum;
			permutation[curNum] = curIndex;
			revn[curIndex] = curNum;
			++curIndex;
		}
		build(0, arrSize-1, 0);
		for (int i = 0; i < arrSize; ++i) {
			cout << depth[i] << " ";
		}
		cout << "\n";
	}
}