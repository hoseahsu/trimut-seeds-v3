#include <bits/stdc++.h>
using namespace std;
template <class T>
struct Matrix {
  int r, c;
  T a[4][4];
  Matrix() { memset(a, 0, sizeof a); }
  Matrix(int si) {
    memset(a, 0, sizeof a);
    r = c = si;
    for (int i = 0; i < si; i++) a[i][i] = 1;
  }
  Matrix operator*(const Matrix& rhs) {
    Matrix<T> ret;
    ret.r = r;
    ret.c = rhs.c;
    for (int k = 0; k < c; ++k)
      for (int i = 0; i < ret.r; ++i)
        for (int j = 0; j < ret.c; ++j)
          ret.a[i][j] =
              (ret.a[i][j] + (long long)a[i][k] * rhs.a[k][j]) % 1000000007;
    return ret;
  }
  Matrix operator^(long long b) {
    Matrix<T> ret, base = *this;
    int setret = 0;
    while (b) {
      if (b & 1) ret = (setret ? ret * base : base), setret = 1;
      base = base * base;
      b >>= 1;
    }
    return ret;
  }
};
int Next[1000010];
char fs[30][1000010];
int fib[30];
int KMP(char* txt, char* str) {
  int len1 = strlen(txt);
  int len2 = strlen(str);
  int i = 0, j = -1;
  Next[0] = -1;
  while (i < len2) {
    if (j == -1 || str[i] == str[j])
      Next[++i] = ++j;
    else
      j = Next[j];
  }
  i = 0, j = 0;
  int ret = 0;
  while (i < len1) {
    if (j == -1 || txt[i] == str[j])
      i++, j++;
    else
      j = Next[j];
    if (j == len2) ret++;
  }
  return ret;
}
char instr[1000010];
char A[1000010], B[1000010];
char temp[1000010];
int main() {
  Matrix<int> M;
  M.r = M.c = 4;
  M.a[0][1] = M.a[0][2] = M.a[1][0] = M.a[1][1] = M.a[2][3] = M.a[3][2] = 1;
  fib[1] = fib[2] = 1;
  fs[1][0] = 'a';
  fs[2][0] = 'b';
  for (int i = 3; i < 30; ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
    strcpy(fs[i], fs[i - 1]);
    strcat(fs[i], fs[i - 2]);
  }
  for (int i = 1; i < 30; ++i) fs[i][fib[i]] = '\0';
  long long k;
  int m;
  cin >> k >> m;
  while (m--) {
    scanf("%s", instr);
    int len = strlen(instr);
    if (k < 30) {
      cout << KMP(fs[k], instr) << endl;
      continue;
    }
    int I;
    for (int i = 1; i < 30; i++) {
      if (fib[i] >= len) {
        strcpy(B, fs[i + 1]);
        strcpy(A, fs[i]);
        I = i;
        break;
      }
    }
    long long CA = KMP(A, instr);
    long long CB = KMP(B, instr);
    strcpy(temp, B);
    long long CBA = KMP(strcat(temp, A), instr) - CB - CA;
    strcpy(temp, A);
    long long CAB = KMP(strcat(temp, B), instr) - CA - CB;
    strcpy(temp, B);
    long long CBB = KMP(strcat(temp, B), instr) - CB - CB;
    Matrix<int> cnt;
    cnt.r = 1;
    cnt.c = 4;
    cnt.a[0][1] = 1;
    cnt = cnt * (M ^ (k - I - 1));
    long long ans = (cnt.a[0][0] * (CBA + CA) + cnt.a[0][1] * CB +
                     cnt.a[0][2] * CAB + cnt.a[0][3] * CBB) %
                    1000000007;
    cout << ans << endl;
  }
  return 0;
}
