#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 1000

struct Info{
	int x,y;
};

int dp[NUM][NUM];
Info info[NUM];

int main(){

	int N;
	scanf("%d",&N);

	for(int i = 0; i < N; i++){
		scanf("%d %d",&info[i].x,&info[i].y);
	}

	for(int i = 0; i < N; i++){
		dp[i][i] = 0;
		for(int k = i+1; k < N; k++){
			dp[i][k] = BIG_NUM;
		}
	}

	int tmp_cost;

	for(int a = 0; a < N; a++){
		for(int i = 0; i+a < N; i++){
			for(int k = i; k < i+a; k++){
				tmp_cost = abs(info[i].x-info[k+1].x)+abs(info[k].y-info[i+a].y);
				dp[i][i+a] = min(dp[i][i+a],dp[i][k]+dp[k+1][i+a]+tmp_cost);
			}
		}
	}

	printf("%d\n",dp[0][N-1]);

	return 0;
}

