#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int land[200][200];
int sea[200][200];

int n;
int R,z[1000];

const int INF = 0x0f0f0f0f;	

int memo[200][1000];
int Solve(int boat, int index)
{
	if(index >= R)
		return 0;
	int &ref = memo[boat][index];
	if(ref >= 0)
		return ref;
	int from = z[index-1];
	int to = z[index];

	ref = land[from][to] + Solve(boat,index+1);

	for(int i=0;i<n;++i)
		ref = min(ref, land[from][boat]+sea[boat][i]+land[i][to] + Solve(i,index+1));
	return ref;
}

int main()
{
	int m,i,j,k;
	int x,y,t;
	char c;
	while(scanf("%d%d",&n,&m),n)
	{
		memset(land,INF,sizeof(land));
		memset(sea,INF,sizeof(sea));
		for(i=0;i<n;++i)
		{
			land[i][i]=0;
			sea[i][i]=0;
		}
		while(m--)
		{
			scanf("%d%d%d %c",&x,&y,&t,&c);
			--x,--y;
			if(c=='L')
				land[y][x]=land[x][y] = min(land[y][x],t);
			else
				sea[y][x]=sea[x][y] = min(sea[y][x],t);
		}
		scanf("%d",&R);
		for(i=0; i<R; ++i)
		{
			scanf("%d",z+i);
			--z[i];
		}

		for(k=0;k<n;++k)
			for(i=0;i<n;++i)
				for(j=0;j<n;++j)
				{
					land[i][j]=min(land[i][j],land[i][k]+land[k][j]);
					sea[i][j] = min(sea[i][j],sea[i][k] +sea[k][j]);
				}

		memset(memo,-1,sizeof(memo));
		printf("%d\n",Solve(z[0],1));
	}
	return 0;
}