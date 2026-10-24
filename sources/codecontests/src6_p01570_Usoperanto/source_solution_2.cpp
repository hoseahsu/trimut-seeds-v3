/* **********************************************

  File Name: j.cpp

  Auther: zhengdongjian@tju.edu.cn

  Created Time: 2015??´10???03??\ ????????? 09??¶57???17?§?

*********************************************** */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1000007;
struct Node {
	int len;
	int to;
} a[MAX];
ll bb[MAX << 1];
int stk[MAX];
vector<int> G[MAX];
vector<int> bakup[MAX];

ll dfs(int u) {
	int top = 0;
	stk[++top] = u;
	ll res = 0LL;
	while (top > 0) {
		u = stk[top];
		//printf("top = %d, u = %d\n", top, u);
		if (G[u].empty()) {
			int tail = 0;
			for (int i = 0; i < (int)bakup[u].size(); ++i) {
				bb[tail++] = a[bakup[u][i]].len;
				a[u].len += a[bakup[u][i]].len;
			}
			ll tp = 0LL;
			sort(bb, bb + tail);
			for (int i = 0; i < tail; ++i) {
				res += tp;
				tp += bb[i];
			}
			--top;
		} else {
			int v = *G[u].rbegin();
			G[u].pop_back();
			stk[++top] = v;
		}
	}
	return res;
}
/*
ll dfs(int u) {
	multiset<ll> st;
	ll res = 0LL;
	ll son = 0LL;
	for (int i = 0; i < (int)G[u].size(); ++i) {
		int& v = G[u][i];
		res += dfs(v);
		st.insert(a[v].len);
		son += a[v].len;
	}
	int sz = st.size() - 1;
	for (multiset<ll>::iterator it = st.begin(); it != st.end(); ++it) {
		res += (*it) * (sz--);
	}
	a[u].len += son;
	//fprintf(stderr, "dfs %d: len = %d, res = %lld\n", u, a[u].len, res);
	return res;
}
*/

int main() {
	int n;
	while (~scanf(" %d", &n)) {
		for (int i = 0; i < n; ++i) {
			G[i].clear();
			bakup[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			scanf(" %d %d", &a[i].len, &a[i].to);
			if (a[i].to != -1) {
				G[a[i].to].push_back(i);
				bakup[a[i].to].push_back(i);
			}
		}
		ll sum = 0LL;
		for (int i = 0; i < n; ++i) {
			if (a[i].to == -1) {
				sum += dfs(i);
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}