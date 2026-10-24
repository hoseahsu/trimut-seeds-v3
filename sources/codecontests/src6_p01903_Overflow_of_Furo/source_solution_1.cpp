#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 120

enum Type{
	BASE,
	TMP,
};


//辺を表す構造体(行先、容量、逆辺のインデックス)
struct Edge{
	Edge(int arg_to,int arg_capacity,int arg_rev_index){
		to = arg_to;
		capacity = arg_capacity;
		rev_index = arg_rev_index;
	}
	int to,capacity,rev_index;
};

int V;
int K,N,E;
vector<Edge> G[2][NUM]; //グラフの隣接リスト表現
int dist[2][NUM]; //sourceからの距離
int cheked_index[2][NUM]; //どこまで調べ終わったか
int table[NUM];
bool can_visit[NUM];

//fromからtoへ向かう容量capacityの辺をグラフに追加する
void add_edge(int from,int to,int capacity){
	G[BASE][from].push_back(Edge(to,capacity,G[BASE][to].size())); //★逆辺はそれぞれ張る★
	G[BASE][to].push_back(Edge(from,0,G[BASE][from].size()-1)); //逆辺の、初期容量は0
}

//sourceからの最短距離をBFSで計算する
void bfs(Type type,int source){
	for(int i = 0; i < V; i++)dist[type][i] = -1;
	queue<int> Q;
	dist[type][source] = 0;
	Q.push(source);

	while(!Q.empty()){
		int node_id = Q.front();
		Q.pop();

		for(int i = 0; i < G[type][node_id].size(); i++){
			Edge &e = G[type][node_id][i];
			if(e.capacity > 0 && dist[type][e.to] < 0){ //辺の容量が正で、かつエッジの行先に未訪問の場合
				dist[type][e.to] = dist[type][node_id]+1;
				Q.push(e.to);
			}
		}
	}
}

//増加パスをDFSで探す
int dfs(Type type,int node_id,int sink,int flow){
	if(node_id == sink)return flow; //終点についたらflowをreturn

	for(int &i = cheked_index[type][node_id]; i < G[type][node_id].size(); i++){ //node_idから出ているエッジを調査
		Edge &e = G[type][node_id][i];
		if(e.capacity > 0 && dist[type][node_id] < dist[type][e.to]){ //流せる余裕があり、かつsourceからの距離が増加する方法である場合
			int tmp_flow = dfs(type,e.to,sink,min(flow,e.capacity)); //流せるだけ流す
			if(tmp_flow > 0){ //流せた場合
				e.capacity -= tmp_flow; //流した分、エッジの容量を削減する
				G[type][e.to][e.rev_index].capacity += tmp_flow; //逆辺の容量を、流した分だけ増加させる
				return tmp_flow;
			}
		}
	}
	return 0;
}

//sourceからsinkへの最大流を求める
int max_flow(Type type,int source,int sink){ //source:始点 sink:終点
	int flow = 0,add;
	while(true){ //増加パスが存在する限り、流量を追加し続ける
		bfs(type,source);
		if(dist[type][sink] < 0)break; //sourceからsinkへと辿り着く残余グラフがない、つまり増加パスが無くなった場合、break
		for(int i = 0; i < V; i++)cheked_index[type][i] = 0;
		while((add = dfs(type,source,sink,BIG_NUM)) > 0){ //増加パスが見つかる間、加算
			flow += add;
		}
	}
	return flow;
}

//sourceから行けるノードを探す
void visit_check(int node_id){
	can_visit[node_id] = true;

	for(int i = 0; i < G[BASE][node_id].size(); i++){
		if(can_visit[G[BASE][node_id][i].to] == true || G[BASE][node_id][i].capacity == 0)continue;
		visit_check(G[BASE][node_id][i].to);
	}
}


int main(){

	scanf("%d %d %d",&K,&N,&E);

	int from,to,capacity;
	for(int loop = 0; loop < E; loop++){
		scanf("%d %d %d",&from,&to,&capacity);
		add_edge(from,to,capacity);
		add_edge(to,from,capacity);
	}

	int source = K+N+1,sink = 0; //浴槽をsinkとする

	for(int i = 1; i <= K; i++){
		add_edge(source,i,BIG_NUM);
	}

	//一回流す
	V = K+N+2;
	int base_flow = max_flow(BASE,source,sink);

	//sourceから行けるノードを探す
	for(int i = 0; i < V; i++)can_visit[i] = false;
	visit_check(source);

	int ans = 0;

	//残余グラフ上でボトルネックを走査(ボトルネック辺はcapacityが0になっているはず)
	//ループの際、sourceとsinkは除く
	table[source] = BIG_NUM;
	table[sink] = BIG_NUM;
	for(int i = 1; i < V-1; i++){
		for(int k = 0; k < NUM; k++){
			G[TMP][k] = G[BASE][k];
		}
		if(can_visit[i]){
			table[i] = max_flow(TMP,source,i);
		}else{
			table[i] = max_flow(TMP,i,sink);
		}
	}

	for(int i = 0; i < V; i++){
		if(!can_visit[i])continue;
		for(int k = 0; k < G[BASE][i].size(); k++){
			if(can_visit[G[BASE][i][k].to])continue;
			ans = max(ans,min(table[i],table[G[BASE][i][k].to]));
		}
	}

	ans += base_flow;

	if(ans >= BIG_NUM){
		printf("overfuro\n");
	}else{
		printf("%d\n",ans);
	}

	return 0;
}

