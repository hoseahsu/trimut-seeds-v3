#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int c[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  c[1] = 1;
  c[2] = 2;
  for (int i = 3; i <= n; i++) {
    c[i] = i + c[i - 2];
  }
  cout << c[n] << endl;
  return 0;
}
