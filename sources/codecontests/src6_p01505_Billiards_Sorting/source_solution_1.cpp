#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef long long ll;

//        0
//      1  2
//     3  4  5
//   6  7  8  9
// 10 11 12 13 14

// nei[i] := ( マス i と隣接するマス )
const int nei[15][4]={
	{ 1, 2,-1,-1},
	{ 0, 3, 4,-1},
	{ 0, 4, 5,-1},
	{ 1, 6, 7,-1},
	{ 1, 2, 7, 8},
	{ 2, 8, 9,-1},
	{ 3,10,11,-1},
	{ 3, 4,11,12},
	{ 4, 5,12,13},
	{ 5,13,14,-1},
	{ 6,-1,-1,-1},
	{ 6, 7,-1,-1},
	{ 7, 8,-1,-1},
	{ 8, 9,-1,-1},
	{ 9,-1,-1,-1}
};

int dist[15][15]; // dist[i][j] := ( マス i にある数字をマス j に移動するための最短手数 )

int n,a[15];

int hstar(int now){
	int sum=0;
	rep(i,n) if(a[i]!=0) sum+=dist[a[i]][i];
	return now+sum;
}

int ub;
bool dfs(int now,int p,int pre,int end){
	if(end==n) return true;

	if(hstar(now)>ub) return false;

	// rep(k,4){
	for(int k=3;k>=0;k--){ // 逆順に調べた方が 10 秒くらい速い ( テストケースの特性?? )
		int q=nei[p][k];
		if(q==-1 || q>=n || q==pre) continue; // 直前の状態には遷移しない
		swap(a[p],a[q]);
		int end2=end-(a[q]==p?1:0)-(a[p]==q?1:0)+(a[p]==p?1:0)+(a[q]==q?1:0);
		if(dfs(now+1,q,p,end2)) return true;
		swap(a[p],a[q]);
	}
	return false;
}

int main(){
	rep(i0,15){
		rep(i,15) dist[i0][i]=77;
		dist[i0][i0]=0;
		int Q[32],head=0,tail=0; Q[tail++]=i0;
		while(head<tail){
			int i=Q[head++];
			rep(k,4){
				int j=nei[i][k];
				if(j!=-1 && dist[i0][j]==77) dist[i0][j]=dist[i0][i]+1, Q[tail++]=j;
			}
		}
	}

	for(int cas=1;scanf("%d",&n),n;cas++){
		n=n*(n+1)/2;
		rep(i,n) scanf("%d",a+i), a[i]--;

		int end=0; // 揃っている数字の個数
		rep(i,n) if(a[i]==i) end++;

		int p=find(a,a+15,0)-a;
		int h=(1<=p&&p<=2||6<=p&&p<=9?1:0); // 1 のある行 mod 2
		for(ub=h;ub<45;ub+=2) if(dfs(0,p,-1,end)) break;
		printf("Case %d: %d\n",cas,ub);
	}

	return 0;
}