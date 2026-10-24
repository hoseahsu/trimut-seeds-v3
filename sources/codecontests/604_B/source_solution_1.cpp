#include <bits/stdc++.h>
using namespace std;
int dx8[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy8[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int X[6] = {0, 0, 0, -1, 0, 1};
int Y[6] = {0, 0, -1, 0, 1, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
int n, k;
vector<int> v;
int boxes = 0;
bool check(long long mid) {
  boxes = 0;
  for (int i = 0, j = n - 1; i <= j;) {
    if (v[i] + v[j] <= mid && i != j) {
      boxes++;
      i++, j--;
    } else if (v[j] > v[i] && v[j] <= mid) {
      boxes++;
      j--;
    } else if (v[i] >= v[j] && v[i] <= mid) {
      boxes++;
      i++;
    } else
      return 0;
  }
  return 1;
}
int main() {
  cin >> n >> k;
  v.resize(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  long long s = 1, e = 1e12, mid, ans = 1e12;
  while (s <= e) {
    mid = s + (e - s) / 2;
    if (check(mid) && boxes <= k) {
      ans = mid;
      e = mid - 1;
    } else
      s = mid + 1;
  }
  cout << ans << "\n";
}
