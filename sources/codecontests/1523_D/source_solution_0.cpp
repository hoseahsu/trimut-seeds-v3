#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string.h>
#include <string>
#include <math.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int arr[200100][65];
int cnt[33010];
int dp[33010];

int popcnt(int msk){
	int ret = 0;
	while (msk > 0){
		ret++;
		msk -= (msk & -msk);
	}
	return ret;
}


int main()
{
	int n, m, p;
	int maxv = -1;
	string ans;

	scanf("%d %d %d", &n, &m, &p);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%1d", &arr[i][j]);
		}
	}

	srand(time(NULL));
	for (int t = 0; t < 50; t++){
		int idx = (rand() * 30000 + rand()) % n;
		vector<int> curr;
		int siz = 0;

		for (int j = 0; j < m; j++){
			if (arr[idx][j]){
				curr.push_back(j);
				siz++;
			}
		}

		memset(cnt, 0, sizeof(cnt));
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < n; i++){
			int msk = 0;
			for (int j = 0; j < siz; j++){
				if (arr[i][curr[j]]) msk += (1 << j);
			}
			cnt[msk]++;
		}


		for (int msk = 0; msk < (1 << siz); msk++){
			for (int smsk = msk;; smsk = ((smsk - 1) & msk)){
				dp[smsk] += cnt[msk];
				if (smsk == 0) break;
			}
		}
		for (int smsk = 0; smsk < (1 << siz); smsk++){
			if (dp[smsk] >= (n + 1) / 2){
				if (maxv < popcnt(smsk)){
					string now = string(m, '0');
					for (int j = 0; j < siz; j++){
						if (smsk & (1 << j)){
							now[curr[j]] = '1';
						}
					}
					maxv = popcnt(smsk);
					ans = now;
				}
			}
		}
	}
	printf("%s\n", ans.c_str());
	return 0;
}
