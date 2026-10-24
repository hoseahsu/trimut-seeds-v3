#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 1005
//#define ivorysi
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
    	if(c == '-') f = -1;
    	c = getchar();
    }
    while(c >= '0' && c <= '9') {
    	res = res * 10 +c - '0';
    	c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
    	out(x / 10);
    }
    putchar('0' + x % 10);
}
const int MOD = 1000000007,V = 505;
struct node {
    int to,next;
}E[MAXN * 2];
int sumE,head[MAXN];
int N;
int dis[MAXN],fa[MAXN],D;
int dp[MAXN][MAXN * 2];
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
void update(int &x,int y) {
    x = inc(x,y);
}
void add(int u,int v) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    head[u] = sumE;
}
void dfs(int u) {
    for(int i = head[u] ; i ; i = E[i].next) {
        int v = E[i].to;
        if(v != fa[u]) {
            fa[v] = u;
            dis[v] = dis[u] + 1;
            dfs(v);
        }
    }
}
void dfs1(int u,int lim,int on) {
    for(int i = head[u] ; i ; i = E[i].next) {
        int v = E[i].to;
        if(v != fa[u]) {
            dfs1(v,lim,on);
        }
    }
    int l = dis[u] - lim - on,r = lim - dis[u] - on;
    for(int i = l + V ; i <= r + V; ++i) {
        dp[u][i] = 1;
        for(int j = head[u] ; j ; j = E[j].next) {
            int v = E[j].to;
            if(v != fa[u]) {
                int t = inc(dp[v][i - 1],dp[v][i + 1]);
                dp[u][i] = mul(dp[u][i],t);
            }
        }
    }
}
int Process_even(int rt) {
    fa[rt] = 0;dis[rt] = 0;
    dfs(rt);
    memset(dp,0,sizeof(dp));
    dfs1(rt,D,0);
    int ans = 0;
    for(int i = 0 ; i <= V * 2 ; ++i) {
        update(ans,dp[rt][i]);
    }
    return ans;
}
int Process_odd(int s,int t,int on) {
    fa[s] = t;fa[t] = s;dis[s] = 0;dis[t] = 0;
    dfs(s);dfs(t);
    memset(dp,0,sizeof(dp));
    dfs1(s,D - 1,0);
    dfs1(t,D,on);
    int ans = 0;
    for(int i = 1 ; i <= V * 2 ; ++i) {
        update(ans,mul(dp[s][i],inc(dp[t][i - 1],dp[t][i + 1])));
    }
    return ans;
}
void Solve() {
    read(N);
    int a,b;
    for(int i = 1 ; i < N ; ++i) {read(a);read(b);add(a,b);add(b,a);}
    dis[1] = 0;fa[1] = 0;dfs(1);
    int u = 1;
    for(int i = 2 ; i <= N ; ++i) {
        if(dis[i] > dis[u]) u = i;
    }
    dis[u] = 0;fa[u] = 0;
    dfs(u);
    u = 1;
    for(int i = 2 ; i <= N ; ++i) {
        if(dis[i] > dis[u]) u = i;
    }
    if(dis[u] % 2 == 0) {
        int r = u;
        for(int i = 1 ; i <= dis[u] / 2 ; ++i) r = fa[r];
        D = dis[u] / 2;
        int ans = Process_even(r);
        out(ans);enter;
    }
    else {
        int s = u;
        for(int i = 1 ; i <= dis[u] / 2 ; ++i) s = fa[s];
        int t = fa[s];
        D = dis[u] / 2 + 1;
        int ans = inc(Process_odd(s,t,0),Process_odd(t,s,0));
        update(ans,MOD - Process_odd(s,t,-1));
        update(ans,MOD - Process_odd(s,t,1));
        out(ans);enter;
    }
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
}
