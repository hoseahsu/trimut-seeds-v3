#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main()
{
    int n, m, k; cin>>n>>m>>k;

    vector<string> a(n);
    vector<vector<int>> v(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    for(int i=0; i<n; ++i) {
        cin>>a[i];
        for(int j=0; j<m; ++j) {
            if (a[i][j]=='S') {
                q.emplace(i, j);
                v[i][j]=0;
                break;
            }
        }
    }

    int dr[4]={-1, 0, 1, 0};
    int dc[4]={0, -1, 0, 1};
    int res=1<<30;
    while (q.size()) {
        int r, c;
        tie(r, c)=q.front();
        q.pop();
        //res=min({res, r, c, n-1-r, m-1-c});
        res=min(res, min(r, min(c, min(n-1-r, m-1-c))));
        if (res==0) break;
        if (v[r][c]==k) continue;

        for(int i=0; i<4; ++i) {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if (nr<0 or nr>=n or nc<0 or nc>=m) continue;
            if (a[nr][nc]=='#') continue;
            if (~v[nr][nc]) continue;
            q.emplace(nr, nc);
            v[nr][nc]=v[r][c]+1;
        }
    }
    cout<<(res+k-1)/k+1<<endl;
}

