#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 262150
#define inf 2147483647
using namespace std;
struct pos1{int l, r;}pos[N][19];
int n, m, k, w[N], now, dp_l[N], dp_r[N], bin[19], x, ff, sum;
int main(){
	scanf("%d%d", &n, &m);
	bin[0]=1; for(int i=1; i<=18; i++)bin[i]=bin[i-1]<<1;
	for(int i=1; i<=n; i++)scanf("%d", &w[i]); w[0]=w[1]-m-1; w[n+1]=w[n]+m+1;
	k=-1; x=m<<1;
	while(x){
		k++; x>>=1; now=0;
		for(int i=1; i<=n; i++){
			if(w[i]-w[i-1]>x)now=i;
			pos[i][k].l=now;
		}
		pos[n+1][k].r=n;
		now=n+1;
		for(int i=n; i; i--){
			if(w[i+1]-w[i]>x)now=i;
			pos[i][k].r=now;
		}
		pos[0][k].l=1;
	}
	dp_l[0]=0; dp_r[0]=n+1;
	for(int i=1; i<=bin[k]-1; i++){
		dp_l[i]=0; dp_r[i]=n+1;
		for(int j=1; j<=k; j++)if(i&bin[j-1]){
			dp_l[i]=max(dp_l[i], pos[dp_l[i-bin[j-1]]+1][j].r);
			dp_r[i]=min(dp_r[i], pos[dp_r[i-bin[j-1]]-1][j].l);
		}
	}
	sum=0; for(int i=1; i<=n; i++)if(pos[i][0].l==i)sum++;
	if(sum>=k+2){for(int i=1; i<=n; i++)printf("Impossible\n"); return 0;}
	for(int i=1; i<=n; i++)if(pos[i][0].l==i){
		ff=0;
		for(int j=0; j<=bin[k]-1; j++)if(dp_l[j]>=pos[i][0].l-1&&dp_r[bin[k]-1-j]<=pos[i][0].r+1){ff=1; break;}
		for(int j=pos[i][0].l; j<=pos[i][0].r; j++)if(ff)printf("Possible\n"); else printf("Impossible\n");
	}
	return 0;
}