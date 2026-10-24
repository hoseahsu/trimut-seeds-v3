#include <bits/stdc++.h>
using namespace std;

int main() {
  long n;
  cin >> n;
  vector<long> a(n);
  for(long i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  cout << a[n-1]-a[0] << endl;
}