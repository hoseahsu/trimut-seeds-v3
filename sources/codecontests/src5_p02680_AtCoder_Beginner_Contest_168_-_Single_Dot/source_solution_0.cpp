#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int N,M;
int A[1000],B[1000],C[1000];
int D[1000],E[1000],F[1000];
bool vis[3010][3010];
vector<pair<int,int> >WX[3010],WY[3010];
bool wx[3010][3010],wy[3010][3010];
int main()
{
	cin>>N>>M;
	vector<long>X,Y;
	X.push_back((long)-2e9);
	X.push_back(0);
	X.push_back((long)2e9);
	Y.push_back((long)-2e9);
	Y.push_back(0);
	Y.push_back((long)2e9);
	for(int i=0;i<N;i++)
	{
		cin>>A[i]>>B[i]>>C[i];
		X.push_back(A[i]);
		X.push_back(B[i]);
		Y.push_back(C[i]);
	}
	for(int i=0;i<M;i++)
	{
		cin>>D[i]>>E[i]>>F[i];
		X.push_back(D[i]);
		Y.push_back(E[i]);
		Y.push_back(F[i]);
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());
	for(int i=0;i<N;i++)
	{
		A[i]=lower_bound(X.begin(),X.end(),A[i])-X.begin();
		B[i]=lower_bound(X.begin(),X.end(),B[i])-X.begin();
		C[i]=lower_bound(Y.begin(),Y.end(),C[i])-Y.begin();
		WX[C[i]].push_back(make_pair(A[i],B[i]));
	}
	for(int i=0;i<M;i++)
	{
		D[i]=lower_bound(X.begin(),X.end(),D[i])-X.begin();
		E[i]=lower_bound(Y.begin(),Y.end(),E[i])-Y.begin();
		F[i]=lower_bound(Y.begin(),Y.end(),F[i])-Y.begin();
		WY[D[i]].push_back(make_pair(E[i],F[i]));
	}
	WX[0].push_back(make_pair(0,X.size()+1));
	WX[Y.size()].push_back(make_pair(0,X.size()+1));
	for(int i=0;i<=Y.size();i++)
	{
		sort(WX[i].begin(),WX[i].end());
		for(int j=0;j<WX[i].size();)
		{
			int L=WX[i][j].first,R=WX[i][j].second;
			while(j<WX[i].size()&&WX[i][j].first<=R)
			{
				R=max(R,WX[i][j].second);
				j++;
			}
			for(int k=L;k<R;k++)wx[i][k]=true;
		}
	}
	WY[0].push_back(make_pair(0,Y.size()+1));
	WY[X.size()].push_back(make_pair(0,Y.size()+1));
	for(int i=0;i<=X.size();i++)
	{
		sort(WY[i].begin(),WY[i].end());
		for(int j=0;j<WY[i].size();)
		{
			int L=WY[i][j].first,R=WY[i][j].second;
			while(j<WY[i].size()&&WY[i][j].first<=R)
			{
				R=max(R,WY[i][j].second);
				j++;
			}
			for(int k=L;k<R;k++)wy[i][k]=true;
		}
	}
	queue<pair<int,int> >P;
	vector<int>sx,sy;
	{
		int id=lower_bound(X.begin(),X.end(),0)-X.begin();
		sx.push_back(id-1);
		sx.push_back(id);
	}
	{
		int id=lower_bound(Y.begin(),Y.end(),0)-Y.begin();
		sy.push_back(id-1);
		sy.push_back(id);
	}
	for(int x:sx)for(int y:sy)
	{
		vis[x][y]=true;
		P.push(make_pair(x,y));
	}
	while(!P.empty())
	{
		int x=P.front().first,y=P.front().second;
		P.pop();
		if(!wy[x][y]&&!vis[x-1][y])
		{
			vis[x-1][y]=true;
			P.push(make_pair(x-1,y));
		}
		if(!wx[y][x]&&!vis[x][y-1])
		{
			vis[x][y-1]=true;
			P.push(make_pair(x,y-1));
		}
		if(!wy[x+1][y]&&!vis[x+1][y])
		{
			vis[x+1][y]=true;
			P.push(make_pair(x+1,y));
		}
		if(!wx[y+1][x]&&!vis[x][y+1])
		{
			vis[x][y+1]=true;
			P.push(make_pair(x,y+1));
		}
	}
	long long ans=0;
	for(int i=0;i<X.size();i++)for(int j=0;j<Y.size();j++)
	{
		if(!vis[i][j])continue;
		if(i==0||j==0||i+1==X.size()||j+1==Y.size())
		{
			cout<<"INF"<<endl;
			return 0;
		}
		ans+=(X[i+1]-X[i])*(Y[j+1]-Y[j]);
	}
	cout<<ans<<endl;
}
