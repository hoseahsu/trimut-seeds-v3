#include<cstdio>
#include<numeric>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef long long ll;

const int V_MAX=109;
const int E_MAX=1000;

template<class T>
struct graph{
	int n,m,head[V_MAX],next[2*E_MAX],to[2*E_MAX];
	T capa[2*E_MAX],flow[2*E_MAX];

	void init(int N){
		n=N;
		m=0;
		rep(u,n) head[u]=-1;
	}

	void add_directed_edge(int u,int v,T ca){
		next[m]=head[u]; head[u]=m; to[m]=v; capa[m]=ca; flow[m]=0; m++;
		next[m]=head[v]; head[v]=m; to[m]=u; capa[m]= 0; flow[m]=0; m++;
	}

	void add_undirected_edge(int u,int v,T ca){
		next[m]=head[u]; head[u]=m; to[m]=v; capa[m]=ca; flow[m]=0; m++;
		next[m]=head[v]; head[v]=m; to[m]=u; capa[m]=ca; flow[m]=0; m++;
	}
};

const ll INF=1LL<<61;

int layer[V_MAX],now[V_MAX];

template<class T>
bool make_layer(const graph<T> &G,int s,int t){
	int n=G.n;
	rep(u,n) layer[u]=(u==s?0:-1);

	int head=0,tail=0;
	static int Q[V_MAX]; Q[tail++]=s;
	while(head<tail && layer[t]==-1){
		int u=Q[head++];

		for(int e=G.head[u];e!=-1;e=G.next[e]){
			int v=G.to[e];
			T capa=G.capa[e],flow=G.flow[e];

			if(capa-flow>0 && layer[v]==-1){
				layer[v]=layer[u]+1;
				Q[tail++]=v;
			}
		}
	}

	return layer[t]!=-1;
}

template<class T>
T augment(graph<T> &G,int u,int t,T water){
	if(u==t) return water;

	for(int &e=now[u];e!=-1;e=G.next[e]){
		int v=G.to[e];
		T capa=G.capa[e],flow=G.flow[e];

		if(capa-flow>0 && layer[v]>layer[u]){
			T w=augment(G,v,t,min(water,capa-flow));
			if(w>0){
				G.flow[ e ]+=w;
				G.flow[e^1]-=w;
				return w;
			}
		}
	}
	return 0;
}

template<class T>
T Dinic(graph<T> &G,int s,int t){
	int n=G.n;
	T ans=0;
	while(make_layer(G,s,t)){
		rep(u,n) now[u]=G.head[u];
		for(T water=1;water>0;ans+=water) water=augment(G,s,t,INF);
	}
	return ans;
}

int main(){
	int n;
	for(ll W;scanf("%d%lld",&n,&W),n;){
		bool aki[100][7]={};
		ll need[100];
		rep(i,n){
			int m; scanf("%lld%d",need+i,&m);
			rep(j,m){
				char s[16]; scanf("%s",s);
				if(s[0]=='S' && s[1]=='u') aki[i][0]=true;
				if(s[0]=='M')              aki[i][1]=true;
				if(s[0]=='T' && s[1]=='u') aki[i][2]=true;
				if(s[0]=='W')              aki[i][3]=true;
				if(s[0]=='T' && s[1]=='h') aki[i][4]=true;
				if(s[0]=='F')              aki[i][5]=true;
				if(s[0]=='S' && s[1]=='a') aki[i][6]=true;
			}
		}

		int s=n+7,t=s+1;
		graph<ll> G;
		G.init(n+9);
		// source -> left nodes
		rep(u,7) G.add_directed_edge(s,u,W);
		// right nodes -> sink
		rep(i,n){
			int v=7+i;
			G.add_directed_edge(v,t,need[i]);
		}
		// left nodes -> right nodes
		rep(i,n) rep(j,7) if(aki[i][j]) {
			int u=j,v=7+i;
			G.add_directed_edge(u,v,W);
		}

		puts(Dinic(G,s,t)==accumulate(need,need+n,0LL)?"Yes":"No");
	}

	return 0;
}