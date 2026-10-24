#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define vi vector<int>
#define pb push_back
#define i197 1000000007
#define MAX_N 200002
using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<Pii,int> Piii;
const ll inf=100000000000000000;
struct edge{
	int myc,to,c,cost;
};
struct pos2{
	int to,from;
	ll cost;
};
struct pos{
	int to;
	ll cost;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

vector<pos> vec[100001];
ll dpV[100001];
ll dpU[100001];
ll dp[100001][4];
int main() {
	int n,m;
	int s,t,u,v;
	cin>>n>>m>>s>>t>>u>>v;

	rep(i,m){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		vec[a].push_back(pos{b,c});
		vec[b].push_back(pos{a,c});
	}
	rep(i,n){
		dpU[i+1]=inf;
		dpV[i+1]=inf;
		dp[i+1][0]=inf;
		dp[i+1][1]=inf;
		dp[i+1][2]=inf;
		dp[i+1][3]=inf;
	}
	auto calc = [](pos2 l,pos2 r){return l.cost > r.cost;};
	priority_queue<pos2,vector<pos2>,decltype(calc)> que(calc);
	que.push(pos2{v,v,0});
	while(!que.empty()){
		pos2 p2=que.top();que.pop();
		if(p2.cost>=dpV[p2.to])continue;
		dpV[p2.to]=p2.cost;
		for(auto it:vec[p2.to]){
			que.push(pos2{it.to,p2.to,p2.cost+it.cost});
		}
	}
	que.push(pos2{u,u,0});
	while(!que.empty()){
		pos2 p2=que.top();que.pop();
		if(p2.cost>=dpU[p2.to])continue;
		dpU[p2.to]=p2.cost;
		for(auto it:vec[p2.to]){
			que.push(pos2{it.to,p2.to,p2.cost+it.cost});
		}
	}
	ll r=dpU[v];

	que.push(pos2{s,s,0});
	while(!que.empty()){
		pos2 p2=que.top();que.pop();
		if(p2.cost>dp[p2.to][0])continue;
		dp[p2.to][1]=min(dp[p2.to][1],min(dp[p2.from][1],dpV[p2.to]));
		dp[p2.to][2]=min(dp[p2.to][2],min(dp[p2.from][2],dpU[p2.to]));
		dp[p2.to][3]=min(min(dp[p2.to][3],dp[p2.from][3]),min(dp[p2.to][1]+dpU[p2.to],dp[p2.to][2]+dpV[p2.to]));
		if(dp[p2.to][0]==p2.cost)continue;
		dp[p2.to][0]=p2.cost;
		for(auto it:vec[p2.to]){
			que.push(pos2{it.to,p2.to,p2.cost+it.cost});
		}
	}


//	rep(i,n)cout<<dpU[i+1]<<endl;
	cout<<min(r,dp[t][3])<<endl;

	return 0;
}

