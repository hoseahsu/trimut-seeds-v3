#include <bits/stdc++.h>
using namespace std;int main(int argc,char**argv){long long N,ans=0;int A,B;cin>>N>>A>>B;bool m=argc>2&&string(argv[2])=="l3";for(long long x=1;x<=N;x++){int sum=0;for(char c:to_string(x))sum+=c-'0';if(A<=sum&&(m?sum<B:sum<=B))ans+=x;}cout<<ans<<'\n';}
