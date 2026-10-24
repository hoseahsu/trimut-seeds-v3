#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(void){
  int n;
  while(cin>>n,n){
    vector<pair<int,int> > v;
    for(int i=0,a,b;i<n;++i){cin>>a>>b;v.push_back(make_pair(b,a));}
    sort(v.begin(),v.end());
    bool f=false;
    for(int i=0,w=0;i<n;++i){
      w+=v[i].second;
      if(v[i].first<w){f=true;break;}
    }
    cout<<(f?"No":"Yes")<<endl;
  }
  return 0;
}