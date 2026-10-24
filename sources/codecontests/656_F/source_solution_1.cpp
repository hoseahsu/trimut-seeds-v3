#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int count = 1;
  for (int p = 1; p < s.size(); p++) {
    count += (s[p] == '0') ? 9 : (s[p] - '0');
  }
  cout << count << "\n";
}
