#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int D, n, m;
vector<int> d;
vector<int> e;
int ans;

int main(){
	while(1){
		d = e;
		ans = 0;
		scanf("%d", &D);
		if(D == 0) break;
		scanf("%d %d", &n, &m);
		d.push_back(0);
		d.push_back(-D);
		d.push_back(D);
		for(int i=0; i<n-1; i++){
			int t;
			scanf("%d", &t);
			d.push_back(t);
			d.push_back(t-D);
			d.push_back(t+D);
		}
		sort(d.begin(), d.end());

		for(int i=0; i<m; i++){
			int t;
			scanf("%d", &t);
			int u, l;
			u = *upper_bound(d.begin(), d.end(), t) - t;
			l = t - *(lower_bound(d.begin(), d.end(), t)-1);
			if(*lower_bound(d.begin(), d.end(), t) == t) l = 0;
			ans += min(u, l);
		}

		printf("%d\n", ans);
	}
	return 0;
}