#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

struct Info{

	bool operator<(const struct Info &arg) const{

		return base < arg.base;
	}

	int index;
	ll base,digit;
};

struct Query{

	bool operator<(const struct Query &arg) const{

		return loc < arg.loc;
	}

	ll loc;
	int index;
};

int H,W;
ll ans[3*SIZE];
ll POW[18];
ll BIT[SIZE];
ll num_row[SIZE],num_col[SIZE];
ll sum_digit[SIZE];
ll COL_SUM_DIGIT;
Info ROW[SIZE],COL[SIZE];
vector<Query> V_Query,QUERY[SIZE];
vector<Info> V_ROW,V_COL;


//仮数部の桁が増えるかチェックする関数→桁が増えるならtrueを返す
bool increase_digit(Info A,Info B){

	ll tmp = A.base*B.base;

	return tmp >= POW[17];
}

void add(int loc,ll value){

	BIT[loc] += value;

	loc += loc & -loc; //最後の1ビットを足した場所が次の★更新★場所

	while(loc <= W){
		BIT[loc] += value;
		loc += loc & -loc;
	}
}

ll getSum(int loc){

	ll sum = BIT[loc];

	loc -= loc & -loc; //最後の1ビットを引いた場所が次の★加算★場所

	while(loc > 0){
		sum += BIT[loc];
		loc -= loc & -loc;
	}
	return sum;
}

ll calc(int left,int right){ //left～rightの区間の総和を、sum(1～right)-sum(1～left-1)で求める
	return getSum(right)-getSum(left-1);
}

int main(){

	POW[0] = 1;
	for(int i = 1; i < 18; i++){

		POW[i] = POW[i-1]*10;
	}

	scanf("%d %d",&H,&W);

	ll tmp;
	ll num_digit;

	for(int i = 1; i <= H; i++){

		scanf("%lld",&tmp);
		num_row[i] = tmp;

		for(num_digit = 1; ;num_digit++){

			if(POW[num_digit] > tmp)break;
		}

		if(num_digit == 10){ //10億

			ROW[i].base = tmp/10;

		}else{

			ROW[i].base = tmp*POW[9-num_digit];
		}

		ROW[i].digit = num_digit-1;
		ROW[i].index = i;

		V_ROW.push_back(ROW[i]);
	}

	sort(V_ROW.begin(),V_ROW.end());

	COL_SUM_DIGIT = 0; //列の各数の桁の総和

	for(int i = 1; i <= W; i++){

		scanf("%lld",&tmp);
		num_col[i] = tmp;

		for(num_digit = 1; ;num_digit++){

			if(POW[num_digit] > tmp)break;
		}

		if(num_digit == 10){ //10億

			COL[i].base = tmp/10;

		}else{

			COL[i].base = tmp*POW[9-num_digit];
		}

		COL[i].digit = num_digit-1;
		COL[i].index = i;

		COL_SUM_DIGIT += COL[i].digit;

		V_COL.push_back(COL[i]);
	}

	sort(V_COL.begin(),V_COL.end());

	//行ごとの、桁の数を計算する

	sum_digit[0] = 0;

	int L,R,mid;
	ll plus_2,plus_1;

	for(int row = 1; row <= H; row++){

		L = 0,R = W-1,mid = (L+R)/2; //★V_COLに合わせるので0オリジン★
		int left_col = W;

		while(L <= R){

			if(increase_digit(ROW[row],V_COL[mid])){

				left_col = mid;
				R = mid-1; //より左へ

			}else{

				L = mid+1;
			}
			mid = (L+R)/2;
		}

		plus_2 = W-left_col;
		plus_1 = W-plus_2;

		sum_digit[row] = ROW[row].digit*W+COL_SUM_DIGIT+2*plus_2+plus_1;

		if(row == 0)continue;

		sum_digit[row] += sum_digit[row-1];
	}

	int num_query;
	scanf("%d",&num_query);

	for(int i = 0; i < num_query; i++){

		Query query;
		scanf("%lld",&query.loc);
		query.index = i;

		V_Query.push_back(query);
	}

	sort(V_Query.begin(),V_Query.end());

	L = 1;
	int loc_row;

	for(int i = 0; i < num_query; i++){

		if(V_Query[i].loc > sum_digit[H]){

			ans[V_Query[i].index] = -1;
			continue;
		}

		R = H,mid = (L+R)/2;

		//どの行の、どの相対位置かを求める

		while(L <= R){

			if(sum_digit[mid] >= V_Query[i].loc){

				loc_row = mid;
				R = mid-1;

			}else{

				L = mid+1;
			}
			mid = (L+R)/2;
		}

		Query query;
		query.loc = V_Query[i].loc-sum_digit[loc_row-1]; //★1オリジンなので注意★
		query.index = V_Query[i].index;

		QUERY[loc_row].push_back(query);
	}

	for(int i = 0; i <= W; i++)BIT[i] = 0;

	for(int i = 1; i <= W; i++){

		add(i,COL[i].digit+1);
	}


	int pre_left_col = -1;

	stack<ll> S;

	for(int i = 0; i < H; i++){ //行を仮数の昇順に処理

		//仮数の掛け算で繰り上がりする左端を求める

		L = 0,R = W-1,mid = (L+R)/2; //★V_COLに合わせるので0オリジン★
		int left_col = -1;
		int row = V_ROW[i].index;

		while(L <= R){

			if(increase_digit(ROW[row],V_COL[mid])){

				left_col = mid;
				R = mid-1; //より左へ

			}else{

				L = mid+1;
			}
			mid = (L+R)/2;
		}

		if(pre_left_col == -1){

			if(left_col != -1){

				for(int col = left_col; col <= W-1; col++){

					add(V_COL[col].index,1); //本来の位置に加算
				}
			}

		}else{

			if(left_col != -1){

				for(int col = left_col; col < pre_left_col; col++){

					add(V_COL[col].index,1); //本来の位置に加算
				}
			}
		}

		pre_left_col = left_col;

		if(QUERY[row].size() == 0)continue;

		for(int k = 0; k < QUERY[row].size(); k++){

			int l = 1,r = W;
			mid = (l+r)/2;
			int loc_col = -1;

			while(l <= r){

				tmp = calc(1,mid)+ROW[row].digit*mid;

				if(tmp >= QUERY[row][k].loc){

					loc_col = mid;
					r = mid-1;

				}else{

					l = mid+1;
				}
				mid = (l+r)/2;
			}

			ll calc_digit = QUERY[row][k].loc;

			if(loc_col > 1){

				calc_digit -= (calc(1,loc_col-1)+ROW[row].digit*(loc_col-1));
			}

			//numberのcalc_digit桁目
			ll number = num_row[row]*num_col[loc_col];

			while(!S.empty())S.pop();

			while(true){

				S.push(number%10);
				number /= 10;

				if(number == 0)break;
			}

			for(int count = 0; count < calc_digit; count++){

				ans[QUERY[row][k].index] = S.top();
				S.pop();
			}
		}
	}

	for(int i = 0; i < num_query; i++){

		if(ans[i] == -1){

			printf("x");
		}else{

			printf("%lld",ans[i]);
		}
	}

	printf("\n");

	return 0;
}

