#include<cstdio>
int n,k;
int tab[105];
bool dp[100005];

int main(){

	scanf("%d %d", &n, &k);
	for(int i=0;i<n;i++){
		scanf("%d", &tab[i]);
	}
	for(int i=k-1;i>=0;i--){
		for(int j=0;j<n;j++){
			if(i+tab[j]>k)break;
			if(!dp[i+tab[j]]){
				dp[i]=true; break;
			}
		}
	}
	if(dp[0])printf("First");
	else printf("Second");
}
