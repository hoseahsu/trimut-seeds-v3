#include<bits/stdc++.h>
#define N 400005
using namespace std;
 
int n,m,cnt,tot,num[N],fst[N],pnt[N],nxt[N],dgr[N],a[N],b[N]; bool vis[N];
map<int,int> mp;
void add(int x,int y){
	dgr[x]++;
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
}
void dfs(int x){
	int i,y; vis[x]=1;
	for (i=fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (!vis[y]) dfs(y);
	}
}
int main(){
	scanf("%d",&n);
	int i; n++;
	for (i=1; i<n; i++){
		scanf("%d",&a[i]); a[n]^=a[i];
	}
	for (i=1; i<n; i++) {
		scanf("%d",&b[i]); b[n]^=b[i];
	}
	for (i=1; i<=n; i++){
		if (!mp[a[i]]) mp[a[i]]=++cnt; a[i]=mp[a[i]];
		if (!mp[b[i]]) mp[b[i]]=++cnt; b[i]=mp[b[i]];
	}
	for (i=1; i<=n; i++) num[a[i]]++;
	for (i=1; i<=n; i++) num[b[i]]--;
	for (i=1; i<=cnt; i++) if (num[i]) break;
	if (i<=cnt){ puts("-1"); return 0; }
	int ans=0;
	for (i=1; i<=n; i++) num[a[i]]++;
	for (i=1; i<=n; i++) if (a[i]!=b[i]){
		add(a[i],b[i]); add(b[i],a[i]);
		if (i<n) ans++; else ans--;
	} else if (i==n && num[a[i]]>1) ans--;
	for (i=1; i<=cnt; i++) if (!vis[i] && dgr[i]){
		ans++; dfs(i);
	}
	printf("%d\n",max(ans,0));
	return 0;
}
