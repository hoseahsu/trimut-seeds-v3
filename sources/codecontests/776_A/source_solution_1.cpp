#include <bits/stdc++.h>
using namespace std;
int main() {
  string name1, name2, names[10001][2];
  cin >> name1;
  cin >> name2;
  int n, i, j;
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < 2; j++) {
      cin >> names[i][j];
    }
  }
  cout << name1 << " " << name2 << "\n";
  for (i = 0; i < n; i++) {
    if (names[i][0] == name1) {
      name1 = names[i][1];
      cout << name1 << " " << name2 << "\n";
    }
    if (names[i][0] == name2) {
      name2 = names[i][1];
      cout << name1 << " " << name2 << "\n";
    }
  }
  return 0;
}
