#include <bits/stdc++.h>
using namespace std;
int func(string s, char ch) {
  if (s.size() == 1) return s[0] != ch;
  int mid = s.size() / 2;
  int cnt_l = s.size() / 2 - count(s.begin(), s.begin() + mid, ch) +
              func(string(s.begin() + mid, s.end()), ch + 1);
  int cnt_r = s.size() / 2 - count(s.begin() + mid, s.end(), ch) +
              func(string(s.begin(), s.begin() + mid), ch + 1);
  return min(cnt_l, cnt_r);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << func(s, 'a') << endl;
  }
}
