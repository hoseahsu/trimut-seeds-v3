#include <bits/stdc++.h>
using namespace std;
long long int fun(long long int a) {
  if (a == 0) return 0;
  if (a % 2 == 0)
    return fun(a / 2);
  else
    return fun(a / 2) + 1;
}
long long int sum[10000000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int i, j, n, cnt = 0, temp;
  cin >> n;
  long long int ara[n];
  for (i = 0; i < n; i++) {
    cin >> temp;
    ara[i] = fun(temp);
    sum[ara[i]]++;
  }
  for (i = 0; i < 1000000; i++) {
    cnt += ((sum[i] * (sum[i] - 1)) / 2);
  }
  cout << cnt << endl;
  return 0;
}
