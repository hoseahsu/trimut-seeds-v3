/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;

#define io ios_base::sync_with_stdio(false)
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define mod 1000000007
#define pii pair<int, int>
#define PI 2*acos(0.0)

ll gcd(ll a, ll b)
{
    return b? gcd(b, a%b):a;
}

int main()
{
    io;
    ll po[200005] = {1};
    for(int i = 1; i< 200005; i++)
        po[i] = po[i-1]*2%mod;
    ll ans = -1, n;
    cin>>n;
    map<pair<ll, ll> , pair<int, int> > cnt;
    while(n--)
    {
        ll x, y;
        cin>>x>>y;
        if( !x && !y)
        {
            ans++;
            continue;
        }
        if(pair<ll, ll> (x, y) < pair<ll, ll> (0LL, 0LL))
        {
            x = -x;
            y = -y;
        }
        ll g = gcd(abs(x), abs(y));
        x/= g; y /= g;
        if(y > 0LL)
            cnt[{x, y}].first++;
        else
            cnt[{-y, x}].second++;
    }
    ll res = 1;
    for(auto p: cnt)
        res = res*(po[p.second.first] + po[p.second.second] - 1)%mod;
    cout<< (ans+res+mod)%mod;
    return 0;
}