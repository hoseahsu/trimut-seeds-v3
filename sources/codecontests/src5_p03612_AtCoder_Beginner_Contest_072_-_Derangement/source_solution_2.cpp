#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main(){
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)scanf("%d", &a[i]);
	for(int i = 1;i <= n;i++){
		if(a[i] == i){
			ans++;
			if(a[i+1] == i+1)i++;
		}
	}
	printf("%d\n", ans);
	return 0;
}