#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

class UnionFind {
	vector<int>par, sz, sz2;
public:
	int cnt=0;
	UnionFind() {}
	int add_vertex(){
		int n=par.size();
		par.push_back(n);
		sz.push_back(1);
		sz2.push_back(0);
		return n;
	}
	int find(int x) {
		if (par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y){
			cnt-=min(sz2[x],sz[x]);
			sz2[x]++;
			cnt+=min(sz2[x],sz[x]);
			return;
		}
		cnt-=min(sz2[x],sz[x]);
		cnt-=min(sz2[y],sz[y]);
		par[y] = x;
		sz[x] += sz[y];
		sz2[x]+=sz2[y];
		sz2[x]++;
		cnt+=min(sz2[x],sz[x]);
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int size(int x) {
		return sz[find(x)];
	}
};

vector<int>E[200000];
int ans[200000];

struct st{
	map<int,int>mp;
	UnionFind uf;
	vector<P>edge;
}dat[200000];

void merge(int u,int v){//u<-v
	if(dat[u].edge.size()<dat[v].edge.size())swap(dat[u],dat[v]);
	for(auto p:dat[v].edge){
		if(!dat[u].mp.count(p.first)){
			dat[u].mp[p.first]=dat[u].uf.add_vertex();
		}
		if(!dat[u].mp.count(p.second)){
			dat[u].mp[p.second]=dat[u].uf.add_vertex();
		}
		dat[u].uf.unite(dat[u].mp[p.first],dat[u].mp[p.second]);
		dat[u].edge.push_back(p);
	}
}

void dfs(int v,int p){
	for(int u:E[v]){
		if(u==p)continue;
		dfs(u,v);
		merge(v,u);
	}
	ans[v]=dat[v].uf.cnt;
}

int main(){
	int n,K;cin>>n>>K;
	rep(i,n-1){
		int a,b;scanf("%d%d",&a,&b);a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	rep(i,n){
		int c,d;scanf("%d%d",&c,&d);c--;d--;
		dat[i].mp[c]=dat[i].uf.add_vertex();
		if(c!=d)dat[i].mp[d]=dat[i].uf.add_vertex();
		dat[i].uf.unite(dat[i].mp[c],dat[i].mp[d]);
		dat[i].edge.push_back(P(c,d));
	}
	dfs(0,-1);
	rep(i,n){
		printf("%d\n",ans[i]);
	}
}
