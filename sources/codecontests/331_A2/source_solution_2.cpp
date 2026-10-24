#include <bits/stdc++.h>
const int MXN = 300010;
int main() {
  int n;
  scanf("%d", &n);
  std::map<int, int> first, last;
  static int ary[MXN];
  static int cut[MXN];
  static long long sum[MXN];
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ary[i]);
    if (ary[i] > 0) {
      cut[i] = cut[i - 1];
      sum[i] = sum[i - 1] + ary[i];
    } else {
      cut[i] = cut[i - 1] + 1;
      sum[i] = sum[i - 1];
    }
    if (first.count(ary[i]) == 0) first[ary[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    if (last.count(ary[i]) == 0) last[ary[i]] = i;
  }
  int ansCut = -1, al, ar;
  long long ansSum;
  std::map<int, int>::iterator it;
  for (it = first.begin(); it != first.end(); it++) {
    int l = it->second;
    int r = last[it->first];
    if (l == r) continue;
    long long get = it->first * 2 + sum[r - 1] - sum[l];
    int toCut = n - r + l - 1 + cut[r - 1] - cut[l];
    if (ansCut == -1 || ansSum < get) {
      ansSum = get;
      ansCut = toCut;
      al = l, ar = r;
    }
  }
  int cc = 0;
  printf("%I64d %d\n", ansSum, ansCut);
  for (int i = 1; i < al; i++) printf("%d%c", i, ++cc == ansCut ? '\n' : ' ');
  for (int i = al + 1; i < ar; i++) {
    if (ary[i] <= 0) printf("%d%c", i, ++cc == ansCut ? '\n' : ' ');
  }
  for (int i = ar + 1; i <= n; i++)
    printf("%d%c", i, ++cc == ansCut ? '\n' : ' ');
}
