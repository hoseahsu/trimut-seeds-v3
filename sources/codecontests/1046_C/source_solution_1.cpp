#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  t = 1;
  while (t--) {
    long long int n, i, tot, cur, k, j, sum = 0;
    cin >> n >> k;
    vector<long long int> v;
    vector<long long int> a;
    for (i = 0; i < n; i++) {
      long long int temp;
      cin >> temp;
      v.push_back(temp);
    }
    for (i = 0; i < n; i++) {
      long long int temp;
      cin >> temp;
      a.push_back(temp);
    }
    cur = v[k - 1] + a[0];
    long long int ans = k, st = -1;
    for (i = 0; i < n; i++) {
      if (v[i] > cur) {
        continue;
      } else {
        st = i;
        break;
      }
    }
    long long int l = (n - k + 1), r = n - 1;
    vector<long long int> temp;
    for (i = 0; i < k - 1 && l <= r; i++) {
      if ((v[i] + a[r]) > cur) {
        temp.push_back(v[i] + a[l++]);
      } else {
        r--;
      }
    }
    cout << temp.size() + 1 << endl;
  }
}
