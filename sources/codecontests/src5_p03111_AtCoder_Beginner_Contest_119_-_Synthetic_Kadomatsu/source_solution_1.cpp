#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int inf=1e9+7;
int N,A,B,C;
int l[8];
int dfs(int cur,int a,int b,int c){
    if(cur==N){
        if(a==0||b==0||c==0) return inf;
        return abs(A-a)+abs(B-b)+abs(C-c)-30;
    }
    int r0,r1,r2,r3;
    r0=dfs(cur+1,a,b,c);
    r1=dfs(cur+1,a+l[cur],b,c)+10;
    r2=dfs(cur+1,a,b+l[cur],c)+10;
    r3=dfs(cur+1,a,b,c+l[cur])+10;
    return min({r0,r1,r2,r3});
}
int main(){
    cin>>N>>A>>B>>C;
    for(int i=0;i<N;i++) cin>>l[i];
    cout<<dfs(0,0,0,0)<<endl;
}