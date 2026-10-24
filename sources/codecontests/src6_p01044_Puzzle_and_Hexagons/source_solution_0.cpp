#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define for_rev(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define allof(a) a.begin(),a.end()
#define minit(a,b) memset(a,b,sizeof(a))
#define size_of(a) (int)a.size()

typedef long long lint;
typedef double Double;
typedef pair< int, int > pii;

int dx[6] = {0,1,1,0,-1,-1};

int dy[2][6] = {
	{1,1,0,-1,0,1},
	{1,0,-1,-1,-1,0}
};

int H, W, Q;
string hanic[55];

void rotate(int x, int y) {
	if (x == 0 || y == 0 || x == W - 1 || y == H - 1) return;
	
	int xp = x % 2;
	char piv = hanic[y + dy[xp][5]][x + dx[5]];
	
	for_rev(i,5,1) {
		hanic[y + dy[xp][i]][x + dx[i]] = hanic[y + dy[xp][i - 1]][x + dx[i - 1]];
	}
	
	hanic[y + dy[xp][0]][x + dx[0]] = piv;
}

void fall() {
	bool update = true;
	
	while (update) {
		update = false;
		
		for (int i = 1; i < H && !update; ++i)
		for (int j = 0; j < W && !update; ++j) {
			if (hanic[i][j] == '.') continue;
			
			bool fal = true;
			for_(d,2,5) {
				if (j == 0 && d == 4) continue;
				if (j == W - 1 && d == 2) continue;
				fal &= (hanic[i + dy[j % 2][d]][j + dx[d]] == '.');
			}
			
			if (fal) {
				hanic[i + dy[j % 2][3]][j + dx[3]] = hanic[i][j];
				hanic[i][j] = '.';
				update = true;
			}
		}
	}
}

bool vis[55][55];

void rec(int x, int y, char col, vector< pii >& vp) {
	vp.push_back(pii(x, y));
	vis[y][x] = 1;
	
	for_(d,0,6) {
		int nx = x + dx[d], ny = y + dy[x % 2][d];
		if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
		if (vis[ny][nx]) continue;
		if (hanic[ny][nx] == col) rec(nx, ny, col, vp);
	}
}

bool vanish() {
	minit(vis, 0);
	bool res = false;
	
	for_(y,0,H) for_(x,0,W) {
		if (!vis[y][x] && hanic[y][x] != '.') {
			vector< pii > vp;
		
			rec(x, y, hanic[y][x], vp);
			
			if (vp.size() >= 3) {
				for (size_t i = 0; i < vp.size(); ++i) {
					pii p = vp[i];
					hanic[p.second][p.first] = '.';
				}
				
				res = true;
			}
		}
	}
	
	return res;
}

int main() {
	cin >> H >> W;
	
	for_(i,0,H) cin >> hanic[H - i - 1];
	
	fall();
	while (vanish()) fall();
	
	cin >> Q;
	for_(i,0,Q) {
		int x, y;
		cin >> x >> y;
		rotate(x, y);
		fall();
		while (vanish()) fall();
	}
	
	for_(i,0,H) cout << hanic[H - i - 1] << endl;
}
