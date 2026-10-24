#include <bits/stdc++.h>
using namespace std;
int X[] = {0, 0, 1, 0, 0, -1};
int Y[] = {0, 1, 0, 0, -1, 0};
int Z[] = {1, 0, 0, -1, 0, 0};
struct node {
  int x;
  string s;
  node() {}
  node(int x, string s) : x(x), s(s) {}
  bool operator<(const node& p) const { return x < p.x; }
};
node ara[10003];
int val[10000];
int main() {
  int i, j, k, l, x, y, z, t, m, n;
  cin >> n;
  memset(val, 0, sizeof(val));
  for (i = 0; i < n; i++) {
    cin >> ara[i].s >> ara[i].x;
  }
  sort(ara, ara + n);
  for (i = 0; i < n; i++) {
    if (ara[i].x > i) {
      printf("-1");
      return 0;
    }
    val[i] = i + 1 - ara[i].x;
    for (j = 0; j < i; j++) {
      if (val[j] >= val[i]) val[j]++;
    }
  }
  for (i = 0; i < n; i++) {
    cout << ara[i].s << " " << val[i] << endl;
  }
  return 0;
}
