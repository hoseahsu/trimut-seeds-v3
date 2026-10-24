#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long

LL n,x=1,base=1;  

inline double S(LL x)
{
	LL tmp=x,sum=0;
	while (tmp>0)
	{
		sum+=tmp%10;
		tmp/=10;
	}	
	return (double)x/double(sum);
} 

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;i++)
	{
		printf("%lld\n",x);
		double now,now_;
		now=S(x+base);
		now_=S(x+base*10);
		if (now_<now) base*=10;
		x+=base;
	}
	return 0;
}