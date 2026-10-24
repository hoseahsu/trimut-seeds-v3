#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define M 500005
int n,A,B,C,D;
int main(){
	scanf("%d %d %d %d %d",&n,&A,&B,&C,&D);
	int m=n-1;
	for(int i=0;i<=m;i++){//加 
		int j=m-i;
		ll xia=A+1ll*i*C-1ll*j*D;
		ll shang=A+1ll*i*D-1ll*j*C;
		if(B>=xia&&B<=shang){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}