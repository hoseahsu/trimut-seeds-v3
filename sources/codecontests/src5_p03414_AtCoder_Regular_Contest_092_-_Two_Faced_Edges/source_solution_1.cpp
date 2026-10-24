#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1000+10;
const int M=200000+10;

int n,m;
vector<int> G[N];
bool f[N][N],g[N][N],t[N];

void dfs(int o,int u)
{
	f[o][u]=true;
	for(vector<int>::iterator it(G[u].begin());it!=G[u].end();++it)if(!f[o][*it])
		dfs(o,*it);
}

void dfs2(int o,int u)     
{                          
	t[u]=true;
	for(vector<int>::iterator it(G[u].begin());it!=G[u].end();++it)if(*it!=o&&!t[*it])
		dfs2(o,*it);
}

void prework()
{
	int i;
	for(i=1;i<=n;++i)
		dfs(i,i);
	vector<int>::iterator it;
	vector<int>::reverse_iterator it2;
	for(i=1;i<=n;++i)
	{
		memset(t,0,sizeof t);
		for(it=G[i].begin();it!=G[i].end();++it)
			if(!t[*it])dfs2(i,*it);
			else g[i][*it]=true;
		memset(t,0,sizeof t);
		for(it2=G[i].rbegin();it2!=G[i].rend();++it2)
			if(!t[*it2])dfs2(i,*it2);
			else g[i][*it2]=true;
	}
}

int u[M],v[M];

int main()
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",u+i,v+i);
		G[u[i]].push_back(v[i]);
	}
	prework();
	for(i=1;i<=m;++i)
		printf((f[v[i]][u[i]]^g[u[i]][v[i]])?"diff\n":"same\n");
	return 0;
}
