#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<long long, long long> isnum;
  vector<vector<long long>> table(3, vector<long long>(6, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> table[i][j];
      isnum[table[i][j]] = 1;
    }
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (n == 1) break;
      isnum[table[0][i] * 10 + table[1][j]] = 1;
      isnum[table[1][j] * 10 + table[0][i]] = 1;
      for (int k = 0; k < 6; k++) {
        if (n == 2) break;
        isnum[table[0][i] * 10 + table[2][k]] = 1;
        isnum[table[2][k] * 10 + table[0][i]] = 1;
        isnum[table[1][j] * 10 + table[2][k]] = 1;
        isnum[table[2][k] * 10 + table[1][j]] = 1;
        isnum[table[0][i] * 100 + table[2][k] * 10 + table[1][j]] = 1;
        isnum[table[0][i] * 100 + table[1][j] * 10 + table[2][k]] = 1;
        isnum[table[1][j] * 100 + table[2][k] * 10 + table[0][i]] = 1;
        isnum[table[1][j] * 100 + table[0][i] * 10 + table[2][k]] = 1;
        isnum[table[2][k] * 100 + table[1][j] * 10 + table[0][i]] = 1;
        isnum[table[2][k] * 100 + table[0][i] * 10 + table[1][j]] = 1;
      }
    }
  }
  for (int i = 1; i <= 999; i++) {
    if (!isnum[i]) {
      cout << i - 1 << endl;
      return 0;
    }
  }
}
