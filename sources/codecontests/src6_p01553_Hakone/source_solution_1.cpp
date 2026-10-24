#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define PI       3.1415926535897932384626433832795028841971
#define INF      100000000
#define EPS      1e-10
#define MOD      1000000007
using namespace std;
typedef long long ll;

int n;
ll dp[222][222];

int main(){
    cin >> n;
    dp[0][0] = 1;
    rep(i,n){
        char x;
        cin >> x;
        if(x == '-'){
            for(int j = 0; j <= n; j++){
                dp[i+1][j] = dp[i][j];
            }
            continue;
        }
        if(x == 'U'){
            for(int j = 0; j <= n; j++){
                dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%MOD;
                dp[i+1][j] = (dp[i+1][j]+dp[i][j]*j)%MOD;
            }
        } else{
            for(int j = 0; j <= n; j++){
                dp[i+1][j-1] = (dp[i+1][j-1]+dp[i][j]*j*j)%MOD;
                dp[i+1][j] = (dp[i+1][j]+dp[i][j]*j)%MOD;
            }
        }
    }
    cout << dp[n][0] << endl;
}