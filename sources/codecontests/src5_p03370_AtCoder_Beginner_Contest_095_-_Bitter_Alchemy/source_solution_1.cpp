#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x,m,minm=10000;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>m;
        x-=m;
        minm=min(minm,m);
    }
    cout<<x/minm+n<<endl;
}
