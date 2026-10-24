#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=100005;
int n,q;
int a[maxn];
int flag[maxn];
int find1(int x)
{
    if(flag[x])
        return x;
    else
        return find1(a[x]);
}
int main()
{
    while (scanf("%d%d",&n,&q)!=EOF&&(n||q))
    {
        memset (flag,0,sizeof(flag));
        for (int i=1;i<=n;i++)
                a[i]=i;
        for (int i=2;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        long long int sum=0;
        flag[1]=1;
        for (int i=0;i<q;i++)
        {
            char s[3];
            int xx;
            scanf("%s",s);
            scanf("%d",&xx);
            if(s[0]=='Q')
            {
                sum+=find1(xx);
            }
            else
            {
                flag[xx]=1;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}

