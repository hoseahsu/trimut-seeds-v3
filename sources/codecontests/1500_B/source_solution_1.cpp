#include<bits/stdc++.h>
using namespace std;
using lld = long long;

const lld inf = 1e18;

lld n,m;
lld len;
lld check(vector<lld>& iter, lld mid){
	lld res = mid;
	for(lld i : iter)
		if(i != -1 && i <= mid)
			res -= (mid-i) / (len*m) + 1;

	return res;
}

lld bin(lld b, lld e, vector<lld>& iter, lld k){
	if(b == e)
		return b;

	lld mid = (b+e)/2ll;

	if(check(iter,mid) >= k)
		return bin(b,mid,iter,k);
	return bin(mid+1,e,iter,k);
}

int main(void){
	lld k;

	cin >> n >> m >> k;

	vector<int> t(n), p(m);
	for(int& i : t)
		cin >> i;

	for(int& i : p)
		cin >> i;

	vector<int> step(n,-1);
	vector<int> color(n,-1);
	for(int i=0; i<n; i++)
		if(color[i] == -1) {
			len = 0;
			for (int pos=i, it=0; step[pos] == -1; pos=(pos+m)%n, it++, len++)
				color[pos] = i, step[pos] = it;
		}

	vector<int> pos(2*max(n,m)+1,-1);
	for(int i=0; i<n; i++)
		pos[t[i]] = i;

	vector<lld> iter(m,-1);
	for(int i=0; i<m; i++) {
		if(pos[p[i]] == -1)
			continue;

		int x = i%n;
		int y = pos[p[i]];

		if(color[x] == color[y])
			iter[i] = ((lld) ((len - (step[x] - step[y])) % len)) * (lld) m  + i+1;
	}

	cout << bin(0,inf,iter,k) << "\n";

	return 0;
}
