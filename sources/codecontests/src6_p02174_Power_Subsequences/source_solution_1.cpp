#include "bits/stdc++.h"

using namespace std;

//int N,M,K,L,R,H,W;
long long int N,M,K,L,R,H,W;

//constexpr long long int MOD=1000000007;
//constexpr  int MOD=1000000007;
constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x;
	while (n) {
		if (n & 1) {
			ret *= by;
			ret %= M;
		}
		by *= by;
		by %= M;
		n >>= 1;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>N;
	vector<long long int>v(N);
	for(auto &i:v)cin>>i;
	vector<long long int>by(N+1,1);
	for(int i=1;i<=N;i++){
		by[i]=by[i-1]*2;
		by[i]%=MOD;
	}
	long long int ans=0;
	for(int i=0;i<N;i++){
		long long int add=power(2,N-i-1,MOD);
		add*=power(v[i]+1,i,MOD);
		add%=MOD;
		add*=v[i];
		add%=MOD;
		ans+=add;
		ans%=MOD;
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
