#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,dp[100100],c[100100][3],top,fa[100100];
long long ans=0;
struct node
{
	int x,y,id;
}a[100100];
struct edge
{
	node p,q;
	int w;
}e[300100];
bool cmp1(node a,node b)
{
	return a.x<b.x;
}
bool cmp2(node a,node b)
{
	return a.y<b.y;
}
bool cmp3(edge a,edge b)
{
	return a.w<b.w;
}
int getfa(int v)
{
	if(fa[v]==v) return v;
	fa[v]=getfa(fa[v]);
	return fa[v];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=2;i<=n;i++)
	{
		e[++top].p=a[i];
		e[top].q=a[i-1];
		e[top].w=a[i].y-a[i-1].y;
	}
	
	sort(a+1,a+n+1,cmp1);
	for(int i=2;i<=n;i++)
	{
		e[++top].p=a[i];
		e[top].q=a[i-1];
		e[top].w=a[i].x-a[i-1].x;
	}
	sort(e+1,e+top+1,cmp3);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int num=0,pnt=1;
	while(num<n-1)
	{
		for(int i=pnt;i<=top;i++)
			if (getfa(e[i].p.id)!=getfa(e[i].q.id))
			{
				pnt=i+1;
				fa[fa[e[i].p.id]]=fa[e[i].q.id];
				ans=ans+e[i].w;
				break;
			}
		num++;	
	}	
	cout<<ans<<endl;
	return 0;
}
/*3
1 5
3 9
7 8*/