#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int cnt[27],n,k;
string s;
int get(int x){ return (k-x%k)%k; }
int main()
{
	int t; cin >> t;
	while( t-- )
	{
		cin >> n >> k >> s;
		for(int i=0;i<n;i++)	cnt[s[i]-'a']++;
		int sum = 0, flag = 1;
		for(int i=0;i<=25;i++)	sum += get( cnt[i] );
		if( sum==0 )	cout << s << endl;
		else if( n%k!=0 )	cout << -1 << endl;	
		else
		{
			for(int i=n-1;i>=0;i--)
			{
				sum = sum-get( cnt[s[i]-'a'] )+get( --cnt[s[i]-'a'] );
				for(int j=s[i]-'a'+1;j<=25;j++)//ö�ٷ��ĸ���ĸ
				{
					int las = sum;
					sum = sum-get( cnt[j] )+get( ++cnt[j] );
					if( (i+1)+sum<=n )
					{
						for(int pos=0;pos<i;pos++)	cout << s[pos];
						cout << char( j+'a' );
						for(int pos=1;pos<=n-sum-(i+1);pos++)	cout << 'a';
						for(int w=0;w<=25;w++)
						{
							int f = get( cnt[w] );
							while( f )	f--,cout << char( w+'a' );
						}
						cout << endl; flag = 0;
						break;
					}
					cnt[j]--; sum = las;	
				}
				if( flag==0 )	break; 
			}
		}
		memset( cnt,0,sizeof cnt );
	}
}
