#include<bits/stdc++.h>
using namespace std;
int n,m;
inline int geti(int x){return (x-1)/m+1;} 
inline int getj(int x){return (x-1)%m+1;}
inline int getx(int i,int j){return (i-1)*m+j;}

const int N=120;
int TL[N],TR[N],vis[N],G[N][N],a[N][N];

int dfs(int x){
	vis[x]=1;
	for(int i=1;i<=n;i++)if(G[x][i]){
		if(!TL[i]){TR[x]=i;TL[i]=x;return 1;}
		else if(!vis[TL[i]]&&dfs(TL[i])){TR[x]=i;TL[i]=x;return 1;}
	}
	return 0;
}

void work(int L){
	memset(G,0,sizeof G);
	memset(TL,0,sizeof TL);
	memset(TR,0,sizeof TR);
	
	for(int i=1;i<=n;++i)
		for(int j=L;j<=m;++j)G[i][geti(a[i][j])]=1;//,fprintf(stderr,"edge %d,%d\n",i,geti(a[i][j]));
	for(int i=1;i<=n;++i){
		memset(vis,0,sizeof vis);
		dfs(i);
	}
	for(int i=1;i<=n;++i){
	//	fprintf(stderr,"TR[%d]=%d\n",i,TR[i]);
		for(int j=L;j<=m;++j)
			if(TR[i]==geti(a[i][j]))swap(a[i][j],a[i][L]);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=1;i<=m;i++)work(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cout<<a[i][j]<<(j==m?'\n':' ');//return 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			while(geti(a[i][j])!=i)swap(a[i][j],a[geti(a[i][j])][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cout<<a[i][j]<<(j==m?'\n':' ');
	return 0;
}

