#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;

int V, E;
int dist[20][20];

int dp[20][(1<<20)+1];
int main() {
    cin >> V >> E;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }

    for(int i = 0; i < V; i++) for(int j = 0; j < (1<<V); j++) dp[i][j] = INF;
    dp[0][0] = 0;

    for (int i = 0; i < (1<<V); i++)
    {
        for (int j = 0; j < V; j++)
        {
            if((i >> j) & 1) continue;
            for (int k = 0; k < V; k++)
            {
                dp[j][i | (1<<j)] = min(dp[j][i | (1<<j)], dp[k][i] + dist[k][j]);
            }
        }
    }

    if(dp[0][(1<<V) - 1] == INF) cout << "-1" << endl;
    else cout << dp[0][(1<<V) - 1] << endl;
}
