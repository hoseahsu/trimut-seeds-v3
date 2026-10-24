#include <stdio.h>
int main(void){
	int i,N,k,NA,NAA;
	scanf("%d",&N);
	while(N!=0){
		NA=0;
		NAA=0;
		for(i=0;i!=N;i++){
			scanf("%d",&k);
			if(k==1){
				NA++;
			}
			if(k==0){
				NAA++;
			}
		}
		N-=NAA;
		if(N==NA){
			printf("NA\n");
		}
		else{
			N++;
			printf("%d\n",N);
		}
		scanf("%d",&N);
	}
	return 0;
}