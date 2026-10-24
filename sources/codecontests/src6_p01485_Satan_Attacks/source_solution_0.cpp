#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <map>
using namespace std;
const int inf = 1e9;
const double EPS = 1e-6;
const double INF = 1e12;
const double PI = acos(-1);
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define X real()
#define Y imag()

typedef complex<double> P;
typedef vector<P> VP;
struct L : array<P, 2>{
    L(const P& a, const P& b){ at(0)=a; at(1)=b; }
    L(){}
};

namespace std{
    bool operator < (const P& a, const P& b){
        return !EQ(a.X,b.X) ? a.X<b.X : a.Y+EPS<b.Y;
    }
    bool operator == (const P& a, const P& b){
        return abs(a-b) < EPS;
    }
}

double dot(P a, P b){
    return (conj(a)*b).X;
}
double cross(P a, P b){
    return (conj(a)*b).Y;
}
int ccw(P a, P b, P c){
    b -= a;
    c -= a;
    if(cross(b,c) > EPS) return +1; //ccw
    if(cross(b,c) < -EPS) return -1; //cw
    if(dot(b,c) < -EPS) return +2; //c-a-b
    if(abs(c)-abs(b) > EPS) return -2; //a-b-c
    return 0; //a-c-b
}

bool intersectSS(const L& a, const L& b){
    return ( ccw(a[0],a[1],b[0]) *ccw(a[0],a[1],b[1]) <= 0 ) &&
        ( ccw(b[0],b[1],a[0]) *ccw(b[0],b[1],a[1]) <= 0 );
}
bool intersectSP(const L& s, const P &p){
    return abs(cross(s[0]-p, s[1]-p))<EPS  && dot(s[0]-p, s[1]-p)<EPS;
}

bool isParallel(const P &a, const P &b){
    return abs(cross(a,b)) < EPS;
}
bool isParallel(const L &a, const L &b){
    return isParallel(a[1]-a[0], b[1]-b[0]);
}

P crosspointLL(const L &l, const L &m) {
  double A = cross(l[1]-l[0], m[1]-m[0]);
  double B = cross(l[1]-l[0], l[1]-m[0]);
  return m[0] + B/A *(m[1]-m[0]);
}

//satan attacks 用の線分アレンジメント
//P(-INF, -INF) に新たなsourceを作る
pair<vector<vector<pair<int, int> > >, VP>
arrangementEX(const vector<L> &l, const vector<double> &w, const VP &source){
    vector<VP> cp(l.size());
    VP plist;
    for(int i=0; i<(int)l.size(); i++){
        for(int j=i+1; j<(int)l.size(); j++){
            if(!isParallel(l[i], l[j]) && intersectSS(l[i], l[j])){
                P cpij = crosspointLL(l[i], l[j]);
                cp[i].push_back(cpij);
                cp[j].push_back(cpij);
                plist.push_back(cpij);
            }
            for(int d=0; d<2; d++){
                if(intersectSP(l[i], l[j][d])) cp[i].push_back(l[j][d]);
                if(intersectSP(l[j], l[i][d])) cp[j].push_back(l[i][d]);
            }
        }
        cp[i].push_back(l[i][0]);
        cp[i].push_back(l[i][1]);
        plist.push_back(l[i][0]);
        plist.push_back(l[i][1]);
        sort(cp[i].begin(), cp[i].end());
        cp[i].erase(unique(cp[i].begin(), cp[i].end()), cp[i].end());
    }
    plist.emplace_back(-INF, -INF);
    sort(plist.begin(), plist.end());
    plist.erase(unique(plist.begin(), plist.end()), plist.end());

    int n = plist.size();
    map<P, int> conv;
    for(int i=0; i<n; i++){
        conv[plist[i]] = i;
    }

    vector<map<int, double> > adj(n);
    for(int i=0; i<(int)cp.size(); i++){
        double len = abs(l[i][1] -l[i][0]);
        for(int j=0; j<(int)cp[i].size()-1; j++){
            int jidx = conv[cp[i][j]];
            int jp1idx = conv[cp[i][j+1]];
            double cap = w[i] *abs(cp[i][j] -cp[i][j+1]) /len;
            adj[jidx][jp1idx] += cap;
            adj[jp1idx][jidx] += cap;
        }
    }
    vector<vector<pair<int, int> > > ret(n);
    for(P p: source){
        int idx = conv[p];
        ret[0].emplace_back(idx, inf);
        ret[idx].emplace_back(0, inf);
    }
    for(int i=0; i<n; i++){
        for(auto next: adj[i]){
            ret[i].emplace_back(next.first, next.second +EPS);
        }
    }
    return make_pair(ret, plist);
}

struct edge{
    int to, cap, rev;
    edge(int t, int c, int r):to(t),cap(c),rev(r){}
    edge(){}
};
void addedge(int from, int to, int cap, vector<vector<edge> > &graph){
    graph[from].emplace_back(to, cap, graph[to].size());
    graph[to].emplace_back(from, 0, graph[from].size()-1);
}

vector<vector<edge> > makeflowgraph(vector<vector<pair<int, int> > > &adj){
    int n = adj.size();
    vector<vector<edge> > ret(n);
    for(int i=0; i<n; i++){
        for(pair<int, int> next: adj[i]){
            addedge(i, next.first, next.second, ret);
        }
    }
    return ret;
}

int dfs(int v, int g, int flow, vector<vector<edge> >& adj, vector<bool>& used){
    if(used[v]) return -1;
    used[v] = true;
    if(v == g) return flow;
    
    for(int i=0; i<(int)adj[v].size(); i++){
        edge& next = adj[v][i];
        if(next.cap > 0){
            int ret = dfs(next.to, g, min(flow, next.cap), adj, used);
            if(ret > 0){
                next.cap -= ret;
                adj[next.to][next.rev].cap += ret;
                return ret;
            }
        }
    }
    return -1;
}
int maxflow(int s, int g, vector<vector<edge> > &graph){
    int res = 0;
    while(1){
        vector<bool> used((graph.size()+1)*2, false);
        int ret = dfs(s, g, inf, graph, used);
        if(ret==-1) break;
        res += ret;
    }
    return res;
}

int maxflow_adj(int s, int g, vector<vector<pair<int, int> > > &adj){
    vector<vector<edge> > graph = makeflowgraph(adj);
    return maxflow(s, g, graph);
}

int main(){
    int n;
    cin >> n;
    vector<L> l(n);
    vector<double> w(n);
    for(int i=0; i<n; i++){
        double xs,ys,xt,yt;
        cin >> xs >> ys >> xt >> yt >> w[i];
        l[i] = L(P(xs, ys), P(xt, yt));
    }
    int m;
    cin >> m;
    VP source(m);
    for(int i=0; i<m; i++){
        double x,y;
        cin >> x >> y;
        source[i] = P(x, y);
    }
    double x,y;
    cin >> x >> y;
    P sink(x, y);

    pair<vector<vector<pair<int, int> > >, VP> ret = arrangementEX(l, w, source);
    vector<vector<pair<int, int> > > &adj = ret.first;
    VP &plist = ret.second;
    int sidx=0;
    int gidx = lower_bound(plist.begin(), plist.end(), sink) -plist.begin();
    cout << maxflow_adj(sidx, gidx, adj) << endl;
    return 0;
}
