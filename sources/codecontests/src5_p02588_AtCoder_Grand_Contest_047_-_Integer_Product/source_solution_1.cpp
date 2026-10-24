#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 2e5+5;
int n,sum[30][50][100];//ten&five&two
double d;ll ans;
signed main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int tens=0;
		ll x=0;bool ok=false;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='.')ok=true;
			else{
				tens-=ok;
				x=x*10+(s[i]-'0');
			}
		}
		int fives=0,twos=0;
		while(x%10==0)x/=10,tens++;
		while(x%5==0)x/=5,fives++;
		while(x%2==0)x/=2,twos++;
		
		for(int j=0;j<25;j++)
		{
			for(int k=0;k<40;k++)
			{
				if((ll)j-10+tens+min(twos,k)>=0)
				{
					ans+=sum[j][k][0];
				}
			}
			for(int k=0;k<70;k++)
			{
				if((ll)j-10+tens+min(fives,k)>=0)
				{
					ans+=sum[j][0][k];
				}
			}
			if((ll)j-10+tens>=0)ans-=sum[j][0][0];
		}
		sum[tens+10][fives][twos]++;
	}
	cout<<ans<<"\n";
	return 0;
}