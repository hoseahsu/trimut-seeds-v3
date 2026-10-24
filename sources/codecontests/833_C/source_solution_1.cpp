#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long dx(long long x, int n) {
  long long res = 1;
  for (int i = 0; i < n; i++) res *= x;
  return res;
}
std::vector<int> ban(10, 0);
vector<std::vector<long long> > cnk(27, std::vector<long long>(27, 0));
long long sel(long long n, long long gd) {
  if (n == 0) return 1;
  if (gd == 0) return 0;
  return cnk[n + gd - 1][gd - 1];
}
struct grpR {
  std::vector<int> ob;
  int cnt;
  int m;
  long long count() {
    for (auto x : ob)
      if (ban[x]) return 0;
    int gd = 0;
    for (int i = m; i < 10; i++)
      if (ban[i] == 0) gd++;
    return sel(cnt, gd);
  }
};
struct grpL {
  std::vector<int> ob;
  int cnt;
  int m;
  long long count() {
    for (auto x : ob)
      if (ban[x]) return 0;
    int gd = 0;
    for (int i = 0; i < m + 1; i++)
      if (ban[i] == 0) gd++;
    return sel(cnt, gd);
  }
};
long long inter(grpR a, grpL b) {
  sort((a.ob).begin(), (a.ob).end());
  sort((b.ob).begin(), (b.ob).end());
  int pta = 0, ptb = 0;
  while (1) {
    if (pta == a.ob.size() && ptb == b.ob.size())
      break;
    else if (pta == a.ob.size()) {
      int dig = b.ob[ptb++];
      if (ban[dig]) return 0;
      if (a.cnt == 0 || a.m > dig) return 0;
      a.cnt--;
    } else if (ptb == b.ob.size()) {
      int dig = a.ob[pta++];
      if (ban[dig]) return 0;
      if (b.cnt == 0 || b.m < dig) return 0;
      b.cnt--;
    } else if (a.ob[pta] == b.ob[ptb]) {
      int dig = a.ob[pta++];
      if (ban[dig]) return 0;
      ptb++;
    } else if (a.ob[pta] < b.ob[ptb]) {
      int dig = a.ob[pta++];
      if (ban[dig]) return 0;
      if (b.cnt == 0 || b.m < dig) return 0;
      b.cnt--;
    } else {
      int dig = b.ob[ptb++];
      if (ban[dig]) return 0;
      if (a.cnt == 0 || a.m > dig) return 0;
      a.cnt--;
    }
  }
  if (a.cnt != b.cnt) {
    cout << "FUCK YOU\n";
  }
  int gd = 0;
  for (int i = a.m; i < b.m + 1; i++)
    if (ban[i] == 0) gd++;
  return sel(a.cnt, gd);
}
int main() {
  for (int i = 0; i < 27; i++) cnk[i][0] = 1;
  for (int i = 1; i < 27; i++) {
    for (int j = 1; j < i + 1; j++) {
      cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % mod;
    }
  }
  long long l, r;
  cin >> l >> r;
  if (l == r) {
    cout << 1;
    return 0;
  }
  long long d10 = 1;
  for (int i = 0; i < 18; i++) d10 *= 10;
  while (l / d10 == r / d10) {
    l -= (l / d10) * d10;
    r -= (r / d10) * d10;
    d10 /= 10;
  }
  std::vector<int> dl, dr;
  while (d10 > 0) {
    dl.push_back((l / d10) % 10);
    dr.push_back((r / d10) % 10);
    d10 /= 10;
  }
  if (dl.size() == 1) {
    cout << dr[0] - dl[0] + 1;
    return 0;
  }
  long long ans = 0;
  std::vector<int> curdig;
  if (dr[0] > dl[0] + 1) {
    for (int i = dl[0] + 1; i < dr[0]; i++) ban[i] = 1;
    int have = dr[0] - dl[0] - 1;
    int k = dr.size();
    int fr = 10;
    while (have > 0) {
      ans += cnk[k + fr - 2][fr - 1];
      have--;
      fr--;
    }
  }
  curdig.push_back(dr[0]);
  int pt = 1;
  int last = 0;
  int dig = dr.size();
  vector<grpR> allr;
  vector<grpL> alll;
  while (pt < dr.size()) {
    bool bad = false;
    while (pt < dr.size()) {
      if (dr[pt] < last) {
        bad = true;
        break;
      } else if (dr[pt] > last)
        break;
      curdig.push_back(last);
      pt++;
    }
    if (bad) break;
    if (pt == dig) {
      allr.emplace_back();
      allr.back().ob = curdig;
      allr.back().cnt = 0;
      allr.back().m = 9;
    } else {
      while (last < dr[pt]) {
        allr.emplace_back();
        allr.back().ob = curdig;
        allr.back().ob.push_back(last);
        allr.back().cnt = dig - pt - 1;
        allr.back().m = last;
        last++;
      }
    }
  }
  pt = 1;
  curdig.clear();
  curdig.push_back(dl[0]);
  last = 9;
  while (pt < dl.size()) {
    bool bad = false;
    while (pt < dl.size()) {
      if (dl[pt] > last) {
        bad = true;
        break;
      } else if (dl[pt] < last)
        break;
      curdig.push_back(last);
      pt++;
    }
    if (bad) break;
    if (pt == dig) {
      alll.emplace_back();
      alll.back().ob = curdig;
      alll.back().cnt = 0;
      alll.back().m = 9;
    } else {
      while (last > dl[pt]) {
        alll.emplace_back();
        alll.back().ob = curdig;
        alll.back().ob.push_back(last);
        alll.back().cnt = dig - pt - 1;
        alll.back().m = last;
        last--;
      }
    }
  }
  for (auto x : alll) ans += x.count();
  for (auto x : allr) ans += x.count();
  for (auto x : allr)
    for (auto y : alll) ans -= inter(x, y);
  cout << ans;
}
