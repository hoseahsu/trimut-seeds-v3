#include<bits/stdc++.h>
using namespace std;
int n,a[20],c[100],tp,ans;
int chk(){
	int ret=10007;
	for(int i=0;i<=tp;++i)
		for(int j=i+1;j<=tp;++j)
			ret=min(ret,min(abs(c[i]-c[j]),24-abs(c[i]-c[j])));
	return ret;
}
void dfs(int x){
	if(x==13){
		ans=max(ans,chk());
		return ;
	}
	if(a[x]==2)c[++tp]=x,c[++tp]=24-x,dfs(x+1),tp-=2;
	else if(a[x]==1)c[++tp]=x,dfs(x+1),c[tp]=24-x,dfs(x+1),tp--;
	else dfs(x+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
		scanf("%d",&x),a[x]++;
	for(int i=0;i<=12;++i)
		if(a[i]>2)return puts("0"),0;
	dfs(0);
	printf("%d",ans);
}