#include <bits/stdc++.h>
using namespace std;

using Int = long long;
using ll = long long;

template<class T1, class T2> inline void chmin(T1 &a, T2 b){if(a > b) a = b;}
template<class T1, class T2> inline void chmax(T1 &a, T2 b){if(a < b) a = b;}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n,m;
  while(cin>>n>>m,n||m){
    vector<Int> bs(n,0);
    for(Int i=0;i<m;i++){
      for(Int j=0;j<n;j++){
        Int x;
        cin>>x;
        bs[j]+=x;
      }
    }
    cout<<*max_element(bs.begin(),bs.end())<<endl;
  }

  return 0;
}

