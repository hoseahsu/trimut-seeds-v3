#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE  1005

int N,K;
ll dp[2][SIZE][SIZE];
ll MID[2][SIZE][SIZE];
ll A[SIZE];


int main(){

	scanf("%d %d",&N,&K);

	for(int i = 0; i < N; i++){

		scanf("%lld",&A[i]);
	}

	sort(A,A+N);

	int CURRENT = 0,NEXT = 1;

	for(int left = 0; left <= N-1; left++){
		for(int right = left; right <= N-1; right++){

			if(left == right){

				dp[CURRENT][left][right] = 0;

			}else{

				dp[CURRENT][left][right] = HUGE_NUM;
			}
		}
	}

	ll ans = HUGE_NUM;
	int right,L,R;

	for(int height = 1; height <= K; height++){

		for(int left = 0; left <= N-1; left++){
			for(int right = left; right <= N-1; right++){

				if(left == right){

					MID[CURRENT][left][right] = left;
					dp[NEXT][left][right] = dp[CURRENT][left][right];

				}else{

					dp[NEXT][left][right] = HUGE_NUM;
				}
			}
		}

		for(int length = 2; length <= N; length++){
			for(int left = 0; left+length-1 <= N-1; left++){

				right = left+length-1;

				L = MID[CURRENT][left][right-1];
				R = MID[CURRENT][left+1][right];

				for(int mid = L; mid <= R; mid++){

					if(dp[NEXT][left][right] > dp[CURRENT][left][mid]+dp[CURRENT][mid+1][right]+(A[right]-A[mid])){
						dp[NEXT][left][right] = dp[CURRENT][left][mid]+dp[CURRENT][mid+1][right]+(A[right]-A[mid]);
						MID[CURRENT][left][right] = mid;
					}
				}
			}
		}

		ans = min(ans,dp[NEXT][0][N-1]);

		swap(CURRENT,NEXT);
	}

	printf("%lld\n",ans);

	return 0;
}

