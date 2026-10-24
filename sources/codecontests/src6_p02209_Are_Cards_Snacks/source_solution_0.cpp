#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////

int main(){fastio
    ll n,k;cin>>n>>k;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    ll sum[1<<n];memset(sum,0,sizeof(sum));
    rep(i,0,(1<<n)-1){
        rep(j,0,n-1){
            if((i>>j)&1)sum[i]+=a[j];
        }
    }
    bool f[1<<n];memset(f,false,sizeof(f));
    rep(i,0,(1<<n)-1){
        if(sum[i]==k)f[i]=true;
    }
    rep(i,0,(1<<n)-1){
        if(f[i]){
            rep(j,0,n-1){
                f[i|(1<<j)]=true;
            }
        }
    }
    ll ans=0;
    /*
    rep(i,0,(1<<n)-1){
        rep(j,0,n-1){
            if((i>>j)&1)cout<<1;
            else cout<<0;
        }cout<<":"<<f[i]<<endl;
    }*/
    rep(i,0,(1<<n)-1){
        if(!f[i]){
            ll c=0;
            rep(j,0,n-1){
                if((i>>j)&1)c++;
            }
            Max(ans,c);
        }
    }
    cout<<n-ans<<endl;
    
    return 0;
}

