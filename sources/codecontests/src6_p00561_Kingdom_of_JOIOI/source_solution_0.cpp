#include <iostream>
#include <algorithm>
#define INF 1001001001001001001
using namespace std;
typedef long long ll;

ll H,W,a_max,a_min;
ll ary[2010][2010],lma[2010][2010],lmi[2010][2010],rma[2010][2010],rmi[2010][2010],dp[2][2010];

inline ll amax(ll a,ll b){
	if(abs(a)>(INF/2)) a=0;
	if(abs(b)>(INF/2)) b=0;
	return max(abs(a),abs(b));
}
inline ll amin(ll a,ll b){
	return min(abs(a),abs(b));
}

int main(){
	cin>>H>>W;
	a_min=INF;a_max=0;
	for(ll i=1;i<=H;i++){
		for(ll j=1;j<=W;j++){
			cin>>ary[i][j];
			a_min=min(a_min,ary[i][j]);
			a_max=max(a_max,ary[i][j]);
		}
	}

	for(ll i=1;i<=H;i++){
		lma[i][0]=0;lmi[i][0]=INF;
		for(ll j=1;j<=W;j++){
			lma[i][j]=max(lma[i][j-1],ary[i][j]);
			lmi[i][j]=min(lmi[i][j-1],ary[i][j]);
		}
	}
	for(ll i=1;i<=H;i++){
		rma[i][W+1]=0;rmi[i][W+1]=INF;
		for(ll j=W;j>=1;j--){
			rma[i][j]=max(rma[i][j+1],ary[i][j]);
			rmi[i][j]=min(rmi[i][j+1],ary[i][j]);
		}
	}
	ll res=INF;

	ll in,ou;
	in=0,ou=1;
	fill(dp[in],dp[in]+2010,INF);
	for(ll i=0;i<=W;i++){
		dp[in][i]=amax(a_max-lmi[1][i],rma[1][i+1]-a_min);
	}
	for(ll i=2;i<=H;i++){
		ll nowmin=INF;
		for(ll j=0;j<=W;j++){
			nowmin=min(nowmin,dp[in][j]);
			dp[ou][j]=max(nowmin,amax(a_max-lmi[i][j],rma[i][j+1]-a_min));
		}
		swap(in,ou);
	}
	for(ll i=0;i<=W;i++) res=min(res,dp[in][i]);

	in=0,ou=1;
	fill(dp[in],dp[in]+2010,INF);
	for(ll i=0;i<=W;i++){
		dp[in][i]=amax(a_max-rmi[1][i+1],lma[1][i]-a_min);
	}
	for(ll i=2;i<=H;i++){
		ll nowmin=INF;
		for(ll j=0;j<=W;j++){
			nowmin=min(nowmin,dp[in][j]);
			dp[ou][j]=max(nowmin,amax(a_max-rmi[i][j+1],lma[i][j]-a_min));
		}
		swap(in,ou);
	}
	for(ll i=0;i<=W;i++) res=min(res,dp[in][i]);

	in=0,ou=1;
	fill(dp[in],dp[in]+2010,INF);
	for(ll i=0;i<=W;i++){
		dp[in][i]=amax(a_max-lmi[H][i],rma[H][i+1]-a_min);
	}
	for(ll i=H-1;i>=1;i--){
		ll nowmin=INF;
		for(ll j=0;j<=W;j++){
			nowmin=min(nowmin,dp[in][j]);
			dp[ou][j]=max(nowmin,amax(a_max-lmi[i][j],rma[i][j+1]-a_min));
		}
		swap(in,ou);
	}
	for(ll i=0;i<=W;i++) res=min(res,dp[in][i]);

	in=0,ou=1;
	fill(dp[in],dp[in]+2010,INF);
	for(ll i=0;i<=W;i++){
		dp[in][i]=amax(a_max-rmi[H][i+1],lma[H][i]-a_min);
	}
	for(ll i=H-1;i>=1;i--){
		ll nowmin=INF;
		for(ll j=0;j<=W;j++){
			nowmin=min(nowmin,dp[in][j]);
			dp[ou][j]=max(nowmin,amax(a_max-rmi[i][j+1],lma[i][j]-a_min));
		}
		swap(in,ou);
	}
	for(ll i=0;i<=W;i++) res=min(res,dp[in][i]);

	cout<<res<<endl;
	return 0;
}


