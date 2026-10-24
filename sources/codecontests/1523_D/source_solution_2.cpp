#include<map>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=200000+10;
long long p[maxn];
int n,m,pp;
char s[100];
int cnt[maxn],dnt[maxn];

int main()
{
    srand(time(0));
    scanf("%d%d%d",&n,&m,&pp);
    for (int i=0;i<n;i++)
    {
        scanf("%s",s);
        for (int j=0;j<m;j++)
        if (s[j]=='1')
            p[i]+=(1LL<<j);
    }
    long long best=0;
    long long res=0;
    for (int w=0;w<60;w++)
    {
        int idx=(long long)rand()*rand()%n;
        int u[100],uu[100];
        int v=0;
        for (int i=0;i<m;i++)
        if (p[idx]&(1LL<<i))
        {
            uu[v]=i;
            u[i]=v++;
        }
        if (v<=res) continue;
        for (int i=0;i<(1<<pp);i++) cnt[i]=dnt[i]=0;
        for (int i=0;i<n;i++)
        {
            long long tmp=p[idx]&p[i];
            long long mask=0;
            int k=0;
            for (int j=0;j<m;j++)
            if (tmp&(1LL<<j))
            {
                mask+=(1LL<<u[j]);
                k++;
            }
            if (k<=res) continue;
            cnt[mask]++;
        }
        for (int i=(1<<v)-1;i>=0;i--)
        if (cnt[i]+dnt[i])
        {
            int k=0;
            for (int j=0;j<v;j++)
            if (i&(1<<j)) k++;
            if (k<=res) continue;
            if ((cnt[i]+dnt[i])*2>=n) 
            {
                res=k;
                best=0;
                for (int j=0;j<v;j++)
                if (i&(1<<j)) best += (1LL<<uu[j]);
            }
            if (!cnt[i]) continue;
            for (int j=i;j;j=(j-1)&i)
                dnt[j]+=cnt[i];
        }
    }
            
    for (int i=0;i<m;i++)
    if(best&(1LL<<i)) printf("1");
    else printf("0");
    printf("\n");
        
    
	return 0;
}