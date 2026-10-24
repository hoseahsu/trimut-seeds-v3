#include <bits/stdc++.h>
using namespace std;
const int W_LEN = sizeof(unsigned int) * 8;
const int SHIFT_LEN = (W_LEN == 32 ? 5 : 6);
const int MAX_N = 50000 + 10;
void AlgB(int m, int n, const char* a, const char* b, int* ll) {
  static unsigned int bit[128][(MAX_N >> SHIFT_LEN) + 2];
  static unsigned int dp[(MAX_N >> SHIFT_LEN) + 2];
  int N = m;
  int M = n;
  int nbits = (N + W_LEN - 1) >> SHIFT_LEN;
  for (int i = 0; i < N; i++)
    bit[a[i]][i >> SHIFT_LEN] |= static_cast<unsigned int>(1)
                                 << (i & (W_LEN - 1));
  memset(dp, 0, nbits * sizeof(unsigned int));
  unsigned int top_bit, carry, t, x, y, *bit_s;
  for (int i = 0; i < M; i++) {
    top_bit = 1;
    bit_s = bit[b[i]];
    for (int j = carry = 0; j < nbits; j++) {
      x = dp[j] | bit_s[j];
      t = dp[j] >> (W_LEN - 1);
      y = (dp[j] << 1) | top_bit;
      top_bit = t;
      dp[j] = x & ((x - y - carry) ^ x);
      carry = (x < y + carry) ? 1 : 0;
    }
  }
  int sum = 0;
  for (int i = 0; i < N; i++) {
    if (dp[i >> SHIFT_LEN] & (1 << (i & (W_LEN - 1)))) ++sum;
    ll[i] = sum;
    bit[a[i]][i >> SHIFT_LEN] = 0;
  }
}
int Lcs(int m, int n, const char* a, const char* b, char* c) {
  if (n <= 0 || m <= 0) {
    return 0;
  } else if (m == 1) {
    for (int i = 0; i < n; ++i) {
      if (a[0] == b[i]) {
        c[0] = a[0];
        return 1;
      }
    }
    return 0;
  }
  static char ra[MAX_N], rb[MAX_N];
  static int ll1[MAX_N], ll2[MAX_N];
  int i = (m - 1) >> 1;
  memcpy(ra, a, m);
  memcpy(rb, b, n);
  reverse(ra, ra + m);
  reverse(rb, rb + n);
  AlgB(n, i + 1, b, a, ll1);
  AlgB(n, m - i - 1, rb, ra, ll2);
  int l1 = 0, l2 = ll2[n - 1], k = -1;
  for (int j = 0; j < n - 1; ++j) {
    if (ll1[j] + ll2[n - j - 2] > l1 + l2) {
      l1 = ll1[j];
      l2 = ll2[n - j - 2];
      k = j;
    }
  }
  if (ll1[n - 1] > l1 + l2) {
    l1 = ll1[n - 1];
    l2 = 0;
    k = n - 1;
  }
  if (l1 > 0) Lcs(i + 1, k + 1, a, b, c);
  if (l2 > 0) Lcs(m - i - 1, n - k - 1, a + i + 1, b + k + 1, c + k + 1);
  memmove(c + l1, c + k + 1, l2);
  return l1 + l2;
}
char a[MAX_N], b[MAX_N], c[MAX_N];
void Print(const char* s, int n) {
  if (n <= 100) {
    for (int i = 0; i < n; ++i) {
      printf("%c", s[i]);
    }
  } else {
    if (n % 2 == 0) {
      for (int i = (n - 100) / 2; i < (n - 100) / 2 + 100; ++i) {
        printf("%c", s[i]);
      }
    } else {
      for (int i = (n - 100) / 2; i < (n - 100) / 2 + 101; ++i) {
        if (i == (n / 2)) {
          continue;
        }
        printf("%c", s[i]);
      }
    }
  }
  printf("\n");
}
int main() {
  scanf("%s", a);
  int n = strlen(a);
  strcpy(b, a);
  reverse(b, b + n);
  int clen = Lcs(n, n, a, b, c);
  Print(c, clen);
  return 0;
}
