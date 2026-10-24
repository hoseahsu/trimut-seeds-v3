#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

const int INF=1<<29;

vector<int> BFS(const graph& G,int s){
	int n=G.size();
	vector<int> d(n,INF);
	d[s]=0;
	queue<int> Q; Q.emplace(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:G[u]) if(d[v]==INF) {
			d[v]=d[u]+1;
			Q.emplace(v);
		}
	}
	return d;
}

int main(){
	int h,w; scanf("%d%d",&h,&w);
	char B[20][21];
	rep(i,h) scanf("%s",B[i]);

	graph G(h*w);
	rep(i,h) rep(j,w) if(B[i][j]=='.') rep(k,4) {
		int y=i+dy[k],x=j+dx[k];
		if(0<=y && y<=h && 0<=x && x<w && B[y][x]=='.') G[i*w+j].emplace_back(y*w+x);
	}

	int ans=0;
	rep(i0,h) rep(j0,w) {
		auto d=BFS(G,i0*w+j0);
		rep(i,h) rep(j,w) if(d[i*w+j]<INF) ans=max(ans,d[i*w+j]);
	}
	printf("%d\n",ans);

	return 0;
}
