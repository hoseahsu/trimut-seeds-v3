#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001
using namespace std;

int main(){

	char buf[100001];
	int table[50001];

	ll ans = 0;

	for(int i = 0; i <= 50000; i++)table[i] = 0;

	int num = 0;

	scanf("%s",buf);

	for(int i = 0;buf[i] != '\0';i++){
		if(buf[i] == '(')num++;
		else{
			num--;
		}
		table[num]++;
	}

	for(int i = 0; i <= 50000; i++){
		if(table[i] >= 2){
			for(int k = 1; k <= table[i]-1; k++){
				ans += k;
			}
		}
	}

	printf("%lld\n",ans);

	return 0;
}