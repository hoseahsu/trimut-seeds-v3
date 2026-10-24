#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[100005],b,c,q,sum=0,cnt[100005];
int main(){
  cin>>n;
  for(ll i=1;i<=n;i++){
    cin>>a[i];
    sum+=a[i];
    cnt[a[i]]++;
  }
  cin>>q;
  for(ll i=1;i<=q;i++){
    cin>>b>>c;
    sum+=(c-b)*cnt[b];
    cnt[c]+=cnt[b];
    cnt[b]=0;
    cout<<sum<<endl;
  }
  return 0;
}