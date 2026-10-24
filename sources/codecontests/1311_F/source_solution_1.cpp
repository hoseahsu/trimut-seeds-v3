#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int v[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) cin >> v[i];
  map<int, int> mp;
  vector<pair<int, int> > vi;
  vector<pair<int, int> > vf;
  for (int i = 0; i < n; i++) {
    vi.push_back({arr[i], v[i]});
    vf.push_back({v[i], arr[i]});
  }
  sort(vi.begin(), vi.end());
  sort(vf.begin(), vf.end());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int val = vi[i].first;
    mp[val] = i;
    ans += (2 * i - n + 1) * ((long long)val);
  }
  for (int i = 0; i < n; i++) {
    int val = vf[i].second;
    if (mp[val] == i) continue;
    ans += (i - mp[val]) * (long long)val;
  }
  cout << ans << endl;
}
