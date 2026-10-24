#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

struct Edge{
	Edge(int arg_to,ll arg_weight){
		to = arg_to;
		weight = arg_weight;
	}
	int to;
	ll weight;
};

struct Info{
	Info(int arg_node_id,int arg_pre){
		node_id = arg_node_id;
		pre = arg_pre;
	}
	int node_id,pre;
};

int N;
int root = 0;
int leaf[SIZE];
int num_visit;
int LEFT[SIZE],RIGHT[SIZE];
ll PARENT[SIZE],num_OUT[SIZE],W[SIZE],euler_W[SIZE],edge_W[SIZE];
ll nodes[2*SIZE+5],max_L[2*SIZE+5],max_R[2*SIZE+5];
vector<Edge> G[SIZE];

//オイラーツアーで、ノードのカバー範囲を計算する
void euler_tour(int node_id,int pre_node,ll sum){
	euler_W[node_id] = sum;
	nodes[num_visit] = node_id;
	LEFT[node_id] = num_visit++;

	for(int i = 0; i < G[node_id].size(); i++){
		if(G[node_id][i].to == pre_node)continue;
		edge_W[G[node_id][i].to] = G[node_id][i].weight; //入次の重み
		euler_tour(G[node_id][i].to,node_id,sum+G[node_id][i].weight);
	}
	nodes[num_visit] = node_id;
	RIGHT[node_id] = num_visit++;
}

int main(){

	scanf("%d",&N);

	int from;
	ll weight;

	for(int to = 1; to <= N-1; to++){
		scanf("%d %lld",&from,&weight);
		G[from].push_back(Edge(to,weight));
		G[to].push_back(Edge(from,weight));
	}

	for(int i = 0; i < N; i++){

		num_OUT[i] = 0;
	}

	queue<Info> Q;
	Q.push(Info(root,-1));

	while(!Q.empty()){

		PARENT[Q.front().node_id] = Q.front().pre;

		for(int i = 0; i < G[Q.front().node_id].size(); i++){
			int next = G[Q.front().node_id][i].to;
			if(next == Q.front().pre)continue;

			num_OUT[Q.front().node_id]++;

			Q.push(Info(next,Q.front().node_id));
		}
		Q.pop();
	}

	ll maximum = 0;
	int A,B;

	queue<int> NODE;

	for(int i = 0; i < N; i++){
		if(num_OUT[i] == 0){
			leaf[i] = i;
			W[i] = 0;
			NODE.push(i);
		}
	}

	ll max_path1,max_path2;
	int a,b;

	while(!NODE.empty()){

		int node = NODE.front();
		NODE.pop();

		max_path1 = 0;
		max_path2 = 0;

		b = node;

		for(int i = 0; i < G[node].size(); i++){

			int child = G[node][i].to;
			if(child == PARENT[node])continue;

			ll tmp = W[child]+G[node][i].weight;

			if(tmp > max_path1){

				max_path2 = max_path1;
				b = a;
				max_path1 = tmp;
				W[node] = tmp;
				leaf[node] = leaf[child];
				a = leaf[child];

			}else if(tmp > max_path2){

				max_path2 = tmp;
				b = leaf[child];
			}
		}

		if(max_path1+max_path2 > maximum){

			maximum = max_path1+max_path2;
			A = a;
			B = b;
		}
		if(PARENT[node] != -1){
			num_OUT[PARENT[node]]--;
		}
		if(num_OUT[PARENT[node]] == 0){

			NODE.push(PARENT[node]);
		}
	}
	num_visit = 0;
	euler_tour(A,-1,0);

	//基準点より左の最大重み
	max_L[0] = euler_W[A];
	for(int i = 1; i < 2*N; i++){

		max_L[i] = max(max_L[i-1],euler_W[nodes[i]]);
	}
	max_R[2*N-1] = euler_W[A];
	for(int i = 2*N-2; i >= 0; i--){

		max_R[i] = max(max_R[i+1],euler_W[nodes[i]]);
	}

	ll ans = 0;
	ll w_L,w_R;

	for(int i = 0; i < N; i++){
		if(i == A)continue;

		if(LEFT[i] > 0){

			w_L = max_L[LEFT[i]-1];
		}
		if(RIGHT[i]+1 < 2*N){

			w_R = max_R[RIGHT[i]+1];
		}
		ans = max(ans,edge_W[i]+max(w_L,w_R));
	}

	num_visit = 0;
	edge_W[B] = 0;
	euler_tour(B,-1,0);

	//基準点より左の最大重み
	max_L[0] = euler_W[B];
	for(int i = 1; i < 2*N; i++){

		max_L[i] = max(max_L[i-1],euler_W[nodes[i]]);
	}
	max_R[2*N-1] = euler_W[B];
	for(int i = 2*N-2; i >= 0; i--){

		max_R[i] = max(max_R[i+1],euler_W[nodes[i]]);
	}

	for(int i = 0; i < N; i++){
		if(i == B)continue;

		if(LEFT[i] > 0){

			w_L = max_L[LEFT[i]-1];
		}
		if(RIGHT[i]+1 < 2*N){

			w_R = max_R[RIGHT[i]+1];
		}
		ans = max(ans,edge_W[i]+max(w_L,w_R));
	}

	printf("%lld\n",ans);

	return 0;
}

