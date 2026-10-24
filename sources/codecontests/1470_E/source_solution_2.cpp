#include<bits/stdc++.h>
#define cs const
#define pb push_back
using namespace std;

typedef pair<int, int> pi;
#define fi first
#define se second
typedef long long ll;
cs int N = 3e4 + 50; 

int T, n, C, q, a[N]; 
int len[N][5][6];
ll dp[N][5], s[N][5][16], w[N][5][6];

int qry(int p, int k, ll x, int y){
	assert(x > 0);
	for(int i = 15; ~i; i--)
	if((p + (1 << i)) <= n + 1) {
		bool ok = s[p][k][i] < x; 
		ll way = dp[n - p - (1 << i) + 1][k];
		ok &= way >= x - s[p][k][i];
		if(ok) x -= s[p][k][i], p += 1 << i;
	} 
	
	if(p > y) return a[y];
	for(int i = 0; i <= k; i++) {
		if(x <= w[p][k][i]) {
			// flip [p, p + len[p][k][i] ]
			int l = len[p][k][i];
			if(y <= p + l) {
				static int b[6];
				for(int z = 0; z <= l; z++)
					b[z] = a[p + z];
				reverse(b, b + l + 1);
				return b[y - p];
			}
			return qry(p + l + 1, k - l, x, y);
		} x -= w[p][k][i];
	}
}
void Main(){
	scanf("%d%d%d", &n, &C, &q);
//	cout << n << " " << C<<" "<<q<<endl;
	for(int i = 0; i <= n; i++)
	for(int j = 0; j <= C; j++)
	dp[i][j] = 0; 
	dp[0][0] = 1; 
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= C; j++)
		for(int k = 0; k <= j; k++)
		if(i >= k + 1)
			dp[i][j] += dp[i - k - 1][j - k];
	}
	for(int i = 0; i <= n; i++)
	for(int j = 1; j <= C; j++)
		dp[i][j] += dp[i][j - 1];
			
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
		
	for(int i = 1; i <= n; i++)
	for(int k = 0; k <= C; k++){
		vector<pi> z;
		for(int j = 0; j <= k && i + j <= n; j++)
			z.pb(pi(a[i + j], j));
		static ll c[6];
		sort(z.begin(), z.end());
		
		for(int j = 0; j < z.size(); j++) {
			len[i][k][j] = z[j].se;
			w[i][k][j] = c[j] = 
			dp[n - (i + z[j].se)][k - z[j].se];
		}
			
//		cout << "Case " << i << " " << k << endl;
//		for(int j = 0; j < z.size(); j++)
//		cout <<z[j].se << " " << c[j] <<endl ; cout << endl;
		
		for(int j = 0; j < z.size(); j++){
			if(j) c[j] += c[j - 1];
			if(z[j].se == 0) 
				s[i][k][0] = j ? c[j - 1] : 0; 
		}
	}
	
	for(int t = 1; t <= 15; t++)
	for(int i = 1; i + (1 << t) - 1 <= n; i++)
	for(int j = 0; j <= C; j++)
	s[i][j][t] = s[i][j][t - 1] + s[i + (1 << (t - 1))][j][t - 1];
	
	while(q--){
		ll x, y; scanf("%lld%lld", &y, &x);
		if(x > dp[n][C]) puts("-1");
		else cout << qry(1, C, x, y) << '\n';
	} 
}
int main(){
	#ifdef FSYo
	freopen("1.in", "r", stdin);
	#endif
	cin >> T;
	while(T--) Main();
	return 0; 
}