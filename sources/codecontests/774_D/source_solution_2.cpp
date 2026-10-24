#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, l, r, tek;
  vector<long long> v(100001);
  bool flag = true;
  cin >> n >> l >> r;
  for (long long i = 1; i < n + 1; i++) {
    cin >> v[i];
  }
  for (long long i = 1; i < n + 1; i++) {
    cin >> tek;
    if (tek != v[i] && i < l || (tek != v[i] && i > r)) {
      flag = false;
    }
  }
  if (flag) {
    cout << "TRUTH";
  } else {
    cout << "LIE";
  }
}
