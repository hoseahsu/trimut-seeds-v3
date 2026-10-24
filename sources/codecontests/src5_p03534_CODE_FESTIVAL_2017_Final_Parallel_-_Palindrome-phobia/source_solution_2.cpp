#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  int a[3] = {-n/3, -n/3, -n/3};
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a']++;
  }
  bool f = true;
  for (int i = 0; i < 3; i++) {
    if (a[i] != 0 && a[i] != 1) {
      f = false;
    }
  }
  cout << (f ? "YES": "NO") << endl;
  return 0;
}
