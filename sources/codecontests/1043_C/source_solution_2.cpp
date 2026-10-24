#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cerr.tie(0);
  string a;
  cin >> a;
  vector<int> res[2];
  for (char e : a) {
    vector<int> ne[2];
    if (e == 'a') {
      ne[0] = res[1];
      ne[0].push_back(1);
      ne[1] = res[1];
      ne[1].push_back(0);
    } else {
      ne[0] = res[0];
      ne[0].push_back(0);
      ne[1] = res[0];
      ne[1].push_back(1);
    }
    res[0] = ne[0];
    res[1] = ne[1];
  }
  for (int e : res[0]) {
    cout << e << " ";
  }
}
