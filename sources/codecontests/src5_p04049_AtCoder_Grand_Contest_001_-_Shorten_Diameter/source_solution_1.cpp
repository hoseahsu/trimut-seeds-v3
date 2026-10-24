#include <bits/stdc++.h>
using namespace std;
const int maxn=2010;
int n,k,tot,ans,x,y;
bool vis[maxn];
vector <int> e[maxn];
void dfs(int node,int fa,int dep){
	if(dep>k/2)tot++;
	for(int i=0;i<e[node].size();++i)
		if(e[node][i]!=fa)
			dfs(e[node][i],node,dep+1);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	ans=n-k-1;
	if(k&1){
		for(int i=1;i<=n;++i){
			for(int j=0;j<e[i].size();++j){
				tot=0;
				dfs(i,e[i][j],0);
				dfs(e[i][j],i,0);
				ans=min(ans,tot);
			}
		}
	}
	else {
		for(int i=1;i<=n;++i){
			tot=0;
			dfs(i,0,0);
			ans=min(ans,tot);
		}
	}
	printf("%d\n",ans);
	return 0;
}