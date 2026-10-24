#include<bits/stdc++.h>
using namespace std;
vector<int>edge[100001];
int p[100001];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	queue<int>q;
	q.push(1);
//	cout<<q.front();
	while(!q.empty())
	{
		int now=q.front();
		for(int i=0;i<edge[now].size();i++)
		{
			if(p[edge[now][i]]==0)
			{
				p[edge[now][i]]=now;
				q.push(edge[now][i]);
			}
			
		}
		q.pop();
	}
	for(int i=2;i<=n;i++)
	{
		if(p[i]==0)
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	for(int i=2;i<=n;i++)
		cout<<p[i]<<endl;
	
	return 0;	
}