#include <bits/stdc++.h>
using namespace std;
set<long long int>::iterator it;
long long int a[2005];
vector<long long int> ev;
vector<long long int> od;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, i;
  cin >> n;
  long long int sum = 0;
  long long int sum1 = 0;
  long long int sum2 = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] % 2 == 0)
      ev.push_back(a[i]);
    else
      od.push_back(a[i]);
  }
  sort(ev.begin(), ev.end(), greater<long long int>());
  sort(od.begin(), od.end(), greater<long long int>());
  long long int temp = (long long int)(ev.size());
  long long int temp1 = (long long int)(od.size());
  if (temp == temp1)
    cout << 0 << endl;
  else if (temp > temp1) {
    for (i = 0; i < temp1; i++) sum1 += od[i];
    for (i = 0; i < temp1 + 1; i++) sum1 += ev[i];
    cout << sum - sum1 << endl;
  } else {
    for (i = 0; i < temp; i++) sum1 += ev[i];
    for (i = 0; i < temp + 1; i++) sum1 += od[i];
    cout << sum - sum1 << endl;
  }
  return 0;
}
