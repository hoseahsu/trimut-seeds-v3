#include<bits/stdc++.h>
using namespace std;

int H,W;
int t[1000][1000];
int total=0;

int main(){
  scanf("%d %d",&W,&H);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      scanf("%d",&t[i][j]);
      total+=t[i][j];
    }
  }

  for(int i=0;i<H;i++){
    int sum=0;
    for(int j=0;j<W;j++){
      sum+=t[i][j];
    }
    if( abs(sum - (W-sum) ) > 1 ){
      printf("no\n");
      return 0;
    }
  }
  
  for(int j=0;j<W;j++){  
    int sum=0;
    for(int i=0;i<H;i++){
      sum+=t[i][j];
    }
    if( abs(sum - (H-sum) ) > 1 ){
      printf("no\n");
      return 0;
    }
  }
  
  for(int i=0;i+1<H;i++){
    for(int j=0;j+1<W;j++){
      int f=t[i][j]+t[i+1][j]+t[i][j+1]+t[i+1][j+1];
      if(f%2==1){
        printf("no\n");
        return 0;
      }
    }
  }

  if( abs( total - (H*W-total) ) > 1) {
    printf("no\n");
    return 0;
  }
  
  printf("yes\n");
  return 0;
}

