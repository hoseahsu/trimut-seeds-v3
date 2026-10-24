#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
const unsigned long long p1 = 19260817, p2 = 1e9 + 7, B = 211;
template <class T>
inline bool read(T& x) {
  x = 0;
  bool f = 0;
  char ch;
  for (ch = getchar(); !isdigit(ch); ch = getchar()) {
    if (ch == EOF) return 0;
    f |= ch == '-';
  }
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  if (f) x = -x;
  return 1;
}
template <class T>
void write(T x) {
  if (x < 0) {
    putchar('-'), write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar((x % 10) | 48);
}
template <class T>
inline void writeln(T x) {
  write(x), putchar('\n');
}
template <class T>
inline void writespace(T x) {
  write(x), putchar(' ');
}
long long n, k, ans;
struct node {
  long long t, b;
  void in() {
    read(t);
    read(b);
  }
} music[300010];
bool cmp(node a, node b) { return a.b > b.b; }
priority_queue<long long> q;
queue<long long> que;
signed main() {
  srand(20050210);
  read(n), read(k);
  for (register long long i = 1; i <= n; ++i) music[i].in();
  sort(music + 1, music + 1 + n, cmp);
  long long cnt = 0;
  for (register long long i = 1; i <= n; ++i) {
    q.push(-music[i].t);
    cnt += music[i].t;
    if ((long long)q.size() > k) {
      cnt += q.top();
      q.pop();
    }
    ans = max(ans, cnt * music[i].b);
  }
  write(ans);
  return 0;
}
