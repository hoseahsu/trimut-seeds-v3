#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
struct Matrix {
  long long ma[3][3];
  int n;
  Matrix() {}
  Matrix(int _n) {
    n = _n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) ma[i][j] = 0;
  }
  Matrix operator*(const Matrix &b) const {
    Matrix ret = Matrix(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++) {
          ret.ma[i][j] = (ret.ma[i][j] + ma[i][k] * b.ma[k][j]) % MOD;
        }
    return ret;
  }
  void set_one() {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) ma[i][j] = (i == j);
  }
};
void Mapow(Matrix &a, Matrix &ans, long long n) {
  ans.set_one();
  while (n) {
    if (n & 1) ans = ans * a;
    a = a * a;
    n >>= 1;
  }
}
const long long EX[3][3] = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
const long long _2[3] = {1, 2, 4};
struct line {
  long long l, r;
  int ty;
  line() {}
  line(long long a, long long b, int c) : l(a), r(b), ty(c) {}
};
vector<line> vec;
struct point {
  long long pos;
  int ty;
  int val;
  point() {}
  point(long long a, int b, int c) : pos(a), ty(b), val(c) {}
  bool operator<(const point &b) const { return pos < b.pos; }
};
vector<point> vv;
int main() {
  int n;
  long long m;
  scanf("%d%lld", &n, &m);
  vv.clear();
  for (int i = 1; i <= n; i++) {
    int ty;
    long long tl, tr;
    scanf("%d%lld%lld", &ty, &tl, &tr);
    vv.push_back(point(tl, ty - 1, 1));
    vv.push_back(point(tr + 1, ty - 1, -1));
  }
  sort(vv.begin(), vv.end());
  vec.clear();
  int a[3] = {0, 0, 0};
  for (auto x : vv) {
    int tmp = 0;
    a[x.ty] += x.val;
    for (int i = 0; i < 3; i++)
      if (a[i] > 0) tmp += _2[i];
    vec.push_back(line(x.pos, 0, tmp));
  }
  for (int i = 0; i < (int)vec.size() - 1; i++) {
    vec[i].r = vec[i + 1].l - 1;
  }
  if (vec.size() > 0) vec.pop_back();
  long long res[3] = {0, 1, 0};
  long long now = 1;
  Matrix mid = Matrix(3);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) mid.ma[i][j] = EX[i][j];
  Matrix ans = Matrix(3);
  long long x1, x2, x3;
  if (vec.size() > 0) {
    Mapow(mid, ans, vec[0].l - 1 - now);
    x1 = (ans.ma[0][0] * res[0] + ans.ma[0][1] * res[1] +
          ans.ma[0][2] * res[2]) %
         MOD;
    x2 = (ans.ma[1][0] * res[0] + ans.ma[1][1] * res[1] +
          ans.ma[1][2] * res[2]) %
         MOD;
    x3 = (ans.ma[2][0] * res[0] + ans.ma[2][1] * res[1] +
          ans.ma[2][2] * res[2]) %
         MOD;
    res[0] = x1;
    res[1] = x2;
    res[2] = x3;
    now = vec[0].l - 1;
    for (auto qq : vec) {
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) mid.ma[i][j] = EX[i][j];
      for (int i = 0; i < 3; i++)
        if (qq.ty & _2[i])
          for (int j = 0; j < 3; j++) mid.ma[i][j] = 0;
      Mapow(mid, ans, qq.r - now);
      if (qq.ty & _2[0])
        x1 = 0;
      else
        x1 = (ans.ma[0][0] * res[0] + ans.ma[0][1] * res[1] +
              ans.ma[0][2] * res[2]) %
             MOD;
      if (qq.ty & _2[1])
        x2 = 0;
      else
        x2 = (ans.ma[1][0] * res[0] + ans.ma[1][1] * res[1] +
              ans.ma[1][2] * res[2]) %
             MOD;
      if (qq.ty & _2[2])
        x3 = 0;
      else
        x3 = (ans.ma[2][0] * res[0] + ans.ma[2][1] * res[1] +
              ans.ma[2][2] * res[2]) %
             MOD;
      res[0] = x1;
      res[1] = x2;
      res[2] = x3;
      now = qq.r;
    }
  }
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) mid.ma[i][j] = EX[i][j];
  Mapow(mid, ans, m - now);
  x2 = (ans.ma[1][0] * res[0] + ans.ma[1][1] * res[1] + ans.ma[1][2] * res[2]) %
       MOD;
  printf("%lld\n", x2);
}
