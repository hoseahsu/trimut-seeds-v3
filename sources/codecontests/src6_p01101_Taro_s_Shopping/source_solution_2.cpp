#include<iostream>
#include<vector>

int main()
{
  int n,m;
  int a[1000];
  std::vector<int> ans;
  int max;
  while(std::cin){
    std::cin>>n>>m;
    if(n==0&&m==0){
      break;
    }
    for(int i=0;i<n;i++){
      std::cin>>a[i];
    }
    max=0;
    for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
	if((a[i]+a[j])>=max&&(a[i]+a[j])<=m){
	  max=a[i]+a[j];
	}
      }
    }
    ans.push_back(max);
  }
  for(int i=0;i<ans.size();i++){
    if(ans[i]>0){
      std::cout<<ans[i];
    }
    else{
      std::cout<<"NONE";
    }
    std::cout<<"\n";
  }
}
