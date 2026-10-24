// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;

char board[1010][1010];
int H, W, K, dist[1010][1010], adj[25][25], dp[1 << 22][22];
vector< pair<int, int> > apples;
pair<int, int> S, G;

void calc_dist(int idx) {
    int sx, sy; tie(sx, sy) = apples[idx];
    fill(dist[0], dist[H], INF);
    dist[sx][sy] = 0;
    queue< tuple<int, int, int> > que;
    que.emplace(sx, sy, 0);
    while(que.size()) {
        int x, y, c; tie(x, y, c) = que.front(); que.pop();
        if(dist[x][y] < c) continue;
        for(int k=0; k<4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 or nx >= H or ny < 0 or ny >= W) continue;
            if(board[nx][ny] == '#') continue;
            if(dist[nx][ny] > c + 1) {
                dist[nx][ny] = c + 1;
                que.emplace(nx, ny, dist[nx][ny]);
            }
        }
    }

    for(size_t i=0; i<apples.size(); i++) {
        int tx, ty; tie(tx, ty) = apples[i];
        // fprintf(stderr, "i = %d, tx = %d, ty = %d, cost = %d\n", i, tx, ty, dist[tx][ty]);
        adj[idx][i] = adj[i][idx] = dist[tx][ty];
    }
}

int main() {
    scanf("%d%d%d", &H, &W, &K);
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            scanf(" %c", &board[i][j]);
            if(board[i][j] == 'a') apples.emplace_back(i, j);
            if(board[i][j] == 's') S = make_pair(i, j);
            if(board[i][j] == 'e') G = make_pair(i, j);
        }
    }

    apples.emplace_back(G);
    apples.emplace_back(S);
    for(size_t i=0; i<apples.size(); i++) {
        calc_dist(i);
    }

    int M = apples.size() - 1, src = M, dst = M - 1;

    /*
    for(int i=0; i<M; i++) {
        for(int j=0; j<M; j++) {
            fprintf(stderr, "%d ", adj[i][j]);
        }
        fprintf(stderr, "\n");
    }
    */
    
    fill(dp[0], dp[1 << M], INF);
    dp[0][src] = 0;
    for(int bit=0; bit<(1<<M); bit++) {
        for(int i=0; i<=M; i++) {
            for(int k=0; k<M; k++) {
                if(bit >> k & 1) continue;
                int nbit = bit | (1 << k);
                chmin(dp[nbit][k], dp[bit][i] + adj[i][k]);
            }
        }
    }

    int ans = INF;
    for(int bit=0; bit<(1<<M); bit++) {
        int c = __builtin_popcount(bit);
        if(bit >> src & 1) c--;
        if(bit >> dst & 1) c--;
        if(dp[bit][dst] == INF or c < K) continue;
        chmin(ans, dp[bit][dst]);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}

