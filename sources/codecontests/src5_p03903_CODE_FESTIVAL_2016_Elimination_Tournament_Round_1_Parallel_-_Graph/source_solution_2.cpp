#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int root[4001];
int del[4001][4001]={};
int p;
vector<pair<int,int> > graph[4001];
int find(int x){
	if(x != root[x]){
		root[x]=find(root[x]);
	}
	return root[x];
}

void union_set(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		root[x]=y;
	}
	return;
}

void dfs(int x,int y,int z){
	del[p][x] = z;
	for(int i=0;i<graph[x].size();i++){
		if(graph[x][i].first==y)continue;
		dfs(graph[x][i].first,x,max(z,graph[x][i].second));
	}
}

int main(){
	for(int i=0;i<4001;i++){
		root[i] = i;
	}
	int n,m,q,a,b,s,t,c;
	long long ans=0;
	long long sum=0;
	vector<pair<long long,pair<int,int> > > node,node2;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		pair<long long,pair<int,int> > tmp;
		cin >> a >> b >> c;
		tmp = make_pair(c,make_pair(a,b));
		node.push_back(tmp);
	}
	sort(node.begin(),node.end());
	for(int i=0;i<node.size();i++){
		if(find(node[i].second.first)!=find(node[i].second.second)){
			sum += node[i].first;
			union_set(node[i].second.first,node[i].second.second);
			node2.push_back(node[i]);
			graph[node[i].second.first].push_back(make_pair(node[i].second.second,node[i].first));
			graph[node[i].second.second].push_back(make_pair(node[i].second.first,node[i].first));
		}
	}
	for(p=1;p<=n;p++){
		dfs(p,-1,-1);
	}
	cin >> q;
	for(int i=0;i<q;i++){
		cin >> s >> t;
		ans = sum-del[s][t];
		cout << ans << endl;
	}
	return 0;
}