#include <bits/stdc++.h>
using namespace std;
template <class T>
void max_self(T& a, const T& b) {
  if (a < b) a = b;
}
template <class T>
void min_self(T& a, const T& b) {
  if (a > b) a = b;
}
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);
int N, q, opt[1505][1505], memo[30][1505];
string in;
void solve(char c) {
  for (int idx = 0; idx < N; ++idx) {
    if (in[idx] != c) {
      opt[idx][0] = 0;
      continue;
    }
    opt[idx][0] = 1 + (idx ? opt[idx - 1][0] : 0);
  }
  for (int diff = 1; diff <= N; ++diff) {
    opt[0][diff] = 1;
  }
  for (int idx = 1; idx < N; ++idx) {
    for (int diff = 1; diff <= N; ++diff) {
      if (in[idx] == c) {
        opt[idx][diff] = 1 + opt[idx - 1][diff];
      } else {
        opt[idx][diff] = 1 + opt[idx - 1][diff - 1];
      }
    }
  }
  for (int diff = 1, bst; diff <= N; ++diff) {
    bst = 0;
    for (int idx = 0; idx < N; ++idx) {
      max_self(bst, opt[idx][diff]);
    }
    memo[c - 'a'][diff] = bst;
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  cin >> in;
  cin >> q;
  for (char c = 'a'; c <= 'z'; ++c) solve(c);
  for (int rep = 0; rep < q; ++rep) {
    int diff;
    char c;
    cin >> diff >> c;
    cout << memo[c - 'a'][diff] << '\n';
  }
  return 0;
}
