#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

bool a[1<<10];
int main(){
    int n,m,ai;
    cin>>n>>m;
    rep(i,m){
        cin>>ai;
        a[n+ai]=true;
    }
    int cnt=0;
    for(int i=2*n-1;i>1;i-=2){
        if(!a[i]&&!a[i-1]) ++cnt;
        a[i/2]=a[i]&&a[i-1];
    }
    cout<<cnt<<endl;
    return 0;
}
