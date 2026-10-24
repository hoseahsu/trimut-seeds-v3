#include <stdio.h>
#include <cmath>
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


struct Data{
	int S,H,V_ruiseki,H_ruiseki;
};

struct Info{
	int K;
	Data data[20];
};

double dp[201][201];

int main(){

	int N,M;
	scanf("%d %d",&N,&M);

	Info info[N];
	int V_sum,H_sum,all_V_sum = 0,all_H_sum = 0;

	for(int i = 0; i < N; i++){
		scanf("%d",&info[i].K);
		V_sum = 0;
		H_sum = 0;

		for(int a = 0; a < info[i].K; a++){
			scanf("%d %d",&info[i].data[a].S,&info[i].data[a].H);
			all_V_sum += info[i].data[a].S*info[i].data[a].H;
			all_H_sum += info[i].data[a].H;
			V_sum += info[i].data[a].S*info[i].data[a].H;
			H_sum += info[i].data[a].H;
			info[i].data[a].V_ruiseki = V_sum;
			info[i].data[a].H_ruiseki = H_sum;
		}
	}

	if(all_V_sum <= M){
		printf("%d\n",all_H_sum);
		return 0;
	}

	for(int i = 0; i <= N; i++){
		for(int k = 0; k <= M; k++)dp[i][k] = -1.0;
	}

	dp[0][M] = 0.0;

	double height;
	int next_rest,num;

	for(int pot = 0; pot < N; pot++){
		for(int rest = 0; rest <= M; rest++){
			if(dp[pot][rest] == -1.0)continue;
			for(int water = 0; water <= rest; water++){

				for(num = 0; num < info[pot].K; num++){
					if(info[pot].data[num].V_ruiseki > water){
						break;
					}
				}

				if(num == info[pot].K){
					height = (double)info[pot].data[info[pot].K-1].H_ruiseki;
					next_rest = water-info[pot].data[info[pot].K-1].V_ruiseki;
					dp[pot+1][next_rest] = max(dp[pot+1][next_rest],dp[pot][rest]+height);
				}else{

					if(num == 0){
						height = (double)water/(double)info[pot].data[num].S;
					}else{
						height = (double)info[pot].data[num-1].H_ruiseki+(double)(water-info[pot].data[num-1].V_ruiseki)/(double)info[pot].data[num].S;
					}
					dp[pot+1][rest-water] = max(dp[pot+1][rest-water],dp[pot][rest]+height);
				}
			}
		}
	}

	printf("%.10lf\n",dp[N][0]);

	return 0;
}