#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 15

struct Data{
	Data(int arg_price,int arg_value,int arg_num){
		price = arg_price;
		value = arg_value;
		num = arg_num;
	}
	int price,value,num;
};

struct Info{

	int num_item;
	vector<Data> V;
};

int N,X,Y;
int POW[SIZE];
int min_dist[SIZE][SIZE];
int TSP[1 << 14][SIZE];
int dp_each[SIZE][305][1005],dp_each2[SIZE][1005];
int dp_A[1 << 7][1005],dp_B[1 << 7][1005];
Info info[SIZE];


int main(){

	POW[0] = 1;
	for(int i = 1; i < SIZE; i++){

		POW[i] = POW[i-1]*2;
	}

	scanf("%d %d %d",&N,&X,&Y);

	int price,value,num;

	for(int i = 0; i < N; i++){

		scanf("%d",&info[i].num_item);
		for(int k = 0; k < info[i].num_item; k++){

			scanf("%d %d %d",&price,&value,&num);
			info[i].V.push_back(Data(price,value,num));
		}
	}

	for(int i = 0; i < N; i++){
		for(int k = 0; k < N; k++){

			scanf("%d",&min_dist[i][k]);
		}
	}

	for(int i = 0; i < N; i++){ //14

		for(int k = 0; k <= info[i].num_item; k++){
			for(int p = 0; p <= Y; p++){
				dp_each[i][k][p] = -BIG_NUM;
			}
		}

		for(int k = 0; k <= Y; k++){

			dp_each2[i][k] = -BIG_NUM;
		}

		dp_each[i][0][0] = 0;
		dp_each2[i][0] = 0;

		for(int k = 0; k < info[i].num_item; k++){ //300

			for(int p = 0; p <= Y; p++){

				dp_each[i][k+1][p] = dp_each[i][k][p];
			}

			int num = info[i].V[k].num;
			int mult;

			for(int p = 1; num > 0; p *= 2){
				mult = min(p,num);
				for(int w = Y; w-mult*info[i].V[k].price >= 0; w--){
					if(dp_each[i][k+1][w-mult*info[i].V[k].price] == -BIG_NUM)continue;
					dp_each[i][k+1][w] = max(dp_each[i][k+1][w],
							dp_each[i][k+1][w-mult*info[i].V[k].price]+mult*info[i].V[k].value);
					dp_each2[i][w] = max(dp_each2[i][w],dp_each[i][k+1][w]);
				}
				num -= mult;
			}
		}

		for(int k = 1; k <= Y; k++){

			dp_each2[i][k] = max(dp_each2[i][k],dp_each2[i][k-1]);
		}
	}

	if(N == 1){

		printf("%d\n",dp_each2[0][Y]);
		return 0;
	}

	//ワーシャルフロイド
	for(int mid = 0; mid < N; mid++){
		for(int start = 0; start < N; start++){
			for(int goal = 0; goal < N; goal++){

				min_dist[start][goal] = min(min_dist[start][goal],min_dist[start][mid]+min_dist[mid][goal]);
			}
		}
	}

	//TSP
	for(int state = 0; state < POW[N]; state++){
		for(int town = 0; town < N; town++){

			TSP[state][town] = BIG_NUM;
		}
	}

	TSP[1][0] = 0;
	for(int state = 1; state < POW[N];state++){
		for(int town = 0; town < N; town++){
			if(TSP[state][town] == BIG_NUM)continue;

			for(int loop = 0; loop < N; loop++){
				if(state & (1 << loop))continue;

				int next_state = state+POW[loop];
				int next_dist = TSP[state][town]+min_dist[town][loop];

				TSP[next_state][loop] = min(TSP[next_state][loop],next_dist);
			}
		}
	}

	vector<int> A,B;
	for(int i = 0; i < N/2; i++){

		A.push_back(i);
	}
	for(int i = N/2; i < N; i++){

		B.push_back(i);
	}

	for(int i = 0; i < POW[A.size()]; i++){
		for(int k = 0; k <= Y; k++){

			dp_A[i][k] = -BIG_NUM;
		}
	}
	dp_A[0][0] = 0;

	for(int state = 0; state < POW[A.size()]; state++){
		for(int i = 0; i <= Y; i++){
			if(dp_A[state][i] == -BIG_NUM)continue;

			for(int loop = 0; loop < A.size(); loop++){
				if(state & (1 << loop))continue;

				for(int k = 0; k <= Y; k++){
					if(i+k > Y)break;

					int next_state = state+POW[loop];
					int next_value = dp_A[state][i]+dp_each2[A[loop]][k];

					dp_A[next_state][i+k] = max(dp_A[next_state][i+k],next_value);
				}
			}
		}

		for(int i = 1; i <= Y; i++){

			dp_A[state][i] = max(dp_A[state][i],dp_A[state][i-1]);
		}
	}

	for(int i = 0; i < POW[B.size()]; i++){
		for(int k = 0; k <= Y; k++){

			dp_B[i][k] = -BIG_NUM;
		}
	}
	dp_B[0][0] = 0;

	for(int state = 0; state < POW[B.size()]; state++){
		for(int i = 0; i <= Y; i++){
			if(dp_B[state][i] == -BIG_NUM)continue;

			for(int loop = 0; loop < B.size(); loop++){
				if(state & (1 << loop))continue;

				for(int k = 0; k <= Y; k++){
					if(i+k > Y)break;

					int next_state = state+POW[loop];
					int next_value = dp_B[state][i]+dp_each2[B[loop]][k];

					dp_B[next_state][i+k] = max(dp_B[next_state][i+k],next_value);
				}
			}
		}

		for(int i = 1; i <= Y; i++){

			dp_B[state][i] = max(dp_B[state][i],dp_B[state][i-1]);
		}
	}

	int ans = 0;

	for(int state_A = 1; state_A < POW[A.size()]; state_A++){

		int num_A = 0;
		for(int loop = 0; loop < A.size(); loop++){
			if(state_A & (1 << loop)){
				num_A += POW[A[loop]];
			}
		}

		for(int state_B = 0; state_B < POW[B.size()]; state_B++){

			int num_B = 0;
			for(int loopB = 0; loopB < B.size(); loopB++){
				if(state_B & (1 << loopB)){
					num_B += POW[B[loopB]];
				}
			}

			int all_state = num_A+num_B;
			int path_cost = BIG_NUM;

			for(int i = 0; i < N; i++){
				if(!(POW[i]&all_state))continue;

				path_cost = min(path_cost,TSP[all_state][i]+min_dist[i][0]);
			}

			int limit = Y;
			if(X-Y < path_cost){

				limit = Y-(path_cost-(X-Y));
			}

			for(int budget_A = 0; budget_A <= limit; budget_A++){
				int budget_B = limit-budget_A;

				ans = max(ans,dp_A[state_A][budget_A]+dp_B[state_B][budget_B]);
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}

