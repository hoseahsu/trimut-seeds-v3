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
#include <unordered_map>

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

const int INFTY=1<<29;

struct Edge{
	int src,dst;
	ll flow,capacity;
	int next;
	Edge(){}
	Edge(int s,int d,ll f,ll c,int n):src(s),dst(d),flow(f),capacity(c),next(n){}
};

void AddEdge(vector<Edge>& es,vi& head,int src,int dst,ll flow,ll capacity){
	es.push_back(Edge(src,dst,flow,capacity,head[src]));
	head[src]=es.size()-1;
}

vi BFS(const vector<Edge>& es,const vi& head,int begin)
{
	int size=head.size();
	vi label(size,size);
	queue<pii> q;
	q.push(mp(begin,0));
	while(q.size()){
		pii cur=q.front(); q.pop();
		if(label[cur.first]<=cur.second)
			continue;
		label[cur.first]=cur.second;
		for(int i=head[cur.first];i!=-1;i=es[i].next)
			if(es[i].capacity-es[i].flow>0)
				q.push(mp(es[i].dst,cur.second+1));
	}
	return label;
}

ll DFS(vector<Edge>& es,vi& head,int v,int end,const vi& label,ll f)
{
	if(v==end)
		return f;
	for(int& i=head[v];i!=-1;i=es[i].next){
		Edge& e=es[i];
		if(label[e.src]>=label[e.dst])
			continue;
		ll residue=e.capacity-e.flow;
		if(residue<=0)
			continue;
		ll augment=DFS(es,head,e.dst,end,label,min(residue,f));
		if(augment>0){
			e.flow+=augment;
			es[i^1].flow-=augment;
			return augment;
		}
	}
	return 0;
}

ll Dinic(vector<Edge>& es,const vi& head,int begin,int end)
{
	int size=head.size();
	for(;;){
		vi label=BFS(es,head,begin);
		if(label[end]==size)
			break;
		vi temp=head;
		while(DFS(es,temp,begin,end,label,INFTY))
			;
	}
	ll res=0;
	for(int i=head[begin];i!=-1;i=es[i].next)
		res+=es[i].flow;
	return res;
}

int main()
{
	unordered_map<string,int> dtoi;
	for(string d:{"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"})
		dtoi.insert(mp(d,dtoi.size()));
	
	for(ll n,w;cin>>n>>w,n|w;){
		vector<Edge> es;
		vi head(7+n+2,-1); // 0..6:曜日, 7..7+n-1:生徒, 7+n:src, 7+n+1:snk
		int src=7+n,snk=src+1;
		rep(i,7){
			AddEdge(es,head,src,i,0,w);
			AddEdge(es,head,i,src,0,0);
		}
		ll sum=0;
		rep(i,n){
			ll t,c; cin>>t>>c;
			sum+=t;
			rep(j,c){
				string s; cin>>s;
				AddEdge(es,head,dtoi[s],7+i,0,w);
				AddEdge(es,head,7+i,dtoi[s],0,0);
			}
			AddEdge(es,head,7+i,snk,0,t);
			AddEdge(es,head,snk,7+i,0,0);
		}
		
		if(Dinic(es,head,src,snk)==sum)
			puts("Yes");
		else
			puts("No");
	}
	
	return 0;
}