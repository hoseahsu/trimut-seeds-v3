#include <bits/stdc++.h>
using namespace std;
const long long N = 100000, QU = 100000, XOR_I = 1048576;
long long n, qu, m;
long long a[N + 1];
long long Xor[N + 1];
long long bsz;
struct query {
  long long l, r, qid;
  friend bool operator<(query x, query y) {
    long long xlin = (x.l + bsz - 1) / bsz, ylin = (y.l + bsz - 1) / bsz;
    return xlin == ylin ? xlin & 1 ? x.r < y.r : x.r > y.r : xlin < ylin;
  }
} qry[QU + 1];
long long cnt[XOR_I];
long long ans[QU + 1];
signed main() {
  cin >> n >> qu >> m;
  for (long long i = 1; i <= n; i++) cin >> a[i], Xor[i] = Xor[i - 1] ^ a[i];
  for (long long i = 1; i <= qu; i++)
    cin >> qry[i].l >> qry[i].r, qry[i].qid = i;
  bsz = max(1ll, min(n, (long long)(n / sqrt(qu))));
  sort(qry + 1, qry + qu + 1);
  long long nowl = 1, nowr = 0, nowans = 0;
  for (long long i = 1; i <= qu; i++) {
    long long l = qry[i].l, r = qry[i].r, qid = qry[i].qid;
    while (nowl > l) cnt[Xor[--nowl]]++, nowans += cnt[Xor[nowl - 1] ^ m];
    while (nowr < r)
      cnt[Xor[++nowr]]++, nowans += cnt[Xor[nowr] ^ m] - !m +
                                    ((Xor[nowl - 1] ^ Xor[nowr]) == m);
    while (nowl < l) nowans -= cnt[Xor[nowl - 1] ^ m], cnt[Xor[nowl++]]--;
    while (nowr > r)
      nowans -= cnt[Xor[nowr] ^ m] - !m + ((Xor[nowl - 1] ^ Xor[nowr]) == m),
          cnt[Xor[nowr--]]--;
    ans[qid] = nowans;
  }
  for (long long i = 1; i <= qu; i++) cout << ans[i] << "\n";
  return 0;
}
