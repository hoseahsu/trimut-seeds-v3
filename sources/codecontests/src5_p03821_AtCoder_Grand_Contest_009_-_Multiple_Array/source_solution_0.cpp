#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long>a(n);
  vector<long>b(n);
  int i;
  for(i=0;i<n;i++){
    cin >> a[i] >> b[i];
  }
  long ans = 0;
  for(i=n-1;i>=0;i--){
    a[i] += ans;
    if(a[i]%b[i]!=0)ans += b[i]-a[i]%b[i];
  }
  cout << ans;
}
