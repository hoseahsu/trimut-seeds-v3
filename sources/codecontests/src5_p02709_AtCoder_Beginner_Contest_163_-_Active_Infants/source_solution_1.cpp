#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(in) in.begin(),in.end()
using ll = long long;
using namespace std;
 
void chmax(ll &a, ll b) { if (a < b) a = b; return; }
using pll = pair<ll,ll>;
 
int main() {
    int n; cin >> n;
    vector<pll> a(n); rep(i,n) cin >> a[i].first, a[i].second = i;
    sort(all(a),greater<pll>());
 
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    rep(i,n) rep(j,n-i){
        chmax(dp[i+1][j], dp[i][j] + a[i+j].first * abs(a[i+j].second - i));
        chmax(dp[i][j+1], dp[i][j] + a[i+j].first * abs((n-1-j) - a[i+j].second));
    }
    ll ans = 0;
    rep(i,n+1) chmax(ans, dp[i][n-i]);
    cout << ans << endl;
}