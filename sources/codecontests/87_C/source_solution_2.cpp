#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T gcd(T a, T b) {
  T c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
int getInt() {
  int x;
  scanf("%d", &x);
  return x;
}
long long getLongLong() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
double getDouble() {
  double x;
  scanf("%lf", &x);
  return x;
}
char getChar() {
  char x;
  scanf("%c", &x);
  return x;
}
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream second(s);
  string x;
  while (getline(second, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << "  ";
  err(++it, args...);
}
void FastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}
vector<pair<int, int> > ls[112345];
int gn[112345][505] = {0};
int grundy(int i) {
  if (i <= 2) return 0;
  if (gn[i][0] != -1) return gn[i][0];
  set<int> mex;
  for (int j = 0; j < ls[i].size(); j++) {
    int k = ls[i][j].first, up = ls[i][j].second + k;
    int xsum = 0;
    for (int p = (ls[i][j].second); p < up; p++) xsum ^= grundy(p);
    gn[i][k] = xsum;
    mex.insert(xsum);
  }
  int g = 0;
  for (set<int>::iterator it = mex.begin(); it != mex.end(); it++, g++)
    if (g != *it) break;
  return gn[i][0] = g;
}
int main() {
  memset(gn, -1, sizeof gn);
  int mxk = 0;
  for (int i = 1; i <= 100000; i++) {
    int sum = i;
    for (int j = i + 1; j <= 100000; j++) {
      sum += j;
      if (sum > 100000) break;
      ls[sum].push_back({j - i + 1, i});
    }
  }
  for (int i = 0; i <= 100000; i++) sort(ls[i].begin(), ls[i].end());
  gn[0][0] = gn[1][0] = gn[2][0] = 0;
  int x = getInt();
  grundy(x);
  if (gn[x][0]) {
    for (int i = 2; i < 500; i++)
      if (!gn[x][i]) {
        printf("%d\n", i);
        break;
      }
  } else
    puts("-1");
  return 0;
}
