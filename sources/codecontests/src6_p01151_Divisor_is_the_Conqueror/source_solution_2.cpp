#include <iostream>
#include <cstring>
using namespace std;

int n,c,crs[14],ans[52];

bool dfs(int s, int t)
{
	if(s==0) return true;

	for(int i=13; i>=1; i--)
	{
		if(crs[i])
		if((s-i)%i == 0)
		{
			ans[t]=i;
			crs[i]--;
			if(dfs(s-i,t+1))
			{
				return true;
			}
			crs[i]++;
		}
	}
	return false;
}

int main()
{
	while(cin >> n, n)
	{
		int s=0;
		memset(crs,0,sizeof(crs));
		for(int i=0; i<n; i++)
		{
			cin >> c;
			s+=c; crs[c]++;
		}

		if(dfs(s,0))
		{
			for(int i=n-1; i>=0; i--)
			{
				cout << ans[i] << (i ? " ":"\n");
			}
		}
		else
		{
			cout << "No" << endl;
		}
	}
}