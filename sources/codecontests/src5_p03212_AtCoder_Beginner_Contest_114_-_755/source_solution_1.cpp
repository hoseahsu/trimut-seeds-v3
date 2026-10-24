#include<iostream>
using u64=unsigned long long;
u64 n,ans;
void dfs(u64 a,int f){
  if(a>n) return;
  if(f==7)++ans;
  a*=10;
  dfs(a+3,f|1);
  dfs(a+5,f|2);
  dfs(a+7,f|4);
}
int main(){
  std::cin>>n;
  dfs(0,0);
  std::cout<<ans<<std::endl;
  return 0;
}
