#include <bits/stdc++.h>
using namespace std;
long long pow(int a, int b) {
  long long ret = 1;
  while (b--) {
    ret = (ret * a) % 1000000007ll;
  }
  return ret;
}
long long work(const char* s, int n) {
  if (n == 0) {
    return 0;
  }
  long long ret = work(s + 1, n - 1);
  ret = (ret + ret) % 1000000007ll;
  if (*s == '1') {
    ret = (ret + (pow(2, 2 * n - 2))) % 1000000007ll;
  }
  return ret;
}
int main() {
  string s;
  getline(cin, s);
  cout << work(s.data(), s.size()) << "\n";
  return 0;
}
