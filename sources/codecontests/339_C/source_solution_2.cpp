#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-9;
long long INF = 1000000000000000005ll;
double PI = acos(-1);
inline string IntToString(long long int a) {
  char x[100];
  sprintf(x, "%lld", a);
  string s = x;
  return s;
}
inline long long int StringToInt(string a) {
  char x[100];
  long long int res;
  strcpy(x, a.c_str());
  sscanf(x, "%lld", &res);
  return res;
}
inline string uppercase(string s) {
  int n = (int)s.size();
  for (long long int i = 0; i < n; i++)
    if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}
inline string lowercase(string s) {
  int n = (int)s.size();
  for (long long int i = 0; i < n; i++)
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}
bool cmp(pair<long long int, long long int> a,
         pair<long long int, long long int> b) {
  long long int as = a.first - a.second;
  long long int binary_search = b.first - b.second;
  return (as > binary_search);
}
long long int dx[] = {-1, 0, 1, 0};
long long int dy[] = {0, 1, 0, -1};
vector<long long int> v[100005];
vector<bool> vis(100005);
string s;
long long int m;
vector<long long int> ans(1005);
void dfs(long long int lev, long long int bal, long long int cur,
         long long int pre) {
  if (lev > m) {
    cout << "YES" << '\n';
    for (long long int i = 1; i <= m; i++) {
      cout << ans[i] << " ";
    }
    exit(0);
  }
  if (lev % 2 == 1) {
    for (long long int i = 0; i < 10; i++) {
      if (s[i] == '1') {
        if (bal + i + 1 <= 10 && bal + i + 1 > 0 && (i + 1) != cur) {
          ans[lev] = i + 1;
          dfs(lev + 1, bal + i + 1, i + 1, cur);
        }
      }
    }
  } else {
    for (long long int i = 0; i < 10; i++) {
      if (s[i] == '1') {
        if (abs(bal - i - 1) <= 10 && bal - i - 1 < 0 && (i + 1) != cur) {
          ans[lev] = i + 1;
          dfs(lev + 1, bal - i - 1, i + 1, cur);
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  cin >> m;
  if (m == 1) {
    for (long long int i = 0; i < 10; i++) {
      if (s[i] == '1') {
        cout << "YES" << '\n';
        cout << i + 1 << '\n';
        return 0;
      }
    }
    cout << "NO" << '\n';
    return 0;
  }
  dfs(1, 0, 0, 0);
  cout << "NO" << '\n';
  return 0;
}
