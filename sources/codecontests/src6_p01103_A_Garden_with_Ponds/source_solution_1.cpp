#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <climits>
//#include "h.h"
using namespace std;

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define pm(first, second) pb(mp(first, second))
#define SPACE " "
#define fpf first.first
#define fps first.second
#define spf second.first
#define sps second.second

#define all(X) (X).begin(), (X).end()

int main(){

	while(true){
		int d, w;
		cin >> d >> w;
		if(d == 0 && w == 0)break;
		vector<vector<int>> ELEV(d, vector<int>(w));
		for(int i = 0; i < d; i ++){
			for(int j = 0; j < w; j ++){
				cin >> ELEV[i][j];
			}
		}
		int ans = 0;
		for(int d1 = 0; d1 < d - 2; d1 ++){
		for(int w1 = 0; w1 < w - 2; w1 ++){
			for(int d2 = d1 + 2; d2 < d; d2 ++){
			for(int w2 = w1 + 2; w2 < w; w2 ++){
				int edgeMin = 100;
				for(int i = w1; i <= w2; i ++){
					edgeMin = min(edgeMin, ELEV[d1][i]);
					edgeMin = min(edgeMin, ELEV[d2][i]);
				}
				for(int i = d1; i <= d2; i ++){
					edgeMin = min(edgeMin, ELEV[i][w1]);
					edgeMin = min(edgeMin, ELEV[i][w2]);
				}
				int tmp = 0;
				bool flag = true;
				for(int i = d1 + 1; i < d2 && flag; i ++){
					for(int j = w1 + 1; j < w2 && flag; j ++){
						if(ELEV[i][j] >= edgeMin){
							flag = false;
							break;
						}
						tmp += edgeMin - ELEV[i][j];
					}
				}
				if(flag)ans = max(ans, tmp);
			}
			}
		}
		}
		cout << ans << endl;
	}

	return 0;
}
