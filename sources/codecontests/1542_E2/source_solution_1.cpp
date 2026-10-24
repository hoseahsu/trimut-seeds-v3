#include <bits/stdc++.h>

using namespace std;

long long n,mod;
const long long B=130000;
long long w[2][2*B+5], s[2][2*B+5];
long long ans[505];

int main()
{
    cin>>n>>mod;

    w[0][B]=s[0][B]=1;
    for(long long i=B;i<=2*B;i++)
        s[0][i]=1;

    for(long long i=1;i<=n;i++)
    {
        long long curs=1;
        long long I=i&1;
        long long J=I^1;

        memset(w[I], 0, sizeof(w[I]));
        memset(s[I], 0, sizeof(s[I]));

        for(long long u=i*(i-1)/2, j=-u+B; j<=u+B; j++)
        {
            w[I][j]=curs;
            curs=(curs-s[J][j]+s[J][j-i]+s[J][j+i]-s[J][j]+2*mod)%mod;
        }

        for(long long j=B-i*(i-1)/2; j<=(i+2)*(i+1)/2+B; j++)
            s[I][j]=(s[I][j-1]+w[I][j])%mod;

        for(long long j=1;j<i;j++)
            ans[i]=(ans[i]+(s[J][(i+1)*i/2+B]-s[J][j+B]+mod)%mod*(i-j))%mod;
    }

    for(long long i=2;i<=n;i++)
    {
        ans[i]+=(ans[i-1]*i)%mod;
        ans[i]%=mod;
    }

    cout<<ans[n];
    return 0;
}
