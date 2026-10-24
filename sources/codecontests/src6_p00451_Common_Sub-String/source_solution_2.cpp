#include <bits/stdc++.h>
using namespace std;

int dp[4001][4001];
char s[4001],t[4001];

int main(){
	while(scanf("%s%s",s,t) == 2){
		int ans = 0;
		int slen = strlen(s);
		int tlen = strlen(t);
		for(int i = 0; i < slen; i++){
			if(s[i] == t[0]){
				dp[0][i] = 1;
				ans = 1;
			}
			else{
				dp[0][i] = 0;
			}
		}
		for(int i = 0; i < tlen; i++){
			if(t[i] == s[0]){
				dp[i][0] = 1;
				ans = 1;
			}
			else{
				dp[i][0] = 0;
			}
		}

		for(int i = 1; i < tlen; i++){
			for(int j = 1; j < slen; j++){
				if(t[i] == s[j]){
					dp[i][j] = dp[i-1][j-1] + 1;
					ans = max(ans,dp[i][j]);
				}
				else{
					dp[i][j] = 0;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

