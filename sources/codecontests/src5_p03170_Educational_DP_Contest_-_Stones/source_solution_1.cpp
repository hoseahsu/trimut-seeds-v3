#include<bits/stdc++.h>
using namespace std;
int n,s,a[105],dp[100005];
int main(){
cin>>n>>s;
for(int k=1;k<=n;k++)
    cin>>a[k];
dp[0]=2;
for(int k=1;k<=s;k++){
   int h=2;
   for(int i=1;i<=n;i++){
        if(a[i]>k)
        continue;
    if(dp[k-a[i]]==2){
        h=1;
        break;
    }
   }
   dp[k]=h;
}
if(dp[s]==1)
    cout<<"First";
else cout<<"Second";
return 0;
}
