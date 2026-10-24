#include <bits/stdc++.h>
#pragma comment(linker, "/stack:16777216")
using namespace std;
const int INF = 1000000000;
const int MAX = 1000007;
const int MAX2 = 2000;
const int BASE = 1000000000;
char s[MAX];
int v[MAX];
set<pair<int, int> > S;
int cur = 0;
int p[MAX], cnt[MAX], c[MAX];
int pn[MAX], cn[MAX];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  int val = 0;
  for (int i = (0); i < (n); ++i) {
    if (s[i] == '(') {
      ++val;
    } else {
      --val;
    }
    v[i] = val;
    S.insert(make_pair(val, i));
  }
  vector<int> ids;
  int M = -INF;
  for (int it = (0); it < (n); ++it) {
    int V = min(S.begin()->first + cur, 0);
    if (V > M) {
      ids.clear();
    }
    if (V >= M) {
      M = V;
      ids.push_back((n - it) % n);
    }
    int id = n - it - 1;
    S.erase(make_pair(v[id], id));
    if (s[id] == '(') {
      ++cur;
      v[id] = 1 - cur;
      S.insert(make_pair(v[id], id));
    } else {
      --cur;
      v[id] = -1 - cur;
      S.insert(make_pair(v[id], id));
    }
  }
  memset(cnt, 0, sizeof(cnt));
  for (int i = (0); i < (n); ++i) ++cnt[s[i] - '('];
  cnt[1] += cnt[0];
  for (int i = (0); i < (n); ++i) p[--cnt[s[i] - '(']] = i;
  c[p[0]] = 0;
  int classes = 1;
  for (int i = 1; i < n; ++i) {
    if (s[p[i]] != s[p[i - 1]]) ++classes;
    c[p[i]] = classes - 1;
  }
  for (int h = 0; (1 << h) < n; ++h) {
    for (int i = (0); i < (n); ++i) {
      pn[i] = p[i] - (1 << h);
      if (pn[i] < 0) pn[i] += n;
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) ++cnt[c[pn[i]]];
    for (int i = 1; i < classes; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) p[--cnt[c[pn[i]]]] = pn[i];
    cn[p[0]] = 0;
    classes = 1;
    for (int i = 1; i < n; ++i) {
      int mid1 = (p[i] + (1 << h)) % n, mid2 = (p[i - 1] + (1 << h)) % n;
      if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) ++classes;
      cn[p[i]] = classes - 1;
    }
    memcpy(c, cn, n * sizeof(int));
  }
  int cl = INF;
  int id;
  for (int i = (0); i < (ids.size()); ++i) {
    if (cn[ids[i]] < cl) {
      cl = cn[ids[i]];
      id = ids[i];
    }
  }
  string R = "";
  for (int i = (0); i < (abs(M)); ++i) {
    R += '(';
  }
  for (int i = (id); i < (n); ++i) {
    R += s[i];
  }
  for (int i = (0); i < (id); ++i) {
    R += s[i];
  }
  val = 0;
  for (int i = (0); i < (R.size()); ++i) {
    if (R[i] == '(')
      ++val;
    else
      --val;
  }
  for (int i = (0); i < (val); ++i) {
    R += ')';
  }
  printf("%s", R.c_str());
  return 0;
}
