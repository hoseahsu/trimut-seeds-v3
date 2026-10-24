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


ll calc(ll x,ll y){
	if(y == 0){
		return x;
	}else{
		return calc(y,x%y);
	}
}

int N;
ll day_len[100],now_t[100],access[100][24];
ll table1[60000],table2[100000];



void func(){

	for(int i = 0; i < 60000; i++)table1[i] = 0;
	for(int i = 0; i < 100000; i++)table2[i] = 0;

	ll cicle1 = 1,cicle2 = 1,common;

	for(int i = 0; i < N; i++){
		scanf("%lld %lld",&day_len[i],&now_t[i]);
		if(day_len[i] == 13 || day_len[i] == 17 || day_len[i] == 19 || day_len[i] == 23){
			if(cicle2 >= day_len[i]){
				common = calc(cicle2,day_len[i]);
			}else{
				common = calc(day_len[i],cicle2);
			}
			cicle2 = (cicle2*day_len[i])/common;
		}else{
			if(cicle1 >= day_len[i]){
				common = calc(cicle1,day_len[i]);
			}else{
				common = calc(day_len[i],cicle1);
			}
			cicle1 = (cicle1*day_len[i])/common;
		}

		for(int k = 0; k < day_len[i]; k++)scanf("%d",&access[i][k]);
	}

	for(int i = 0; i < N; i++){
		if(day_len[i] == 13 || day_len[i] == 17 || day_len[i] == 19 || day_len[i] == 23){
			for(int k = 0; k < cicle2; k++){
				table2[k] += access[i][(now_t[i]+k)%day_len[i]];
			}
		}else{
			for(int k = 0; k < cicle1; k++){
				table1[k] +=  access[i][(now_t[i]+k)%day_len[i]];
			}
		}
	}

	ll maximum1 = 0,maximum2 = 0;
	for(int k = 0; k < cicle1; k++)maximum1 = max(maximum1,table1[k]);
	for(int k = 0; k < cicle2; k++)maximum2 = max(maximum2,table2[k]);

	printf("%lld\n",maximum1+maximum2);

}


int main(){

	while(true){
		scanf("%d",&N);
		if(N == 0)break;

		func();
	}

	return 0;
}