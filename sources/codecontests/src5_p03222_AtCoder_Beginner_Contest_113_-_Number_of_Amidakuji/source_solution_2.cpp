#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)



int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll h,w,k,mod=1e9+7;
    cin>>h>>w>>k;
    vector<ll>combi{1,1,1,2,3,5,8,13,21};

    ll dp[110][10]={};// [h][w]
    dp[0][1]=1;
    rep(i,h+1){
        forx(j,1,w+1){
            dp[i][j]%=mod;

            dp[i+1][j]+=dp[i][j]*combi[j]*combi[w+1-j];
            dp[i+1][j-1]+=dp[i][j]*combi[j-1]*combi[w+1-j];
            dp[i+1][j+1]+=dp[i][j]*combi[j]*combi[w-j];

            dp[i+1][j]%=mod;
            dp[i+1][j-1]%=mod;
            dp[i+1][j+1]%=mod;
        }
    }

    cout<<dp[h][k]<<endl;

    return 0;
}
