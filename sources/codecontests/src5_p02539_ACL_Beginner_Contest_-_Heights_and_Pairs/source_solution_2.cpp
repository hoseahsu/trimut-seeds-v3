#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define PI 3.14159265358979323846264338327950
#define eps 1e-8
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

const llint mod = 998244353;

using namespace std;
typedef pair<llint, llint> P;


/*
{1224736769, 3}, // 2^24 * 73 + 1,
{1053818881, 7}, // 2^20 * 3 * 5 * 67 + 1
{1051721729, 6}, // 2^20 * 17 * 59 + 1
{1045430273, 3}, // 2^20 * 997 + 1
{1012924417, 5}, // 2^21 * 3 * 7 * 23 + 1
{1007681537, 3}, // 2^20 * 31^2 + 1
{1004535809, 3}, // 2^21 * 479 + 1
{998244353, 3},  // 2^23 * 7 * 17 + 1
{985661441, 3},  // 2^22 * 5 * 47 + 1
{976224257, 3},  // 2^20 * 7^2 * 19 + 1
{975175681, 17}, // 2^21 * 3 * 5 * 31 + 1
{962592769, 7},  // 2^21 * 3^3 * 17 + 1
{950009857, 7},  // 2^21 * 4 * 151 + 1
{943718401, 7},  // 2^22 * 3^2 * 5^2 + 1
{935329793, 3},  // 2^22 * 223 + 1
{924844033, 5},  // 2^21 * 3^2 * 7^2 + 1
{469762049, 3},  // 2^26 * 7 + 1
{167772161, 3},  // 2^25 * 5 + 1
*/

llint modpow(llint a, llint n, llint mod)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1, mod)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2, mod) % mod;
	}
}

int rev(int x, int n)
{
	int ret = 0;
	for(int i = 0; i < n; i++){
		ret <<= 1;
		ret |= (x>>i) & 1;
	}
	return ret;
}

//f[]とF[]は異なる実体を持たなければならない。rootには1の原始2^n乗根を渡す
void DFT(llint f[], llint F[], int n, llint mod, llint root)
{
	int N = 1<<n;
	for(int i = 0; i < N; i++) F[rev(i, n)] = f[i];
	
	llint a, b, x, z;
	for(int i = 1; i <= n; i++){
		int l = 1<<i;
		z = modpow(root, 1<<(n-i), mod);
		for(int j = 0; j < N/l; j++){
			x = 1;
			for(int k = 0; k < l/2; k++){
				a = F[j*l+k], b = F[j*l+k+l/2];
				F[j*l+k] = a + x * b % mod;
				F[j*l+k+l/2] = a - x * b % mod + mod;
				if(F[j*l+k] >= mod) F[j*l+k] -= mod;
				if(F[j*l+k+l/2] >= mod) F[j*l+k+l/2] -= mod;
				x *= z, x %= mod;
			}
		}
	}
}

//f[]とF[]は異なる実体を持たなければならない。rootには1の原始2^n乗根を渡す
void IDFT(llint F[], llint f[], int n, llint mod, llint root)
{
	int N = 1<<n;
	for(int i = 0; i < N; i++) f[rev(i, n)] = F[i];
	root = modpow(root, mod-2, mod);
	
	llint a, b, x, z;
	for(int i = 1; i <= n; i++){
		int l = 1<<i;
		z = modpow(root, 1<<(n-i), mod);
		for(int j = 0; j < N/l; j++){
			x = 1;
			for(int k = 0; k < l/2; k++){
				a = f[j*l+k], b = f[j*l+k+l/2];
				f[j*l+k] = a + x * b % mod;
				f[j*l+k+l/2] = a - x * b % mod + mod;
				if(f[j*l+k] >= mod) f[j*l+k] -= mod;
				if(f[j*l+k+l/2] >= mod) f[j*l+k+l/2] -= mod;
				x *= z, x %= mod;
			}
		}
	}
	llint Ninv = modpow(N, mod-2, mod);
	for(int i = 0; i < N; i++) f[i] *= Ninv, f[i] %= mod;
}

llint n;
llint a[100005];
llint seki[200005];
llint root;

priority_queue<P, vector<P>, greater<P> >Q;
vector<llint> vec[100005];

llint getlog(llint n)
{
	llint ret = 0;
	for(;n;n/=2) ret++;
	return ret;
}

llint f[1<<19], g[1<<19], F[1<<19], G[1<<19];
llint calc(llint u, llint v)
{
	llint degu = vec[u].size() - 1, degv = vec[v].size() - 1;
	llint n = getlog(degu+degv+1), N = 1<<n;
	for(int i = 0; i < N; i++) f[i] = F[i] = g[i] = G[i] = 0;
	for(int i = 0; i < vec[u].size(); i++) f[i] = vec[u][i];
	for(int i = 0; i < vec[v].size(); i++) g[i] = vec[v][i];
	
	DFT(f, F, n, mod, modpow(root, 1<<(23-n), mod));
	DFT(g, G, n, mod, modpow(root, 1<<(23-n), mod));
	for(int i = 0; i < N; i++) F[i] *= G[i], F[i] %= mod;
	IDFT(F, f, n, mod, modpow(root, 1<<(23-n), mod));
	
	vec[u].resize(degu+degv+1);
	for(int i = 0; i <= degu+degv; i++) vec[u][i] = f[i];
	return degu+degv;
}

const int FACT_MAX = 200005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

llint comb(llint n, llint k)
{
	llint ret = 1;
	ret *= fact[n];
	ret *= fact_inv[k], ret %= mod;
	ret *= fact_inv[n-k], ret %= mod;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	make_fact();
	
	cin >> n;
	llint h;
	for(int i = 1; i <= 2*n; i++){
		cin >> h;
		a[h]++;
	}
	
	root = modpow(3, 119, mod);
	
	seki[0] = 1;
	for(int i = 2; i < 200005; i+=2) seki[i] = seki[i-2] * comb(i, 2) % mod;
	
	for(int i = 1; i <= 100000; i++){
		//if(a[i] < 2) continue;
		vec[i].resize(a[i]/2+1);
		llint mul = 1;
		for(int j = 0; j <= a[i]/2; j++){
			vec[i][j] = mul*fact_inv[j]%mod;
			if(a[i]-2*j >= 0) mul *= comb(a[i]-2*j, 2), mul %= mod;
		}
		Q.push(P(a[i]/2+1, i));
	}
	
	while(Q.size() >= 2){
		llint u = Q.top().second; Q.pop();
		llint v = Q.top().second; Q.pop();
		llint res = calc(u, v);
		Q.push(P(res, u));
	}
	
	llint x = Q.top().second;
	
	llint ans = 0;
	for(int i = 0; i < vec[x].size(); i++){
		llint tmp = vec[x][i];
		tmp *= seki[2*(n-i)], tmp %= mod;
		tmp *= fact_inv[n-i], tmp %= mod;
		if(i % 2) ans += mod - tmp, ans %= mod;
		else ans += tmp, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}