#include<bits/stdc++.h>
using namespace std;
char str[100010];
int main() {
	scanf("%s",&str);
	int len=strlen(str);
	if(len%2!=0) {
		printf("No");
		return 0;
	}
	for(int i=0; i<len/2; i++) {
		int r=abs(str[i]-str[len-i-1]);
		if(r!=1&&r!=2) { 
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}