#include <bits/stdc++.h>
int exp(int x, int y, int p) {
  int res = 1;
  while (y) {
    if (y % 2) res = (res * x % p) % p;
    x = (x * x) % p;
    y /= 2;
  }
  return res;
}
int expo(int x, int y) {
  int res = 1;
  while (y) {
    if (y % 2) res = (res * x % ((int)1e9 + 7)) % ((int)1e9 + 7);
    x = (x * x) % ((int)1e9 + 7);
    y /= 2;
  }
  return res;
}
long long add(long long a, long long b) {
  return (a % ((int)1e9 + 7) + b % ((int)1e9 + 7) + ((int)1e9 + 7)) %
         ((int)1e9 + 7);
}
int sub(int a, int b) {
  return (a % ((int)1e9 + 7) - b % ((int)1e9 + 7) + ((int)1e9 + 7)) %
         ((int)1e9 + 7);
}
long long mul(long long a, long long b) {
  return ((a % ((int)1e9 + 7)) * (b % ((int)1e9 + 7)) + ((int)1e9 + 7)) %
         ((int)1e9 + 7);
}
int inv(int x) { return expo(x, ((int)1e9 + 7) - 2); }
int sv[2000006] = {0};
using namespace std;
string change_string(string s, long long index) {
  string ans = s;
  for (int i = 0; i <= index; i++) {
    if (s[index - i] == '0')
      ans[i] = '1';
    else
      ans[i] = '0';
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<long long> ans;
    for (int i = n - 1; i >= 0; i--) {
      if (s1[i] == s2[i])
        continue;
      else {
        if (s1[i] == s1[0]) {
          ans.push_back(i + 1);
          s1 = change_string(s1, i);
        } else {
          ans.push_back(1);
          if (s1[0] == '0')
            s1[0] = '1';
          else
            s1[0] = '0';
          ans.push_back(i + 1);
          s1 = change_string(s1, i);
        }
      }
    }
    cout << (long long)ans.size() << " ";
    for (int i = 0; i < (long long)ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
  }
}
