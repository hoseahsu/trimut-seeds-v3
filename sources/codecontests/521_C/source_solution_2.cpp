#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i) {
    if (i != v.begin()) os << ", ";
    os << *i;
  }
  os << "]";
  return os;
}
const int MOD = 1e9 + 7;
int power(int a, int b) {
  long long res = 1, p = a;
  while (b > 0) {
    if (b % 2) res = (res * p) % MOD;
    b /= 2;
    p = ((p) * (p)) % MOD;
  }
  return res;
}
int inverse(int a) { return power(a, MOD - 2); }
vector<int> D, C, CC, S;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  D.resize(n + 7, 0);
  D[0] = 1;
  for (int i = (int)(1); i <= (int)(((int)((D).size())) - 1); ++i)
    D[i] = (10ll * D[i - 1]) % MOD;
  C.resize(n + 7, 0);
  for (int i = 0; i < (int)(((int)((C).size()))); ++i)
    if (i < k - 1) {
      C[i] = 0;
    } else if (i == k - 1) {
      C[i] = 1;
    } else {
      C[i] = (long long)C[i - 1] * i % MOD * inverse(i - k + 1) % MOD;
    }
  CC.resize(n + 7, 0);
  for (int i = 0; i < (int)(((int)((CC).size()))); ++i)
    if (i < k) {
      CC[i] = 0;
    } else if (i == k) {
      CC[i] = 1;
    } else {
      CC[i] = (long long)CC[i - 1] * i % MOD * inverse(i - k) % MOD;
    }
  S.resize(n, 0);
  for (int i = (int)(1); i <= (int)(n - 1); ++i)
    S[i] = (S[i - 1] + (long long)D[i - 1] * C[n - 1 - i]) % MOD;
  int res = 0;
  for (int i = 0; i < (int)(n); ++i) {
    char _c;
    scanf(" %c", &_c);
    long long c = _c - '0';
    res += c * (S[n - i - 1] + (long long)D[n - i - 1] * CC[i]) % MOD;
    res %= MOD;
  }
  printf("%d\n", res);
}
