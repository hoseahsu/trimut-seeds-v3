#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <bitset>
#include <time.h>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
// ios::sync_with_stdio(false);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ull unsigned long long
#define il inline
#define endl "\n"
#define int long long
#define re register
#define double long double
using namespace std;
const double eqs = 1e-6;
const long long max_ = 2e5 + 7;
//ull  haxi = 137, haximod = 998244353;
const int mod = 19260817;
const int inf = 1e9 + 7;
const long long INF = 1e18;
il int read() {
	int ret = 0, f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
	while (ch >= '0'&&ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	return ret * f;
}
inline void write(int x) {
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
int A[max_],B[max_],N,lim;
struct {
	int day,shengxia;
}f[max_];
void ini(){
	int T = read();
	while(T--){
		N = read();lim = read();
		for(int i = 1;i <= N;i++){
			A[i] = read();
		}
		for(int i = 1;i < N;i++){
			B[i] = read();
		}
		int temp;int t2;
		for(int i = 2;i <= N;i++){
			temp = max(0,B[i - 1] - f[i-1].shengxia);
			t2 = (int)(ceil((1.0*temp)/A[i-1]));
			f[i].day = f[i-1].day + (int)t2 + 1;
			f[i].shengxia = f[i-1].shengxia + t2*A[i - 1]-B[i-1];
		}	
		int ans = INF;
		for(int i = 1;i <= N;i++){
			temp = max(0,lim - f[i].shengxia);
			t2 = (int)(ceil((1.0*temp)/A[i]));
			ans = min(ans,t2 + f[i].day);
		}
		printf("%lld\n",ans);
	}
}
signed main(){
	ini();
	return 0;
}