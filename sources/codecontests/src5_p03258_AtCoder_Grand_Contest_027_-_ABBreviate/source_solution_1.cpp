#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int n,f[100010],la[100010],sla[100010][3],sum[100010],ans,fir;
char s[100010];

int main()
{
	scanf("%s",s+1),n=strlen(s+1),sum[0]=0;
	for (int i=1; i<=n; i++) sum[i]=(sum[i-1]+(s[i]-'a'+1))%3;
	sla[0][0]=0,sla[0][1]=sla[0][2]=-1;
	for (int i=1; i<=n; i++)
		memcpy(sla[i],sla[i-1],sizeof(sla[i])),sla[i][sum[i]]=i;
	la[0]=la[1]=-1;
	for (int i=2; i<=n; i++)
		if (s[i]==s[i-1]) la[i]=i-1;
		else la[i]=la[i-1];
	if (la[n]==-1) return puts("1"),0;
	f[n+1]=1;
	for (int nw,i=n; i; i--)
	{
		f[i]=(f[i]+f[i+1]>=mod?f[i]+f[i+1]-mod:f[i]+f[i+1]);
		if ((nw=la[i])!=-1)
		{
			nw=sla[nw][(sum[i]-((s[i]-'a')^1)+5)%3];
			if (nw!=-1) f[nw+1]=(f[nw+1]+f[i+1]>=mod?f[nw+1]+f[i+1]-mod:f[nw+1]+f[i+1]);
		}
	}
	ans=0;
	for (int i=1; i<=n; i++) if (sum[i-1]==0) 
		ans=(ans+f[i]>=mod?ans+f[i]-mod:ans+f[i]);
	return printf("%d\n",ans),0;
}