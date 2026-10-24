#include <bits/stdc++.h>
using namespace std;
const int SIZE = (int)1e5;
int n;
int a[SIZE], b[SIZE];
int posa[SIZE], posb[SIZE];
int main() {
  cin >> n;
  for (int i = 0; i < (int)(n); i++) cin >> a[i];
  for (int i = 0; i < (int)(n); i++) cin >> b[i];
  for (int i = 0; i < (int)(n); i++) {
    posa[--a[i]] = i;
    posb[--b[i]] = i;
  }
  multiset<int> s;
  for (int i = 0; i < (int)(n); i++) s.insert(posb[i] - posa[i]);
  for (int i = 0; i < (int)(n); i++) {
    multiset<int>::iterator itr = s.lower_bound(i);
    int d = *itr - i;
    if (itr != s.begin()) {
      --itr;
      d = min(d, i - *itr);
    }
    cout << d << endl;
    int c = b[i];
    s.erase(s.find(posb[c] - posa[c]));
    s.insert(n + i - posa[c]);
  }
  return 0;
}
