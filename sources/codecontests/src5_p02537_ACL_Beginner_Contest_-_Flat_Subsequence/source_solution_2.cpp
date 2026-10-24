#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;

int n,k,a[N],f[N<<2];
void pushup(int o){
	f[o]=max(f[o<<1],f[o<<1|1]);
}
int ask(int l,int r,int o,int ld,int rd){
	if(l==r)return f[o];
	if(ld<=l&&rd>=r)return f[o];
	int mid=l+r>>1,ans=0;
	if(rd>mid)ans=max(ans,ask(mid+1,r,o<<1|1,ld,rd));
	if(ld<=mid)ans=max(ans,ask(l,mid,o<<1,ld,rd));
	return ans;
}
void modify(int l,int r,int o,int x,int y){
	if(l==r){
		f[o]=y;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)modify(l,mid,o<<1,x,y);
	else modify(mid+1,r,o<<1|1,x,y);
	pushup(o);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]++;
	for(int i=1;i<=n;i++){
		int x=ask(1,300001,1,max(1,a[i]-k),min(300001,a[i]+k))+1;
		modify(1,300001,1,a[i],x);
	}
	printf("%d\n",f[1]);
}