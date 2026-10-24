#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, pair<long long, long long> > > L;
set<pair<long long, long long> > Z;
struct N {
  int l;
  int d;
};
bool comp(N a, N b) { return a.l < b.l; }
long long combination[1010][1010];
int main() {
  long long k, c, i, j;
  cin >> k;
  combination[0][0] = 1;
  for (i = 1; i < 1004; i++) {
    combination[i][0] = 1;
    for (j = 1; j < i + 1; j++) {
      combination[i][j] =
          (combination[i - 1][j] + combination[i - 1][j - 1]) % 1000000007;
    }
  }
  long long ans = 1, N = 0, R;
  for (i = 0; i < k; i++) {
    cin >> c;
    N += c;
    R = c - 1;
    ans = (ans * combination[N - 1][R]) % 1000000007;
  }
  cout << ans << endl;
  return 0;
}
