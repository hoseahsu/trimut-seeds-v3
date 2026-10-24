#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  cin >> TESTS;
  while (TESTS--) {
    string s;
    cin >> s;
    int l = s.size();
    if (s[l - 1] == 'o')
      cout << "FILIPINO";
    else if (s[l - 1] == 'u')
      cout << "JAPANESE";
    else
      cout << "KOREAN";
    cout << '\n';
  }
  return 0;
}
