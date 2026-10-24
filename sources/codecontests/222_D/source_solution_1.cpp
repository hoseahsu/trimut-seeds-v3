#include <bits/stdc++.h>
using namespace std;
int a[100007], b[100007];
multiset<int> S1, S2;
int f(int x) {
  int cnt = 0;
  for (multiset<int>::iterator it = S1.begin(); it != S1.end(); ++it) {
    int r = x - (*it);
    if (r <= 0)
      S2.erase(S2.begin()), ++cnt;
    else {
      multiset<int>::iterator it2 = S2.lower_bound(r);
      if (it2 != S2.end()) S2.erase(it2), ++cnt;
    }
    if (S2.empty()) break;
  }
  return cnt + 1;
}
int main() {
  int n, x;
  cin >> n >> x;
  for (int(i) = (int)(0); (i) < (int)(n); ++(i)) cin >> a[i];
  for (int(i) = (int)(0); (i) < (int)(n); ++(i)) cin >> b[i];
  sort(a, a + n);
  sort(b, b + n);
  int pmin = 1;
  int pmax = 1;
  int p1, p2;
  for (int(i) = (int)(0); (i) < (int)(n); ++(i))
    if (a[i] + b[i] >= x) {
      if (a[i] + b[i] == x) {
        for (int(k) = (int)(0); (k) < (int)(n); ++(k)) S1.insert(a[k]);
        for (int(k) = (int)(0); (k) < (int)(n); ++(k)) S2.insert(b[k]);
        S1.erase(S1.find(a[i]));
        S2.erase(S2.find(b[i]));
        pmax = max(pmax, f(x));
      } else {
        if (a[i] + b[i] > x) {
          S1.clear();
          S2.clear();
          for (int(k) = (int)(0); (k) < (int)(n); ++(k)) S1.insert(a[k]);
          for (int(k) = (int)(0); (k) < (int)(n); ++(k)) S2.insert(b[k]);
          for (int(j) = (int)(0); (j) < (int)(i + 1); ++(j))
            if (a[i] + b[j] >= x) {
              p1 = i, p2 = j;
              break;
            }
          S1.erase(S1.find(a[p1]));
          S2.erase(S2.find(b[p2]));
          pmax = max(pmax, f(x));
          S1.clear();
          S2.clear();
          for (int(k) = (int)(0); (k) < (int)(n); ++(k)) S1.insert(a[k]);
          for (int(k) = (int)(0); (k) < (int)(n); ++(k)) S2.insert(b[k]);
          for (int(j) = (int)(0); (j) < (int)(i + 1); ++(j))
            if (a[j] + b[i] >= x) {
              p1 = j, p2 = i;
              break;
            }
          S1.erase(S1.find(a[p1]));
          S2.erase(S2.find(b[p2]));
        }
      }
      break;
    }
  cout << pmin << " " << pmax << endl;
  return 0;
}
