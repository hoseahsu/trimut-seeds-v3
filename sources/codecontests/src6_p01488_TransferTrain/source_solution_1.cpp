#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
using namespace std;
const int inf = 1e9;
struct node{
    int time,num;
    int i,j;
    node(int i, int j, int t, int n):time(t),num(n),i(i),j(j){}
    node(){}
    bool operator <(const node &a) const{
        return (time!=a.time)? time>a.time: num>a.num;
    }
};
typedef pair<int, int> pii;
pii operator +(const pii &a, const pii &b){
    return pii(a.first+b.first, a.second+b.second);
}

int main(){
    int n,ct;
    cin >> n >> ct;
    string a,b;
    cin >> a >> b;
    vector<vector<string>> s(n);
    vector<vector<int>> t(n);
    map<string, vector<pii>> change_line;
    for(int i=0; i<n; i++){
        int ns;
        cin >> ns;
        s[i].resize(ns);
        for(int j=0; j<ns; j++){
            cin >> s[i][j];
            change_line[s[i][j]].emplace_back(i, j);
        }
        t[i].resize(ns-1);
        for(int j=0; j<ns-1; j++){
            cin >> t[i][j];
        }
    }

    priority_queue<node> wait;    
    vector<vector<pii>> mincost(n);
    set<string> used;
    for(int i=0; i<n; i++){
        mincost[i] = vector<pii>(s[i].size(), pii(inf, inf));
    }
    for(auto &p: change_line[a]){
        wait.push(node(p.first, p.second, 0, 0));
        mincost[p.first][p.second] = pii(0, 0);
    }
    used.insert(a);
    pii ans(-1, -1);
    while(!wait.empty()){
        node curr = wait.top();
        wait.pop();
        size_t i=curr.i, j=curr.j;
        if(s[i][j] == b){
            ans = mincost[i][j];
            break;
        }
        if(pii(curr.time, curr.num) > mincost[i][j]){
            continue;
        }
        vector<pair<pii, pii>> next;
        if(j!=0) next.emplace_back(pii(i, j-1), pii(t[i][j-1], 0));
        if(j<t[i].size()) next.emplace_back(pii(i, j+1), pii(t[i][j], 0));
        if(used.find(s[i][j]) == used.end()){
            used.insert(s[i][j]);
            for(auto &p: change_line[s[i][j]]){
                next.emplace_back(pii(p.first, p.second), pii(ct, 1));
            }
        }
        for(auto &pp: next){
            int ni=pp.first.first, nj=pp.first.second;
            pii cost=mincost[i][j]+pp.second;
            if(cost < mincost[ni][nj]){
                mincost[ni][nj] = cost;
                wait.push(node(ni, nj, cost.first, cost.second));
            }
        }
    }
    if(ans.first == -1){
        cout << -1 << endl;
    }else{
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}

