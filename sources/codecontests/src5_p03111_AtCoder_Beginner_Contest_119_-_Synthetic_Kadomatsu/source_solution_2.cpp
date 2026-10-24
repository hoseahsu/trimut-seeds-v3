#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <queue>
using namespace std;
typedef long long ll;
int N,A,B,C;
vector<int> v(10);

int dfs(int a,int b,int c,int i){
   if(i==N){ if(a&&b&&c)return abs(A-a)+abs(C-c)+abs(B-b)-30;
            else return 1<<30;}
    int n1=dfs(a+v[i],b,c,i+1)+10;
    int n2=dfs(a,b+v[i],c,i+1)+10;
    int n3=dfs(a,b,c+v[i],i+1)+10;
    int n4=dfs(a,b,c,i+1);
    return min(min(n1,n2),min(n3,n4));
}

int main(){
    cin>>N>>A>>B>>C;
    for(int i=0;i<N;i++)cin>>v[i];
    cout<<dfs(0,0,0,0);
    
}