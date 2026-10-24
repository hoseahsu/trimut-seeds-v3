#include <iostream>

#include <string>

using namespace std;

int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};

int main(){

	int d;

	cin >> d;

	for(int t = 0;t < d;t++){

		if(t) cout << endl;

		char s[102][102];

		int n;

		cin >> n;
		
		if(n == 1){
			cout << "#" << endl;
			continue;
			}

		for(int i = 0;i < n;i++){

			for(int j = 0;j < n;j++) s[i][j] = ' ';

		}

		int x = n - 1,y = 0,dir = 0;

		for(int k = 0;k < n;k++){

			bool flag = false;

			while(1){

				int nx = x + dx[dir],ny = y + dy[dir];

			 if(nx < 0 || nx >= n + 1 || ny < 0 || ny >= n + 1 || s[nx][ny] == '#') break;

s[x][y] = '#';

flag = true;

				x = nx;

				y = ny;

			}

if(x)x -= dx[dir];

if(y)y -= dy[dir];

			if(!flag) break;

			dir = (dir + 1) % 4;

		}

for(int i = 0;i < n;i++) {

for(int j = 0;j < n;j++){

cout << s[i][j];

}

cout << endl;}

	}

}