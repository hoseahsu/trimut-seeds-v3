#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 1000000007
#define INF 1000000000000000
using ppp=pair<ll,pair<int,int>>;

int main(){
  ll N,M,S;
  cin>>N>>M>>S;
  vector<vector<pair<int,int>>> G(N);
  vector<ll> A(M),B(M);
  for(int i=0;i<M;i++){
    int u,v;
    cin>>u>>v>>A.at(i)>>B.at(i);
    u--;
    v--;
    G.at(u).push_back(make_pair(v,i));
    G.at(v).push_back(make_pair(u,i));
  }
  vector<ll> C(N),D(N);
  for(int i=0;i<N;i++){
    cin>>C.at(i)>>D.at(i);
  }

  vector<vector<ll>> time(N,vector<ll>(2501,INF));
  if(S>2500){
    S=2500;
  }
  time.at(0).at(S)=0;
  priority_queue<ppp,vector<ppp>,greater<ppp>> pq;
  pq.push(make_pair(0,make_pair(0,S)));
  while(!pq.empty()){
    int v=pq.top().second.first;
    int money=pq.top().second.second;
    pq.pop();
    int nm=(int)min<ll>(2500,money+C.at(v));
    if(time.at(v).at(nm)>time.at(v).at(money)+D.at(v)){
      time.at(v).at(nm)=time.at(v).at(money)+D.at(v);
      pq.push(make_pair(time.at(v).at(nm),make_pair(v,nm)));
    }
    for(auto p:G.at(v)){
      int nv=p.first;
      int e=p.second;
      if(money<A.at(e)){
        continue;
      }
      if(time.at(nv).at(money-A.at(e))>time.at(v).at(money)+B.at(e)){
        time.at(nv).at(money-A.at(e))=time.at(v).at(money)+B.at(e);
        pq.push(make_pair(time.at(nv).at(money-A.at(e)),make_pair(nv,money-A.at(e))));
      }
    }
  }

  for(int i=1;i<N;i++){
    ll ans=INF;
    for(int j=0;j<=2500;j++){
      ans=min<ll>(ans,time.at(i).at(j));
    }
    cout<<ans<<endl;
  }
}
