#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;
 
 
#define NUM 100005
 
struct Edge{
    Edge(int arg_to,ll arg_cost){
        to = arg_to;
        cost = arg_cost;
    }
    int to;
    ll cost;
};
 
vector<Edge> G[NUM]; //グラフの隣接リスト表現
int N; //ノードの個数
int root; //根ノードの番号
int MAX_LOG_V = 17;
int POW[18];
int parent[20][NUM];
int depth[NUM];
ll COST[NUM];
 
//parentとdepthを再帰的に設定
void dfs(int node_id,int parent_id,int d,ll sum_cost){
 
    parent[0][node_id] = parent_id;
    depth[node_id] = d;
    COST[node_id] = sum_cost;
 
    for(int i = 0; i < G[node_id].size(); i++){
        if(G[node_id][i].to != parent_id){
            dfs(G[node_id][i].to,node_id,d+1,sum_cost+G[node_id][i].cost);
        }
    }
}
 
//初期化
void init(){
    //parent[0]とdepthを初期化する
    dfs(root,-1,0,0);
    //parentを初期化する
    for(int k = 0; k + 1 < MAX_LOG_V; k++){
        for(int node_id = 0; node_id < N; node_id++){
            if(parent[k][node_id] < 0)parent[k+1][node_id] = -1; //node_idの2^k上のノードがルートノードより上なら、2^(k+1)上も同様とする
            else{
                parent[k+1][node_id] = parent[k][parent[k][node_id]];
            }
        }
    }
}
 
//leftとrightのLCAを求める
int lca(int left,int right){
    //leftとrightの深さが同じになるまで親を辿る
    if(depth[left] > depth[right])swap(left,right); //rightの方が深い所にいる
 
    for(int k = MAX_LOG_V-1; k >= 0; k--){
        if(depth[right]-depth[left] >= POW[k]){ //たとえば深さの差が39なら、32+4+2+1のように、ノードを上方に移動させる
            right = parent[k][right];
        }
    }
 
    if(left == right)return left;
 
    for(int k = MAX_LOG_V-1; k >= 0; k--){
        if(parent[k][left] == parent[k][right]){
            //Do nothing
        }else{
            left = parent[k][left];
            right = parent[k][right];
        }
    }
    return parent[0][left]; //最後は、leftの親とrightの親が必ず一致している
}
 
ll get_cost(int left,int right){
 
    int LCA = lca(left,right);
 
    return COST[left]+COST[right]-2*COST[LCA];
}
 
int get_node(int base_node,int diff){
 
    int ret = base_node;
 
    for(int loop = MAX_LOG_V-1; loop >= 0; loop--){
        if(diff & (1 << loop)){
            ret = parent[loop][ret];
        }
    }
    return ret;
}
 
ll calc_ans(int deeper,int LCA,ll DIST){
 
    int L = LCA,R = deeper,mid;
 
    ll ret = HUGE_NUM;
 
    ll cost_to_mid,REST;
 
    for(int loop = 0; loop < 20; loop++){
 
        mid = get_node(R,(depth[R]-depth[L])/2);
 
        cost_to_mid = COST[deeper]-COST[mid];
        REST = DIST-cost_to_mid;
 
        ret = min(ret,max(cost_to_mid,REST));
 
        if(cost_to_mid == REST){
 
            return ret;
 
        }else if(cost_to_mid < REST){
 
            R = parent[0][mid];
 
        }else{
 
            L = mid;
        }
    }
 
    return ret;
}
 
ll calc(int a,int b,int c){
 
    ll dist[3];
 
    dist[0] = get_cost(a,b);
    dist[1] = get_cost(a,c);
    dist[2] = get_cost(b,c);
 
    ll maximum = -HUGE_NUM;
    int index;
    for(int i = 0; i < 3; i++){
        if(maximum < dist[i]){
            maximum = dist[i];
            index = i;
        }
    }
 
    int left,right;
    ll DIST = maximum;
 
    switch(index){
    case 0:
        left = a;
        right = b;
        break;
    case 1:
        left = a;
        right = c;
        break;
    case 2:
        left = b;
        right = c;
        break;
    }
 
    int LCA = lca(left,right);
 
    ll cost_left = get_cost(left,LCA);
    ll cost_right = get_cost(right,LCA);
 
    if(cost_left == cost_right){
 
        return cost_left;
    }
 
    if(cost_left > cost_right){
 
        return calc_ans(left,LCA,DIST);
 
    }else{
 
        return calc_ans(right,LCA,DIST);
    }
}
 
int main(){
 
    for(int i = 0; i <= 17; i++)POW[i] = pow(2,i);
 
    int num_query;
 
    scanf("%d %d",&N,&num_query);
 
    int from,to;
    ll cost;
 
    for(int i = 0; i < N-1; i++){
 
        scanf("%d %d %lld",&from,&to,&cost);
        from--;
        to--;
        G[from].push_back(Edge(to,cost));
        G[to].push_back(Edge(from,cost));
    }
 
    root = 0;
    init();
 
    int a,b,c;
 
    for(int loop = 0; loop < num_query; loop++){
 
        scanf("%d %d %d",&a,&b,&c);
        a--;
        b--;
        c--;
 
        printf("%lld\n",calc(a,b,c));
    }
 
    return 0;
}
