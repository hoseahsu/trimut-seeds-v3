#include<iostream>
#include <cstring>
using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main()
{
	int n;
	long long k;
	while(cin >> n >> k && n){
		k--;
		if( k >= (1ll<<(n/2)) || n % 2 == 1 ){
			cout << "No" << endl;
			cout << endl;
			continue;
		}
		int table[64][64];
		memset(table,-1,sizeof(table));
		//一行決めると一意に定まる
		for(int i = 0 ; i < n ; i++)
			table[0][i] = ( k >> ((n-i-1)/2) & 1 );
		
		for(int i = 0 ; i < n-1 ; i++){
			for(int j = 0 ; j < n ; j++){
				int cnt = 0;
				for(int d = 0 ; d < 4 ; d++){
					int tx = j + dx[d],ty = i + dy[d];
					if( tx < 0 || tx >= n || ty < 0 || ty >= n ) continue;
					if( table[ty][tx] == table[i][j] ) cnt++;
				}
				if( cnt == 2 ) table[i+1][j] = !table[i][j];
				else table[i+1][j] = table[i][j];
			}
		}
		for(int y = 0 ; y < n ; y++){
			for(int x = 0 ; x < n ; x++){
				cout << (char)(table[y][x]?'E':'.');
			}
			cout << endl;
		}
		cout << endl;
	}
}