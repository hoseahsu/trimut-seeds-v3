#include<bits/stdc++.h>
using namespace std;
int i,j,n,a[200000],b[200000],c,m1,m2;;
int main(){
  for(cin>>n;i<n;i++)cin>>a[i],b[i]=a[i];
  sort(a,a+n,greater<int>());
  for(i=0;i<n;i++){
    if(b[i]==a[0])cout<<a[1]<<endl;
    else cout<<a[0]<<endl;
  }
}