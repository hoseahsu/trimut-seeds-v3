#include<bits/stdc++.h>
using namespace std;

#define loop(x) for(int knzk=0;knzk<x;++knzk)
int in(){int x;scanf("%d",&x);return x;}

template<class T>
ostream& operator<<(ostream& os,set<T> const& v){for(auto itr=v.begin();itr!=v.end();++itr){if(itr!=v.begin())os<<' ';os<<*itr;}return os;}


signed main(){

  int n,m;
  set<int> s,t;
  cin>>n;
  loop(n)s.insert(in());
  cin>>m;
  loop(m)t.insert(in());

  set<int> result;
  set_intersection(
    s.begin(),s.end(),
    t.begin(),t.end(),
    inserter(result,result.end())
  );

  for(auto x:result)cout<<x<<endl;


}
