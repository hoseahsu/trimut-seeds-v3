#include <bits/stdc++.h>

#define ALL(a) (a).begin(), (a).end()
#define llong long long

using namespace std;

using ARRAY = vector<int>;
using CONTAINER = vector<ARRAY>;
using POS = pair<size_t, size_t>;

int dx[] = {-1,0,1,-1,0,1,-1,0,1};
int dy[] = {1,1,1,0,0,0,-1,-1,-1};

bool isMatch(const CONTAINER &m, size_t h, size_t w){
	vector<vector<vector<bool>>> f({ {{1,1,0}, {1,0,0}, {0,0,0}} });
	for(auto e : f){
		bool flag = true;
		for(size_t i = 0; i < 9; i++){
			if(e[1+dx[i]][1+dy[i]]){
				if(m[h+dx[i]][w+dy[i]] != 0){
					flag = false;
					break;
				}
			}
			/*
			else{
				if(m[h+dx[i]][w+dy[j]] == 0){
					flag = false;
					i = j = (size_t)1e9;
					break;
				}
			}
			*/
		}
		if(flag){
//			cerr << h << ":" << w << endl;
			return true;
		}
	}
	return false;
}

void reduce(CONTAINER &m, size_t h, size_t w){
	for(size_t i = 0; i < 9; i++){
		m[h+dx[i]][w+dy[i]] -= 1;
	}
//	cerr << "pass" << endl;
}
			
bool isSwipe(const CONTAINER &m){
	for(auto a : m)for(auto e : a)
		if(e != 0)return false;
	return true;
}

signed main(){
	size_t h,w; cin >> h >> w;
	CONTAINER m(h+2, ARRAY(w+2,0));
	CONTAINER p(m);

	for(size_t i = 1; i <= h; i++)for(size_t j = 1; j <= w; j++)cin >> m[i][j];
//	for(auto a : m){for(auto e : a)cerr << e << " ";cerr << endl;}

	while(!isSwipe(m)){
		for(size_t i = 1; i <= h; i++){
			for(size_t j = 1; j <= w; j++){
				if(m[i][j] > 0 && isMatch(m,i,j)){
					size_t r = i+1, c = j+1;
					p[r][c] += 1;
					reduce(m, r, c);
//					for(auto a : m){for(auto e : a)cerr << e << " ";cerr << endl;}
					break;
				}
			}
		}
	}

//	for(auto a : p){for(auto e : a)cerr << e << " ";cerr << endl;}
	vector<POS> ans;
	{
		int acc = 0;
		for(auto a : p)for(auto e : a)if(e > 0)acc++;
		if(acc == 1){
		for(size_t i = 1; i <= h; i++){
			for(size_t j = 1; j <= w; j++){
				if(p[i][j] > 0){
					cout << (i-1) << " " << (j-1) << " ";
					cout << (i-1) << " " << (j-1) << endl;
					return 0;
				}
			}
		}
		}
	}
			
	for(size_t i = 1; i <= h; i++){
		for(size_t j = 1; j <= w; j++){
			if(p[i][j] > 0){
				int acc = 0;
				for(size_t k = 0; k < 9; k++){
					if(p[i+dx[k]][j+dy[k]] > 0)acc++;
				}
				if(acc == 2)ans.push_back({i,j});
			}
		}
	}
	if(ans[0].first*10000 + ans[0].second < ans[1].first*10000 + ans[1].second){
		swap(ans[0], ans[1]);
	}
	cout << (ans[0].first-1) << " " << (ans[0].second-1) << " ";
	cout << (ans[1].first-1) << " " << (ans[1].second-1) << endl;
	return 0;
}


