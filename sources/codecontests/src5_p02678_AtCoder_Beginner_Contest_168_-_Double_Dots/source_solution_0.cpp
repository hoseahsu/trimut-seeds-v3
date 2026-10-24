#include<bits/stdc++.h>
using namespace std;
int main()
{
	int nodes,edges;
	cin >> nodes >> edges;
	vector<int> adj[nodes+1];
	vector<bool> visited(nodes+1);
	vector<int> ans(nodes+1);
	for(int i=1;i<=edges;i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> q;
	q.push(1);
	ans[1] = 1;
	visited[1] = true;
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		for(int next : adj[cur])
		{
			if(!visited[next])
			{
				q.push(next);
				visited[next] = true;
				ans[next] = cur;
			}
		}
	}
	cout << "Yes\n";
	for(int i=2;i<=nodes;i++)
		cout << ans[i] << "\n";
}	
