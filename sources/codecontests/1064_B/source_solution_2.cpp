#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
const int MOD = 1e9 + 7;
priority_queue<pair<long long int, int> > pq;
vector<pair<long long int, long long int> > vp;
map<long long int, long long int> mp, mpp;
long long int dp[N];
vector<long long int> v, v1, v2;
stack<long long int> s, s1;
long long int visit[N];
struct domingo {
  int val, left, right;
} o[N];
long long int BIT[N];
long long int seg_tree[4 * N];
set<long long int> se[250];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, val, k, d, mi = 1e9, mx(0);
  long long int sum(0), ct(0), p(0), q(0);
  string s;
  long long int a, b, c;
  int t;
  cin >> t;
  for (int i = 0; i <= 31; i++) {
    long long int po = powl(2, i);
    po--;
    mp[po]++;
  }
  while (t--) {
    long long int a;
    cin >> a;
    int p = (__builtin_popcount((a)));
    cout << (long long int)powl(2, p) << endl;
  }
}
