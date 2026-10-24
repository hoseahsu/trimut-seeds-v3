#include<bits/stdc++.h>
using namespace std;

int n,d,T,a[505000],b[505000],c[505000];

int main(){
  ios::sync_with_stdio(0);
  cin>>n>>b[0];
  for (int i=1;i<=n;++i) cin>>a[i], b[i]=min(abs(b[i-1]-a[i]),b[i-1]);
  c[n+1]=0;
  for (int i=n;i;--i){
    c[i]= c[i+1]>=a[i]/2? min(c[i+1]+a[i],b[0]): c[i+1];
  }
  for (cin>>T;T--;){
    cin>>d;
    puts(c[d+1]>=b[d-1]? "NO": "YES");
  }
}
