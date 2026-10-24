#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef vector<long> vi;
typedef vector<vi> vvi;

#define all(c) (c).begin(), (c).end()
#define loop(i,a,b) for(int i=(a); i<(int)(b); i++)
#define rep(i,b) loop(i,0,b)

const long inf = 1e15;

struct edge {
    long to,cost;
};
struct state {
    long v, cost;
    bool operator<(const state& r) const {
        return cost>r.cost;
    }
};

int dijk(const vector<vector<edge>> & G){
    vi dis(G.size(),inf);
    priority_queue<state> q;
    dis[0]=0;
    q.push({0,0});

    while(q.size()){
        state sta=q.top();
        q.pop();

        if(dis[sta.v] > sta.cost) continue;

        const vector<edge>& es=G[sta.v];
        rep(i, es.size()){
            if(dis[es[i].to] <= dis[sta.v] + es[i].cost) continue;
            dis[es[i].to] = dis[sta.v] + es[i].cost;
            q.push({es[i].to, dis[es[i].to]});
        }
    }

    return dis[G.size()-1];
}

int main(){
    int L,n;
    while(cin>>L>>n){
        map<long,int> m;
        vector<long> s(n), g(n), t(n);
        rep(i,n){
            int pp,dd,tt;
            cin>>pp>>dd>>tt;
            s[i]=pp, g[i]=pp+dd, t[i]=tt;
            m[pp]=m[pp+dd]=0;
        }
        if(n==0){
            cout << L << endl;
        } else {
            m[0]=m[L]=0;
            int i=0;
            for(auto & p:m){
                p.second = i++;
            }

            vector<vector<edge>> G(m.size());
            rep(i,n){
                if(t[i] < g[i] - s[i]){
                    G[m[s[i]]].push_back({m[g[i]], min(t[i], g[i]-s[i])});
                }
            }
            auto it=m.begin();
            it++;
            auto jt=it;
            it--;
            while(jt!=m.end()){
                G[it->second].push_back({jt->second, jt->first-it->first});
                it++;
                jt++;
            }
            cout << dijk(G) << endl;
        }
    }
}
