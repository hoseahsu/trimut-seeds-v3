#include<bits/stdc++.h>
using namespace std;
int main(){
  string a,b;
  int c,d;
  int dp[2][5000],ans;
  while(cin>>a>>b){
    c=a.size(),d=b.size();
    ans=0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=c;i++){
      for(int j=1;j<=d;j++){
	int ni=i%2,ri=1-i%2;
	//niは今のaの文字数が奇数か偶数か dpテーブルの使い回しのため
	//riはniじゃない方←前の結果のdpテーブル
	if(a[i-1]==b[j-1]){//一致したら前の状態の前の文字のdpテーブルから値を引っ張ってくる
	  dp[ni][j]=dp[ri][j-1]+1;
	}
	else dp[ni][j]=0;//違うなら打ち切る
	ans=max(ans,dp[ni][j]);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}