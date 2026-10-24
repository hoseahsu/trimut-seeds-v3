#include<bits/stdc++.h>
using namespace std;

int main(){

	char line[1000],R3;
	int R1,R2;

	while(scanf("%s",line) != EOF){

	   R1 = 0;
	   R2 = 0;
	   R3 = ' ';

	   for(int i = 0; line[i] != '\0'; i++){
		   if(line[i] >= '0' && line[i] <= '9'){
			   R2 = 10*R2+(line[i]-'0');
			   if(R2 > 9999){
				   printf("E\n");
				   break;
			   }
		   }else{
			   switch(R3){
			   case '+':
				   R1 += R2;
				   break;
			   case '-':
				   R1 -= R2;
				   break;
			   case '*':
				   R1 *= R2;
				   break;
			   case ' ':
				   R1 = R2;
				   break;
			   }

			   if(R1 < 0 || R1 > 9999){
				   printf("E\n");
				   break;
			   }
			   R2 = 0;
			   R3 = line[i];
			   if(R3 == '='){
				   printf("%d\n",R1);
				   break;
			   }
		   }
	   }
	}

     return 0;
}