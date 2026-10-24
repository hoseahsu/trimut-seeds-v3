#include <bits/stdc++.h>
using namespace std;

int memo[501][501][10][3][2];
// [n桁目][剰余][どの数字を使った]
// [どっちでも、上昇、下降][上限を超えそう/超えない]

char A[1024], B[1024];
int M;
char *str;

int dp(int n, int mod, int use, int updn, int limit)
{
	if (str[n] == '\0')	return mod == 0 && (use || updn);
	
	if (memo[n][mod][use][updn][limit]){
		return memo[n][mod][use][updn][limit];
	}
	
	int res = 0;
	for (int i = 0; i <= 9; i++){
		if ( (limit == 1 || (limit == 0 && i <= str[n] - '0')) && ((updn == 0 && (!use || (use != i))) || ((updn == 1 && i < use) || (updn == 2 && i > use))) ){
			int UPDN = 0;
			if (updn == 0){
				if (use != 0){
					if (i < use) UPDN = 2;
					else UPDN = 1;
				}
			}
			else UPDN = !(updn - 1) + 1;
			
			res += dp(n + 1, (mod * 10 + i) % M, i, UPDN, limit || i < str[n] - '0');
			res %= 10000;
		}
	}
	
	memo[n][mod][use][updn][limit] = res;
	return res;
}
			
int main()
{
	scanf("%s %s %d", A, B, &M);
	
	int p = strlen(A) - 1;
	while (true){
		if (A[p] > '0'){
			A[p]--;
			break;
		}
		else {
			A[p] = '9';
			p--;
		}
	}
	
	str = A;
	int tmp = dp(0, 0, 0, 0, 0);
	str = B;
	memset(memo, 0, sizeof(memo));
	printf("%d\n", (dp(0, 0, 0, 0, 0) - tmp + 10000) % 10000);
	
	return 0;
}