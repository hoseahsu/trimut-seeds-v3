#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int n;
string ch;
int a[maxn], s[maxn];
int main() {
  cin >> n >> ch;
  for (int i = 0; i <= n - 1; i++) {
    if (ch[i] == '(')
      a[i] = 1;
    else
      a[i] = -1;
    s[i + 1] = s[i] + a[i];
  }
  if (s[n] != 0)
    printf("0\n1 1\n");
  else {
    int del = 0, mmin = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] < mmin) {
        del = i;
        mmin = s[i];
      }
    }
    for (int i = del + 1; i <= n; i++) s[i] -= mmin;
    for (int i = n + 1; i <= n + del; i++) s[i] = s[i - n] - mmin;
    int tot1 = 0, tot2 = 0, l = 1, r = 1, crease = 0;
    for (int i = del + 1; i <= n + del; i++) tot1 += (s[i] == 0);
    for (int i = del + 1, last = 1; i <= del + n; i = max(last, i + 1)) {
      if (s[i] == 1) {
        last = i + 1;
        int tmp = 0;
        while (s[last] > 1) {
          tmp += (s[last] == 2);
          last++;
        }
        if (tmp > crease) {
          crease = tmp;
          l = i + 1, r = last;
        }
      }
    }
    tot1 += crease;
    for (int i = del + 1, last = 1; i <= del + n; i = max(last, i + 1)) {
      if (s[i] == 1) {
        last = i;
        int tmp = 0;
        while (s[last] > 0) {
          tmp += (s[last] == 1);
          last++;
        }
        if (tmp > tot1) {
          tot1 = tmp;
          l = i, r = last;
        }
      }
    }
    l = (l - 1) % n + 1, r = (r - 1) % n + 1;
    printf("%d\n", max(tot1, tot2));
    printf("%d %d\n", l, r);
  }
}
