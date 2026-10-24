#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
const int N = 110000;
const double EPS = 1e-8;
pair<int, int> p[N];
int n;
int fromLeft() {
  auto ans = 2, prev = p[0].first;
  for (auto i = 1; i < n - 1; ++i) {
    auto cur = p[i];
    if (cur.first - cur.second > prev) {
      ++ans;
      prev = cur.first;
    } else if (cur.first + cur.second < p[i + 1].first) {
      ++ans;
      prev = cur.first + cur.second;
    } else {
      prev = cur.first;
    }
  }
  return ans;
}
int fromRight() {
  auto ans = 2, next = p[n - 1].first;
  for (auto i = n - 2; i >= 1; --i) {
    auto cur = p[i];
    if (cur.first + cur.second < next) {
      ++ans;
      next = cur.first;
    } else if (cur.first - cur.second > p[i - 1].first) {
      ++ans;
      next = cur.first - cur.second;
    } else {
      next = cur.first;
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (auto i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  if (n <= 2) {
    cout << n << endl;
    return 0;
  }
  cout << max(fromLeft(), fromRight()) << endl;
}
