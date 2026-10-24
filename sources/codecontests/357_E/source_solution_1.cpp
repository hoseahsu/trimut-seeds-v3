#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, n;
  cin >> n;
  long long i;
  map<long long, long long> mp;
  srand(time(NULL));
  for (i = 0; i < n; i++) {
    cin >> m;
    mp[m]++;
  }
  long long c1, c2, c3, c4, ct = 0;
  c1 = mp[1];
  c2 = mp[2];
  c3 = mp[3];
  c4 = mp[4];
  while ((c1 > 0) || (c2 > 0)) {
    long long c = min(c1, c2);
    ct += c;
    c1 -= c;
    c2 -= c;
    c3 += c;
    if (c1 > 0) {
      while (c1 >= 3) {
        c3++;
        ct += 2;
        c1 -= 3;
      }
      if (c1 == 1) {
        if (c3)
          ct++;
        else if (c4 >= 2) {
          ct += 2;
        } else {
          cout << -1;
          return 0;
        }
      } else if (c1 == 2) {
        if (c3 >= 2)
          ct += 2;
        else if (c4) {
          ct += 2;
        } else {
          cout << -1;
          return 0;
        }
      }
      cout << ct;
      return 0;
    } else {
      while (c2 >= 3) {
        c2 -= 3;
        c3 += 2;
        ct += 2;
      }
      if (c2 == 0) {
        cout << ct;
        return 0;
      } else if (c2 == 1) {
        if (c4 > 0)
          ct++;
        else if (c3 >= 2)
          ct += 2;
        else {
          cout << -1;
          return 0;
        }
        cout << ct;
        return 0;
      } else {
        ct += 2;
        cout << ct;
        return 0;
      }
    }
  }
  cout << ct;
  return 0;
}
