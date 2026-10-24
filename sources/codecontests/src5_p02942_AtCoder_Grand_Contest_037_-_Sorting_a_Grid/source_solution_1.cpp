#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 924844033
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
int a[114][114];
int b[114][114];
int c[114][114];
priority_queue<int> c1[114][114];

struct BipartiteMatching {
  vector< vector< int > > graph;
  vector< int > match, alive, used;
  int timestamp;

  BipartiteMatching(int n) : graph(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}

  void add_edge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  bool dfs(int idx) {
    used[idx] = timestamp;
    for(auto &to : graph[idx]) {
      int to_match = match[to];
      if(alive[to] == 0) continue;
      if(to_match == -1 || (used[to_match] != timestamp && dfs(to_match))) {
        match[idx] = to;
        match[to] = idx;
        return true;
      }
    }
    return false;
  }

  int bipartite_matching() {
    int ret = 0;
    for(int i = 0; i < graph.size(); i++) {
      if(alive[i] == 0) continue;
      if(match[i] == -1) {
        ++timestamp;
        ret += dfs(i);
      }
    }
    return ret;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      if(i < match[i]) {
        cout << i << "-" << match[i] << endl;
      }
    }
  }
};

signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			a[i][j]--;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int k = a[i][j] / m;
			c1[i][k].push(a[i][j]);
		}
	}
	for(int tim = 0; tim < m; tim++){
		BipartiteMatching bm(2*n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if( !c1[i][j].empty() )bm.add_edge(i,j+n);
			}
		}
		bm.bipartite_matching();
		for(int i = 0; i < bm.graph.size(); i++) {
			if(i < bm.match[i]) {
				int num=-1;
				if(!c1[i][bm.match[i]-n].empty())num = c1[i][bm.match[i]-n].top(); c1[i][bm.match[i]-n].pop(); 
				b[i][tim] = num;
			}
		}
    }
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<b[i][j]+1<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<m;i++){
		vector<int> vec;
		for(int j=0;j<n;j++){
			vec.pb(b[j][i]);
		}
		sort(vec.begin(),vec.end());
		for(int j=0;j<n;j++){
			c[j][i]=vec[j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<c[i][j]+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}