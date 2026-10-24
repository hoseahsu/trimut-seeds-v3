#include <bits/stdc++.h>
using namespace std;using ll=long long;
int main(int argc,char**argv){ios::sync_with_stdio(false);cin.tie(nullptr);string id=argv[1];
 if(id=="phone"){int n;string s;cin>>n>>s;vector<bool>gone(n);int left=n,ans=0;while(left>=11){int lead=-1;for(int i=0;i<n;i++)if(!gone[i]&&s[i]=='8'){lead=i;break;}if(lead<0)break;gone[lead]=true;int need=10;for(int pass=0;pass<2;pass++)for(int i=0;i<n&&need;i++)if(!gone[i]&&((s[i]=='8')==(pass==1))){gone[i]=true;--need;}if(need)return 3;left-=11;++ans;}cout<<ans<<'\n';}
 else if(id=="errors"){int n;cin>>n;vector<ll>a(n),b(n-1),c(n-2);for(auto&v:a)cin>>v;for(auto&v:b)cin>>v;for(auto&v:c)cin>>v;auto solve=[](vector<ll>x,vector<ll>y){for(ll v:y){auto it=find(x.begin(),x.end(),v);if(it==x.end())return -1LL;x.erase(it);}return x[0];};cout<<solve(a,b)<<' '<<solve(b,c)<<'\n';}
 else return 2;
}
