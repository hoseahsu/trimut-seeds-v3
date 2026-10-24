#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int memo[1 << 16][16];
int stat[5][5];

int val(int t, int b)
{
	return ((b >> 2 * t) & 3);
}

int calc(int bit, int y)
{
	int ret = 0;
	
	for (int i = 0; i < 5; i++){
		int k = stat[y][i];
		if (!~k) continue;
		k += (i ? val(i - 1, bit) + val(i + 3, bit) : 0) + (i != 4 ? val(i, bit) + val(i + 4, bit) : 0);
		k %= 4;
		ret += !!k * 50 + 10 * k;
	}
	return (ret);
}

int getMax(int bit, int pos)
{
	int ret = 0;
	
	if (pos && pos % 4 == 0) ret = calc(bit, pos / 4 - 1);
	if (pos == 16) return (ret + calc(bit & 0x00ff, 4));
	
	if (memo[bit][pos] >= 0) return (memo[bit][pos]);
	
	int t = 0;
	
	for (int i = 0; i < 4; i++) t = max(t, getMax(((bit << 2) | i) & 0xffff, pos + 1));
	
	return (memo[bit][pos] = ret + t);
}

int main()
{
	int n;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		
		for (int y = 0; y < 5; y++){
			for (int x = 0; x < 5; x++){
				scanf("%d", &stat[y][x]);
				stat[y][x]--;
			}
		}
		
		memset(memo, -1, sizeof(memo));
		printf("%d\n", getMax(0, 0));
	}
	
	return (0);
}