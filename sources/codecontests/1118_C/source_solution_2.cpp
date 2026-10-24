#include <bits/stdc++.h>
using namespace std;
long long mat[22][22];
int main() {
  long long n;
  cin >> n;
  map<long long, long long> mp;
  for (long long i = 0; i < n * n; i++) {
    long long val;
    cin >> val;
    mp[val]++;
  }
  if (n % 2 == 0) {
    long long i = 1, j = 1;
    for (auto it : mp) {
      if (mp[it.first] % 4 != 0) {
        cout << "NO" << endl;
        return 0;
      }
      while (mp[it.first] != 0) {
        mat[i][j] = it.first;
        mp[it.first] -= 4;
        j++;
        if (j > n / 2) {
          j = 1;
          i++;
        }
      }
    }
    for (int i = 1; i <= n / 2; i++) {
      for (int j = 1; j <= n / 2; j++) {
        mat[n - i + 1][j] = mat[n - i + 1][n - j + 1] = mat[i][n - j + 1] =
            mat[i][j];
      }
    }
  } else {
    long long i = 1, j = 1;
    for (auto it : mp) {
      while (mp[it.first] >= 4) {
        mat[i][j] = it.first;
        mat[i][n - j + 1] = mat[n - i + 1][j] = mat[n - i + 1][n - j + 1] =
            mat[i][j];
        mp[it.first] -= 4;
        j++;
        if (j > n / 2) {
          j = 1;
          i++;
        }
        if (i == n / 2 + 1) break;
      }
      if (i == n / 2 + 1) break;
    }
    i = n / 2 + 1;
    j = 1;
    for (auto it : mp) {
      while (mp[it.first] >= 2) {
        mat[i][j] = mat[i][n - j + 1] = it.first;
        mp[it.first] -= 2;
        j++;
        if (j == n / 2 + 1) break;
      }
      if (j == n / 2 + 1) break;
    }
    i = 1;
    j = n / 2 + 1;
    for (auto it : mp) {
      while (mp[it.first] >= 2) {
        mat[i][j] = mat[n - i + 1][j] = it.first;
        mp[it.first] -= 2;
        i++;
        if (i == n / 2 + 1) break;
      }
      if (i == n / 2 + 1) break;
    }
    long long ctr = 0;
    for (auto it : mp) {
      while (mp[it.first] >= 1) {
        mat[n / 2 + 1][n / 2 + 1] = it.first;
        mp[it.first] -= 1;
        ctr++;
        if (ctr == 1) break;
      }
      if (ctr == 1) break;
    }
    for (auto it : mp) {
      if (mp[it.first] != 0) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}
