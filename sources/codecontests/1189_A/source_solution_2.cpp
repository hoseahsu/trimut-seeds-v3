#include <bits/stdc++.h>
using namespace std;
vector<int> v0;
vector<int> v1;
int cntZero = 0, cntOne = 0;
int n = 0;
string s;
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      cntZero++;
    else
      cntOne++;
  }
  if (cntOne == cntZero) {
    cout << 2 << endl;
    cout << s[0] << ' ';
    cout << s.substr(1) << endl;
  } else {
    cout << 1 << endl;
    cout << s << endl;
  }
  return 0;
}
