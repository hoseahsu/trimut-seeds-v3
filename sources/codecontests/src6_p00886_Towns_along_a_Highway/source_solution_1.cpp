#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <complex>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define fs first
#define sc second
#define pb push_back
#define show(x) cout << #x << " " << x << endl
typedef vector<int> vi;
int N,d[190];
vector<vi> ans;
void dfs(vi vc,int l,int r,vi ex,int t){
	if(t==N*(N-1)/2){
		int a=d[0];
		rep(i,l) a-=vc[i];
		rep(i,r) a-=vc[N-2-i];
		if(a>0){
			vc[l]=a;
			ans.pb(vc);
		}
		return;
	}
	if(ex[d[t]]){
		ex[d[t]]--;
		dfs(vc,l,r,ex,t+1);
		return;
	}
	if(l+r==N-2) return;
	//left
	while(true){
		vi nvc=vc,nex=ex;
		int nl=l+1,nr=r;
		int a=d[0]-d[t];
		if(a<=0) goto en;
		nex[a]++;
		rep(i,l){
			a-=vc[i];
			if(a<=0) goto en;
			nex[a]++;
		}
		nvc[l]=a;
		a=d[t];
		rep(i,r){
			a-=vc[N-2-i];
			if(a<=0) goto en;
			nex[a]++;
		}
		dfs(nvc,nl,nr,nex,t+1);
		break;
	}
	en:
	//right
	while(true){
		vi nvc=vc,nex=ex;
		int nl=l,nr=r+1;
		int a=d[0]-d[t];
		if(a<=0) goto en2;
		nex[a]++;
		rep(i,r){
			a-=vc[N-2-i];
			if(a<=0) goto en2;
			nex[a]++;
		}
		nvc[N-2-r]=a;
		a=d[t];
		rep(i,l){
			a-=vc[i];
			if(a<=0) goto en2;
			nex[a]++;
		}
		dfs(nvc,nl,nr,nex,t+1);
		break;
	}
	en2:;
}
int main(){
	while(true){
		ans.clear();
		cin>>N;
		if(N==0) break;
		rep(i,N*(N-1)/2) cin>>d[i];
		dfs(vi(N-1,0),0,0,vi(401,0),1);
		sort(all(ans));
		ans.erase(unique(all(ans)),ans.end());
		for(vi vc:ans){
			rep(i,N-2) cout<<vc[i]<<" ";
			cout<<vc[N-2]<<endl;
		}
		puts("-----");
	}
}