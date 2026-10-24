#include <cstdio>
const int N = 200;
int n, l, r, m;
char L, R, M;
char ans[5], s[N];

void read_ans()
{
	printf("\n");
	fflush(stdout);
	scanf("%s", ans);
}

char ask(int x)
{
	printf("?");
	for (int i = 1; i <= n; ++i)
		printf(" %d", x + i - 1);
	read_ans();
	return ans[0];
}

char ask(int x, int y)
{
	printf("?");
	if (x < y || y + n < x)
	{
		printf(" %d", x);
		for (int i = 1; i <= n - 1; ++i)
			printf(" %d", y + i);
		read_ans();
		return ans[0];
	} 
	else 
	{
		for (int i = 0; i <= n; ++i)
			if (y + i != x)
				printf(" %d", y + i);
		read_ans();
		return ans[0] ^ 'R' ^ 'B';
	}
}

int main()
{
	scanf("%d", &n);
	l = 1, L = ask(l);
	r = n + 1, R = ask(r);
	while (l + 1 < r)
	{
		m = (l + r) / 2;
		M = ask(m);
		if (L == M)
			l = m;
		if (R == M)
			r = m;
	}
	for (int i = 1; i <= 2 * n; ++i)
		s[i - 1] = ask(i, l);
	printf("! %s\n", s);
	fflush(stdout);
}
