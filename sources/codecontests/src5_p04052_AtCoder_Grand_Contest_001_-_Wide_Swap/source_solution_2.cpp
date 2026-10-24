#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define M 500010
#define ls node<<1
#define rs node<<1|1
#define inf 1e9
using namespace std;
int n,num,k,cnt;
int p[M],a[M],dig[M],ans[M],head[M],val[M<<2];
struct edge{int next,to;}e[M<<1];
void add(int from,int to) {
	e[++num]=(edge){head[from],to};
	head[from]=num;
}
priority_queue<int,vector<int>,greater<int> >Q;
void build(int node,int l,int r) {
	val[node]=inf;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
void change(int node,int l,int r,int p,int v) {
	val[node]=min(val[node],v);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(p<=mid) change(ls,l,mid,p,v);
	else change(rs,mid+1,r,p,v);
}
int query(int node,int l,int r,int l1,int r1) {
	if(l1>r1) return inf;
	if(l1<=l&&r1>=r) return val[node];
	int mid=(l+r)>>1,ans=inf;
	if(l1<=mid) ans=min(ans,query(ls,l,mid,l1,r1));
	if(r1>mid) ans=min(ans,query(rs,mid+1,r,l1,r1));
	return ans;
}
int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) a[p[i]]=i;
	build(1,1,n);
	for(int i=n;i>=1;i--) {
		int res;
		res=query(1,1,n,max(1,a[i]-k+1),a[i]-1);
		if(res!=inf) add(a[i],a[res]),dig[a[res]]++;
		res=query(1,1,n,a[i]+1,min(a[i]+k-1,n));
		if(res!=inf) add(a[i],a[res]),dig[a[res]]++;
		change(1,1,n,a[i],i);
	}
	for(int i=1;i<=n;i++) 
		if(!dig[i]) Q.push(i);
	while(!Q.empty()) {
		int x=Q.top();Q.pop();ans[x]=++cnt;
		for(int i=head[x];i;i=e[i].next) {
			int to=e[i].to;
			if((--dig[to])==0)
				Q.push(to); 
		}
	}
	for(int i=1;i<=cnt;i++) printf("%d\n",ans[i]);
	return 0;
}