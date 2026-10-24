#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)(v).size())
const int MAXN = 10000005;
const int mod = 998244353;
using lint = long long;
lint ipow(lint x, lint p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}

lint fact[MAXN], invf[MAXN];

lint binom(int x, int y){
	return fact[x] * (invf[y] * invf[x-y] % mod) % mod;
}

int main() { 
	int n; cin >> n;
	fact[0] = 1;
	for(int i=1; i<=n; i++){
		fact[i] = fact[i-1] * i % mod;
	}
	invf[n] = ipow(fact[n], mod - 2);
	for(int i=n-1; i>=0; i--){
		invf[i] = invf[i + 1] * (i + 1) % mod;
	}
	lint ans = 0;
	for(int i=0; i<n/2; i++){
		ans += ipow(2, i + 1) * binom(n, i) % mod;
	}
	ans %= mod;
	ans = ipow(3, n) - ans + mod;
	cout << ans % mod << endl;
}
