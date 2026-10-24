#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	for(int lim,n,m,x;scanf("%d%d%d%d",&lim,&n,&m,&x),lim;){
		int e_sec[100],s_sec[100];
		rep(i,n) scanf("%*s%d%d",e_sec+i,s_sec+i);
		int e[100],s[100];
		rep(i,m) scanf("%*s%d%d",e+i,s+i);

		int dp[101][1001]; // dp[i][j] := i ツ人, j ツ円ツ使ツづつスツづつォツづ個催妥・ツ鳴楪堕ォツ度
		rep(i,m+1) rep(j,lim+1) dp[i][j]=-INF;
		dp[0][0]=0;
		rep(i,m) for(int k=i;k>=0;k--) for(int j=e[i];j<=lim;j++) {
			dp[k+1][j]=max(dp[k+1][j],dp[k][j-e[i]]+s[i]);
		}

		int ans=-INF;
		for(int i=x;i<=m;i++) rep(j,lim+1) if(dp[i][j]>=0) {
			int tmp=-INF;
			rep(k,n){
				if(j+e_sec[k]<=lim) tmp=max(tmp,s_sec[k]);
				rep(l,k) if(j+e_sec[k]+e_sec[l]<=lim) tmp=max(tmp,s_sec[k]+s_sec[l]);
			}
			ans=max(ans,dp[i][j]+tmp);
		}
		printf("%d\n",ans);
	}

	return 0;
}