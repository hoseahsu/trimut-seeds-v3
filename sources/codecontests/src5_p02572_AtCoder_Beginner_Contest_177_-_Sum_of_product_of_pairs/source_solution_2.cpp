#include <bits/stdc++.h>
using namespace std;
int N,i;
int main() {
	cin>>N;
	int A[N];
	long long sum=0,ans=0,mod=1e9+7;
	for(i=0;i<N;i++) {
		cin>>A[i];
		sum+=A[i];
		sum%=mod;
	}
	for(i=0;i<N;i++) {
		sum-=A[i];
		if(sum<0) {
			sum+=mod;
		}
		ans+=sum*A[i];
		ans%=mod;
	}
	cout<<ans<<endl;
}

