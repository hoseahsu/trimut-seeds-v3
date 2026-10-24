#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const int MN=1e5+5;
int to[MN<<2],nxt[MN<<2],h[MN],cnt;
inline void ins(int s,int t){
	to[++cnt]=t;nxt[cnt]=h[s];h[s]=cnt;
	to[++cnt]=s;nxt[cnt]=h[t];h[t]=cnt;
}
int n,m,pre[MN];
queue<int>q;
int main(){
	scanf("%d%d",&n,&m);
	for(reg int i=1,s,t;i<=m;i++)
		scanf("%d%d",&s,&t),ins(s,t);
	q.push(1);pre[1]=1;
	while(!q.empty()){
		reg int v=q.front();q.pop();
		for(reg int i=h[v];i;i=nxt[i])
			if(!pre[to[i]])pre[to[i]]=v,q.push(to[i]);
	}
	puts("Yes");
	for(reg int i=2;i<=n;i++)printf("%d\n",pre[i]);
	return 0;
}