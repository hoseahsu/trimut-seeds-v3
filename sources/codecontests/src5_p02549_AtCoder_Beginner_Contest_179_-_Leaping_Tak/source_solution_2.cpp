#include<bits/stdc++.h>
#define PI 3.141592653589793238462
using namespace std;
typedef long long ll;
typedef long double db;
ll d[200005],x[200005],y[200005],mod=998244353;
int main(){
    ll n,k;cin>>n>>k;
    for(ll i=1;i<=k;i++){
        cin>>x[i]>>y[i];
    }
    d[1]=1;d[0]=0;
    for(ll i=2;i<=n;i++){
        for(ll j=1;j<=k;j++){
            if(i<x[j]) continue;
            ll l=i-x[j],r=max((ll)0,i-y[j]-1);
            d[i]+=d[l]-d[r];d[i]=(d[i]%mod+mod)%mod;
        }
        d[i]+=d[i-1];d[i]%=mod;
    }
    cout<<((d[n]-d[n-1])%mod+mod)%mod<<endl;
}