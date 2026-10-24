#include<iostream>
using namespace std;
int x,y;
char ch;
bool bj[5001][5001];
int main()
{
	cin>>x>>y;
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
		{
			cin>>ch;
			bj[i][j]=(ch=='#');
		}
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			if(bj[i][j]==0) cout<<bj[i-1][j]+bj[i+1][j]+bj[i][j-1]+bj[i][j+1]+bj[i-1][j-1]+bj[i+1][j-1]+bj[i-1][j+1]+bj[i+1][j+1]; else cout<<'#';
		}
		cout<<endl;
	}
	return 0;
}