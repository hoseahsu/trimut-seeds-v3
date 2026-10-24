#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  long long i,j,n,m;
  cin >> n >> m;
  long long a[n],b[n],c[m],d[m];
  for(i=0;i<n;i++)cin >> a[i] >> b[i];
  for(i=0;i<m;i++)cin >> c[i] >> d[i];
  for(i=0;i<n;i++){
    long long ret = 3e8;
    long long ans = -1;
    for(j=0;j<m;j++){
      if(ret>(abs(a[i]-c[j])+abs(b[i]-d[j]))){
        ret = abs(a[i]-c[j])+abs(b[i]-d[j]);
        ans = j+1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
