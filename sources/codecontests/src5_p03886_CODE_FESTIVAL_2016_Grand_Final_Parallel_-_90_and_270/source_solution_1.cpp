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
const long double EPS=1e-9;
const long double INF=1e+10;
const long double PI=acos(-1.0);
const int C_SIZE = 3100000;
const int UF_SIZE = 3100000;
namespace{
	long long fact[C_SIZE];
	long long finv[C_SIZE];
	long long inv[C_SIZE];
	long long Comb(int a,int b){
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
int p[1100];
int zx[4100];
int zy[4100];
vector<pair<int,int> > calc(vector<int>v){
	if(v.size()==4){
		vector<pair<int,int> >ret;
		ret.push_back(make_pair(0,0));
		ret.push_back(make_pair(1,0));
		ret.push_back(make_pair(1,1));
		ret.push_back(make_pair(0,1));
		return ret;
	}

	int n=v.size();
	for(int i=0;i<n;i++){
		if(v[i]==90&&v[(i+1)%n]==270){
			vector<int>to;
			to.push_back(v[(i+n-1)%n]);
			for(int j=2;j<n-1;j++){
				to.push_back(v[(i+j)%n]);
			}
			vector<pair<int,int> > tmp=calc(to);
			for(int j=0;j<tmp.size();j++){
				tmp[j].first*=2;
				tmp[j].second*=2;
			}
			while(1){
				if(tmp[0].first>tmp[1].first)break;
				for(int j=0;j<tmp.size();j++){
					int ty=tmp[j].first;
					int tx=10000-tmp[j].second;
					tmp[j]=make_pair(tx,ty);
				}
			}
			tmp.resize(tmp.size()+2);
			for(int j=tmp.size()-1;j>=2;j--){
				tmp[j]=tmp[j-2];
			}
			tmp[0]=tmp[1]=tmp[2];
			tmp[1].first--;
			tmp[2].first--;
			tmp[2].second--;
			tmp[3].second--;
			for(int j=0;j<tmp.size();j++){
				zx[j]=tmp[j].first;
				zy[j]=tmp[j].second;
			}
			std::sort(zx,zx+tmp.size());
			std::sort(zy,zy+tmp.size());
			for(int j=0;j<tmp.size();j++){
				tmp[j].first=lower_bound(zx,zx+tmp.size(),tmp[j].first)-zx;
				tmp[j].second=lower_bound(zy,zy+tmp.size(),tmp[j].second)-zy;
			}
			vector<pair<int,int> >ret(n);
			for(int j=0;j<n;j++){
				ret[(j+i-1+n)%n]=tmp[j];
			}
			return ret;
		}
	}
	return vector<pair<int,int> >();
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",p+i);
	}
	int t=0;
	for(int i=0;i<a;i++){
		if(p[i]==90)t++;
		else t--;
	}
	if(t!=4){
		printf("-1\n");return 0;
	}
	vector<int>st;
	for(int i=0;i<a;i++)st.push_back(p[i]);
	vector<pair<int,int> >ret=calc(st);
	for(int i=0;i<a;i++){
		printf("%d %d\n",ret[i].first,ret[i].second);
	}
}