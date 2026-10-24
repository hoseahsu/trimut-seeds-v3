#include<bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
	int a,b;
	cin>>a>>b;
	vector<int>c(a);
	vector<int>d(b);
	for(int e=0;e<a;e++)cin>>c[e];
	for(int e=0;e<b;e++)cin>>d[e];
	vector<vector<int>>dp(a+1,vector<int>(b+1));
	for(int f=0;f<a;f++){
		int x=INT_MAX;
		for(int g=f;g<b;g++){
			x=min(x,dp[f][g]);
			dp[f+1][g+1]=x+c[f]*d[g];
			}
		}
		int s=INT_MAX;
		for(int x:dp[a]){
			if(x!=0&&x<s)s=x;
			}
			cout<<s<<endl;
}