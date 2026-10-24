#include <bits/stdc++.h>
const int MAX = 3e5 + 5;
const int INF = 1e9 + 5;
const double M = 4e18;
using namespace std;
const int MOD = 1e9 + 7;
const double eps = 0.000000001;
char a[MAX], b[MAX], an[MAX];
bool vi[MAX];
int len1, len2;
int cnt1[50], cnt2[50];
int anum(int x) {
  int cnt = 0, i;
  for (i = 0; i < 26; i++) {
    cnt += cnt1[i];
    if (cnt >= x) break;
  }
  return i;
}
int bnum(int x) {
  int cnt = 0, i;
  for (i = 25; i; i--) {
    cnt += cnt2[i];
    if (cnt >= x) break;
  }
  return i;
}
int main() {
  scanf("%s%s", a, b);
  int len = strlen(a);
  for (int i = 0; i < len; i++) {
    ++cnt1[a[i] - 'a'];
    ++cnt2[b[i] - 'a'];
  }
  len1 = (len + 1) / 2;
  len2 = len - len1;
  int x, y;
  int l1 = 1, r1 = len1, l2 = 1, r2 = len2;
  int l = 0, r = len - 1;
  int now1, now2;
  for (int i = 0; i < len; i++) {
    now1 = anum(l1);
    now2 = bnum(l2);
    if (now1 < now2) {
      if (i & 1) {
        an[l++] = 'a' + now2;
        ++l2;
      } else {
        an[l++] = 'a' + now1;
        ++l1;
      }
    } else {
      if (i & 1) {
        now2 = bnum(r2--);
        an[r--] = 'a' + now2;
      } else {
        now1 = anum(r1--);
        an[r--] = 'a' + now1;
      }
    }
  }
  printf("%s\n", an);
}
