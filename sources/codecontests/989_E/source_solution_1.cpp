#include <bits/stdc++.h>
using namespace std;
const double PI = 2 * acos(0.0);
template <class T>
void show(const set<T> &a) {
  for (T x : a) cout << x << " ";
  cout << endl;
}
template <class T>
void show(const vector<T> &a) {
  for (T x : a) cout << x << " ";
  cout << endl;
}
int n;
inline int gcd(int a, int b) {
  if (a < b) swap(a, b);
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
vector<pair<int, int>> points;
const int N = 201;
pair<int, int> normalized[N][N];
const int L = 14;
long double pow_mats[L][N][N];
inline void build_mat() {
  for (int i = 0; i < int(n); ++i) {
    vector<char> used(n, 0);
    used[i] = 1;
    int cnt = 0;
    for (int j = 0; j < int(n); ++j)
      if (!used[j]) {
        used[j] = 1;
        vector<int> cur_trans;
        cur_trans.push_back(i);
        cur_trans.push_back(j);
        for (int k = 0; k < int(n); ++k)
          if (!used[k])
            if (normalized[i][j] == normalized[i][k]) {
              used[k] = 1;
              cur_trans.push_back(k);
            }
        for (auto j : cur_trans)
          pow_mats[0][i][j] += 1.0 / ((long double)((int)(cur_trans.size())));
        ++cnt;
      }
    for (int j = 0; j < int(n); ++j) pow_mats[0][i][j] /= ((long double)cnt);
  }
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < i; ++j) swap(pow_mats[0][i][j], pow_mats[0][j][i]);
}
inline void build_powers() {
  for (int p = 1; p < L; ++p)
    for (int i = 0; i < int(n); ++i)
      for (int j = 0; j < int(n); ++j)
        for (int k = 0; k < int(n); ++k)
          pow_mats[p][i][j] += pow_mats[p - 1][i][k] * pow_mats[p - 1][k][j];
}
long double init_vectors[N * N][N];
int initsz;
inline void build_init_vectors() {
  vector<vector<int>> all;
  vector<char> used(n, 0);
  for (int i = 0; i < int(n); ++i) {
    used.assign(used.size(), 0);
    used[i] = 1;
    for (int j = 0; j < int(n); ++j)
      if (!used[j]) {
        vector<int> cur_v;
        used[j] = 1;
        for (int k = 0; k < int(n); ++k) {
          if (i == k || j == k) cur_v.push_back(k);
          if (!used[k])
            if (normalized[i][j] == normalized[i][k]) {
              used[k] = 1;
              cur_v.push_back(k);
            }
        }
        all.push_back(cur_v);
      }
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  initsz = ((int)(all.size()));
  for (int j = 0; j < int(((int)(all.size()))); ++j)
    for (auto &&i : all[j])
      init_vectors[j][i] = 1.0 / ((long double)((int)(all[j].size())));
}
long double b[N];
void get(long double *a, int p) {
  for (int i = L - 1; i >= 0; --i) {
    if ((1 << i) <= p) {
      fill(b, b + n, 0);
      for (int j = 0; j < int(n); ++j)
        for (int k = 0; k < int(n); ++k) b[j] += a[k] * pow_mats[i][k][j];
      for (int j = 0; j < int(n); ++j) a[j] = b[j];
      p -= (1 << i);
    }
  }
  assert(!p);
}
long double *a;
long double solve(int ind, int strides) {
  long double ret = 0;
  fill(a, a + n, 0);
  a[ind] = 1;
  get(a, strides);
  for (int j = 0; j < int(initsz); ++j) {
    long double cur = 0;
    for (int i = 0; i < int(n); ++i) cur += a[i] * init_vectors[j][i];
    ret = max(ret, (cur));
  }
  return ret;
}
void prec() {
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(n); ++j)
      if (i != j) {
        pair<int, int> a = points[i];
        pair<int, int> b = points[j];
        b.first -= a.first;
        b.second -= a.second;
        int g = gcd(abs(b.first), abs(b.second));
        if (b.first < 0 || (!b.first && b.second < 0)) {
          b.first *= -1;
          b.second *= -1;
        }
        normalized[i][j] = make_pair(b.first / g, b.second / g);
      }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  a = new long double[n];
  for (int i = 0; i < int(n); ++i) {
    int x, y;
    cin >> x >> y;
    points.push_back(make_pair(x, y));
  }
  prec();
  build_mat();
  build_powers();
  build_init_vectors();
  int q;
  cin >> q;
  vector<pair<pair<int, int>, int>> queries;
  cout << setprecision(7) << fixed;
  for (int iter = 0; iter < int(q); ++iter) {
    int t, m;
    cin >> t >> m;
    cout << solve(--t, --m) << "\n";
  }
}
