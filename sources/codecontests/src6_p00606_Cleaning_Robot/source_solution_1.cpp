#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char room[5][5] = {
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1}
};

void solve(char n, double p[5][5] ){
	for( ; n>0 ; n-- ){
		double tmp[5][5] = {0};
		
		for(int y=1 ; y <= 3 ; y++ ){
			for(int x=1 ; x <= 3 ; x++ ){
				if( p[y][x] > 0.0 ){
					for(int i=0 ; i<4 ; i++ ){
						int mx = x + dx[i];
						int my = y + dy[i];
						if( room[my][mx] == 0 ){
							tmp[my][mx] += p[y][x]/4.0;
						}else{
							tmp[y][x] += p[y][x]/4.0;
						}
					}
				}
			}
		}
		for(int y=1 ; y <= 3 ; y++ ){
			for(int x=1 ; x <= 3 ; x++ ){
				p[y][x] = tmp[y][x];
			}
		}
	}
}

int main(){
	char fx[256] = {0}, fy[256] = {0};
	int n;
	char s, t, b;
	
	for(int i=0;i<9;i++){
		fx[i+'A'] = i%3+1;
		fy[i+'A'] = i/3+1;
	}
	
	while( scanf("%d", &n) , n ){
		scanf(" %c %c %c ", &s, &t, &b);
		double p[5][5] = {0};
		for(int i=1 ; i<=3 ; i++){
			for(int j=1 ; j<=3 ; j++){
				room[i][j] = 0;
			}
		}
				
		room[ fy[b] ][ fx[b] ] = 1;
		p[ fy[s] ][ fx[s] ] = 1.0;
		
		solve( n , p );
		
		printf("%.9f\n" , p[ fy[t] ][ fx[t] ] );
	}
}