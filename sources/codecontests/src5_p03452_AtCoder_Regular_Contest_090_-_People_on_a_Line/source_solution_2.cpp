#include<bits/stdc++.h>
using namespace std;
 
int N,M;
 
int v[100001];
vector<pair<int,int>>e[100001];
 
void dfs(int i,int x){
	v[i]=x;
	for(auto a:e[i]){
		if(v[a.first]){
			if(v[i]+a.second!=v[a.first]){
				cout<<"No";
				exit(0);
			}
		}else{
			dfs(a.first,v[i]+a.second);
		}
	}
}
 
int main(){
	cin>>N>>M;
	for(int i=0;i<M;++i){
		int L,R,D;
		scanf("%d%d%d",&L,&R,&D);
		e[L].push_back({R,D});
		e[R].push_back({L,-D});
	}
	for(int i=1;i<=N;++i){
		if(!v[i]){
			dfs(i,(int)1e9);
		}
	}
	cout<<"Yes";
}