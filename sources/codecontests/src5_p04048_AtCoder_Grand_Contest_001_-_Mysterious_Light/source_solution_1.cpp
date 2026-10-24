#include <bits/stdc++.h>
using namespace std;
long long f(long long x,long long y){
	if(!y)return -x;
	return x/y*y*2+f(y,x%y);
}
int main(){
	long long n,x;
	scanf("%lld%lld",&n,&x);
	printf("%lld",n+f(n-x,x));
	return 0;
}
