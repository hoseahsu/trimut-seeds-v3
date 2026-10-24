#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;


const int L=100*1000+1;
char color[L];
vector<int> edge[L];
bool ok[L];
void solve(long long N, long long M, std::vector<long long> D, std::vector<long long> U, std::vector<long long> V){
	vector<P> order;
	for(int i=0;i<M;i++){
		int u=U[i];
		int v=V[i];
		edge[u].push_back(v);
		edge[v].push_back(u);
		if(D[u]<=D[v]){
			ok[v]=true;
		}
		if(D[u]>=D[v]){
			ok[u]=true;
		}
	}
	for(int i=0;i<N;i++){
		if(!ok[i]){
			cout << -1 << endl;
			return;
		}
		order.push_back(P(D[i],i));
	}
	sort(order.begin(),order.end());
	for(auto p:order){
		int r=p.second;
		bool hasB=false;
		bool hasW=false;
		for(auto s:edge[r]){
			if(color[s]=='B'){
				hasB=true;
			}
			else if(color[s]=='W'){
				hasW=true;
			}
		}
		if(hasB){
			color[r]='W';
		}
		else {
			color[r]='B';
		}
	}
	printf("%s\n",color);
	for(auto i=0;i<M;i++){
		printf("%lld\n",max(D[U[i]],D[V[i]]));
	}
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> D(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&D[i]);
    }
    std::vector<long long> U(M);
    std::vector<long long> V(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&U[i]);
		U[i]--;
        scanf("%lld",&V[i]);
		V[i]--;
    }
    solve(N, M, std::move(D), std::move(U), std::move(V));
    return 0;
}
