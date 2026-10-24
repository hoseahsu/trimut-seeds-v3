#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int a;
  cin >> a;
  int l = -2e9;
  int r = 2e9;
  while (a--) {
    string c;
    int n;
    char s;
    cin >> c >> n >> s;
    if (c == ">") {
      if (s == 'Y')
        l = max(l, n + 1);
      else
        r = min(r, n);
    } else if (c == "<") {
      if (s == 'Y')
        r = min(r, n - 1);
      else
        l = max(l, n);
    } else if (c == "<=") {
      if (s == 'Y')
        r = min(r, n);
      else
        l = max(l, n + 1);
    } else {
      if (s == 'Y')
        l = max(l, n);
      else
        r = min(r, n - 1);
    }
  }
  if (l <= r)
    cout << l;
  else
    cout << "Impossible";
}
