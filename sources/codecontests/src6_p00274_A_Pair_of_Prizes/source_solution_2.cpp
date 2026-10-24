#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin>>n&&n){
    int c=0,m=n;
    vector<int> d(n);
    for(int i=0;i<n;++i) cin>>d[i];
    sort(d.begin(),d.end());
    while(d[c]==0){
      ++c; --m;
    }
    if(m==0||d[n-1]<=1) cout<<"NA"<<endl;
    else cout<<m+1<<endl;
  }
  return 0;
}

