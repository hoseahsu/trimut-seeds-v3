#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
int inf=100000000;
ll INF=100000000000000000;
ll MOD=1000000007;

ll mpow(ll x, ll n){
ll ans = 1;
while(n != 0){
if(n&1) ans = ans*x % MOD;
x = x*x % MOD;
n = n >> 1;
}
return ans;
}
ll kj(ll x){
ll s = 1;
for(ll i = 1; i <= x; i++){
s = s * i % MOD;
}
return s;
}
ll combination(ll a, ll b){
if(a == 0 && b == 0) return 1;
if(a < b || a < 0) return 0;
return (kj(a) * mpow(kj(b), MOD-2) % MOD) * mpow(kj(a-b), MOD-2) % MOD;
}

int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+1);
    ll ans=1,r;
    r=mpow(2,n);
    a.at(0)=1;
    for (ll i=1;i<n+1;i++){
        if (i<m) {ans=ans*2%MOD;a.at(i)=ans;continue;}
        else if (i==m) ans=(ans*2-1)%MOD;
        else ans=(ans*2-a.at(i-m-1))%MOD;
        a.at(i)=ans;
    }
    cout << (MOD+r-ans)%MOD << endl;
}

