#include <bits/stdc++.h>
using namespace std;
template <typename T>
void stmin(T &a, T b) {
  if (a > b) a = b;
}
template <typename T>
void stmax(T &a, T b) {
  if (a < b) a = b;
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long int c = 0;
  for (long long int i = 0; i < n; i++) {
    if (a[i] >= c + 1) {
      c++;
    }
  }
  cout << c << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int test = 1;
  while (test--) {
    solve();
  }
}
