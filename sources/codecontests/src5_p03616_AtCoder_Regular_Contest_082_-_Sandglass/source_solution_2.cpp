#include <cstdio>
#include <iostream>
using namespace std;
const int Q=1<<17;
int s[Q],n,maxn;
int Ch(int x,int l,int r)
{return max(l,min(r,x));}
int main()
{
	scanf("%d%d",&maxn,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	int p=1,l=0,r=maxn;
	int qaq,t,a,ty=-1,del=0;
	for(scanf("%d",&qaq);qaq;--qaq){
		scanf("%d%d",&t,&a);
		while(p<=n&&s[p]<=t){
			int val=ty*(s[p]-s[p-1]);
			l=Ch(l+val,0,maxn);
			r=Ch(r+val,0,maxn);
			del+=val;
			ty=-ty;
			++p;
		}
		printf("%d\n",Ch(Ch(a+del,l,r)+ty*(t-s[p-1]),0,maxn));
	}
	return 0;
}