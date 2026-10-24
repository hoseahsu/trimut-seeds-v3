#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int N, M, w[100005], fa[100005], cnt[100005], ans;
ll sum[100005];
struct edge {int u, v, w;} ed[100005];

inline bool operator < (const edge &ed1, const edge &ed2) {return ed1.w < ed2.w;}
int getf(const int &u) {return fa[u] == u ? u : fa[u] = getf(fa[u]);}

int main(){
	getint(N), getint(M);
	for(register int i = 1; i <= N; i++) getint(w[i]);
	for(register int i = 1; i <= M; i++) getint(ed[i].u), getint(ed[i].v), getint(ed[i].w);
	sort(ed + 1, ed + M + 1);
	for(register int i = 1; i <= N; i++) fa[i] = i, cnt[i] = 0, sum[i] = w[i];
	for(register int i = 1; i <= M; i++){
		const int fu = getf(ed[i].u), fv = getf(ed[i].v);
		if(fu == fv) cnt[fu]++;
		else cnt[fu] += cnt[fv] + 1, sum[fu] += sum[fv], fa[fv] = fu;
		if(sum[fu] >= ed[i].w) ans += cnt[fu], cnt[fu] = 0;
	}
	return printf("%d\n", M - ans), 0;
}