#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define M 1000000007
int n,m,w[205];
ll dp[2][205][10005],ans;
int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>w[i];
    sort(w,w+n);
    w[n]=m;
    dp[1][n][0]=1;
    for(int i=0;i<n;i++){
        int u=(i+1)%2;
        for(int j=0;j<=m;j++){
            for(int k=0;k<n;k++){
                if(j>=w[i])dp[i%2][k][j]=(dp[u][k][j-w[i]]+dp[u][k][j])%M;
                else dp[i%2][k][j]=dp[u][k][j];
                if(k==i)dp[i%2][k][j]=(dp[i%2][k][j]+dp[u][n][j])%M;
            }
            if(j>=w[i])dp[i%2][n][j]=dp[u][n][j-w[i]];
            else dp[i%2][n][j]=0;
        }
    }
    for(int j=0;j<=n;j++)for(int k=m-w[j]+1;k<=m;k++)ans=(ans+dp[(n-1)%2][j][k])%M;
    cout<<ans<<endl;
}
