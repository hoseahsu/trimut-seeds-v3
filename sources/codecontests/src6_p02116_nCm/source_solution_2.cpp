#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll n;
ll two_pow[61];

bool C(ll v){
	ll cnt=0;
	for(int i=1;i<=60;i++){
		cnt+=n/two_pow[i];
		cnt-=(n-v)/two_pow[i];
		if(cnt<=-(1LL<<60))return false;
		cnt-=v/two_pow[i];
		if(cnt>=(1LL<<60))return true;
		if(cnt<=-(1LL<<60))return false;
	}
	return cnt>0LL;
}

int main(void){
	two_pow[0]=1;
	for(int i=0;i<60;i++){
		two_pow[i+1]=two_pow[i]*2LL;
	}
	scanf("%lld",&n);
	if(n%2LL==0){
		printf("%lld\n",1LL);
		return 0;
	}
	ll l=1;
	while(l<n){
		if(C(l))break;
		else l*=2LL;
	}
	if(l>=n){
		printf("%lld\n",n+1LL);
	}else{
		printf("%lld\n",l);
	}
	return 0;
}