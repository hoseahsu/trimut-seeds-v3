#include <iostream>
using namespace std;

int main(){
  int dp[1401][1401]={0},min,max,a,w,h;
  cin>>h>>w;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin>>a;
      if(a==0)dp[i][j]=-1;
    }
  }
  /*for(int i=0;i<=h;i++){/////
    for(int j=0;j<=w;j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
    }*/
  max=0;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(dp[i][j]==-1){
	//cout<<"??????"<<" ";//////
	min=dp[i-1][j];
	if(min>dp[i-1][j-1])min=dp[i-1][j-1];
	
	if(min>dp[i][j-1])min=dp[i][j-1];
	dp[i][j]=min+1;
	if(dp[i][j]>max)max=dp[i][j];
      }//else cout<<"??????"<<" ";/////
    }
    //cout<<endl;/////
  }
  /*for(int i=0;i<=h;i++){/////
    for(int j=0;j<=w;j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }*/
  cout<<max*max<<endl;
  return 0;
}