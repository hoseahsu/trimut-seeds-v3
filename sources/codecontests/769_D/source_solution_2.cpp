#include <bits/stdc++.h>
using namespace std;
int calc_dist(int a, int b) {
  register int i = 14;
  register int k = 0;
  while (i-- > 0) {
    if ((a ^ b) & 1) k++;
    a >>= 1;
    b >>= 1;
  }
  return k;
}
int main() {
  int n;
  int k;
  cin >> n >> k;
  vector<int> arr(n);
  vector<pair<int, int> > com;
  map<int, int> m;
  for (int register i = 0; i < n; i++) {
    cin >> arr[i];
    if (m.find(arr[i]) != m.end()) {
      m[arr[i]]++;
    } else
      m[arr[i]] = 1;
  }
  for (auto register i = m.begin(); i != m.end(); i++) {
    com.push_back(make_pair(i->first, i->second));
  }
  int c = com.size();
  long long ans = 0;
  for (int register i = 0; i < c; i++) {
    for (int register j = i + 1; j < c; j++)
      if (calc_dist(com[i].first, com[j].first) == k)
        ans += (long long)com[i].second * (long long)com[j].second;
    if (k == 0) {
      ans += ((long long)com[i].second * (com[i].second - 1)) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}
