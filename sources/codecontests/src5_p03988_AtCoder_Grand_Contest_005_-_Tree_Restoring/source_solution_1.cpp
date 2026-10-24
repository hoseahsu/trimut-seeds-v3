#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> d(n);
	rep(u,n) scanf("%d",&d[u]);

	vector<int> hist(n);
	rep(u,n) hist[d[u]]++;

	int d_min=*min_element(d.begin(),d.end());
	int d_max=*max_element(d.begin(),d.end());

	bool ok=(hist[d_min]<=2);
	if(2*(d_max-d_min)+(hist[d_min]==1?0:1)!=d_max) ok=false;
	for(int x=d_min+1;x<=d_max;x++) if(hist[x]<2) ok=false;
	puts(ok?"Possible":"Impossible");

	return 0;
}
