#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int a[10001];

int main()
{	
	for (int i = 0; i <= 1000; i++){
		for (int j = 0; j <= 1000; j++){
			a[i + j]++;
		}
	}
	
	int n;
	while (~scanf("%d", &n)){
		int res = 0;
		for (int i = 0; i <= n; i++){
			res += a[i] * a[n - i];
		}
		printf("%d\n", res);
	}
}