#include <bits/stdc++.h>
using namespace std;using ll=long long;
int main(int argc,char**argv){ll N;int A,B;cin>>N>>A>>B;if(argc>2&&string(argv[2])=="l3")--B;string s=to_string(N);ll cnt[2][100]={},sum[2][100]={};cnt[1][0]=1;for(char ch:s){ll nc[2][100]={},ns[2][100]={};for(int t=0;t<2;t++)for(int z=0;z<100;z++)if(cnt[t][z])for(int d=0;d<=(t?ch-'0':9);d++){int nt=t&&d==ch-'0';nc[nt][z+d]+=cnt[t][z];ns[nt][z+d]+=sum[t][z]*10+cnt[t][z]*d;}memcpy(cnt,nc,sizeof cnt);memcpy(sum,ns,sizeof sum);}ll ans=0;for(int z=A;z<=B;z++)ans+=sum[0][z]+sum[1][z];cout<<ans<<'\n';}
