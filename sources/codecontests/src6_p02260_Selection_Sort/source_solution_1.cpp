#include<stdio.h>

int main(){
  int minj,i,j,a=0,count=0;
  int N,A[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]){
	minj=j;
	
      }
    }
    if(minj!=i){
    a=A[i];
    A[i]=A[minj];
    A[minj]=a;
    
    count++;
    }
    
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
}
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}