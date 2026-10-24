#include <bits/stdc++.h>
using namespace std;
int n, T;
pair<int, int> a[200010];
long long getval(vector<long long> &f, int pos) {
  pos++;
  long long ans = 0;
  for (int i = pos; i > 0; i -= (i & -i)) ans += f[i];
  return ans;
}
void upd(vector<long long> &f, int pos, int val) {
  pos++;
  for (int i = pos; i < int(f.size()); i += (i & -i)) f[i] += val;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].first;
  for (int i = 0; i < n; i++) cin >> a[i].second;
  sort(a, a + n);
  vector<int> compress_v;
  for (int i = 0; i < n; i++) compress_v.push_back(a[i].second);
  sort(compress_v.begin(), compress_v.end());
  compress_v.resize(unique(compress_v.begin(), compress_v.end()) -
                    compress_v.begin());
  vector<long long> cnt(compress_v.size() + 1), sum(compress_v.size() + 1);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int pos = lower_bound(compress_v.begin(), compress_v.end(), a[i].second) -
              compress_v.begin();
    ans += getval(cnt, pos) * 1ll * a[i].first - getval(sum, pos);
    upd(cnt, pos, 1);
    upd(sum, pos, a[i].first);
  }
  cout << ans;
}
