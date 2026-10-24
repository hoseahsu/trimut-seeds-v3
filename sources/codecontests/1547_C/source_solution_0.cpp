#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;

int t, n, m, k, tot;
int a[N], b[N], ans[N];

template <typename T>
inline void read(T &x){
	x = 0;
	char c = getchar();
	T op = 1;
	for(; c < '0' || c > '9'; c = getchar())
		if(c == '-') op = -1;
	for(; c <= '9' && c >= '0'; c = getchar())
		x = (x << 3) + (x << 1) + c - '0';
	x *= op;
}

int main(){
	read(t);
	while(t--){
		tot = 0;
		read(k), read(n), read(m);
		for(int i = 1; i <= n; ++i)	read(a[i]);
		for(int i = 1; i <= m; ++i)	read(b[i]);
		int i = 1, j = 1;
		while(i <= n || j <= m){
			while(a[i] == 0 && i <= n)	++k, ans[++tot] = 0, ++i;
			while(b[j] == 0 && j <= m)	++k, ans[++tot] = 0, ++j;
			if(a[i] <= k && i <= n)	ans[++tot] = a[i], ++i;
			else if(b[j] <= k && j <= m)	ans[++tot] = b[j], ++j;
			else break;
		}
		if(i <= n || j <= m)	printf("-1");
		else for(int i = 1; i <= tot; ++i)	printf("%d ", ans[i]);
		putchar('\n');
	}
	return 0;
}
