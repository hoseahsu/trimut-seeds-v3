#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <utility>
using namespace std;

int main(){
	int m, n;
	pair<int, int> p1[202];
	pair<int, int> p2[1002];
	while(cin >> m, m){
		fill(p1, p1+202, make_pair(-1, -1));
		fill(p2, p2+1002, make_pair(-1, -1));
		for(int i = 0;i < m;i++)cin >> p1[i].first >> p1[i].second;
		cin >> n;
		for(int i = 0;i < n;i++)cin >> p2[i].first >> p2[i].second;
		
		sort(p1, p1+m);
		sort(p2, p2+n);
		pair<int, int> t;
		int ans[3] = {0, 0, 0};
		for(int i = 0;i < n;i++){
			ans[0] = 0;
			for(int j = 1;j < m;j++){
				t.first = p2[i].first+(p1[j].first-p1[0].first);
				t.second = p2[i].second+(p1[j].second-p1[0].second);
				ans[0] += binary_search(p2, p2+n, t);
			}
			if(ans[0] == m-1){
				ans[1] = p2[i].first - p1[0].first;
				ans[2] = p2[i].second - p1[0].second;
			}
			
		}
		cout << ans[1] << " " << ans[2] << endl;
	}
	return 0;
}