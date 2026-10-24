#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  int a[1000], b[1000], c[1000];
  int dist[100][100];
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) dist[i][j] = 0;
      else dist[i][j] = 1e9;
    }
  }
  for(int i = 0; i < m; i++){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
    dist[a[i]][b[i]] = dist[b[i]][a[i]] = c[i];
  }
  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  int sum = m;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(dist[j][a[i]] + c[i] == dist[j][b[i]]){
        sum -= 1;
        break;
      }
    }
  }
  cout << sum << endl;
  return 0;
}
