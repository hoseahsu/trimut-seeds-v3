#include <stdio.h>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


enum DIR{
	YOKO,
	TATE,
};

struct Info{
	Info(int arg_row,int arg_col,ll arg_total_cost){
		row = arg_row;
		col = arg_col;
		total_cost = arg_total_cost;
	}
	bool operator<(const struct Info &arg) const{
		return total_cost > arg.total_cost;
	}
	int row,col;
	ll total_cost;
};

int W,H,N;
int diff_row[4] = {-1,0,0,1},diff_col[4] = {0,-1,1,0};
ll min_cost[501][501],cost[501][501][2];

bool rangeCheck_Cable(int row,int col){
	if(row >= 0 && row <= H && col >= 0 && col <= W)return true;
	else{
		return false;
	}
}

bool rangeCheck_Staff(int row,int col){
	if(row >= 0 && row <= H-1 && col >= 0 && col <= W-1)return true;
	else{
		return false;
	}
}

void func(){

	for(int row = 0; row <= H; row++){
		for(int col = 0; col <= W; col++)min_cost[row][col] = 9999999999999;
	}

	for(int row = 0; row <= H; row++){
		for(int col = 0; col <= W; col++){
			cost[row][col][TATE] = 0;
			cost[row][col][YOKO] = 0;
		}
	}

	int start_row,start_col,end_row,end_col;
	scanf("%d %d %d %d",&start_col,&start_row,&end_col,&end_row);

	int T,tmp_row,tmp_col;
	char buf[1001];

	for(int loop = 0; loop < N; loop++){
		scanf("%d %d",&tmp_col,&tmp_row);
		scanf("%d %s",&T,buf);

		for(int count = 0; count < T; count++){
			for(int i = 0; buf[i] != '\0'; i++){
				switch(buf[i]){
				case 'U':
					if(rangeCheck_Staff(tmp_row-1,tmp_col)){
						cost[tmp_row][tmp_col][YOKO] += 1;
						tmp_row--;
					}
					break;
				case 'D':
					if(rangeCheck_Staff(tmp_row+1,tmp_col)){
						cost[tmp_row+1][tmp_col][YOKO] += 1;
						tmp_row++;
					}
					break;
				case 'L':
					if(rangeCheck_Staff(tmp_row,tmp_col-1)){
						cost[tmp_row][tmp_col][TATE] += 1;
						tmp_col--;
					}
					break;
				case 'R':
					if(rangeCheck_Staff(tmp_row,tmp_col+1)){
						cost[tmp_row][tmp_col+1][TATE] += 1;
						tmp_col++;
					}
					break;
				}
			}
		}
	}

	priority_queue<Info> Q;
	min_cost[start_row][start_col] = 0;
	Q.push(Info(start_row,start_col,0));

	int next_row,next_col;
	ll next_cost;

	while(!Q.empty()){

		if(Q.top().row == end_row && Q.top().col == end_col){
			Q.pop();
		}else if(Q.top().total_cost > min_cost[Q.top().row][Q.top().col]){
			Q.pop();
		}else{

			for(int i = 0; i < 4; i++){

				next_row = Q.top().row+diff_row[i];
				next_col = Q.top().col+diff_col[i];

				if(!rangeCheck_Cable(next_row,next_col))continue;

				switch(i){
				case 0:
					next_cost = Q.top().total_cost+cost[next_row][next_col][TATE];
					break;
				case 1:
					next_cost = Q.top().total_cost+cost[next_row][next_col][YOKO];
					break;
				case 2:
					next_cost = Q.top().total_cost+cost[Q.top().row][Q.top().col][YOKO];
					break;
				case 3:
					next_cost = Q.top().total_cost+cost[Q.top().row][Q.top().col][TATE];
					break;
				}
				if(min_cost[next_row][next_col] > next_cost){
					min_cost[next_row][next_col] = next_cost;
					Q.push(Info(next_row,next_col,next_cost));
				}
			}

			Q.pop();
		}
	}

	printf("%lld\n",min_cost[end_row][end_col]);
}

int main(){

	scanf("%d %d %d",&W,&H,&N);

	func();

	return 0;
}