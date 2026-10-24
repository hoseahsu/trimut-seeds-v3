#include <bits/stdc++.h>

#define For(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

const int N = 110;

int n, cnt[N];
int Mx;

void fail(){
	puts("Impossible");
	exit(0);
}

int main(){
	scanf("%d", &n);
	For(i, 1, n){
		int x;
		scanf("%d", &x);
		cnt[x]++;
		Mx = max(Mx, x);
	}

	if(Mx & 1){
		int mid = Mx / 2 + 1;
		For(i, 0, mid - 1) if(cnt[i]) fail();
		if(cnt[mid] != 2) fail();
		For(i, mid + 1, Mx) if(cnt[i] < 2) fail();
	}
	else{
		int mid = Mx / 2;
		For(i, 0, mid - 1) if(cnt[i]) fail();
		if(cnt[mid] != 1) fail();
		For(i, mid + 1, Mx) if(cnt[i] < 2) fail();
	}

	puts("Possible");
	return 0;
}