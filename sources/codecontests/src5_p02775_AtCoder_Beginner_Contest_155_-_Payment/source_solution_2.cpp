#include <bits/stdc++.h>

using namespace std;

int n;
char a[1000010];
int b[1000010];

int main(){
	scanf("%s",a);
	n = strlen(a);
	for(int i=n;i>=1;i--){
		b[i]=a[i-1]-'0';
	}
	b[0]=0;

	int ans = 0;
	for(int i=n;i>=0;i--){
		if(b[i]>9){
			b[i] -= 10;
			b[i-1]++;
		}
		if(b[i]<=4)
			ans += b[i];
		else if (b[i]>=6){
			ans += 10-b[i];
			b[i-1]++;
		}else{
			if(b[i-1]<5)ans += b[i];
			else {b[i-1]++;ans += b[i];}
		}
//		printf("%d %d\n",i,ans);
	}
	printf("%d\n",ans);
}