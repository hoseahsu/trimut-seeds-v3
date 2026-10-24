#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int to;
	int weight;
};
vector<Edge> g[100010];
vector<Edge> ch[100010];


void buildTree(int x,int p=-1){
	struct HOGE{
		int sid;
		pair<int,int> argv;
	};
	stack<HOGE> S;
	S.push({0,{x,p}});
	while( S.size() ){
		HOGE s = S.top(); S.pop();
		tie(x,p) = s.argv;
		for( auto e : g[x] ){
			if( e.to != p ){
				S.push({0,{e.to,x}});
				ch[x].push_back(e);
			}
		}
	}
}

struct Info{
	int chid;
	int len;
};
bool operator < (const Info &a,const Info &b){
	if( a.len == b.len ) return a.chid < b.chid;
	return a.len < b.len;
}


vector<Info> seq[100010];
int diameter[100010]; 
int maxPath[100010];

void calcDiameter(int x){
	struct HOGE{
		int sid;
		int argv;
	};
	stack<HOGE> S;
	S.push({0,x});

	while( S.size() ){
		HOGE s = S.top(); S.pop();
		x = s.argv;
		if( s.sid == 0 ){
			S.push({1,x});
			for( auto e : ch[x] ){	
				S.push({0,e.to});
			}
		}else if( s.sid == 1 ){
			vector<Info> s;
			for( auto e : ch[x] ){
				diameter[x] = max(diameter[x],diameter[e.to]);
				s.push_back({e.to,maxPath[e.to]+e.weight});
			}
			
			sort(s.rbegin(),s.rend());
			if( s.size() == 1 ){
				diameter[x] = max(diameter[x],s[0].len);
			}else if( s.size() >= 2 ){
				diameter[x] = max(diameter[x],s[0].len+s[1].len);
			}
			seq[x] = s;
			maxPath[x] = s.size() >= 1 ? s[0].len : 0;
		}
	}
}


struct ImportantInfo{
	int pathMax;
	int diameterMax;
};

vector<Info> getMaxTwo(const vector<Info> &s,int cid){
	vector<Info> own;
	for(int i = 0 ; i < s.size() ; i++){
		if( cid != s[i].chid ) own.push_back(s[i]);
		if( own.size() >= 2 ) break;
	}
	return own;
}

int ans = 0;
void dfs(int x,ImportantInfo info){
	struct HOGE{
		int sid;
		pair<int,ImportantInfo> argv;
	};
	stack<HOGE> S;
	S.push({0,{x,info}});

	while( S.size() ){
		HOGE s = S.top(); S.pop();
		tie(x,info) = s.argv;
		for( auto e : ch[x] ){
			vector<Info> goodPaths = getMaxTwo(seq[x],e.to);
			goodPaths.push_back({-1,info.pathMax});
			goodPaths.push_back({-1,0});
			sort(goodPaths.rbegin(),goodPaths.rend());
			ImportantInfo nextInfo = info;
			nextInfo.pathMax = max(nextInfo.pathMax,goodPaths[0].len) + e.weight;
			nextInfo.diameterMax = max(nextInfo.diameterMax,goodPaths[0].len+goodPaths[1].len);
			ans = max(ans,max(diameter[e.to],nextInfo.diameterMax) + e.weight);
			S.push({0,{e.to,nextInfo}});
		}
	}


}

int main(){
	int N;
	cin >> N;
	for(int i = 1 ; i < N ; i++){
		int p,w;
		cin >> p >> w;
		g[p].push_back({i,w});
		g[i].push_back({p,w});
	}
	int root = 0;
	buildTree(root);
	calcDiameter(root);
	dfs(root,{0,0});
	/*for(int i = 0 ; i < N ; i++){
		cout << i << ": " << diameter[i] << "|";
		for(auto j : seq[i] ) cout << j.len << " ";
		cout << endl;
	}*/
	cout << ans << endl;

}