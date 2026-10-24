#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define MOD 998244353
using namespace std;
typedef long long ll;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int gcd(const int &a, const int &b) {return b ? gcd(b, a % b) : a;}

int N, a[100005];
ll ans = 1;

int main(){
	getint(N);
	for(register int i = 1; i <= N; i++) getint(a[i]);
	sort(a + 1, a + N + 1);
	for(register int i = 0; i < N; i++) ans = ans * (ll)gcd(i, a[i + 1]) % MOD;
	return printf("%lld\n", ans), 0;
}