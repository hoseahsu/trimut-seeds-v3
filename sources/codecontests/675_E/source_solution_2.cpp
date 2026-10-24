#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
long long ar[100005], dp[100005];
long long arr[100005], tree[4 * 100005] = {0};
void build_tree(int node, int a, int b) {
  if (a > b) return;
  if (a == b) {
    tree[node] = arr[a];
    return;
  }
  build_tree(node * 2, a, (a + b) / 2);
  build_tree(node * 2 + 1, 1 + (a + b) / 2, b);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
void update_tree(int node, int a, int b, int i, int j, long long value) {
  if (a > b || a > j || b < i) return;
  if (a == b) {
    tree[node] = value;
    return;
  }
  update_tree(node * 2, a, (a + b) / 2, i, j, value);
  update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
long long query_tree(int node, int a, int b, int i, int j) {
  if (a > b || a > j || b < i) return 1e18;
  if (a >= i && b <= j) return tree[node];
  long long q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
  long long q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);
  long long res = min(q1, q2);
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  long long n;
  cin >> n;
  build_tree(1, 0, n);
  for (long long i = 1; i < n; ++i) cin >> ar[i];
  dp[n] = 1000000000;
  dp[n - 1] = 1;
  update_tree(1, 0, n, n - 1, n - 1, dp[n - 1] + n - 1);
  for (int i = n - 2; i >= 1; i--) {
    dp[i] = query_tree(1, 0, n, i + 1, min(ar[i], n - 1)) + n - i - ar[i];
    update_tree(1, 0, n, i, i, dp[i] + i);
  }
  long long an = 0;
  for (long long i = 1; i < n; ++i) an += dp[i];
  cout << an << endl;
  return 0;
}
