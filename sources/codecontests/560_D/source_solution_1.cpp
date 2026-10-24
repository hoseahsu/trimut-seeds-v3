#include <bits/stdc++.h>
using namespace std;
bool havasar(string ::iterator s1, int n, string::iterator s2, int m) {
  if (n != m) return 0;
  if (n == 1) return (*s1) == (*s2);
  bool mark = true;
  string::iterator s3 = s1, s4 = s2;
  for (int i = 0; i < n; i++) {
    if ((*s1) != (*s2)) {
      mark = false;
      break;
    }
    s1++;
    s2++;
  }
  s1 = s3;
  s2 = s4;
  if (mark) return true;
  if (n % 2 == 1) return false;
  int tn = n / 2;
  int tm = m / 2;
  int kn = n - tn;
  int km = m - tm;
  return ((havasar(s1, tn, s2, tm) && havasar(s1 + tn, kn, s2 + tm, km)) ||
          (havasar(s1, tn, s2 + tm, km) && havasar(s1 + tn, kn, s2, tm)));
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << (havasar(s1.begin(), s1.size(), s2.begin(), s2.size()) ? "YES" : "NO")
       << endl;
  return 0;
}
