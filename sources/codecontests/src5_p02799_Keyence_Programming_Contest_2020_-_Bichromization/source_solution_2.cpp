#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T,class U> using P = pair<T,U>;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

struct edge{
    ll to,id;
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vec<ll> D(N),id(N);
    iota(id.begin(),id.end(),0);
    for(int i=0;i<N;i++) cin >> D[i];
    sort(id.begin(),id.end(),[&](int a,int b){
        return D[a]<D[b];
    });
    vvec<edge> g(N);
    ll inf = 1e9;
    vec<char> ansv(N,'A');
    vec<ll> anse(M,inf);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    
    auto bfs = [&](int s){
        queue<int> Q;
        Q.push(s);
        while(!Q.empty()){
            int now = Q.front(); Q.pop();
            for(auto& e:g[now]) if(ansv[e.to]=='A' && D[s]==D[e.to]){
                if(now==s) ansv[now] = 'B';
                anse[e.id] = D[s];
                ansv[e.to] = (ansv[now]=='W'? 'B':'W');
                Q.push(e.to);
            }
        }
    };

    for(int i=0;i<N;i++) if(ansv[i]=='A') bfs(i);

    for(int i=0;i<N;i++){
        int now = id[i];
        if(ansv[now]!='A') continue;
        sort(g[now].begin(),g[now].end(),[&](edge& a,edge& b){
            return D[a.to]<D[b.to];
        });
        bool ok = false;
        for(auto& e:g[now]){
            if(ansv[e.to]!='A' && D[e.to]<D[now]){
                anse[e.id] = D[now]-D[e.to];
                ansv[now] = ansv[e.to];
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i=0;i<N;i++){
        cout << ansv[i];
    }
    cout << endl;
    for(int i=0;i<M;i++) cout << anse[i] << endl;
}