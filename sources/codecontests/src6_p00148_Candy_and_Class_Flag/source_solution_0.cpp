#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main() {
	int n;
	while (cin >> n) {
		if (!(n % 39))puts("3C39");
		else printf("3C%02d\n", n % 39);
	}
}