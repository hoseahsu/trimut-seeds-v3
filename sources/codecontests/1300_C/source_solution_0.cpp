#include <bits/stdc++.h>
using namespace std;
bool sortinrev(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.first > b.first);
}
int main() {
  long long int n;
  cin >> n;
  long long int ar[n];
  for (long long int i = 0; i < n; i++) cin >> ar[i];
  if (n == 1) {
    cout << ar[0];
    return 0;
  }
  long long int pos = 0;
  long long int pre[n];
  long long int suff[n];
  pre[0] = ~ar[0];
  for (long long int i = 1; i < n; i++) {
    pre[i] = (~ar[i] & pre[i - 1]);
  }
  suff[n - 1] = ~ar[n - 1];
  for (long long int i = n - 2; i >= 0; i--) {
    suff[i] = (~ar[i] & suff[i + 1]);
  }
  long long int maxi = ar[0] & suff[1];
  for (long long int i = 1; i < n - 1; i++) {
    long long int val = (pre[i - 1] & suff[i + 1]) & ar[i];
    if (val >= maxi) {
      maxi = val;
      pos = i;
    }
  }
  cout << endl;
  if ((pre[n - 2] & ar[n - 1]) > maxi) pos = n - 1;
  swap(ar[0], ar[pos]);
  for (long long int i = 0; i < n; i++) cout << ar[i] << " ";
  cout << endl;
  return 0;
}
