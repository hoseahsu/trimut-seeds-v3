#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
long long n,m,i,j,f[5005][5005],sum;
int main(){
	n=read();m=read();
	f[0][m]=1;
	for(i=1;i<=n;i++){
		sum=0;
		for(j=m;j>=1;j--){
			f[i][j]=(sum*j+f[i-1][j]*(j+1))%mo;
			sum=(sum*2+f[i-1][j])%mo;
		}
	}
	sum=0;
	for(i=1;i<=m;i++)
		sum=(sum+f[n][i])%mo;
	pus(sum,2);
    return 0;
}
