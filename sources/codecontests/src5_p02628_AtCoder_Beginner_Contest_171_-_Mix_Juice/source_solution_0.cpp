#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  int p[n];
  for (int i=0; i<n; i++) cin>>p[i];
  sort(p, p + n);
  int sum = 0;
  for (int i=0; i<k; i++) sum += p[i];
  cout<<sum<<endl;
}