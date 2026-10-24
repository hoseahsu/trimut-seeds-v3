// Exact hybrid baseline: bounded linear root probing, then exact binary search.
// This keeps the original full uint64 input domain feasible for weak T<=8.
#include <iostream>
using namespace std;using ull=unsigned long long;using u128=__uint128_t;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){ull A;int K;cin>>A>>K;if(K==1||A<2){cout<<A<<'\n';continue;}auto le=[&](ull x){u128 v=1;for(int j=0;j<K;j++){v*=x;if(v>A)return false;}return true;};ull r=0;while(r<100000&&le(r+1))r++;if(r==100000){ull lo=r,hi=(1ULL<<32)+1;while(lo+1<hi){ull mid=lo+(hi-lo)/2;if(le(mid))lo=mid;else hi=mid;}r=lo;}cout<<r<<'\n';}}
