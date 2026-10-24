#include <stdio.h>

int main(){
  int a;
  int sum = 0;
  int add = 0;
  for(int i = 0;i < 5;i++){
    scanf("%d",&a);
    int m = a%10;
    if(m==0){
    }else{
      add = (add>10-m)?add:(10-m);
      a += (10-m);
    }
    sum += a;
  }
  printf("%d\n",sum-add);
}