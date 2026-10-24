#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using P = pair<ll, ll>;
using P3 = pair<P,ll>;
using PP = pair<P, P>;
constexpr int INF = 1 << 28;
constexpr ll MOD = ll(1e9)+7;
constexpr int di[] = {0, 1, 0, -1};
constexpr int dj[] = {1, 0, -1, 0};
constexpr int di8[] = {0, 1, 1, 1, 0, -1, -1, -1};
constexpr int dj8[] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr double EPS = 1e-9;

bool chmin(int &a, int b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}

vector<vector<P> > g, gr;
vector<P> es;
vector<int> ord;
vector<bool> visited;

void dfs(int v, int &k){
    visited[v] = true;
    for(auto e : gr[v]){
        int u = e.first;
        if(!visited[u]) dfs(u, k);
    }
    ord[k++] = v;
}

int solve(){
    int n, m;
    cin >> n >> m;
    g.resize(n);
    gr.resize(n);
    es.resize(m);
    for(int i=0;i<m;i++){
        int s, e, t1, t2;
        cin >> s >> e >> t1 >> t2;
        s--; e--;
        g[s].emplace_back(P(e,i));
        gr[e].emplace_back(P(s,i));
        es[i] = P(t1,t2);
    }

    ord.resize(n, -1);
    visited.resize(n);
    int k = 0;
    dfs(n-1, k);

    vector<int> idx(n);
    for(int i=0;i<n;i++) idx[ord[i]] = i;

    vector<vector<int> > dp(n, vector<int>(n, INF));
    dp[ord[0]][ord[0]] = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int v = ord[i], u = ord[j];
            if(v == u){
                for(auto e1 : g[v]){
                    int w1 = e1.first, id1 = e1.second;
                    for(auto e2 : g[v]){
                        int w2 = e2.first, id2 = e2.second;
                        if(w1 == w2) chmin(dp[w1][w1], dp[v][u] + es[id1].first + es[id1].second);
                        else chmin(dp[w1][w2], dp[v][u] + es[id1].first + es[id2].first);
                    }
                }
            }else{
                for(auto e : g[v]){
                    int w = e.first, id = e.second;
                    if(idx[w]<idx[u]) chmin(dp[w][u], dp[v][u] + es[id].first);
                    else chmin(dp[u][w], dp[v][u] + es[id].first);
                }
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
    return 0;
}

int main(){
    solve();
    // while(solve()==0);
    // int t; cin >> t; for(;t>0;t--) solve();
    return 0;
}

