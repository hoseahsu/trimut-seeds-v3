#include <bits/stdc++.h>
int len;
char s[1000010];
int l[1000010], r[1000010];
bool d[1000010];
std ::queue<int> Q, NQ;
int ans;
int main() {
  int i, v, lp, rp;
  scanf("%s", s + 1);
  len = strlen(s + 1);
  s[0] = s[1];
  s[len + 1] = s[len];
  for (i = 1; i <= len; i++) l[i] = i - 1;
  for (i = 1; i <= len; i++) r[i] = i + 1;
  for (i = 1; i <= len; i++)
    if (s[i] != s[i - 1] || s[i] != s[i + 1]) {
      Q.push(i);
      d[i] = true;
    }
  while (!Q.empty()) {
    ans++;
    while (!Q.empty()) {
      v = Q.front();
      Q.pop();
      lp = l[v];
      while (Q.front() == r[v]) {
        v = Q.front();
        Q.pop();
      }
      rp = r[v];
      r[lp] = rp;
      l[rp] = lp;
      if (lp == 0) s[lp] = s[rp];
      if (rp == len + 1) s[rp] = s[lp];
      if (s[lp] != s[rp]) {
        if (lp != 0 && !d[lp]) d[lp] = true, NQ.push(lp);
        if (rp != len + 1 && !d[rp]) d[rp] = true, NQ.push(rp);
      }
    }
    Q = NQ;
    while (!NQ.empty()) NQ.pop();
  }
  printf("%d\n", ans);
}
