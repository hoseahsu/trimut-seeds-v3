#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 1005
#define EMPTY 10

struct Loc{
	int row,col;
};

struct Data{

	Loc loc;
	char ch;
};

struct Info{
	Info(int arg_tmp_index,int arg_state,int arg_last_item,int arg_sum_dist,int arg_sum_value){
		tmp_index = arg_tmp_index;
		state = arg_state;
		last_item = arg_last_item;
		sum_dist = arg_sum_dist;
		sum_value = arg_sum_value;
	}
	bool operator<(const struct Info &arg) const{
		if(sum_dist != arg.sum_dist){ //距離の昇順(PQ)
			return sum_dist > arg.sum_dist;
		}else{ //総価値の降順(PQ)
			return sum_value < arg.sum_value;
		}
	}
	int tmp_index,state,last_item;
	int sum_dist,sum_value;
};

struct State{
	State(int arg_row,int arg_col,int arg_sum_dist){
		row = arg_row;
		col = arg_col;
		sum_dist = arg_sum_dist;
	}
	bool operator<(const struct State &arg) const{

		return sum_dist > arg.sum_dist;  //距離の昇順(PQ)
	}
	int row,col,sum_dist;
};

int H,W;
int POW[11];
int diff_row[4] = {-1,0,0,1},diff_col[4] = {0,-1,1,0};
int dist_table[35][35];
int min_dist[NUM][NUM];
int min_cost[11][1025][35],max_value[11][1025][35];
int table[11][11];
char base_map[NUM][NUM];
Data data[35];

bool rangeCheck(int row,int col){

	if(row >= 0 && row <= H-1 && col >= 0 && col <= W-1){
		return true;
	}else{
		return false;
	}
}

int main(){

	POW[0] = 1;
	for(int i = 1; i <= 10; i++){

		POW[i] = POW[i-1]*2;
	}

	scanf("%d %d",&W,&H);

	int index = 0;
	int start_index,goal_index;

	for(int row = 0; row < H; row++){

		scanf("%s",base_map[row]);
		for(int col = 0; col < W; col++){
			if(base_map[row][col] != '.' && base_map[row][col] != '#'){

				data[index].ch = base_map[row][col];
				data[index].loc.row = row;
				data[index].loc.col = col;

				if(data[index].ch == 'S'){

					start_index = index;

				}else if(data[index].ch == 'T'){

					goal_index = index;
				}
				index++;
			}
		}
	}

	for(int row = 0; row < 10; row++){
		for(int col = 0; col < 10; col++){

			scanf("%d",&table[row][col]);
		}
	}
	for(int col = 0; col < 10; col++){

		table[EMPTY][col] = 0; //EMPTY:所持品なし
	}

	priority_queue<State> PQ;
	int next_row,next_col,next_state,next_last_item,next_cost,next_value;

	//ダイクストラで主要地点間の距離を求める
	for(int i = 0; i < index; i++){

		for(int row = 0; row < H; row++){
			for(int col = 0; col < W; col++){
				min_dist[row][col] = BIG_NUM;
			}
		}

		min_dist[data[i].loc.row][data[i].loc.col] = 0;
		PQ.push(State(data[i].loc.row,data[i].loc.col,0));

		while(!PQ.empty()){

			if(PQ.top().sum_dist > min_dist[PQ.top().row][PQ.top().col]){

				PQ.pop();

			}else{

				for(int k = 0; k < 4; k++){

					next_row = PQ.top().row+diff_row[k];
					next_col = PQ.top().col+diff_col[k];

					if(rangeCheck(next_row,next_col) == false || base_map[next_row][next_col] == '#')continue;

					if(base_map[next_row][next_col] == '.' || base_map[next_row][next_col] == 'S' || base_map[next_row][next_col] == 'T'){

						next_cost = PQ.top().sum_dist+1;
						if(min_dist[next_row][next_col] > next_cost){

							min_dist[next_row][next_col] = next_cost;
							PQ.push(State(next_row,next_col,next_cost));
						}

					}else{ //その他の文字

						next_cost = PQ.top().sum_dist+1;
						if(min_dist[next_row][next_col] > next_cost){

							min_dist[next_row][next_col] = next_cost;
							//★★遷移を打ち切る★★
						}
					}
				}

				PQ.pop();
			}
		}

		for(int k = 0; k < index; k++){

			dist_table[i][k] = min_dist[data[k].loc.row][data[k].loc.col];
		}
	}

	for(int a = 0; a <= 10; a++){
		for(int b = 0; b <= POW[10]; b++){
			for(int c = 0; c < index; c++){

				min_cost[a][b][c] = BIG_NUM; //min_cost[最後に取得したアイテム][状態][場所のインデックス] = 最小コスト
				max_value[a][b][c] = -BIG_NUM;
			}
		}
	}

	min_cost[EMPTY][0][start_index] = 0;
	max_value[EMPTY][0][start_index] = 0;

	priority_queue<Info> Q;
	Q.push(Info(start_index,0,EMPTY,0,0));

	int next_index;
	int ans_dist = BIG_NUM,ans_value = -1;

	while(!Q.empty()){

		if(Q.top().sum_dist > min_cost[Q.top().last_item][Q.top().state][Q.top().tmp_index]){

			Q.pop();

		}else if(Q.top().tmp_index == goal_index && Q.top().state == POW[10]-1){ //クリア

			if(ans_dist > Q.top().sum_dist){

				ans_dist = Q.top().sum_dist;
				ans_value = Q.top().sum_value;

			}else if(ans_dist == Q.top().sum_dist && ans_value < Q.top().sum_value){

				ans_value = Q.top().sum_value;
			}

			Q.pop();
		}else{

			for(int i = 0; i < index; i++){

				if(i == Q.top().tmp_index || dist_table[Q.top().tmp_index][i] == BIG_NUM)continue;

				next_index = i;

				if(data[next_index].ch >= '0' && data[next_index].ch <= '9'){

					if((Q.top().state & (1 << (data[next_index].ch-'0')))){ //取得済

						next_state = Q.top().state;
						next_last_item = Q.top().last_item;
						next_cost = Q.top().sum_dist+dist_table[Q.top().tmp_index][next_index];
						next_value = Q.top().sum_value;

					}else{ //不所持

						//取得する
						next_state = Q.top().state+POW[data[next_index].ch-'0'];
						next_last_item = data[next_index].ch-'0';
						next_cost = Q.top().sum_dist+dist_table[Q.top().tmp_index][next_index];
						next_value = Q.top().sum_value+table[Q.top().last_item][next_last_item];

						if(min_cost[next_last_item][next_state][next_index] > next_cost){

							min_cost[next_last_item][next_state][next_index] = next_cost;
							max_value[next_last_item][next_state][next_index] = next_value;
							Q.push(Info(next_index,next_state,next_last_item,next_cost,next_value));

						}else if(min_cost[next_last_item][next_state][next_index] == next_cost && max_value[next_last_item][next_state][next_index] < next_value){

							max_value[next_last_item][next_state][next_index] = next_value;
							Q.push(Info(next_index,next_state,next_last_item,next_cost,next_value));

						}

						//取得しない
						next_state = Q.top().state;
						next_last_item = Q.top().last_item;
						next_cost = Q.top().sum_dist+dist_table[Q.top().tmp_index][next_index];
						next_value = Q.top().sum_value;

					}

				}else if(data[next_index].ch >= 'A' && data[next_index].ch <= 'J'){ //該当するアイテムを不所持なら入れる

					if((Q.top().state & (1 << (data[next_index].ch-'A'))))continue;

					next_state = Q.top().state;
					next_last_item = Q.top().last_item;
					next_cost = Q.top().sum_dist+dist_table[Q.top().tmp_index][next_index];
					next_value = Q.top().sum_value;

				}else if(data[next_index].ch >= 'a' && data[next_index].ch <= 'j'){ //該当するアイテムを持っているなら入れる

					if((Q.top().state & (1 << (data[next_index].ch-'a')))){

						//Do nothing

					}else{
						continue;
					}

					next_state = Q.top().state;
					next_last_item = Q.top().last_item;
					next_cost = Q.top().sum_dist+dist_table[Q.top().tmp_index][next_index];
					next_value = Q.top().sum_value;

				}else{ //goalかスタート

					next_state = Q.top().state;
					next_last_item = Q.top().last_item;
					next_cost = Q.top().sum_dist+dist_table[Q.top().tmp_index][next_index];
					next_value = Q.top().sum_value;
				}

				if(min_cost[next_last_item][next_state][next_index] > next_cost){

					min_cost[next_last_item][next_state][next_index] = next_cost;
					max_value[next_last_item][next_state][next_index] = next_value;
					Q.push(Info(next_index,next_state,next_last_item,next_cost,next_value));

				}else if(min_cost[next_last_item][next_state][next_index] == next_cost && max_value[next_last_item][next_state][next_index] < next_value){

					max_value[next_last_item][next_state][next_index] = next_value;
					Q.push(Info(next_index,next_state,next_last_item,next_cost,next_value));

				}
			}

			Q.pop();
		}
	}

	if(ans_dist == BIG_NUM){

		printf("-1\n");

	}else{

		printf("%d %d\n",ans_dist,ans_value);
	}

	return 0;
}

