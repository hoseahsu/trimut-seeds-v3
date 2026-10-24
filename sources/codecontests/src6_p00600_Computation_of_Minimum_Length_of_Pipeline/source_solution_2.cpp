#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <complex>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <functional>
#include <iterator>

using namespace std;

#define dump(n) cerr<<"# "<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define iter(c) __typeof__((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)
#define all(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

struct UnionFind{
	vi data;
	UnionFind(int size):data(size,-1){}
	int Find(int n){
		return data[n]<0?n:(data[n]=Find(data[n]));
	}
	void Unite(int a,int b){
		int ra=Find(a),rb=Find(b);
		if(ra!=rb){
			if(-data[ra]<-data[rb])
				swap(ra,rb);
			data[ra]+=data[rb];
			data[rb]=ra;
		}
	}
	int Size(int n){
		return -data[Find(n)];
	}
};

struct Edge{
	int src,dst,weight;
	Edge(){}
	Edge(int s,int d,int w):src(s),dst(d),weight(w){}
	bool operator<(const Edge& e)const{return weight<e.weight;}
	bool operator>(const Edge& e)const{return weight>e.weight;}
};
typedef vector<vector<Edge> > Graph;

int Kruskal(const Graph& g,vector<Edge>& forest)
{
	forest.clear();
	
	vector<Edge> es;
	rep(i,g.size()) rep(j,g[i].size())
		es.push_back(g[i][j]);
	sort(all(es));
	
	UnionFind uf(g.size());
	int res=0;
	rep(i,es.size())
		if(uf.Find(es[i].src)!=uf.Find(es[i].dst)){
			uf.Unite(es[i].src,es[i].dst);
			res+=es[i].weight;
			forest.push_back(es[i]);
		}
	return res;
}

int main()
{
	for(int m,n;cin>>m>>n,m|n;){
		Graph g(m+n+1);
		rep(i,m) rep(j,n){
			int w; cin>>w;
			if(!w) continue;
			g[i].emplace_back(i,m+j,w);
			g[m+j].emplace_back(m+j,i,w);
		}
		rep(i,n) repi(j,i+1,n){
			int w; cin>>w;
			if(!w) continue;
			g[m+i].emplace_back(m+i,m+j,w);
			g[m+j].emplace_back(m+j,m+i,w);
		}
		rep(i,m)
			g[m+n].emplace_back(m+n,i,0);
		
		vector<Edge> forest;
		cout<<Kruskal(g,forest)<<endl;
	}
	
	return 0;
}