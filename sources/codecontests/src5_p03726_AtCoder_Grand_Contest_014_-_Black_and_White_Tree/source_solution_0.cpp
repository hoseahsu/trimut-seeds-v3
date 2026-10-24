#include<bits/stdc++.h>
#define N 200005
using namespace std;
vector<int> G[N];
int n,d[N];
void GG(){ printf("First"); exit(0);}
int dfs(int t,int fa)
{
	int i,cnt=0;
	for(i=0;i<G[t].size();i++)
		if(G[t][i]!=fa)
			cnt+=dfs(G[t][i],t);
	if(cnt>=2) GG();
	if(cnt==1) return 0;
	else return 1;
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
		d[x]++,d[y]++;
	  }
	if(n==2){
		printf("Second");
		return 0;
	  }
	for(i=n;i>=1;i--)
		if(d[i]>1) break;
	dfs(i,0);
	printf("Second");
	return 0;
}
