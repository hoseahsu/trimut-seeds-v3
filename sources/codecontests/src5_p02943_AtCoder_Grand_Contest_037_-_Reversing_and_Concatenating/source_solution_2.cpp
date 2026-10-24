#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
 
using namespace std;
 
typedef long long ll;

string rev(string s) {
  reverse(s.begin(), s.end());
  return s;
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  string s; 
  cin >> s;
  if (k > 15) {
    char mn = 'z';
    for (char c : s) mn = min(mn, c);
    for (int i = 0; i < n; ++i) cout << mn;
    cout << '\n';
    return 0;
  }
  for (int i = 0; i < k; ++i) {
    string u = s + rev(s);
    if (i == k - 1) {
      s = string(n, 'z');
      for (int i = 0; i <= n; ++i) {
        s = min(s, u.substr(i, n));
      }
    } else {
      s = string(n, 'z');
      for (int i = 0; i <= n; ++i) {
        s = min(s, rev(u.substr(i, n)));
      }
      s = rev(s);
    }
  }
  cout << s << '\n';
}
 
