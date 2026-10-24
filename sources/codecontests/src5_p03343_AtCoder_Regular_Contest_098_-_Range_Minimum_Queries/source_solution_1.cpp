#include <bits/stdc++.h>
const int N=2005;
int d[N],a[N],c[N],b[N],n,k,q,ans=1000000000;
int solve(int x){
	int cnt=0,tot=0;
	for (int i=1;i<=n+1;i++){
		if (a[i]<x){
			if (cnt>=k){ 
				std::sort(c+1,c+cnt+1);
				for (int j=1;j+k-1<=cnt;j++) d[++tot]=c[j];
			}
			cnt=0;
		}else c[++cnt]=a[i];
	}
	if (tot<q) return ans;
	std::sort(d+1,d+tot+1);
	return d[q]-d[1];
}
int main(){
	scanf("%d%d%d",&n,&k,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	std::sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
		ans=std::min(ans,solve(b[i]));
	printf("%d\n",ans);
}