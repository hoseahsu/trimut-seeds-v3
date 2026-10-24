#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}, N, M, P[] = {1, 0, 3, 2}, Q[] = {3, 2, 1, 0};
int memo[100][100][11][11][4];
string G[100];
const int INF = 1e5;

bool in_range(int a, int x){ return (a >= 0 && a < x);}

int dfs(int x, int y, int d, int p, int q){
  int &val = memo[x][y][p][q][d];
  /*
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      cout << G[i][j];
    }cout <<endl;
  }cout << endl;
  */
  if(val >= 0) return val;
  if(G[x][y] == 'G'){
    return val = 0;
  }
  val = INF;
  int x_ = x + dx[d], y_ = y + dy[d];
  if(in_range(x_, N) && in_range(y_, M) && G[x_][y_] != '#'){
    char c = G[x][y];
    if(G[x][y] != 'S') G[x][y] = '#';
    val = min(val, dfs(x_, y_, d, p, q));
    G[x][y] = c;
  }
  x_ = x + dx[P[d]], y_ = y + dy[P[d]];
  if(G[x][y] != 'S' && in_range(x_, N) && in_range(y_, M) && G[x_][y_] != '#' && p > 0){
    char c = G[x][y];
    G[x][y] = '#';
    val = min(val, dfs(x_, y_, P[d], p-1, q) + 1);
    G[x][y] = c;
  }
  x_ = x + dx[Q[d]], y_ = y + dy[Q[d]];
  if(G[x][y] != 'S' && in_range(x_, N) && in_range(y_, M) && G[x_][y_] != '#' && q > 0){
    char c = G[x][y];
    G[x][y] = '#';
    val = min(val, dfs(x_, y_, Q[d], p, q-1) + 1);
    G[x][y] = c;
  }
  //printf("dp[%d][%d][%d][%d][%d] = %d\n", x, y, p, q, d, memo[x][y][p][q][d]);
  return val;
}

int main() {
  int A;
  scanf("%d %d %d", &N, &M, &A);
  int sx, sy;
  for(int i = 0; i < N; ++i){
    cin >> G[i];
    for(int j = 0; j < M; ++j){
      if(G[i][j] == 'S'){
        sx = i;
        sy = j;
      }
    }
  }
  fill(memo[0][0][0][0], memo[100][0][0][0], -1);
  int ans = dfs(sx, sy, 0, A, A);
  cout << (ans >= INF ? -1 : ans) << endl;
  return 0;
}


