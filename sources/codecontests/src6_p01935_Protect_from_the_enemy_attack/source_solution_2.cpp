#include<bits/stdc++.h>
#define INF 1e9
#define MAX_N 5005
using namespace std;
struct edge{int from,to,cap,rev;};

bool used[MAX_N];
vector< edge > G[MAX_N];
int N,M;

void add_edge(int from,int to,int cap){
  int A=G[from].size();
  int B=G[to].size();
  G[from].push_back( (edge){from,to,cap,B} );
  G[to].push_back( (edge){to,from,cap,A} );
}

int dfs(int v,int t,int f){
  if(v==t)return f;
  used[v]=true;
  for(int i=0;i<(int)G[v].size();i++){
    edge &e=G[v][i];
    if(!used[e.to] && e.cap>0){
      int d=dfs(e.to,t,min(f,e.cap));
      if(d>0){
        e.cap-=d;
        G[e.to][e.rev].cap+=d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s,int t){
  int flow=0;
  for(;;){
    memset(used,0,sizeof(used));
    int f=dfs(s,t,INF);
    if(f==0)break;
    flow+=f;
  }
  return flow;
}

bool check(int s,int t){
  memset(used,0,sizeof(used));
  return dfs(s,t,1);
}

int main(){
  cin>>N>>M;
  for(int i=0;i<M;i++){
    int a,b,c;
    cin>>a>>b>>c;
    add_edge(a,b,c);
  }
  
  int ans=max_flow(0,N-1);
  
  if(ans>10005){
    cout<<-1<<endl;
    return 0;
  }
  
  for(int i=0;i<N;i++){
    for(int j=0;j<(int)G[i].size();j++){
      edge &e=G[i][j];
      edge &e2=G[e.to][e.rev];
      //      cout<<e.from<<' '<<e.to<<' '<<e.cap<<endl;
      //      cout<<e2.from<<' '<<e2.to<<' '<<e2.cap<<endl;
      if(e.cap!=0)continue;
      if(e2.cap!=2)continue;

      if(check(e.from,e.to)){
        e.cap++;
        e2.cap--;
        continue;
      }

      check(e.from,0);
      check(N-1,e.to);
      if( check(0,N-1) ){
        e.cap++;
        e2.cap--;
      }else{
        cout<<ans-1<<endl;
        return 0;
      }

      
    }
  }
  if(ans>10000)ans=-1;
  cout<<ans<<endl;
  return 0;  
}