// AOJ 2014

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
string field[60];
int h, w;
int type, cnt;
bool done[60][60];

typedef pair <int, int> P;

void dfs(int y, int x)
{
	cnt++;
	for (int i = 0; i < 4; i++){
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || h <= ny || w <= nx) continue;
		// puts("*");
		if (!done[ny][nx] && field[ny][nx] == '.'){
			done[ny][nx] = true;
			// puts("*");
			dfs(ny, nx);
		}
		if (field[ny][nx] == 'B'){
			type |= 1;
		}
		if (field[ny][nx] == 'W'){
			type |= 2;
		}
	}
}

int main(void)
{
	while (cin >> w >> h, w && h){
		for (int i = 0; i < 60; i++){
			field[i].clear();
		}
		for (int i = 0; i < 60; i++){
			for (int j = 0; j < 60; j++){
				done[i][j] = false;
			}
		}

		for (int i = 0; i < h; i++){
			cin >> field[i];
		}

		int ret[128] = {0};
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				if (!done[i][j] && field[i][j] == '.') {
					done[i][j] = true;
					type = cnt = 0;
					dfs(i, j);
					// cout << cnt << " ";
					ret[type] += cnt;
					/*
					if (type == 1) cout << 'w';
					if (type == 0) cout << 'b';
					*/
				}
				// else cout << field[i][j];
			}
			// puts("");
		}
		// puts("");
/*
		for (int i = 0; i < 20; i++){
			cout << ret[i] << " ";
		}
		puts("");
*/
		cout << ret[1] << " " << ret[2] << endl;
	}
}