#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int mp[111111];
vector<vector<int>> v(111111);

int main(){
	
	int n,q;cin >> n;
	REP(i,n){
		int a,b;cin >> a >> b;
		a--;b--;
		mp[a]++;
		mp[b]++;
		v[a].PB(b);
		v[b].PB(a);
	}
	
	queue<int> que;
	
	REP(i,n)if(mp[i] == 1)que.push(i);
	
	while(!que.empty()){
		int now = que.front();que.pop();
		REP(i,v[now].size()){
			mp[v[now][i]]--;
			if(mp[v[now][i]] == 1)que.push(v[now][i]);
		}
	}
	//SHOW1d(mp,n);
	cin >> q;
	REP(i,q){
		int a,b;cin >> a >> b;
		a--;b--;
		if(mp[a] > 1 && mp[b] > 1){
			cout << 2 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
	
	return 0;
}
