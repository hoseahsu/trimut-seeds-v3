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

// nei[i] := ( テ」ツδ榲」ツつケ i テ」ツ?ィテゥツ堋」テヲツ篠・テ」ツ?凖」ツつ凝」ツδ榲」ツつケ )
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

int dist[15][15]; // dist[i][j] := ( テ」ツδ榲」ツつケ i テ」ツ?ォテ」ツ?づ」ツつ凝ヲツ閉ーテ・ツュツ療」ツつ津」ツδ榲」ツつケ j テ」ツ?ォテァツァツサテ・ツ仰陛」ツ?凖」ツつ凝」ツ?淌」ツつ?」ツ?ョテヲツ慊?ァツ淞ュテヲツ可凝ヲツ閉ー )

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
	for(int k=3;k>=0;k--){ // テゥツ??ゥツ??」ツ?ォティツェツソテ」ツ?ケテ」ツ?淌ヲツ鳴ケテ」ツ??10 テァツァツ津」ツ?湘」ツつ嘉」ツ??ゥツ?淌」ツ??( テ」ツδ?」ツつケテ」ツδ暗」ツつアテ」ツδシテ」ツつケテ」ツ?ョテァツ可ケテヲツ?ァ?? )
		int q=nei[p][k];
		if(q==-1 || q>=n || q==pre) continue; // テァツ崢エテ・ツ可催」ツ?ョテァツ環カテヲツ?凝」ツ?ォテ」ツ?ッテゥツ?キテァツァツサテ」ツ?療」ツ?ェテ」ツ??
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

		int end=0; // テヲツ渉ε」ツ?」テ」ツ?ヲテ」ツ??」ツつ凝ヲツ閉ーテ・ツュツ療」ツ?ョテ・ツ?凝ヲツ閉ー
		rep(i,n) if(a[i]==i) end++;

		int p=find(a,a+15,0)-a;
		int h=(1<=p&&p<=2||6<=p&&p<=9?1:0); // 1 テ」ツ?ョテ」ツ?づ」ツつ凝ィツ。ツ?mod 2
		for(ub=h;ub<45;ub+=2) if(dfs(0,p,-1,end)) break;
		printf("Case %d: %d\n",cas,ub);
	}

	return 0;
}