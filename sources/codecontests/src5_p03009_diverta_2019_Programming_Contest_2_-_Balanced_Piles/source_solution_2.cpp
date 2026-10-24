#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;

using _loop_int = int;
#define REP(i,n) for(_loop_int i=0; i<(_loop_int)(n); i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a); i<(_loop_int)(b); i++)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1; i>=(_loop_int)(a); i--)

#define CHMIN(a,b) (a)=min((a),(b))
#define CHMAX(a,b) (a)=max((a),(b))
#define ALL(v) (v).begin(),(v).end()

#define DEBUG(x) cerr<<#x<<": "<<(x)<<endl
#define DEBUG_VEC(v) cerr<<#v<<": ";REP(__i,(v).size())cerr<<((v)[__i])<<", ";cerr<<endl

const ll MOD = 1000000007ll;

ll n,h,d;
ll fact[1252525];
ll dp[1252525];
ll sum[1252525];

int main(){
    cin>>n>>h>>d;
    fact[0] = 1;
    FOR(i,1,n+1)fact[i]=i*fact[i-1]%MOD;

    ll a = fact[n];
    ll m = 0;
    REP(i,n+1)m = (m+fact[i])%MOD;

    dp[0] = a;
    sum[1] = (sum[0] + dp[0]) % MOD;
    FOR(i,1,d){
        dp[i] = dp[i-1]*m%MOD;
        sum[i+1] = (sum[i] + dp[i]) % MOD;
    }
    FOR(i,d,h){
        dp[i] = (sum[i]-sum[i-d]+MOD)*(m-1)%MOD;
        sum[i+1] = (sum[i] + dp[i]) % MOD;
    }
    printf("%lld\n",dp[h-1]);
    return 0;
}
