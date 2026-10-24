#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
using ll=int_fast64_t;
using P=pair<ll,ll>;
const ll INF=1LL<<30;
const ll LINF=1LL<<61;
const double EPS=1e-9;
const int MOD=1e9+7;
struct edge{int to;ll cost;};
int main(){
    int N,M;cin>>N>>M;
    int S,T;cin>>S>>T;--S;--T;
    int U,V;cin>>U>>V;--U;--V;
    vector<vector<edge>> G(N),nG(N);
    for(int i=0;i<M;i++){
        int a,b;ll c;cin>>a>>b>>c;--a;--b;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    vector<ll> ds(N,LINF),dt(N,LINF),du(N,LINF),dv(N,LINF);
    ds[S]=0,dt[T]=0,du[U]=0,dv[V]=0;
    priority_queue<P,vector<P>,greater<P>> q;
    q.push(P(0,S));
    while(!q.empty()){
        int v=q.top().second;q.pop();
        for(auto e:G[v]){
            if(ds[e.to]<=ds[v]+e.cost)continue;
            ds[e.to]=ds[v]+e.cost;
            q.push(P(ds[e.to],e.to));
        }
    }
    q.push(P(0,T));
    while(!q.empty()){
        int v=q.top().second;q.pop();
        for(auto e:G[v]){
            if(dt[e.to]<=dt[v]+e.cost)continue;
            dt[e.to]=dt[v]+e.cost;
            q.push(P(dt[e.to],e.to));
        }
    }
    q.push(P(0,U));
    while(!q.empty()){
        int v=q.top().second;q.pop();
        for(auto e:G[v]){
            if(du[e.to]<=du[v]+e.cost)continue;
            du[e.to]=du[v]+e.cost;
            q.push(P(du[e.to],e.to));
        }
    }
    q.push(P(0,V));
    while(!q.empty()){
        int v=q.top().second;q.pop();
        for(auto e:G[v]){
            if(dv[e.to]<=dv[v]+e.cost)continue;
            dv[e.to]=dv[v]+e.cost;
            q.push(P(dv[e.to],e.to));
        }
    }
    vector<int> in(N),vs;
    for(int i=0;i<N;i++){
        for(auto e:G[i]){
            if(ds[i]+e.cost+dt[e.to]==ds[T]){
                nG[i].push_back(e);
                in[e.to]++;
            }
        }
    }
    stack<int> st;
    for(int i=0;i<N;i++){
        if(in[i]==0&&nG[i].size()){
            st.push(i);
        }
    }
    while(!st.empty()){
        int v=st.top();st.pop();
        vs.push_back(v);
        for(auto e:nG[v]){
            in[e.to]--;
            if(in[e.to]==0)st.push(e.to);
        }
    }
    ll ans=du[V];
    vector<P> dp(N,P(LINF,LINF));
    for(auto v:vs){
        dp[v].first=min(dp[v].first,du[v]);
        dp[v].second=min(dp[v].second,dv[v]);
        ans=min(ans,dp[v].first+dv[v]);
        ans=min(ans,dp[v].second+du[v]);
        for(auto e:nG[v]){
            dp[e.to].first=min(dp[e.to].first,dp[v].first);
            dp[e.to].second=min(dp[e.to].second,dp[v].second);
        }
    }
    cout<<ans<<endl;
}   
