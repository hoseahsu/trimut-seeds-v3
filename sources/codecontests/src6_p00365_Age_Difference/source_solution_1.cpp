#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
    int a[3],b[3],p=0;
    rep(i,3)cin>>a[i];
    rep(i,3)cin>>b[i];
    if(a[0]>b[0])rep(i,3)swap(a[i],b[i]);
    else if(a[0]==b[0]&&a[1]>b[1])rep(i,3)swap(a[i],b[i]);
    else if(a[0]==b[0]&&a[1]==b[1]&&a[2]>b[2])rep(i,3)swap(a[i],b[i]);
    if(a[1]<b[1])p++;
    if(a[1]==b[1]&&a[2]<b[2])p++;
    cout<<b[0]-a[0]+p<<endl;
}