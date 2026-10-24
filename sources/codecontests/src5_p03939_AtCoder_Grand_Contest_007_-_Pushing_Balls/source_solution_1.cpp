#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
using namespace std;
long double ans,sum,n,d,x,d1,x1,sum1;
int main()
{
//	freopen("Pushing Balls.in","r",stdin);
	cin>>n>>d>>x; sum=2*d*n+n*x*(2*n-1);
	for(int i=n;i;i--)
	{
		ans+=sum/2/n;
		d1=(2*d+2*n*d+5*x)/2/n, sum1=sum-(2*d+(2*n-1)*x)/n;
		n-=1;
		x1=(sum1-2*d1*n)/n/(2*n-1);
		d=d1, x=x1, sum=sum1;
	}
	printf("%.15lf\n",(double)ans);
	return 0;
}