#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) {
  long long z = y;
  while (x % y != 0) {
    z = x % y;
    x = y;
    y = z;
  }
  return z;
}
bool fg;
vector<int> tmp, ans;
unordered_map<int, int> C;
int stp;
void cal(vector<int> &v, int dep) {
  if (dep > 22) return;
  if (v.empty()) {
    if (!fg || tmp.size() < ans.size()) {
      ans = tmp;
      fg = 1;
    }
    return;
  }
  vector<int> vp, vp1;
  if (v.size() == 1 && abs(v[0]) == 1) {
    if (v[0] == -1)
      tmp.push_back(-(1 << dep));
    else
      tmp.push_back(1 << dep);
    cal(vp, dep + 1);
    tmp.pop_back();
    return;
  } else if (v.size() == 2 && abs((long long)v[0] * v[1]) == 1) {
    if (v[0] != v[1]) {
      tmp.push_back(-(1 << dep));
      tmp.push_back(1 << dep);
    } else if (v[0] == 1)
      tmp.push_back(1 << dep);
    else
      tmp.push_back(-(1 << dep));
    cal(vp, dep + 1);
    tmp.pop_back();
    if (v[0] != v[1]) tmp.pop_back();
    return;
  }
  stp++;
  for (int c : v) {
    if (c % 2 == 0) {
      int tar = c / 2;
      if (tar != 0 && C[tar] != stp) {
        C[tar] = stp;
        vp.push_back(tar);
      }
    } else
      vp1.push_back(c);
  }
  if (vp1.empty()) {
    cal(vp, dep + 1);
    return;
  }
  int OS = stp;
  stp++;
  int N = vp.size();
  for (int z : vp1) {
    int tar = (z + 1) / 2;
    if (tar == 0) continue;
    if (C[tar] == stp || C[tar] == OS) continue;
    C[tar] = stp;
    vp.push_back(tar);
  }
  tmp.push_back(-(1 << dep));
  cal(vp, dep + 1);
  tmp.pop_back();
  while (vp.size() > N) vp.pop_back();
  stp++;
  for (int z : vp1) {
    int tar = (z - 1) / 2;
    if (tar == 0) continue;
    if (C[tar] == stp || C[tar] == OS) continue;
    C[tar] = stp;
    vp.push_back(tar);
  }
  tmp.push_back(1 << dep);
  cal(vp, dep + 1);
  tmp.pop_back();
}
void fmain(int ID) {
  scanf("%d", &n);
  vector<int> vp;
  stp++;
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    scanf("%d", &k);
    if (C[k] != stp && k != 0) {
      C[k] = stp;
      vp.push_back(k);
    }
  }
  cal(vp, 0);
  printf("%d\n", ans.size());
  for (int z : ans) printf("%d ", z);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
