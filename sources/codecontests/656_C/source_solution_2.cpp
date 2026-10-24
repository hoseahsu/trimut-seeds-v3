#include <bits/stdc++.h>
using namespace std;
bool isint(double x) { return (int)x == x; }
int main() {
  string s;
  long long sum = 0;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (isupper(s[i])) {
      sum += s[i] - '@';
    } else if (islower(s[i])) {
      sum -= s[i] - '`';
    }
  }
  cout << sum;
  return 0;
}
