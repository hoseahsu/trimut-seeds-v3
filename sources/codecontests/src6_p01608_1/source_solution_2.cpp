#include  <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

const int vmax=5010;
const int inf=1<<30;
struct edge{int to,cap,rev;};
vector<edge> graph[vmax];
int level[vmax],iter[vmax];

void reset(){
	rep(i,vmax) graph[i].clear();
}

void add_edge(int from,int to,int cap){
	// cout << from << " " << to << " "  << cap << endl;
	graph[from].push_back({to,cap,(int)graph[to].size()});
	graph[to].push_back({from,0,(int)graph[from].size()-1});
}

int max_flow(int s,int t){
	auto bfs=[&](int s,int t){
		rep(i,vmax) level[i]=-1;
		queue<int> q;
		level[s]=0,q.push(s);
		while(!q.empty()){
			int v=q.front();q.pop();
			for(auto &e:graph[v]){
				if(e.cap>0 && level[e.to]<0){
					level[e.to]=level[v]+1;
					q.push(e.to);
				}
			}
		}
		return level[t]>=0;
	};
	function<int(int,int,int)> dfs=[&dfs](int v,int t,int f){
		if(v==t) return f;
		for(int &i=iter[v];i<graph[v].size();i++){
			edge &e=graph[v][i];
			if(e.cap>0 && level[v]<level[e.to]){
				int d=dfs(e.to,t,min(f,e.cap));
				if(d==0) continue;
				e.cap-=d;graph[e.to][e.rev].cap+=d;
				return d;
			}
		}
		return 0;
	};
	int flow=0;
	while(bfs(s,t)){
		rep(i,vmax) iter[i]=0;
		while(1){
			int f=dfs(s,t,inf);
			if(f==0) break;
			flow+=f;
		}
	}
	return flow;
}

int n,w,a[1010],b[1010];
void set_edge(int s,int t){
	reset();
	// init select 0
	rep(i,w+1){
		if(i%2==0)
			add_edge(i,t,inf);
		else
			add_edge(s,i,inf);
	}
	// select 0~n-1
	/*
	rep(i,n){
		int idx=i+w+1;
		add_edge(s,idx,0);
		add_edge(idx,t,0);
	}
	*/
	// a[i] cost loss
	rep(i,n){
		int idx=i+w+1;
		add_edge(idx,idx-1,a[i]);
		add_edge(idx-1,idx,a[i]);
	}
	// b[i] cost loss
	rep(i,n){
		add_edge(i,i+2*w+1,b[i]);
		add_edge(i+2*w+1,i,b[i]);
	}
}

string get(){
	string ret="";
	int cur=0;
	rep(i,n){
		int idx=i+w+1;
		int nxt=(level[idx]>=0);
		nxt^=(idx%2);
		ret+=(nxt^cur)+'0';
		cur=nxt;
	}
	return ret;
}

int main(void){
	cin >> n >> w;
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	int vertex=n+2*w+1;
	const int s=vertex,t=vertex+1;

	set_edge(s,t);
	// last select type 0
	rep(i,w+1){
		int idx=i+n+w;
		if(idx%2==0)
			add_edge(idx,t,inf);
		else
			add_edge(s,idx,inf);
	}

	int zero_score=max_flow(s,t);
	string zero_str=get();

	set_edge(s,t);
	// last select type 2
	rep(i,w+1){
		int idx=i+n+w;
		if(idx%2==0)
			add_edge(s,idx,inf);
		else
			add_edge(idx,t,inf);
	}

	int one_score=max_flow(s,t);
	string one_str=get();

	if(zero_score<one_score)
		cout << zero_str << endl;
	else
		cout << one_str << endl;
	return 0;
}