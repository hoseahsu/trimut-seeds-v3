#include <iostream>
#include <vector>

using namespace std;
const int INF = 1000000000;

int dp[51][51][51];

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), c(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i] >> c[i];
	}
	for(int i = 0; i < 51; ++i){
		for(int j = 0; j < 51; ++j){
			for(int k = 0; k < 51; ++k){ dp[i][j][k] = -INF; }
		}
	}
	dp[0][0][0] = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= m; ++j){
			for(int k = 0; k <= 8; ++k){
				int prev = dp[i][j][k];
				for(int l = 0; l <= 8 && l + j <= m; ++l){
					int add = c[i];
					if(l > 0){
						add = max(add, a[i] * l);
						add = max(add, a[i]);
					}
					if(k > 0){
						add = max(add, b[i] * k);
						add = max(add, b[i]);
					}
					if(l + k > 0){
						add = max(add, a[i] * l + b[i] * min(8 - l, k));
						add = max(add, a[i] * min(8 - k, l) + b[i] * k);
					}
					dp[i + 1][j + l][l] =
						max(dp[i + 1][j + l][l], prev + add);
				}
			}
		}
	}
	int answer = -INF;
	for(int i = 0; i <= m; ++i){
		for(int j = 0; j <= m; ++j){
			answer = max(answer, dp[n][i][j]);
		}
	}
	cout << answer << endl;
	return 0;
}