#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
long long a[100];
long long s[100];
long long t[100];
long long x[100];
long long y[100];
int main(){
	int T=0;
	int n;
	while(scanf("%d",&n),n){
		n*=2;
		int p=(int)(sqrt((double)n+0.00000005));
		if(p*p==n){
			printf("Case %d: %d %d\n",++T,p,1);
			continue;
		}
		long double now=sqrt((long double)n);
		a[0]=(long long)now;
		s[0]=0;t[0]=1;
		x[0]=1;y[0]=0;
		x[1]=a[0];y[1]=1;
		for(int i=0;i<50;i++){
			s[i+1]=a[i]*t[i]-s[i];
			t[i+1]=((long long)n-s[i+1]*s[i+1])/t[i];
			a[i+1]=(a[0]+s[i+1])/t[i+1];
			x[i+2]=a[i+1]*x[i+1]+x[i];
			y[i+2]=a[i+1]*y[i+1]+y[i];
	//		printf("%lld %lld %lld %lld %lld\n",s[i+1],t[i+1],a[i+1],x[i+2],y[i+2]);
			if(t[i+1]==1&&x[i+1]*x[i+1]-y[i+1]*y[i+1]*n==1){
				printf("Case %d: %lld %lld\n",++T,x[i+1],y[i+1]);
				break;
			}
		}
	}
}