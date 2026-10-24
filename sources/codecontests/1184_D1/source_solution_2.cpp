#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 5;
const int INF = 1e9;
const int M = 1000000007;
vector<int> adj[100005];
vector<int> vis(100005, 0);
void solve() { return; }
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    int n, k, m, te;
    cin >> n >> k >> m >> te;
    int start = 1, end = n;
    while (te--) {
      int a, b;
      cin >> a >> b;
      if (a == 0) {
        if (b < k) {
          k = k - b;
          end = end - b;
        } else if (b == k) {
          end = k;
        } else {
          end = b;
        }
      } else {
        if (b <= k) {
          k++;
          end++;
        } else {
          end++;
        }
      }
      cout << end << ' ' << k << '\n';
    }
  }
  return 0;
}
