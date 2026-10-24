#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int l, r;
  string moves;
  cin >> n;
  cin >> moves;
  for (int i = 0; i < n; i++) {
    if (moves[i] == 'L') {
      l = l + 1;
    }
  }
  r = n - l;
  cout << r + l + 1;
}
