#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[2000+100][2000+100];

signed main(){
	int N; cin>>N;
	vector<pair<int,int>> A(N);
	for(int i=0;i<N;i++){
		cin>>A[i].first;
		A[i].second=i;
	}
	sort(A.begin(),A.end());
	reverse(A.begin(),A.end());
	for(int x=0;x<N;x++){
		for(int y=0;y<N;y++){
			if(x+y>=N)continue;
			int a=A[x+y].first,i=A[x+y].second;
			dp[x+1][y]=max(dp[x+1][y],dp[x][y]+a*(i-x));
			dp[x][y+1]=max(dp[x][y+1],dp[x][y]+a*(N-1-y-i));
		}
	}
	int ans=0;
	for(int x=0;x<=N;x++){
		ans=max(ans,dp[x][N-x]);
	}
	cout<<ans<<endl;
}