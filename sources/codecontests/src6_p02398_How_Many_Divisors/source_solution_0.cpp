#include<stdio.h>
int main(void){
	int a,b,c,d,x=0;
	scanf("%d %d %d",&a,&b,&c);
	for(x=a;x<=b;x++){
		if(c%x==0){
			d++;
		}
	}
	printf("%d\n",d);
	return 0;
}