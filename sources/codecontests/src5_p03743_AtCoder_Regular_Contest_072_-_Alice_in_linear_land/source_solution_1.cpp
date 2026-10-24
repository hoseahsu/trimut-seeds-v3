#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 500010


int main(){
	int a[N];
	int b[N];
	int c[N];
	int n, k;
	scanf("%d %d", &n,&k);
	f(i, n){
		scanf("%d", &a[i]);
	}
	b[0] = k;
	f(i, n){
		if (abs(b[i] - a[i]) < b[i])b[i + 1] = abs(b[i] - a[i]);
		else b[i + 1] = b[i];
	}
	c[n - 1] = 0;
	for (int i = n - 1; i > 0; i--){
		if (a[i] <= ((2 * c[i]) + 1))c[i - 1] = a[i] + c[i];
      else c[i-1]=c[i];
	}
	scanf("%d", &n);
	f(i, n){
		scanf("%d", &k);
		k--;
		if (b[k] > c[k])printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
