
// "Say:He is the Most Merciful,We have believed in him and upon him we have relied" [67:29]
 
//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
//#pragma GCC optimize("unroll-loops")
 
#include<bits/stdc++.h>
using namespace std;
                                                     
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 */
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef map<int,int> mpi;
typedef map<ll,ll> mpl;
typedef unordered_map<int,int> umpi;
typedef unordered_map<ll,ll> umpl;
 
#define ump unordered_map
#define mod 1000000007
#define inf 1000000000000000006
#define infi 2000000009
#define ff first
#define ss second
#define pb push_back
#define all(v) v.begin(), v.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pi acos(-1.0)
#define dec(n) fixed << setprecision(n)
#define N 300005
//#define int long long

inline void IO(string name) { // Usaco
     freopen((name + ".in").c_str(), "r", stdin);
     freopen((name + ".out").c_str(), "w", stdout);
}

ll n,a[N],t[N],k,d[N];
vector<pii> v;
void solve(){
	cin >> n >> k;
	for(int i=0;i<k;i++) cin >> a[i];
	for(int i=0;i<k;i++) cin >> t[i];
	priority_queue<pii> pq;
	for(int i=1;i<=n;i++) d[i]=infi;
	for(int i=0;i<k;i++){
		pq.push({-t[i],a[i]});
		d[a[i]]=t[i];
	}
	//int cc=0;
	while(!pq.empty()){
		//cc++;
		int u=pq.top().ss,c=-pq.top().ff;
		pq.pop();
		if(u-1!=0 && d[u-1]>c+1){
			d[u-1]=c+1;
			pq.push({-d[u-1],u-1});
		}
		if(u+1!=n+1 && d[u+1]>c+1){
			d[u+1]=c+1;
			pq.push({-d[u+1],u+1});
		}
	}
	for(int i=1;i<=n;i++) cout << d[i] << " ";
	cout << endl;
	//cout << cc << endl;
	
}

signed main(){
    fastio;
    //srand(chrono::steady_clock::now().time_since_epoch().count());
    int T=1,cs=0;
    cin >> T;
    while(T--){
        //cout << "Case " << ++cs << ":" << " " ; 
    	solve();
    } 
}
