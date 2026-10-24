#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
string g = "";
void fun(vector<long long int> ans[], long long int p, long long int s,
         long long int d) {
  if (ans[s].size() == 1 || g.size() == d - 1) {
    g = g + char(ans[s][0] + 97);
    return;
  }
  if (ans[s][0] != p) {
    g = g + char(ans[s][0] + 97);
    fun(ans, s, ans[s][0], d);
  } else {
    g = g + char(ans[s][1] + 97);
    fun(ans, s, ans[s][1], d);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(20);
  long long int t = 1;
  cin >> t;
  while (t--) {
    string a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < b.size(); i++) {
      if (c[i] == a[i])
        b[i] = c[i];
      else
        a[i] = c[i];
    }
    if (b == a)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
  return 0;
}
