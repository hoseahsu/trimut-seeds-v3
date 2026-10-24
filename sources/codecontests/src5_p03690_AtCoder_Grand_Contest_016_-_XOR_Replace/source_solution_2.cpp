#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int maxn = 100005;
int N, a[maxn], b[maxn];
bool check() {
	static int A[maxn], B[maxn];
	memcpy(A, a, sizeof A);
	memcpy(B, b, sizeof B);
	sort(A+1, A+N+1);
	sort(B+1, B+N+1);
	for(int i=1; i<=N; ++i) if(A[i]!=B[i]) return false;
	int n = unique(A+1, A+N+1)-A-1;
	for(int i=1; i<=N; ++i)
		a[i] = lower_bound(A+1, A+n+1, a[i])-A;
	for(int i=1; i<=N; ++i)
		b[i] = lower_bound(A+1, A+n+1, b[i])-A;
	return true;
}
vector<int> v[maxn];
int vis[maxn];
void dfs(int x) {
	vis[x] = 1;
	vector<int> &t = v[b[x]];
	for(int i=0; i<(int)t.size(); ++i) 
		if(!vis[t[i]]) dfs(t[i]);
}
int main() {
	scanf("%d", &N);
	for(int i=1; i<=N; ++i) scanf("%d", a+i), a[N+1] ^= a[i];
	for(int i=1; i<=N; ++i) scanf("%d", b+i), b[N+1] ^= b[i];
	++N;
	if(!check()) {
		puts("-1");	return 0;
	}
	int ans = 0;
	for(int i=1; i<N; ++i) ans += a[i]!=b[i];
	++ans;
	for(int i=1; i<=N; ++i) 
		if(a[i]!=b[i] or i==N) v[a[i]].push_back(i);
	for(int i=1; i<=N; ++i) 
		if((a[i]!=b[i] or i==N) && !vis[i]) ++ans, dfs(i);
	printf("%d\n", ans-2);
	return 0;
}