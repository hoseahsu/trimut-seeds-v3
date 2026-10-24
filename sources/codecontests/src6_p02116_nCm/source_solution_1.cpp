#include <stdio.h>
#include <cmath>
typedef long long int ll;
using namespace std;

int main(){

	ll N;

	scanf("%lld",&N);

	if(N%2 == 0){
		printf("1\n");
		return 0;
	}else{
		N++;

		ll ans = 1;

		while(N%2 == 0){
			N /= 2;
			ans *= 2;
		}
		printf("%lld\n",ans);
	}

	return 0;
}