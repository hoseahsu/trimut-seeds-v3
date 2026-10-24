#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e9 + 70;
const long long mod = 1e9 + 7;
const int maxn = 2e6 + 1000;
struct SuffixArray {
  int n;
  string s;
  int SA[maxn], tempSA[maxn], RA[maxn], tempRA[maxn];
  void countingsort(int k) {
    int maxi = max(n, 300);
    vector<int> c(maxi);
    for (int i = (0); i < (n); i++) {
      int v = (i + k < n ? RA[i + k] : 0);
      c[v]++;
    }
    int s = 0;
    for (int i = (0); i < (maxi); i++) {
      int t = c[i];
      c[i] = s;
      s += t;
    }
    for (int j = (0); j < (n); j++) {
      int i = SA[j];
      int v = (i + k < n ? RA[i + k] : 0);
      tempSA[c[v]] = i;
      c[v]++;
    }
    for (int i = (0); i < (n); i++) SA[i] = tempSA[i];
  }
  void init(string e) {
    e = e + "$";
    s = e;
    n = s.length();
    for (int i = (0); i < (n); i++) {
      SA[i] = i;
      RA[i] = s[i];
    }
    for (int k = 1; k <= n; k *= 2) {
      countingsort(k);
      countingsort(0);
      for (int j = (0); j < (n); j++) {
        int i = SA[j];
        if (j == 0) {
          tempRA[i] = 0;
          continue;
        }
        int p = SA[j - 1];
        if (RA[i] == RA[p] && RA[i + k] == RA[p + k]) {
          tempRA[i] = tempRA[p];
        } else {
          tempRA[i] = tempRA[p] + 1;
        }
      }
      for (int i = (0); i < (n); i++) RA[i] = tempRA[i];
      vector<bool> seen(n);
      bool done = true;
      for (int i = (0); i < (n / 2); i++) {
        if (seen[RA[i]]) {
          done = false;
          break;
        }
        seen[RA[i]] = true;
      }
      if (done) {
        break;
      }
    }
  }
} Z;
int delta[maxn];
int pre[maxn];
int suf[maxn];
int main() {
  if (fopen("i.txt", "r")) freopen("i.txt", "r", stdin);
  string s;
  cin >> s;
  int n = s.length();
  delta[0] = 0;
  for (int i = (1); i < (n + 1); i++) {
    delta[i] = delta[i - 1] + (s[i - 1] == '(' ? 1 : -1);
  }
  for (int i = (0); i < (n + 3); i++) {
    pre[i] = inf;
    suf[i] = inf;
  }
  for (int i = (1); i < (n); i++) {
    pre[i] = min(pre[i - 1], delta[i - 1]);
  }
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = min(suf[i + 1], delta[i]);
  }
  Z.init(s + s);
  if (delta[n] >= 0) {
    vector<int> options;
    for (int i = (0); i < (n); i++) {
      int mn = min(pre[i] + delta[n] - delta[i], suf[i] - delta[i]);
      if (mn >= 0) {
        options.push_back(i);
      }
    }
    int best = options[0];
    for (int e : options) {
      if (Z.RA[e] < Z.RA[best]) {
        best = e;
      }
    }
    cout << s.substr(best) << s.substr(0, best);
    for (int i = (0); i < (delta[n]); i++) {
      cout << ')';
    }
    cout << "\n";
  } else {
    int k = -delta[n];
    for (int i = (0); i < (k); i++) {
      cout << '(';
    }
    vector<int> options;
    for (int i = (0); i < (n); i++) {
      int mn = min(pre[i] + delta[n] - delta[i], suf[i] - delta[i]);
      if (mn >= -k) {
        options.push_back(i);
      }
    }
    int best = options[0];
    for (int e : options) {
      if (Z.RA[e] < Z.RA[best]) {
        best = e;
      }
    }
    cout << s.substr(best) << s.substr(0, best);
  }
  return 0;
}
