#include<iostream>
#include<queue>
#include<cstdio>
#define rep(i,j) for(int (i)=0;(i)<(j);(i)++)

using namespace std;

struct state{
  int prev,now,v;
  double time;
  bool operator <(const state &s)const{
    return time>s.time;
  }
};

const double INFd=1e9;
int n,m;
int s,g;
struct edge{
  int to,d,c;
};

vector< vector<edge> > G; 

double solve(){

  priority_queue<state> que;

  double dist[31][31][31];
  rep(i,31)rep(j,31)rep(k,31)dist[i][j][k]=INFd;
  
  que.push((state){s,s,0,0});
  dist[s][s][0]=0;
  
  while(!que.empty()){
    state now=que.top();que.pop();
    //cout<<"now"<<endl;
    //printf("%d %d %d %f\n",now.prev,now.now,now.v,now.time);
    
    rep(i,G[now.now].size()){
      edge &e=G[now.now][i];
      if(e.to!=now.prev){
        rep(j,3){
          int nv=now.v+j-1;
          double ntime=now.time+e.d/(double)nv;
          if(nv<=e.c && nv>0){
            state nxt=(state){now.now,e.to,nv,ntime};

            if(dist[now.now][e.to][nv]>ntime){
              dist[now.now][e.to][nv]=ntime;
              que.push(nxt);
            }
          }
        }
      }
    }
  }

  double ans=INFd;
  rep(i,31){
    ans=min(dist[i][g][1],ans);
  }
  
  return ans;
}


int main(){
  while(true){
    cin>>n>>m;
    if(n==0 and m==0)break;
    cin>>s>>g;
    s--;
    g--;
    G.clear();
    G.resize(n);
    rep(i,m){
      int x,y,d,c;
      cin>>x>>y>>d>>c;
      x--;
      y--;
      G[x].push_back((edge){y,d,c});
      G[y].push_back((edge){x,d,c});
    }
    double ans=solve();
    if(ans!=INFd)
      printf("%.9f\n",solve());
    else
      printf("unreachable\n");
    
  }

  
}