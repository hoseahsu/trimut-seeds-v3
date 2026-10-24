#include <bits/stdc++.h>
using namespace std;
long long n, m, cr[100055], ans[100055];
vector<long long> vr[100055];
map<string, long long> mr;
unordered_map<long long, long long> dis[100055];
vector<pair<long long, long long> > qr[100055];
vector<long long> root;
void inc(long long), dec(long long), dfs(long long, long long),
    func(long long, long long);
int main() {
  string str;
  long long p, tt = 0;
  scanf("%lld", &n);
  for (int i = 1; i < n + 1; i++) {
    cin >> str >> p;
    vr[p].push_back(i);
    if (mr.find(str) != mr.end())
      cr[i] = mr[str];
    else {
      cr[i] = tt;
      mr[str] = tt++;
    }
    if (p == 0) root.push_back(i);
  }
  scanf("%lld", &m);
  for (int i = 0; i < m; i++) {
    long long idx, d;
    scanf("%lld %lld", &idx, &d);
    qr[idx].push_back(make_pair(d, i));
  }
  for (int i = 0; i < root.size(); i++) {
    dfs(root[i], 0);
    func(root[i], 0);
  }
  for (int i = 0; i < m; i++) printf("%lld\n", ans[i]);
}
long long sr[100055], inv[100055], st[100055], ft[100055], dr[100055], tim = 0;
void dfs(long long idx, long long d) {
  dr[idx] = d;
  inv[tim] = idx;
  st[idx] = tim++;
  sr[idx] = 1;
  for (int i = 0; i < vr[idx].size(); i++) {
    dfs(vr[idx][i], d + 1);
    sr[idx] += sr[vr[idx][i]];
  }
  ft[idx] = tim;
}
void func(long long idx, long long keep) {
  long long m = 0, h = -1;
  for (int i = 0; i < vr[idx].size(); i++) {
    if (sr[vr[idx][i]] > m) {
      m = sr[vr[idx][i]];
      h = vr[idx][i];
    }
  }
  for (int i = 0; i < vr[idx].size(); i++) {
    if (vr[idx][i] != h) func(vr[idx][i], 0);
  }
  if (h != -1) func(h, 1);
  for (int i = 0; i < vr[idx].size(); i++) {
    if (vr[idx][i] != h) {
      for (int j = st[vr[idx][i]]; j < ft[vr[idx][i]]; j++) {
        inc(j);
      }
    }
  }
  inc(st[idx]);
  for (int i = 0; i < qr[idx].size(); i++) {
    if (dr[idx] + qr[idx][i].first > 100000)
      ans[qr[idx][i].second] = 0;
    else
      ans[qr[idx][i].second] = dis[dr[idx] + qr[idx][i].first].size();
  }
  if (!keep) {
    for (int i = st[idx]; i < ft[idx]; i++) dec(i);
  }
}
void inc(long long i) {
  long long x = cr[inv[i]];
  long long d = dr[inv[i]];
  dis[d][x]++;
  ;
}
void dec(long long i) {
  long long x = cr[inv[i]];
  long long d = dr[inv[i]];
  dis[d][x]--;
  if (dis[d][x] == 0) dis[d].erase(x);
}
