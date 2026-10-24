#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

#define int long long
typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
#define MAX_N (1<<17)

struct SegTree {
  P seg[MAX_N*2-1];
  SegTree() {
    for (int i=0; i<MAX_N*2-1; i++) seg[i] = P(0, 0);
  }

  void update(int i, P x) {
    i += MAX_N-1;
    if (seg[i] >= x) return;
    seg[i] = x;
    while (i > 0) {
      i = (i-1) / 2;
      seg[i] = max(seg[i*2+1], seg[i*2+2]);
    }
  }
  P query(int a, int b, int k=0, int l=0, int r=MAX_N) {
    if (r <= a || b <= l) return P(0, 0);
    if (a <= l && r <= b) return seg[k];
    return max(
      query(a, b, k*2+1, l, (l+r)/2),
      query(a, b, k*2+2, (l+r)/2, r)
    );
  }
};

int N;
int A[100000];
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  rep(i, N) cin >> A[i], A[i]++;
  SegTree seg;
  rep(i, N) {
    P p = seg.query(0, A[i]);
    seg.update(A[i], P(p._1+1, p._2+A[i]-1));
  }
  cout<< seg.query(0, MAX_N)._2 << "\n";
  return 0;
}

