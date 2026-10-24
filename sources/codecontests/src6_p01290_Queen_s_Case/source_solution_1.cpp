#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;
int dx[5] = {1, 0, -1, 0, 0};
int dy[5] = {0, 1, 0, -1, 0};

const int MAX_T = 10 * 30 / 4;

int W, H;
string grid[30];
char memo[30][30][30][30][MAX_T];
bool valid(int x, int w) {
    return 0 <= x && x < w;
}
int dfs(int x1, int y1, int x2, int y2, int t) {
    //printf("%d %d %d %d %d %c %c\n", x1, y1, x2, y2, t, grid[y1][x1], grid[y2][x2]);
    if(t >= MAX_T) return 2;
    char& res = memo[y1][x1][y2][x2][t];
    if(res != -1) return res;

    if(y1 == y2 && x1 == x2) return res = 1;

    int turn = t % 2;
    if(turn == 0) {
        if(grid[y1][x1] == 'E') return res = 0;

        bool draw = false;
        REP(r, 5) {
            int nx = x1 + dx[r];
            int ny = y1 + dy[r];
            if(valid(nx, W) && valid(ny, H) && grid[ny][nx] != '#') {
                int check = dfs(nx, ny, x2, y2, t + 1);
                if(check == 0) {
                    return res = 0;
                } else if(check == 2) {
                    draw = true;
                }
            }
        }
        return res = (draw ? 2 : 1);
    } else {
        bool draw = false;
        REP(r, 5) {
            int nx = x2 + dx[r];
            int ny = y2 + dy[r];
            if(valid(nx, W) && valid(ny, H) && grid[ny][nx] != '#') {
                int check = dfs(x1, y1, nx, ny, t + 1);
                if(check == 1) {
                    return res = 1;
                } else if(check == 2) {
                    draw = true;
                }
            }
        }
        return res = (draw ? 2 : 0);
    }
}

int main(){
    while(cin >> W >> H && W > 0){
        REP(y, H) cin >> grid[y];
        int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
        REP(y, H) REP(x, W) if(grid[y][x] == 'Q') x1 = x, y1 = y;
        REP(y, H) REP(x, W) if(grid[y][x] == 'A') x2 = x, y2 = y;

        memset(memo, -1, sizeof(memo));
        int ans = dfs(x1, y1, x2, y2, 0);
        if(ans == 0) {
            cout << "Queen can escape." << endl;
        } else if(ans == 1) {
            cout << "Army can catch Queen." << endl;
        } else {
            cout << "Queen can not escape and Army can not catch Queen." << endl;
        }
    }
    return 0;
}