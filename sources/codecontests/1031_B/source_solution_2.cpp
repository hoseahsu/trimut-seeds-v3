#include <bits/stdc++.h>
using namespace std;
int a[100000], b[100000], t[100000];
int n;
bool check(int ti, int i) {
  t[i] = ti;
  if (i == n - 1) return true;
  if (a[i] == 0) {
    if (b[i] == 0 && ti == 0) {
      return check(0, i + 1);
    }
  }
  if (a[i] == 1) {
    if (b[i] == 1 && ti == 1) {
      return check(1, i + 1);
    }
    if (b[i] == 0) {
      if (ti == 0) return check(1, i + 1);
      if (ti == 1) return check(0, i + 1);
    }
  }
  if (a[i] == 2) {
    if (b[i] == 0) {
      if (ti == 0) {
        return check(2, i + 1);
      }
      if (ti == 2) return check(0, i + 1);
    }
    if (b[i] == 2 && ti == 2) return check(2, i + 1);
  }
  if (a[i] == 3) {
    if (b[i] == 0) {
      return check(3 - ti, i + 1);
    }
    if (b[i] == 1) {
      if (ti == 1) return check(3, i + 1);
      if (ti == 3) return check(1, i + 1);
    }
    if (b[i] == 2) {
      if (ti == 3) return check(2, i + 1);
      if (ti == 2) return check(3, i + 1);
    }
    if (ti == 3) return check(3, i + 1);
  }
  return false;
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    cin >> b[i];
  }
  bool c;
  for (int k = 0; k < 4; ++k) {
    c = check(k, 0);
    if (c) {
      cout << "YES" << endl;
      for (int i = 0; i < n; ++i) cout << t[i] << " ";
      break;
    }
  }
  if (!c) {
    cout << "NO";
  }
  return 0;
}
