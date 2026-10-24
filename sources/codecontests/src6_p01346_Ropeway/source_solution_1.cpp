#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))


struct FenwickTree {
  static const int SIZE = 60000;
  int tree[SIZE + 10];
  FenwickTree() { memset(tree, 0, sizeof(tree)); }
  void add(int index, int value) {
    for (index += SIZE / 2; index < SIZE + 1; index += (index & -index)) {
      tree[index] += value;
    }
  }
  int sum(int index) {
    int ret = 0;
    for (index += SIZE / 2; index > 0; index -= (index & -index)) {
      ret += tree[index];
    }
    return ret;
  }
};

int n;
ll l, m, r;
ll seq[110];
FenwickTree ftree[2];

int main() {
  while (scanf("%d %lld %lld %lld", &n, &l, &m, &r) > 0) {
    m *= 2;
    r *= 2;
    REP(i, n) {
      scanf("%lld", &seq[i]);
    }
    ftree[0] = FenwickTree();
    ftree[1] = FenwickTree();
    ftree[0].add(0, 1);
    ftree[0].add(1, -1);
    REP(i, n) {
      int prev = i & 1;
      int next = prev ^ 1;
      ftree[next] = FenwickTree();
      ll l1 = -l * seq[i];
      ll r1 = -r * seq[i];
      ll l2 = r * seq[i];
      ll r2 = l * seq[i];
      FOREQ(w, -m, m) {
        if (ftree[prev].sum(w) == 0) { continue; }
        ll l, r;
        l = max(-m - 1, min(m + 1, l1 + w));
        r = max(-m - 1, min(m + 1, r1 + w));
        ftree[next].add(l, 1);
        ftree[next].add(r + 1, -1);
        l = max(-m - 1, min(m + 1, l2 + w));
        r = max(-m - 1, min(m + 1, r2 + w));
        ftree[next].add(l, 1);
        ftree[next].add(r + 1, -1);
      }
      bool ok = false;
      FOREQ(w, -m, m) {
        if (ftree[next].sum(w) >= 1) { ok = true; }
        //putchar(ftree[next].sum(w) > 0 ? 'o' : 'x');
      }
      //puts("");
      if (!ok) { goto ng; }
    }
    puts("Yes");
    continue;
ng:
    puts("No");
  }
}