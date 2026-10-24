#include<iostream>
#include<algorithm>
using namespace std;
int N,K,A[20];
int S[1<<20];
bool exs[1<<20];
int main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>A[i];
	int ans=0;
	for(int i=0;i<1<<N;i++)
	{
		for(int j=0;j<N;j++)if(i>>j&1)S[i]+=A[j];
		exs[i]=S[i]==K;
		for(int j=0;j<N;j++)
		{
			if(i>>j&1)exs[i]|=exs[i&~(1<<j)];
		}
		if(!exs[i])ans=max(ans,__builtin_popcount(i));
	}
	cout<<N-ans<<endl;
}

