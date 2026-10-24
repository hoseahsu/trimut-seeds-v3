#include <bits/stdc++.h>
using namespace std;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<vector<int>> dp(N,vector<int>(N))
                        ,check(N,vector<int>(N,1));
    for (int i=0;i<N;++i){
        for (int j=0;j<N;++j){
            dp[i][j]=min(min(i,N-1-i),min(j,N-1-j));
        }
    }
    int ans=0;
    queue<pair<int,int>> que;
    for (int i=0;i<N*N;++i){
        int P; cin >> P; --P;
        int sx=P/N,sy=P%N;
        ans+=dp[sx][sy];
        check[sx][sy]=0;
        que.emplace(sx,sy);
        while(!que.empty()){
            auto p=que.front(); que.pop();
            int x=p.first,y=p.second;
            for (int i=0;i<4;++i){
                int nx=x+dx[i],ny=y+dy[i];
                if (nx<0||N<=nx||ny<0||N<=ny) continue;
                if (dp[nx][ny]<=dp[x][y]+(check[x][y])) continue;
                dp[nx][ny]=dp[x][y]+check[x][y];
                que.emplace(nx,ny);
            }
        }
    }
    cout << ans << '\n';
}