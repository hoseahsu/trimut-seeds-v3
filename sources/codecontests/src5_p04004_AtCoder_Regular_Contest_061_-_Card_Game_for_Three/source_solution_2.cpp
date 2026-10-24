#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 6, mod = 1e9 + 7;
int N, M, K, L, R;
long long ans, last;
long long fac[maxn], inv[maxn], p[maxn];

inline long long fpow(long long t, int x){
    long long ret = 1, tmp = t;
    while(x){
        if(x & 1) ret = ret * tmp % mod;
        tmp = tmp * tmp % mod; x >>= 1;
    }
    return ret;
}

inline void prepare(){
    fac[0] = 1; inv[0] = 1; p[0] = 1;
    for(int i = 1; i <= N + M + K; ++i) fac[i] = fac[i - 1] * i % mod, p[i] = p[i - 1] * 3 % mod;
    inv[N + M + K] = fpow(fac[N + M + K], mod - 2);
    for(int i = N + M + K - 1; i >= 1; --i) inv[i] = inv[i + 1] * (i + 1) % mod;
}

inline long long C(int n, int m){
    if(m > n) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

inline long long calc(int l, int r, int x){
    long long ret = last;
    ret = last * 2 - C(x - 1, L) - C(x - 1, R) + C(x, L);
    while(R < r){R++; ret += C(x, R);}
    while(L < l){L++; ret -= C(x, L - 1);}
    while(ret < 0) ret += mod; last = ret % mod;
	return last;
}



inline void workk(){
    for(int len = N - 1; len < N + M + K; ++len){
        long long ret = p[N + M + K - len - 1] * C(len, N - 1) % mod;
        if(len == N - 1){last = 1; ans = ret * last % mod;}
        else ans = (ans + ret * calc(max(0, len - (N - 1) - K), min(M, len - (N - 1)), len - (N - 1))) % mod;
    }
    cout << ans;
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    prepare();
    workk();
    return 0;
}