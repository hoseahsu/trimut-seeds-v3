
#include<bits/stdc++.h>

using namespace std;

const int maxn=1400;

int dp[maxn][maxn],g[maxn][maxn];

int getlargestsquare(int h,int w)
{
    int maxwidth=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dp[i][j]=(g[i][j]+1)%2;
            maxwidth|=dp[i][j];
        }
    }
    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            if(g[i][j]){
                dp[i][j]=0;
            }else{
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                maxwidth=max(maxwidth,dp[i][j]);
            }
        }
    }
    return maxwidth*maxwidth;
}

int main()
{
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>g[i][j];
        }
    }
    printf("%d\n",getlargestsquare(h,w));
    return 0;
}

