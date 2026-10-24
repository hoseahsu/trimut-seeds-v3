#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5 + 200000;
long long arr[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  N <<= 1;
  for (int i = (int)0; i < (int)N; ++i) cin >> arr[i];
  sort(arr, arr + N);
  int orN = N >> 1;
  long long ans = numeric_limits<long long>::max();
  for (int i = (int)0; i < (int)orN; ++i) {
    long long newans;
    if (i == 0) {
      newans = (arr[i + orN - 1] - arr[i]) * (arr[N - 1] - arr[orN]);
    } else {
      newans = (arr[i + orN - 1] - arr[i]) * (arr[N - 1] - arr[0]);
    }
    ans = min(ans, newans);
  }
  cout << ans;
  return 0;
}
