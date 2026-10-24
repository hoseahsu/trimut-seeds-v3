#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c == '8') cnt++;
  }
  cout << min(cnt, n / 11) << endl;
}
