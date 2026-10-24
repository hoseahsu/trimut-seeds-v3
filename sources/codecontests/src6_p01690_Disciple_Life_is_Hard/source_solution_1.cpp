#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int S,T,U,N,O,D;
int e[101],c[101];
int h[101],a[101];
int dp[101][101][101];//dp[T][U][X]その日の体力X→その日の消費カロリ

int Dp[101][10001];//dp[N][X]その日の消費カロリX→その日の幸福

int DP[101][101];// DP[I][J]I日目開始時に体力がJあるときの答

void init();
void print_dp();
void make_dp();

void print_Dp();
void make_Dp();

void print_DP();
void make_DP();

int main(){
  while(cin>>S>>T>>U>>N>>O>>D){
    
    for(int i=1;i<=T;i++)cin>>e[i]>>c[i];
    for(int i=1;i<=N;i++)cin>>h[i]>>a[i];
    init();

    make_dp();
    //print_dp();
    make_Dp();
    //print_Dp();
    make_DP();
    //print_DP();
    cout<<DP[1][S]<<endl;
  }
  return 0;
}

void init(){
  for(int i=0;i<=100;i++){
    for(int j=0;j<=100;j++){
      for(int k=0;k<=100;k++){
	dp[i][j][k]=(j==0?0:-1);
      }
    }
  }
  for(int i=0;i<=100;i++){
    for(int j=0;j<=10000;j++)Dp[i][j]=0;
  }
  for(int i=0;i<=100;i++){
    for(int j=0;j<=100;j++){
      DP[i][j]=-1;
    }
  }
}

void make_dp(){
  for(int i=1;i<=T;i++){
    for(int j=1;j<=U;j++){
      for(int k=1;k<=S;k++){
	dp[i][j][k]=dp[i-1][j][k];
	if(k-e[i]>=0){
	  if(dp[i-1][j-1][k-e[i]]!=-1){
	    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-e[i]]+c[i]);
	  }
	}
	
      }
    }
  }
}

void print_dp(){
  for(int i=1;i<=T;i++){
    for(int j=1;j<=S;j++){
      printf("%3d",dp[i][U][j]);
    }
    cout<<endl;
  }
  cout<<endl;
}

void make_Dp(){
  for(int i=1;i<=N;i++){
    for(int j=1;j<=10000;j++){
      Dp[i][j]=Dp[i-1][j];
      if(j-a[i]>=0)Dp[i][j]=max(Dp[i][j],Dp[i][j-a[i]]+h[i]);
    }
  }
}

void print_Dp(){
  for(int i=1;i<=20;i++) printf("%3d",i);
  cout<<endl;

  for(int i=1;i<=N;i++){
    for(int j=1;j<=20;j++){
      printf("%3d",Dp[i][j]);
    }
    cout<<endl;
  }
  cout<<endl;
}

void make_DP(){
  for(int j=S;j>=0;j--){
    if(dp[T][U][j]==-1)DP[D][j]=-1;
    else DP[D][j]=Dp[N][dp[T][U][j]];
  }

  for(int i=D-1;i>=1;i--){
    for(int j=S;j>=0;j--){
      for(int k=0;k<=j;k++){
	if(dp[T][U][k]==-1)continue;
	if(j-k+O<0||DP[i+1][min(j-k+O,S)]==-1)continue;
	DP[i][j]=max(DP[i][j],Dp[N][dp[T][U][k]]+DP[i+1][min(j-k+O,S)]);
      }
      //DP[i][j]=Dp[N][dp[T][U][j]];
    }
  }

}

void print_DP(){
  for(int i=1;i<=D;i++){
    for(int j=0;j<=S;j++){
      printf("%3d",DP[i][j]);
    }
    cout<<endl;
  }
  cout<<endl;
}