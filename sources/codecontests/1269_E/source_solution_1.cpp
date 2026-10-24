#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1 << 62;
const long long MOD = 1e9 + 7;
const int iINF = 1 << 30;
const double PI = 3.14159265359;
int LSOne(int n) { return n & (-n); }
class FenwickTree {
 private:
  vector<int> ft;

 public:
  FenwickTree(int n) { ft.assign(n + 1, 0); }
  int rsq(int b) {
    int sum = 0;
    for (; b; b -= LSOne(b)) {
      sum += ft[b];
    }
    return sum;
  }
  int rsq(int a, int b) { return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
  void adjust(int k, int v) {
    for (; k < (int)ft.size(); k += LSOne(k)) {
      ft[k] += v;
    }
  }
};
long long nsum(int x, int y) {
  long long s = (long long)y * (y + 1) / 2;
  s -= (long long)x * (x - 1) / 2;
  return s;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), pos(n + 1), less(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  FenwickTree ft(n);
  long long inv = 0;
  set<int> mintree, maxtree;
  long long minsum = 0, maxsum = 0;
  cout << "0 ";
  ft.adjust(pos[1] + 1, 1);
  mintree.insert(pos[1]);
  minsum += pos[1];
  for (int i = 2; i <= n; i++) {
    auto it1 = mintree.end();
    it1--;
    if (pos[i] < *it1) {
      maxsum += *it1;
      maxtree.insert(*it1);
      minsum -= *it1;
      mintree.erase(it1);
      minsum += pos[i];
      mintree.insert(pos[i]);
    } else {
      maxsum += pos[i];
      maxtree.insert(pos[i]);
    }
    if (maxtree.size() > mintree.size()) {
      int val = *maxtree.begin();
      maxsum -= val;
      maxtree.erase(maxtree.begin());
      minsum += val;
      mintree.insert(val);
    }
    inv += ft.rsq(pos[i] + 1, n);
    it1 = mintree.end();
    it1--;
    int med = *it1;
    int x = med - mintree.size() + 1;
    int y = med + maxtree.size();
    long long push = nsum(x, med) - minsum;
    push += maxsum - nsum(med + 1, y);
    cout << inv + push << " ";
    ft.adjust(pos[i] + 1, 1);
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
