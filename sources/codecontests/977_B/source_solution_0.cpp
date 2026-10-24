#include <bits/stdc++.h>
using ll = long long;
using namespace std;
template <typename... Args>
void read(Args &...args) {
  ((cin >> args), ...);
}
template <typename... Args>
void write(Args... args) {
  ((cout << args << " "), ...);
}
template <typename... Args>
void writeln(Args... args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
template <typename T>
void read(vector<T> &a) {
  for (auto &ele : a) cin >> ele;
}
template <typename T>
void writeln(vector<T> &a) {
  for (auto &ele : a) cout << ele << ' ';
  cout << "\n";
}
const pair<int, int> dxy[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const pair<int, int> fxy[] = {{-1, 0}, {1, 0},   {0, -1}, {0, 1},
                              {1, 1},  {-1, -1}, {-1, 1}, {1, -1}};
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  int n;
  string s;
  read(n, s);
  map<string, int> m;
  for (int i = 0; i < n - 1; ++i) {
    string tmp = s.substr(i, 2);
    m[tmp]++;
  }
  int cnt = 0;
  string res;
  for (auto it = m.begin(); it != m.end(); ++it) {
    if (it->second > cnt) {
      cnt = it->second;
      res = it->first;
    }
  }
  writeln(res);
  return 0;
}
