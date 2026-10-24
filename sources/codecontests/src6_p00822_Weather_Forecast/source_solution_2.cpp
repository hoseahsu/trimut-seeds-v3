#include <bits/stdc++.h>
#define range(i, a, n) for(int (i) = (a); (i) < (n); (i)++)
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int n;
int memo[366][3][3][7][7][7][7];
int fes[366][4][4];

vi dx = { 1, 0,-1, 0, 0};
vi dy = { 0,-1, 0, 1, 0};

bool rec(int day, int y, int x, int a, int b, int c, int d){
    if(a == 7 or b == 7 or c == 7 or d == 7) return false;
    if(day == n){
        return true;
    }

    if(memo[day][y][x][a][b][c][d] != -1) return memo[day][y][x][a][b][c][d];

    rep(i, 2){
        rep(j, 2){
            if(fes[day][y + i][x + j]){
                return memo[day][y][x][a][b][c][d] = false;
            }
        }
    }

    bool ret = false;
    rep(i, 5){
        range(j, 1, 3){
            int ny = y + dy[i] * j;
            int nx = x + dx[i] * j;

            if(nx < 0 or 2 < nx or
               ny < 0 or 2 < ny) continue;

            int na = a + 1, nb = b + 1, nc = c + 1, nd = d + 1;
            if(ny == 0 and nx == 0) na = 0;
            if(ny == 0 and nx == 2) nb = 0;
            if(ny == 2 and nx == 0) nc = 0;
            if(ny == 2 and nx == 2) nd = 0;

            ret |= rec(day + 1, ny, nx, na, nb, nc, nd);
        }
    }

    return memo[day][y][x][a][b][c][d] = ret;
}

int main(void){
    for(; cin >> n, n;){
        rep(i, n){
            rep(y, 4){
                rep(x, 4){
                    cin >> fes[i][y][x];
                }
            }
        }

        rep(i1, n) rep(i2, 3) rep(i3, 3) rep(i4, 7) rep(i5, 7) rep(i6, 7) rep(i7, 7) memo[i1][i2][i3][i4][i5][i6][i7] = -1;

        cout << rec(0, 1, 1, 1, 1, 1, 1) << endl;
    }

	return 0;
}