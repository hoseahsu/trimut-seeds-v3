#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);}
int n;
int a[2010];
int in[2010];
int vis[2010];
int ed[2010][2010];
vector<int> e[2010];
priority_queue<int,vector<int>,less<int> > q;
void dfs(int x)
{
	vis[x]=1;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&ed[x][i])
		{
			in[i]++;
			e[x].push_back(i);
			dfs(i);
		}
}
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(gcd(a[i],a[j])!=1)
				ed[i][j]=1,ed[j][i]=1;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
	for(int i=1;i<=n;i++)
		if(in[i]==0)
			q.push(i);
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		printf("%d ",a[u]);
		for(int i=0;i<e[u].size();i++)
		{
			int to=e[u][i];
			in[to]--;
			if(in[to]==0)
				q.push(to);
		}
	}
	return 0;
}
