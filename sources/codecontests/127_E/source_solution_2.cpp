#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2005;
int n, con;
bool r[2][MAX_N];
bool c[2][MAX_N];
char a[MAX_N][MAX_N];
int main() {
  cin >> n;
  for (int i(0); i < (n); i++) {
    cin >> a[i];
    for (int j(0); j < (n); j++) a[i][j] -= '0';
  }
  for (int j = n; j-- > 0;) {
    for (int i(0); i < (j); i++) {
      if (a[i][j] ^ r[0][i] ^ c[0][j]) {
        con++;
        r[0][i] ^= 1;
        c[0][j] ^= 1;
      }
    }
  }
  for (int j(0); j < (n); j++) {
    for (int i = n; i-- > j + 1;) {
      if (a[i][j] ^ r[1][i] ^ c[1][j]) {
        con++;
        r[1][i] ^= 1;
        c[1][j] ^= 1;
      }
    }
  }
  for (int i(0); i < (n); i++)
    if (a[i][i] ^ r[0][i] ^ c[0][i] ^ r[1][i] ^ c[1][i]) con++;
  cout << con << endl;
}
