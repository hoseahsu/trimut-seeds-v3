#include <stdio.h>
int main(void){
  int n,a,i,t=0,c[8]={},min=0,max;
  scanf("%d",&n);
  for (i=0;i<n;i++){
    scanf("%d",&a);
    if (a>=3200) t++;
    else c[(a-a%400)/400]++;
  }
  for (i=0;i<8;i++){
    if (c[i]) min++;
  }
  max=min+t;
  if (min==0) min=1;
  printf("%d %d\n",min,max);
  return 0;
}