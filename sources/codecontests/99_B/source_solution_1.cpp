#include <bits/stdc++.h>
using namespace std;
struct node {
  int v, id;
} cup[10005];
int cnt[100005], idx[10];
int cmp(node a, node b) { return a.v < b.v; }
int main() {
  int i, j, k, n;
  scanf("%d", &n);
  memset(cnt, 0, sizeof(cnt));
  for (i = 0; i < n; i++) {
    scanf("%d", &cup[i].v);
    cnt[cup[i].v]++;
    cup[i].id = i;
  }
  sort(cup, cup + n, cmp);
  if (n == 1) {
    puts("Exemplary pages.");
    return 0;
  }
  if (n == 2) {
    if (cup[0].v != cup[1].v) {
      if ((cup[1].v - cup[0].v) % 2 == 0) {
        printf("%d ml. from cup #%d to cup #%d.\n", (cup[1].v - cup[0].v) / 2,
               cup[0].id + 1, cup[1].id + 1);
      } else
        puts("Unrecoverable configuration.");
    } else
      puts("Exemplary pages.");
    return 0;
  }
  j = 0;
  int maxx = -1, Min = 9999999;
  int cnt1 = 0, cnt2 = 0;
  for (i = 0; i < n; i++) {
    if (i == 0 || cup[i].v != cup[i - 1].v) {
      j++;
      if (cup[i].v > maxx) {
        cnt1 = 1;
        maxx = cup[i].v;
        idx[2] = cup[i].id + 1;
      }
      if (cup[i].v < Min) {
        cnt2 = 1;
        Min = cup[i].v;
        idx[1] = cup[i].id + 1;
      }
    } else {
      if (cup[i].v == maxx) cnt1++;
      if (cup[i].v == Min) cnt2++;
    }
  }
  if (Min == maxx)
    puts("Exemplary pages.");
  else if (j == 3 && ((maxx - Min) % 2 == 0) && cnt1 == 1 && cnt2 == 1) {
    for (i = 0; i < n; i++)
      if (cup[i].v != Min && cup[i].v != maxx) k = cup[i].v;
    if (maxx + Min == 2 * k)
      printf("%d ml. from cup #%d to cup #%d.\n", (maxx - Min) / 2, idx[1],
             idx[2]);
    else
      puts("Unrecoverable configuration.");
  } else
    puts("Unrecoverable configuration.");
  return 0;
}
