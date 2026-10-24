#include <bits/stdc++.h>
using namespace std;
const int int_inf = 0x3f3f3f3f;
const long long int ll_inf = 0x3f3f3f3f3f3f3f3f;
const int max_n = 2e5 + 5;
int pri[max_n >> 1], num[max_n >> 1];
bool vis[max_n];
int init() {
  int i, j;
  int lim = max_n - 5;
  int cnt = 0;
  for (i = 2; i <= lim; i++) {
    if (!vis[i]) pri[cnt++] = i;
    for (j = 0; j < cnt && i * pri[j] <= lim; j++) {
      vis[i * pri[j]] = true;
      if (i % pri[j] == 0) break;
    }
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int i, j;
  int n;
  int cnt = init();
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> num[i];
  }
  long long int ans = 1;
  for (i = 0; i < cnt; i++) {
    long long int k = (long long int)pri[i];
    while (1) {
      int flag = 0;
      for (j = 1; j <= n; j++) {
        if (num[j] % k) {
          flag++;
        }
        if (flag == 2) break;
      }
      if (flag == 2) break;
      k *= pri[i];
    }
    k /= pri[i];
    ans *= k;
  }
  cout << ans << endl;
  return 0;
}
