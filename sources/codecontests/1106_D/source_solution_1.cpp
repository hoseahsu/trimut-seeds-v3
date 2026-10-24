#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const int mod = 1000000007;
const int mod2 = 998244353;
const double eps = 1e-9;
const double pi = acos(-1.0);
inline int rint() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long rll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline long long ri64() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
void rvi(vector<int> &a, int n) {
  for (int i = 0; i < n; i++) {
    a.push_back(rint());
  }
}
void rvll(vector<long long> &a, int n) {
  for (int i = 0; i < n; i++) {
    a.push_back(rll());
  }
}
void showvi(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    printf("%d%c", a[i], (i + 1 == a.size() ? '\n' : ' '));
  }
}
void showvll(vector<long long> &a) {
  for (int i = 0; i < a.size(); i++) {
    printf("%lld%c", a[i], (i + 1 == a.size() ? '\n' : ' '));
  }
}
void showviln(vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    printf("%d%c", a[i], '\n');
  }
}
void showvllln(vector<long long> &a) {
  for (int i = 0; i < a.size(); i++) {
    printf("%lld%c", a[i], '\n');
  }
}
void showi(int x) { printf("%d", x); }
void cfinit() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
priority_queue<int, vector<int>, greater<int> > pq;
int n, m;
vector<int> v[100011];
int vis[100011];
void add(int p) {
  cout << p << " ";
  vis[p] = 1;
  for (int i = 0; i < (v[p].size()); i++)
    if (vis[v[p][i]] == 0) pq.push(v[p][i]);
}
int main() {
  cfinit();
  cin >> n >> m;
  for (int i = 0; i < (m); i++) {
    int l, r;
    cin >> l >> r;
    v[l].push_back(r);
    v[r].push_back(l);
  }
  add(1);
  for (int i = 0; i < (n - 1); i++) {
    while (vis[pq.top()]) pq.pop();
    int fk = pq.top();
    pq.pop();
    add(fk);
  }
  return 0;
}
