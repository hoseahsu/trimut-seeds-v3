#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  return a + b;
}

int mul(int a, int b) {
  return (long long) a * b % MOD;
}

vector< vector<int> > mat_mul(const vector< vector<int> > &a, const vector< vector<int> > &b) {
  int n = (int) a.size(), m = (int) b[0].size(), t = (int) b.size();
  vector< vector<int> > c(n, vector<int>(m, 0));
  for (int k = 0; k < t; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
      }
    }
  }
  return c;
}

vector< vector<int> > mat_pow(const vector< vector<int> > &a, long long p) {
  vector< vector<int> > ans;
  if (p == 0) {
    ans.assign((int) a.size(), vector<int>((int) a.size(), 0));
    for (int i = 0; i < (int) a.size(); i++) ans[i][i] = 1;
    return ans;
  }
  ans = mat_pow(mat_mul(a, a), p / 2);
  if (p % 2 == 1) ans = mat_mul(ans, a);
  return ans;
}

int solve(const vector <int> &a) {
  int n = (int) a.size();
  vector< pair<long long, long long> > v;
  long long cur = 0;
  for (auto& x : a) {
    if (x < 0) v.push_back({cur - 1, cur + x});
    else v.push_back({cur + 1, cur + x});
    cur += x;
  }
  v[0].first = 0;
  vector<long long> peaks;
  for (auto& p : v) {
    peaks.push_back(p.first - 1); peaks.push_back(p.first); peaks.push_back(p.first + 1);
    peaks.push_back(p.second - 1); peaks.push_back(p.second); peaks.push_back(p.second + 1);
  }
  sort(peaks.begin(), peaks.end());
  peaks.erase(unique(peaks.begin(), peaks.end()), peaks.end());
  peaks.pop_back();
  vector<int> ans(n + 1, 0); ans[0] = 1;
  cur = -1;
  for (auto& x : peaks) {
    vector< vector<int> > mat(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
      if (min(v[i].first, v[i].second) <= cur + 1 && x <= max(v[i].first, v[i].second)) {
        if (v[i].first < v[i].second) for (int j = 0; j <= i + 1; j++) mat[j][i + 1] = 1;
        else for (int j = 0; j <= i; j++) mat[j][i + 1] = 1;
      }
    }
    mat = mat_pow(mat, x - cur);
    vector<int> tmp(n + 1, 0);
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        tmp[j] = add(tmp[j], mul(ans[i], mat[i][j]));
      }
    }
    swap(ans, tmp);
    cur = x;
  }
  int sum = 0;
  for (auto& x : ans) sum = add(sum, x);
  return sum;
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int x;
  cin >> x;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x != 0) a.push_back(x);
  }
  n = (int) a.size();
  long long mx = 0;
  for (int i = 0; i < n; i++) {
    long long cur = 0;
    for (int j = i; j < n; j++) {
      cur += a[j];
      mx = max(mx, cur);
    }
  }
  if (mx == 0) {
    long long ans = 1;
    for (auto& x : a) ans = add(ans, -x);
    cout << 1 << ' ' << ans << '\n';
    return 0;
  }
  vector< pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    long long cur = 0;
    int k = -1;
    for (int j = i; j < n; j++) {
      cur += a[j];
      if (cur == mx) k = j;
    }
    if (k != -1) {
      v.push_back({i, k});
      i = k;
    }
  }
  int ans = 0;
  for (auto& p : v) ans = add(ans, solve(vector<int>(a.begin() + p.first, a.begin() + p.second + 1)));
  cout << mx + 1 << ' ' << ans << '\n';
  return 0;  
}