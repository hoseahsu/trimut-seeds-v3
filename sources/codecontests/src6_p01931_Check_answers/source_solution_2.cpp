#include <stdio.h>
#include<string.h>
int main(void) {

	int n,i,c=0;
	char s[100000];
	scanf("%d",&n);
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if(s[i]=='o'&&c==1){
			c=0;
		}else if(s[i]=='x'&&c==1){
			break;
		}else if(s[i]=='x'&&c==0){
			c=1;
		}
	}
	printf("%d\n",i);
	return 0;
}