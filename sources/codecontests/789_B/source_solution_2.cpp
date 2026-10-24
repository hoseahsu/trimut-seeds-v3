#include <bits/stdc++.h>
using namespace std;
long long b1, q, l, m;
vector<long long> v;
int main() {
  cin >> b1 >> q >> l >> m;
  long long c_b1, c_q;
  bool is_there_zero = false;
  c_b1 = b1;
  c_q = q;
  for (int i = 0; i < m; i++) {
    long long tmp;
    cin >> tmp;
    v.push_back(tmp);
    if (tmp == 0) is_there_zero = true;
  }
  sort(v.begin(), v.end());
  long long res = 0;
  bool inf_flag = false;
  b1 = (b1 < 0) ? (b1 * -1) : b1;
  q = (q < 0) ? (q * -1) : q;
  vector<long long>::iterator it;
  if (q == 0 || q == 1) {
    long long base = b1;
    map<long long, int> found_before, not_granted;
    int cnt = 0;
    while (base <= l) {
      if (found_before[c_b1] == 4) break;
      found_before[c_b1] = found_before[c_b1] + 1;
      it = lower_bound(v.begin(), v.end(), c_b1);
      if (c_b1 != 0 && (*it) == c_b1) {
        not_granted[c_b1] = 1;
      } else if (c_b1 == 0 && is_there_zero == true) {
        not_granted[c_b1] = 1;
      } else {
        res++;
        if (found_before[c_b1] > 2) {
          inf_flag = true;
        }
      }
      c_b1 *= c_q;
      base *= q;
    }
  } else if (b1 == 0) {
    if (is_there_zero == false) {
      inf_flag = true;
    }
  } else {
    long long base = b1;
    while (base <= l) {
      res++;
      it = lower_bound(v.begin(), v.end(), c_b1);
      if ((*it) == c_b1) {
        res--;
      }
      base *= q;
      c_b1 *= c_q;
    }
  }
  if (inf_flag) {
    cout << "inf" << endl;
  } else {
    cout << res << endl;
  }
  return 0;
}
