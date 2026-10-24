#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100005
#define MAX_M 100005
typedef pair<int,int> P;

int n,m;
int x[MAX_M],y[MAX_M],w[MAX_M];

vector<int> G[MAX_N];
vector<int> g[MAX_N];

vector<int> group[MAX_N];
int id[MAX_N];
bool visited[MAX_N];
vector<int> vd;

int dp[MAX_N];

bool dfs(int pos,int prev,int root){
  id[pos]=root;
  visited[pos]=true;
  group[root].push_back(pos);
  for(int i=0;i<(int)G[pos].size();i++){
    int to=G[pos][i];
    if(to==prev)continue;
    if(i&&to==G[pos][i-1])return true;
    if(visited[to])return true;
    if(dfs(to,pos,root))return true;
  }
  return false;
}

bool check(){
  memset(visited,false,sizeof(visited));
  for(int i=0;i<n;i++){
    if(visited[i])continue;
    if( dfs(i,-1,i) )return true;
  }

  vector< int > deg(n);
  vector< vector<int> > graph(n);
  
  for(int i=0;i<m;i++){
    if(w[i]==1){
      int X=id[ x[i] ];
      int Y=id[ y[i] ];
      if(X==Y)return true;
      graph[X].push_back(Y);
      deg[Y]++;
    }
  }

  queue<int> Q;
  for(int i=0;i<n;i++)
    if(deg[i]==0&&id[i]==i)
      Q.push(i);

  while(!Q.empty()){
    int pos=Q.front();Q.pop();
    vd.push_back(pos);
    for(int to:graph[pos]){
      deg[to]--;
      if(deg[to]==0)Q.push(to);
    }
  }
  
  for(int i=0;i<n;i++)
    if(deg[i]>0)return true;
  
  return false;
}

int d[MAX_N];

void init(int root){
  root=id[root];
  for(int pos:group[root])
    d[pos]=-1;
}

void bfs(int root){
  init(root);
  queue<int> Q;
  Q.push(root);
  d[root]=0;
  while(!Q.empty()){
    int pos=Q.front();Q.pop();
    for(int to:G[pos]){
      if(d[to]!=-1)continue;
      d[to]=d[pos]+1;
      Q.push(to);
    }
  }
}

void update(int root,int dif){
  for(int pos:group[root])
    for(int to:g[pos])
      dp[to]=max(dp[to],d[pos]+dif+1);
}

int solve(int root){
  int res=0;
  bfs(root);
  int maxm=-1,maxmid;
  for(int pos:group[root])
    if(d[pos]+dp[pos]>maxm)maxm=d[pos]+dp[pos],maxmid=pos;
  
  bfs(maxmid);
  update(root,dp[maxmid]);
  for(int pos:group[root])res=max(res,d[pos]+dp[maxmid]);
  
  maxm=-1;
  for(int pos:group[root])
    if(d[pos]+dp[pos]>maxm)maxm=d[pos]+dp[pos],maxmid=pos;

  bfs(maxmid);
  update(root,dp[maxmid]);
  for(int pos:group[root])res=max(res,d[pos]+dp[maxmid]);
  
  return res;
}

int main(){
  scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++){
    scanf("%d %d %d",&x[i],&y[i],&w[i]);
    x[i]--,y[i]--;
    if(w[i]==1){
      g[x[i]].push_back(y[i]);
    }
    if(w[i]==2){
      G[x[i]].push_back(y[i]);
      G[y[i]].push_back(x[i]);
    }
  }
  
  if( check() ){
    printf("Infinite\n");
    return 0;
  }

  int ans=0;
  for(int root : vd ){
    if(root!=id[root])continue;
    ans=max(ans,solve(root));
  }
  printf("%d\n",ans);  
  return 0;
}