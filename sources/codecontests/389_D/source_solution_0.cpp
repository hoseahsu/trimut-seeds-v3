#include <bits/stdc++.h>
using namespace std;
int powInt(int x, int y) {
  int r = 1;
  while (y > 0) {
    if (y & 1) r = (r * x);
    x = (x * x);
    y /= 2;
  }
  return r;
}
int qrt(long k, int ex) {
  int res = 1;
  while (powInt(res, ex) <= k) {
    res++;
  }
  return res - 1;
}
int main() {
  int k;
  cin >> k;
  vector<int> nds;
  int ex = 3;
  int sum, n;
  do {
    int tmpk = k;
    sum = 0;
    while (tmpk > 0) {
      int tmp = qrt((long)tmpk, ex);
      nds.push_back(tmp);
      tmpk -= powInt(tmp, ex);
    }
    for (int((i)) = (0); ((i)) < ((nds.size())); ((i))++) {
      sum += nds[i];
    }
    n = ex * sum + 2;
    if (n > 1000) {
      nds.clear();
      ex++;
    }
  } while (n > 1000);
  string init(n, 'N');
  vector<string> g(n, init);
  for (int(i) = (2); (i) < (sum + 2); (i)++) {
    g[0][i] = 'Y';
    g[i][0] = 'Y';
    g[1][i + (ex - 1) * sum] = 'Y';
    g[i + (ex - 1) * sum][1] = 'Y';
  }
  int offset = 2;
  cout << n << endl;
  for (int((i)) = (0); ((i)) < ((nds.size())); ((i))++) {
    int c = nds[i];
    for (int(j) = (offset); (j) < (offset + c); (j)++) {
      for (int(q) = (0); (q) < (ex - 1); (q)++) {
        for (int(p) = (0); (p) < (nds[i]); (p)++) {
          g[j + q * sum][(q + 1) * sum + p + offset] = 'Y';
          g[(q + 1) * sum + p + offset][j + q * sum] = 'Y';
        }
      }
    }
    offset += c;
  }
  for (int((i)) = (0); ((i)) < ((n)); ((i))++) {
    cout << g[i] << endl;
  }
  return 0;
}
