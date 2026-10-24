#include<bits/stdc++.h>
using namespace std;
#define INF (1 << 29)
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int H, W, d[1000], st, en;
char A[50][50];

struct edge
{
	int to, cost;
};

typedef pair<int, int> P;

vector<edge> G[1000]; 

int main()
{
	fill(d, d + 1000, INF);
	cin >> H >> W;
	for(int y = 0; y < H; y++)
	{
		for(int x = 0; x < W; x++)
		{
			cin >> A[y][x];
			if(A[y][x] == 'S')
				st = y * W + x;
			if(A[y][x] == 'G') 
				en = y * W + x;
		}
	}
	for(int y = 0; y < H; y++)
	{
		for(int x = 0; x < W; x++)
		{
			if(A[y][x] == '#')
				continue;
			for(int i = 0; i < 4; i++)
			{
				int cost = 0;
				int teki = 0, mikata = 0, hutuu = 0;
				for(int j = 1; j <= 3; j++)
				{
					int ty = y + dy[i] * j, tx = x + dx[i] * j;
					if(tx < 0 || ty < 0 || tx >= W || ty >= H)
						break;	
					if(A[ty][tx] == '#')
						break;
					else if(A[ty][tx] == 'o')
						mikata++;
					else if(A[ty][tx] == 'x')
						teki++;
					else
						hutuu++;
					edge e1 = {ty * W + tx, 2 + j}, e2 = {ty * W + tx, mikata + hutuu * 2};
					G[y * W + x].push_back(e1);
					if(teki == 0)
						G[y * W + x].push_back(e2);
				}
			}
		}
	}
	priority_queue<P, vector<P>, greater<P> > q;
	d[st] = 0;
	q.push(P(0, st));
	while(!q.empty())
	{
		P p = q.top(); q.pop();
		int v = p.second;
		if(d[v] < p.first)
			continue;
		for(int i = 0; i < G[v].size(); i++)
		{
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				q.push(P(d[e.to], e.to));
			}
		}
	}
	cout << d[en] << endl;
}