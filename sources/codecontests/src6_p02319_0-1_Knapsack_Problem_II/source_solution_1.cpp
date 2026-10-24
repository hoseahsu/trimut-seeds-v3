#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;
long long int INF = 1e18;

long long int DP[20000];

int main()
{
	long long int N, W;
	cin >> N >> W;
	
	for(int i = 0; i < 20000; i++){
		DP[i] = INF;
	}
	DP[0] = 0;
	
	for(int i = 0; i < N; i++){
		long long int v, w;
		cin >> v >> w;
		for(int j = 20000; j >= v; j--){
			DP[j] = min(DP[j], DP[j - v] + w);
		}
	}
	
	long long int ans = 0;
	for(int i = 0; i < 20000; i++){
		if(DP[i] <= W){
			ans = i;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
