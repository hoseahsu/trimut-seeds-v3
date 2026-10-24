#include<iostream>
using namespace std;
int sum[2001];
int main()
{
	for(int i = 0; i < 1001; ++i)
	{
		for(int j = 0; j < 1001; ++j)
		{
			sum[i+j]++;
		}
	}
	int n;
	while(cin>>n) 
	{
		long long ans=0;
		for(int i = 0; i <= 1000; ++i)
		{
			for(int j = 0; j <= 1000; ++j)
			{
				if(n-i-j>2001) continue;
				if(n-i-j<0) break;
				ans+=sum[n-i-j];
			}
		}
		cout<<ans<<endl;
	}
  return 0;
}