#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int t, m, n, id[MAXN], size[MAXN], num = 1;
char op[20];
bool free(int p, int n) {
  if (p + n - 1 > m) return false;
  for (int i = 0; i < n; ++i) {
    if (id[p + i] != 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (cin >> t >> m; t--;) {
    cin >> op;
    if (op[0] == 'd') {
      for (int i = 1, j = 1; j <= m; ++j) {
        if (id[j] > 0) {
          int tid = id[j];
          int tsz = size[j];
          id[j] = 0;
          size[j] = 0;
          id[i] = tid;
          size[i] = tsz;
          i += tsz;
          j += tsz - 1;
        }
      }
    } else {
      cin >> n;
      bool found = false;
      if (op[0] == 'a') {
        for (int i = 1; i <= m; ++i) {
          if (id[i] != 0)
            i += size[i] - 1;
          else if (free(i, n)) {
            id[i] = num;
            size[i] = n;
            cout << num++ << endl;
            found = true;
            break;
          }
        }
        if (!found) cout << "NULL" << endl;
      } else {
        for (int i = 1; n > 0 && i <= m; ++i) {
          if (id[i] == n) {
            id[i] = 0;
            size[i] = 0;
            found = true;
            break;
          }
        }
        if (!found) cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
      }
    }
  }
  return 0;
}
