#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n, m;
vector<P> v[200];

double solve(){
  double res = 0;
  double dp[201][201];
  vector<int> area[200];
  vector<int> hv[200];
  
  fill(dp[0], dp[201], 0);  

  for(int i=0;i<n;i++){
    int a = 0;
    int h = 0;
    area[i].push_back(0);
    hv[i].push_back(0);
    for(int j=0;j<v[i].size();j++){
      a += v[i][j].first * v[i][j].second;
      area[i].push_back(a);

      h += v[i][j].second;
      hv[i].push_back(h);
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<=m;j++){
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
    }

    for(int j=0;j<v[i].size();j++){
      for(int k=0;k<=area[i][j+1]-area[i][j];k++){
        for(int l=0;l+area[i][j]+k<=m;l++){
          dp[i+1][l+area[i][j]+k] = max(dp[i+1][l+area[i][j]+k], dp[i][l] + hv[i][j] + (double)k / (double)v[i][j].first);
        }
      }
    }
    
    /*
    for(int j=0;j<v[i].size();j++){
      for(int k=0;k<=m;k++){
        if(k + area[i][j+1] <= m){
          dp[i+1][k+area[i][j+1]] = max(dp[i+1][k+area[i][j+1]], dp[i][k] + hv[i][j+1]);
        } else if(k + area[i][j] <= m){
          //cout << dp[i+1][m] << " -> ";
          dp[i+1][m] = max(dp[i+1][m], dp[i][k] + hv[i][j] + (double)(m - k - area[i][j]) / (double)v[i][j].first);
        //cout << dp[i+1][m] << endl;
        } else break;
      }
    }
    */
  }

  return dp[n][m];
}

int main(){
  int k, x, y;
  while(cin >> n >> m){
    for(int i=0;i<n;i++){
      v[i].clear();
      cin >> k;
      for(int j=0;j<k;j++){
        cin >> x >> y;
        v[i].push_back(P(x, y));
      }
    }
    printf("%.6f\n", solve());
  }
}