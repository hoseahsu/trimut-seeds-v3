#include<iostream>
#include<algorithm>
using namespace std;
long dp[3],a;
char op;
int n;
int main()
{
	cin>>n>>dp[0];
	dp[1]=dp[2]=-1e18;
	for(int i=1;i<n;i++)
	{
		cin>>op>>a;
		if(op=='+')
		{
			for(int j=0;j<3;j++)dp[j]+=j%2?-a:a;
		}
		else
		{
			dp[2]=max(dp[2]+a,dp[1]+a);
			dp[1]=max(dp[1]+a,dp[0]-a);
			dp[0]-=a;
		}
		dp[1]=max(dp[1],dp[2]);
		dp[0]=max(dp[0],dp[1]);
	}
	cout<<dp[0]<<endl;
}
