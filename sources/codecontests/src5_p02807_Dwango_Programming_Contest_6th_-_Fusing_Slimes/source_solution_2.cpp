//by (111110101)2
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
const long long md=1e9+7;
long long n,a[101010],qian[101010],hou[101010],ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long bf=1;
	qian[1]=1;
	for(int i=2;i<n;i++)
	{
		bf=bf*(i-1);
		bf%=md;
		qian[i]=(qian[i-1]*i+bf)%md;
	}
	hou[n-1]=1;
	for(int i=n-2;i>=0;i--)
	{
		hou[i]=hou[i+1]*(i+1)%md;
	}
	for(int i=1;i<n;i++)
	{
		ans+=(a[i]-a[i-1])*qian[i]%md*hou[i]%md;
		ans%=md;
	}
	cout<<ans<<endl;
	return 0;
}