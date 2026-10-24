#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char s[N];
int cnt1[10], cnt2[10];
int mi[5];
int ma, mx = -1;
int c[10][2] = {{5, 5}, {1, 9}, {2, 8}, {3, 7}, {4, 6}};
int cc[10][2] = {{0, 9}, {5, 4}, {1, 8}, {2, 7}, {3, 6}};
string a1, a2;
int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = (0); i < (n); i++) cnt1[s[i] - '0']++, cnt2[s[i] - '0']++;
  for (int i = (0); i < (5); i++) {
    int a = c[i][0], b = c[i][1];
    if (cnt1[a] == 0 || cnt2[b] == 0) continue;
    cnt1[a]--;
    cnt2[b]--;
    int t = 1;
    for (int j = (0); j < (10); j++) {
      int x = j, y = 9 - j;
      t += min(cnt2[x], cnt1[y]);
    }
    if (t > mx) mx = t, ma = i;
    cnt1[a]++;
    cnt2[b]++;
  }
  if (mx == -1) {
    for (int i = (0); i < (10); i++)
      for (int j = (0); j < (cnt1[i]); j++) a1 += '0' + i;
    a2 = a1;
  } else {
    int a = c[ma][0], b = c[ma][1];
    cnt1[a]--;
    cnt2[b]--;
    a1 += '0' + a;
    a2 += '0' + b;
    for (int j = (0); j < (10); j++) {
      int x = j, y = 9 - j;
      mi[j] = min(cnt1[x], cnt2[y]);
      for (int k = (0); k < (mi[j]); k++) a1 += '0' + x;
      for (int k = (0); k < (mi[j]); k++) a2 += '0' + y;
      cnt1[x] -= mi[j];
      cnt2[y] -= mi[j];
    }
    int zero = min(cnt1[0], cnt2[0]);
    for (int j = (0); j < (zero); j++) {
      a1 = '0' + a1;
      a2 = '0' + a2;
    }
    cnt1[0] -= zero;
    cnt2[0] -= zero;
    for (int j = (0); j < (10); j++)
      for (int k = (0); k < (cnt1[j]); k++) a1 += '0' + j;
    for (int j = (0); j < (10); j++)
      for (int k = (0); k < (cnt2[j]); k++) a2 += '0' + j;
  }
  reverse(a1.begin(), a1.end());
  reverse(a2.begin(), a2.end());
  cout << a1 << endl << a2 << endl;
  return 0;
}
