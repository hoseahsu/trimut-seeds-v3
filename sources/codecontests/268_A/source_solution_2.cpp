#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-11;
const int inf = 0x3f3f3f3f;
template <class T>
void show(T a, int n) {
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << endl;
}
template <class T>
void show(T a, int r, int l) {
  for (int i = 0; i < r; ++i) show(a[i], l);
  cout << endl;
}
const int N = 1e6 + 111;
map<int, int> k;
int x[31], y[31];
const int maxnode = 2001100;
const int sigma_size = 26;
int ch[maxnode][sigma_size];
int main() {
  int n, a, b, i, j;
  cin >> n;
  int ans = 0;
  for (i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    k[y[i]]++;
  }
  for (i = 0; i < n; i++) {
    ans += k[x[i]];
  }
  cout << ans << endl;
  return 0;
}
