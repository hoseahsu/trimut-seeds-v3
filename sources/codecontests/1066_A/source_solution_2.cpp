#include <bits/stdc++.h>
using namespace std;
void ins(long long int a[], long long int n, long long int i = 0) {
  for (long long int i = 0; i < n; i++) a[i] = i;
}
template <typename t>
void ins(t a[], long long int n, t b = 0) {
  for (long long int i = 0; i < n; i++) a[i] = b;
}
void print(long long int a[], long long int n) {
  for (long long int i = 0; i < n; i++) cout << a[i] << " ";
  ;
  cout << endl;
}
template <typename t>
void print(t a[], long long int n) {
  for (long long int i = 0; i < n; i++) cout << a[i] << " ";
  ;
  cout << endl;
}
void po(long long int a[], long long int n) {
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
}
template <typename t>
void po(t a[], long long int n) {
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
}
void ps(long long int a[], long long int b[], long long int n,
        long long int o = 1, long long int t = 0, long long int p = 0) {
  for (long long int i = 0; i < n + p; i++) b[i] = 0;
  long long int sum = 0;
  if (o == 1) {
    for (long long int i = 0; i < n + p; i++) {
      sum += a[i];
      b[i + t] = sum;
    }
  }
  if (o == 2) {
    for (long long int i = 0; i < n + p; i++) {
      sum += a[n - 1 - i];
      b[n - 1 - i - t] = sum;
    }
  }
}
signed main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long int u = a / b;
  https:
    long long int v1 = d / b;
    long long int v2;
    if (c % b == 0) {
      v2 = c / b - 1;
    } else {
      v2 = c / b;
    }
    cout << u - (v1 - v2) << endl;
  }
  return 0;
}
