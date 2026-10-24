#include<bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define ll long long 
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mkp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ff first
#define ss second
#define endl "\n"
#define MOD 1000000007
#define MOD1 998244353
#define inf 1e18

ll GCD(ll x,ll y){if(y==0)return x;return GCD(y,x%y);}
ll LCM(ll x,ll y){return (x*y)/(GCD(x,y));}
ll MPOW( ll a, ll b, ll m) { if(b==0) return 1; ll x=MPOW(a,b/2,m); x=(x*x)%m; if(b%2==1) x=(x*a)%m; return x;}
ll MINV(ll a,ll m) {return MPOW(a,m-2,m);}

class pnc{
  ll FACT_MAX,MODU;
  vector<ll> fact;
public:
  pnc( ll n, ll m) { FACT_MAX = n; fact.resize(FACT_MAX); MODU = m; MFACT_INIT(MODU);}
  void MFACT_INIT( ll m) { fact[0]=1; for(ll i=1;i<FACT_MAX;++i) fact[i]=(i*fact[i-1])%MODU;}
  ll MFACT( ll n) { return fact[n];}
  ll PERM( ll n, ll r) { return (fact[n]*::MINV(fact[n-r],MODU))%MODU;}
  ll COMB( ll n , ll r) { return (PERM(n,r)*::MINV(fact[r],MODU))%MODU;}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    

    ll test=1;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;

        vector<ll> uni[n+5];

        ll u[n],skill[n];

        for(ll i=0;i<n;i++)
        cin>>u[i];

        for(ll i=0;i<n;i++)
        cin>>skill[i];

        for(ll i=0;i<n;i++)
        {
            uni[u[i]].pb(skill[i]);
        }

        vector<ll> ans(n+5,0);

        for(ll i=0;i<=n;i++)
        {
            if(!uni[i].empty())
            {
                sort(uni[i].rbegin(),uni[i].rend());
                ll sz=uni[i].size();
                vector<ll> s(sz+5,0);

                for(ll j=1;j<=sz;j++)
                {
                    ll val=uni[i][j-1];
                    s[j]=s[j-1]+val;

                    for(ll t=1;t<=sqrt(j);t++)
                    {
                        if(j%t!=0)
                        continue;
                        
                        ll x=t;
                        ll y=j/t;

                        ans[x]+=s[j]-s[j-x];

                        if(x!=y)
                        ans[y]+=s[j]-s[j-y];
                    }
                }
            }
        }

        for(ll i=1;i<=n;i++)
        cout<<ans[i]<<' ';
        cout<<endl;
    }
}