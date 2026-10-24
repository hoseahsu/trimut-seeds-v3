#include <bits/stdc++.h>
using namespace std;
int n, x[100000];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < (int)(n); i++) cin >> x[i];
  long long sum = 0;
  for (int i = 0; i < (int)(n); i++) sum += x[i];
  long long ret = *max_element(x, x + n);
  ret = max(ret, (sum + n - 2) / (n - 1));
  cout << ret << endl;
  return 0;
}
