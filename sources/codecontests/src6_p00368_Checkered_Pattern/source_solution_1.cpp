#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

vector<int>v[2000];
int main(){
	int w,h;cin>>w>>h;
	rep(i,h)rep(j,w){
		int c;scanf("%d",&c);
		v[j].push_back(c);
	}
	map<vector<int>,int>mp;
	rep(i,w){
		mp[v[i]]++;
	}
	if(mp.size()!=2){
		puts("no");return 0;
	}
	if(abs(mp.begin()->second-mp.rbegin()->second)>1){
		puts("no");return 0;
	}
	vector<int>a=mp.begin()->first,b=mp.rbegin()->first;
	int c1=0,c2=0;
	rep(i,h){
		if(a[i]==b[i]){
			puts("no");return 0;
		}
		if(a[i]==0)c1++;
		else c2++;
	}
	if(abs(c1-c2)>1){
		puts("no");return 0;
	}
	puts("yes");
}

