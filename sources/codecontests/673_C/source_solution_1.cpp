#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
int A[N];
int main(int argc, char const *argv[]) {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  vector<int> sol(n + 1);
  for (int i = 0; i < n; i++) {
    vector<int> cnt(n + 1);
    pair<int, int> ans = make_pair(0, 0);
    for (int j = i; j < n; j++) {
      cnt[A[j]]++;
      if (cnt[A[j]] > ans.first) {
        ans = make_pair(cnt[A[j]], A[j]);
      } else if (cnt[A[j]] == ans.first && A[j] < ans.second) {
        ans = make_pair(cnt[A[j]], A[j]);
      }
      sol[ans.second]++;
    }
  }
  for (int i = 1; i <= n; i++) cout << sol[i] << ' ';
  cout << '\n';
  return 0;
}
