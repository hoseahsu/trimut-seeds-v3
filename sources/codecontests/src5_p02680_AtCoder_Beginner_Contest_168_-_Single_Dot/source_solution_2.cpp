#include<bits/stdc++.h>
using namespace std;
const int maxn=3006;
const int inf=1e9+7; 
typedef long long ll;
int dir[][2]={1,0,-1,0,0,1,0,-1};
int a[maxn],b[maxn],c[maxn],D[maxn],e[maxn],f[maxn];
int u[maxn][maxn],d[maxn][maxn],l[maxn][maxn],r[maxn][maxn],vis[maxn][maxn];
vector<int>xx({-inf,inf}),yy({-inf,inf});
void bfs(int x,int y){
	vis[x][y]=1;
	queue<pair<int,int>>q;
	q.push({x,y});
	while(!q.empty()){
		x=q.front().first,y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			if(i==0&&r[x][y]) continue;
			if(i==1&&l[x][y]) continue;
			if(i==2&&u[x][y]) continue;
			if(i==3&&d[x][y]) continue;
			int nx=x+dir[i][0];
			int ny=y+dir[i][1];
			if(nx<0||ny<0) continue;
			if(nx>=xx.size()-1||ny>=yy.size()-1) continue;
			if(vis[nx][ny]) continue;
			vis[nx][ny]=1;
			q.push({nx,ny});
		}
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
		scanf("%d",&c[i]);
		xx.push_back(a[i]);
		xx.push_back(b[i]);
		yy.push_back(c[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&D[i]);
		scanf("%d",&e[i]);
		scanf("%d",&f[i]);
		xx.push_back(D[i]);
		yy.push_back(e[i]);
		yy.push_back(f[i]);
	}
	sort(xx.begin(),xx.end());
	sort(yy.begin(),yy.end());
	xx.resize(unique(xx.begin(),xx.end())-xx.begin());
	yy.resize(unique(yy.begin(),yy.end())-yy.begin());
	for(int i=0;i<n;i++){
		int aa=lower_bound(xx.begin(),xx.end(),a[i])-xx.begin();
		int bb=lower_bound(xx.begin(),xx.end(),b[i])-xx.begin();
		int cc=lower_bound(yy.begin(),yy.end(),c[i])-yy.begin();
		for(int x=aa;x<bb;x++){
			u[x][cc-1]=1;
			d[x][cc]=1;
		}
	}
	for(int i=0;i<m;i++){
		int dd=lower_bound(xx.begin(),xx.end(),D[i])-xx.begin();
		int ee=lower_bound(yy.begin(),yy.end(),e[i])-yy.begin();
		int ff=lower_bound(yy.begin(),yy.end(),f[i])-yy.begin();
		for(int y=ee;y<ff;y++){
			l[dd][y]=1;
			r[dd-1][y]=1;
		}
	}
	int x=lower_bound(xx.begin(),xx.end(),0)-xx.begin()-1;
	int y=lower_bound(yy.begin(),yy.end(),0)-yy.begin()-1;
	bfs(x,y);
	if(vis[0][0]||vis[xx.size()-1][yy.size()-1]){
		printf("INF\n");return 0;
	}
	ll ans=0;
	for(int i=0;i<xx.size()-1;i++){
		for(int j=0;j<yy.size()-1;j++){
			if(vis[i][j]) ans+=(ll)(xx[i+1]-xx[i])*(yy[j+1]-yy[j]);
		}
	}
	printf("%lld\n",ans);
}