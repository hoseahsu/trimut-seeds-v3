#include<bits/stdc++.h>
#define N 41
using namespace std;
typedef long long ll;
ll n,m,a,b,p,q,d[N];
vector<ll> v[2],x[2];

int main(){
  cin>>n>>m>>a>>b>>p>>q;
  ll ans=m;
  if(a==1&&b==1){
    ll ti=min(n,m/(p+q));
    ans=min(ans,min(m-ti*(p+q),abs(min(ti+1,n)*(p+q)-m)));
  }
  ll A=1,B=1;
  for(int i=0;i<min((ll)N,n);i++){
    d[i]=p*A+q*B;
    if(i<min((ll)N,n)/2)v[0].push_back(d[i]);
    else v[1].push_back(d[i]);
    if(d[i]>m)break;
    A*=a,B*=b;
  }
  for(int i=0;i<2;i++){
    v[i].push_back(0);
    for(int j=0;j<(1<<v[i].size());j++){
      ll sum=0;
      for(int k=0;k<v[i].size();k++){
	if(!(j&(1<<k)))continue;
	sum+=v[i][k];
      }
      x[i].push_back(sum);
    }
    sort(x[i].begin(),x[i].end());
  }
  for(int i=0;i<x[0].size();i++){
    ll search=m-x[0][i];
    vector<ll>::iterator r=lower_bound(x[1].begin(),x[1].end(),search);
    if(r!=x[1].end())ans=min(ans,(*r)-search);
    if(r!=x[1].begin())ans=min(ans,search-(*(r-1)));
  }
  cout<<ans<<endl;
  return 0;
}