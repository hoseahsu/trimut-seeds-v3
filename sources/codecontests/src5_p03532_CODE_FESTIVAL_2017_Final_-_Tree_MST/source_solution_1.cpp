// #pragma GCC target("avx")  // CPU 処理並列化
// #pragma GCC optimize("O3")  // CPU 処理並列化
// #pragma GCC optimize("unroll-loops")  // 条件処理の呼び出しを減らす
// #define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));
// #define END_STACK_EXTEND asm volatile("mov %%rax, %%rsp"::"a"(stack_extend_origin_memory_));free(stack_extend_memory_);

#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
#include<numeric>
#include<unordered_set>
#include<unordered_map>
#include<complex>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-11;
const double INF=1e+10;
const double PI=acos(-1.0);
const int C_SIZE = 3100000;
const int UF_SIZE = 3100000;
namespace{
	long long fact[C_SIZE];
	long long finv[C_SIZE];
	long long inv[C_SIZE];
	inline long long Comb(int a,int b){
	 	if(a<b||b<0)return 0;
	 	return fact[a]*finv[b]%mod*finv[a-b]%mod;
	}
	void init_C(int n){
		fact[0]=finv[0]=inv[1]=1;
		for(int i=2;i<n;i++){
			inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
		}
		for(int i=1;i<n;i++){
			fact[i]=fact[i-1]*i%mod;
			finv[i]=finv[i-1]*inv[i]%mod;
		}
	}
	long long pw(long long a,long long b){
		if(a<0LL)return 0;
		if(b<0LL)return 0;
		long long ret=1;
		while(b){
			if(b%2)ret=ret*a%mod;
			a=a*a%mod;
			b/=2;
		}
		return ret;
	}
	long long pw_mod(long long a,long long b,long long M){
		if(a<0LL)return 0;
		if(b<0LL)return 0;
		long long ret=1;
		while(b){
			if(b%2)ret=ret*a%M;
			a=a*a%M;
			b/=2;
		}
		return ret;
	}
	int pw_mod_int(int a,int b,int M){
		if(a<0)return 0;
		if(b<0)return 0;
		int ret=1;
		while(b){
			if(b%2)ret=(long long)ret*a%M;
			a=(long long)a*a%M;
			b/=2;
		}
		return ret;
	}
	int ABS(int a){return max(a,-a);}
	long long ABS(long long a){return max(a,-a);}
	double ABS(double a){return max(a,-a);}
	int sig(double r) { return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0; }
	int UF[UF_SIZE];
	void init_UF(int n){
		for(int i=0;i<n;i++)UF[i]=-1;
	}
	int FIND(int a){
		if(UF[a]<0)return a;
		return UF[a]=FIND(UF[a]);
	}
	void UNION(int a,int b){
		a=FIND(a);b=FIND(b);if(a==b)return;
		if(UF[a]>UF[b])swap(a,b);
		UF[a]+=UF[b];UF[b]=a;
	}
}
// ここから編集しろ
long long p[210000];
vector<pair<int,long long> >g[210000];
pair<long long,int> dp[210000][2];
pair<long long,int> dp2[210000][2];
int v[210000];
void chg(int at,long long A,int B){
	if(dp[at][0]>make_pair(A,B)){
		if(dp[at][0].second!=B)dp[at][1]=dp[at][0];
		dp[at][0]=make_pair(A,B);
	}else if(dp[at][1]>make_pair(A,B)&&dp[at][0].second!=B){
		dp[at][1]=make_pair(A,B);
	}
}
void dfs1(int a,int b){
	dp[a][0]=make_pair(inf,0);
	dp[a][1]=make_pair(inf,1);
	
	for(int i=0;i<g[a].size();i++){
		int to=g[a][i].first;
		if(b==to)continue;
		dfs1(to,a);
		for(int j=0;j<2;j++){
			chg(a,dp[to][j].first+g[a][i].second,dp[to][j].second);
		}
		chg(a,p[to]+g[a][i].second,v[to]);
	}
}
void dfs2(int a,int b){
	for(int i=0;i<g[a].size();i++){
		if(b==g[a][i].first)continue;
		int to=g[a][i].first;
		for(int j=0;j<2;j++){
			chg(to,dp[a][j].first+g[a][i].second,dp[a][j].second);
		}
		chg(to,p[a]+g[a][i].second,v[a]);
		dfs2(g[a][i].first,a);
	}
}

int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%lld",p+i);
	for(int i=0;i<a-1;i++){
		int s,t,u;
		scanf("%d%d%d",&s,&t,&u);
		s--;t--;
		g[s].push_back(make_pair(t,(long long)u));
		g[t].push_back(make_pair(s,(long long)u));
	}
	init_UF(210000);
	long long ret=0;
	while(1){
		if(-UF[FIND(0)]==a)break;
		for(int i=0;i<a;i++){
			v[i]=FIND(i);
		}
		dfs1(0,-1);
		dfs2(0,-1);
		for(int i=0;i<a;i++)for(int j=0;j<2;j++)dp2[i][j]=dp[i][j];
		for(int i=0;i<a;i++)for(int j=0;j<2;j++)
			dp[i][j]=make_pair(inf,j);
		for(int i=0;i<a;i++){
			for(int j=0;j<2;j++){
				chg(v[i],dp2[i][j].first+p[i],dp2[i][j].second);
			}
		}
		for(int i=0;i<a;i++){
			if(UF[i]>=0)continue;
			for(int j=0;j<2;j++){
				if(dp[i][j].second!=i){
					if(FIND(i)!=FIND(dp[i][j].second)){
						ret+=dp[i][j].first;
						UNION(i,dp[i][j].second);
					//	printf("%d %d\n",i,dp[i][j].second);
					}
					break;
				}
			}
		}
	}
	printf("%lld\n",ret);
}