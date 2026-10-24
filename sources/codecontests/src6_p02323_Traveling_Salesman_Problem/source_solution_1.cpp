#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
const int inf=1e9+7;
const ll mod=1e9+7;

int DP[50000][20];
vector<vector<pair<int, int> > > edge(20);
int V;

int solve(int S, int v){
    if(DP[S][v]>=0) return DP[S][v];
    DP[S][v] = inf;
    for(int i=0;i<edge[v].size();++i){
        if((S&(1<<edge[v][i].fi))==0){
            DP[S][v] = min(DP[S][v], solve(S|(1<<edge[v][i].fi), edge[v][i].fi) + edge[v][i].se);
        }
    }
    return DP[S][v];
}

int main() {
    for(int i=0;i<50000;++i){
        for(int j=0;j<20;++j){
            DP[i][j] = -1;
        }
    }
    int E;
    cin>>V>>E;
    DP[(1<<V)-1][0] = 0;
    int s, t, d;
    for(int i=0;i<E;++i){
        cin>>s>>t>>d;
        edge[s].push_back(make_pair(t, d));
    }
    int ans = solve(0, 0);
    if(ans==inf) cout<<-1<<endl;
    else cout<<ans<<endl;
}

