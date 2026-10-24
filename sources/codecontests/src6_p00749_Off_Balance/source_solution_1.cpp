#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<queue>
#define rep(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
using namespace std;

//マクロ
#define H_M 62
#define W_M 13
#define NONE '.'
#define bp(x) block[(x)].h][block[(x)].w
#define bw(x) block[(x)].w
#define bh(x) block[(x)].h

struct P{ int h, w; };
bool judge(const P l, const P r){ return(l.w < r.w); }

//グローバル
int H, W;
char tower[H_M][W_M];
bool used[H_M][W_M];
const P dir[4] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };

//重心が両端の内側にあればfalse
bool calc_weight(int block[],int left,int right){
	double a=0,b = 0;
	rep(i, 0, W_M){
		double x = (double)i + 0.5;
		b += x*block[i];
		a += block[i];
	}
	//cout << b << '/' << a << "=";
	b /= a;
	//cout << b << endl;
	return !((double)left < b&&b < (double)right);
}

//同色判定したブロックをblockに格納 
void bfs(P s, char color,P *block){
	int n = 0;
	queue<P> que;
	que.push(s);
	while (!que.empty()){
		s = que.front(); que.pop();
		if (used[s.h][s.w] == true)continue;
		//cout << "n=" << n << endl;
		used[s.h][s.w] = true;
		block[n++] = s;
		rep(i, 0, 4){
			P p; p.h = s.h + dir[i].h, p.w = s.w + dir[i].w;
			//printf("p:%d,%d|%c\n", p.h, p.w,color);
			if (tower[p.h][p.w] == color&&used[p.h][p.w] == false)
				que.push(p);
		}
	}
	
	sort(block, block + 4, judge);
	return;
}

bool solve(P *block,int *b_num){
	char color = tower[bp(0)];
	char under;
	int left,right,tmp;
//	rep(j, 0, 4)printf("%d,%d|%c\n", bh(j), bw(j), color);
	rep(i, 0, 4)
	if (tower[bh(i) - 1][bw(i)] != color&&tower[bh(i) - 1][bw(i)] != NONE){
		under = tower[bh(i) - 1][bw(i)];
		left = bw(i);
		tmp = i;
		break;
	}
	rep(i, tmp, 4)
	if (tower[bh(i) - 1][bw(i)] == under)right = bw(i) + 1;
	//printf("l=%d,r=%d,now=%c,under=%c\n", left, right, color, under);

	//ここまでデッドライン決め
	P bk[4][4] = { { 0, 0 } };
	
	int block_size = 0;
	rep(i, 0, 4)if (used[bh(i) + 1][bw(i)] == false && tower[bh(i) + 1][bw(i)] != NONE){
		P p = { bh(i) + 1, bw(i) };
		bfs(p, tower[bh(i) + 1][bw(i)], bk[block_size]);
		int x[W_M] = { 0 };
		if (solve(bk[block_size], x))return true;
		block_size++;
		rep(j, 0, W_M)b_num[j] += x[j];
	}
	
	rep(i, 0, 4)b_num[bw(i)]++;
	return(calc_weight(b_num, left, right));

	
}

int main(void){
	while (true){
		cin >> W >> H;
		if (W == 0)return(0);
		memset(used, 0, sizeof(used));
		rep(i, 0, W + 2)tower[0][i] ='0', tower[H + 1][i] = NONE;
		rep(i, 0, H){
			tower[i+1][0] = tower[i + 1][W + 1] = NONE;
			rep(j, 0, W)cin >> tower[H - i][j + 1];
		}
		/*rep(i, 0, H + 2){
			rep(j, 0, W + 2)
				cout << tower[i][j];
				cout << endl;
		}*/
		rep(i, 0, W + 2)if (tower[1][i] != NONE){
			P s = { 1, i };
			P block[4] = { { 0, 0 } };
			bfs(s, tower[1][i], block);
			int x[W_M] = { 0 };
			if(solve(block,x))puts("UNSTABLE");
			else puts("STABLE");
		break;
		}
	}
}