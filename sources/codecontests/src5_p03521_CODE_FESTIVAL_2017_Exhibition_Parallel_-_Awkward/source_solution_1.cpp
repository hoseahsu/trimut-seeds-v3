#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define x first
#define y second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

const int N=2010;
const int mod=1000000007;
const int inv2=(mod+1)/2;

vi e[2010];

int dp[2010][2010][3],size[2010];
int fac[2010],pow2[2010];

template <class T>
void read(T &x)
{
	char ch;
	for (ch=getchar();(ch<'0'||ch>'9')&&ch!='-';) ch=getchar();
	x=0;int t=1;if (ch=='-') {ch=getchar();t=-1;}
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	x*=t;
}

void dfs(int k)
{
	dp[k][1][0]=1;size[k]=1;
	for (vi::iterator p=e[k].begin();p!=e[k].end();p++)
	{
		dfs(*p);
		for (int j=size[k];j;j--)
			for (int x=2;x>=0;x--)
			{
				for (int l=1;l<=size[*p];l++)
				{
					if (x<2)
						for (int y=0;y<2;y++)
							dp[k][j+l-1][x+1]=(ll(dp[k][j][x])*dp[*p][l][y]+dp[k][j+l-1][x+1])%mod;
					for (int y=0;y<=2;y++)
					{
							dp[k][j+l][x]=(ll(dp[k][j][x])*dp[*p][l][y]%mod*(y==0 ? inv2 : 1)+dp[k][j+l][x])%mod;
							//if (k==2) printf("%d %d %d %d %d\n",dp[2][2][0],j,x,l,y);
					}
				}
				dp[k][j][x]=0;
			}
		size[k]+=size[*p];
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
	#endif
	int n;scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		int x;scanf("%d",&x);e[x].pb(i);
	}
	memset(dp,0,sizeof(dp));
	dfs(1);
	fac[0]=1;for (int i=1;i<=n;i++) fac[i]=ll(fac[i-1])*i%mod;
	pow2[0]=1;for (int i=1;i<=n;i++) pow2[i]=pow2[i-1]*2%mod;
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=2;j++)
		{
			int t=ll(fac[i])*pow2[i]%mod*dp[1][i][j]%mod*(j==0 ? inv2 : 1)%mod;
			if ((n-i)&1) ans=(ans-t+mod)%mod; else ans=(ans+t)%mod;
		}
	printf("%d\n",ans);
	return 0;
}

