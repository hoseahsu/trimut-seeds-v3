#include<cstdio>
#include<vector>
#include<cstdlib>
using namespace std;
const int N=1000,V=5000,inf=0x3f3f3f3f;
int f[N+10][2],v[N+10],n;
vector<int> G[N+10]; int tmp[N+10][V+10];
void dfs(int x){
	for(int i=0;i<G[x].size();++i) dfs(G[x][i]);
	for(int i=0;i<=1;++i){
		for(int j=0;j<=v[x];++j) tmp[0][0]=inf; tmp[0][0]=0;
		for(int j=0;j<G[x].size();++j){
			int e=G[x][j];
			for(int k=0;k<=v[x];++k) tmp[j+1][k]=inf;
			for(int k=0;k<=v[x];++k){
				if(k+v[e]<=v[x]) tmp[j+1][k+v[e]]=min(tmp[j+1][k+v[e]],tmp[j][k]+f[e][i^1]);
				if(k+f[e][i^1]<=v[x])
					tmp[j+1][k+f[e][i^1]]=min(tmp[j+1][k+f[e][i^1]],tmp[j][k]+v[e]);
			}
		}
		f[x][i]=inf;
		for(int j=0;j<=v[x];++j) f[x][i]=min(f[x][i],tmp[G[x].size()][j]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		int x; scanf("%d",&x); G[x].push_back(i);
	}
	for(int i=1;i<=n;++i) scanf("%d",&v[i]);
	dfs(1);
	printf("%s",f[1][0]<inf||f[1][1]<inf?"POSSIBLE":"IMPOSSIBLE"); return 0;
}