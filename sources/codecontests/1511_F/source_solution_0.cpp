#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <time.h>
#include <complex>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <bitset>

#pragma warning(disable:4996)
#define PII std::pair<long long, long long>
#define PTT std::pair<tree *, tree *>

template<typename T> T min(T x, T y)
{
	return x < y ? x : y;
}
template<typename T> T max(T x, T y)
{
	return x > y ? x : y;
};

const long long INF = 2000000005;//00000;// autojs.org
const long long mod = 998244353;//1000000007;// 
const int MAXN = 180;

struct vector {
	long long e[MAXN];
	vector() { memset(e, 0, sizeof(e)); }
	vector operator * (int a)
	{
		vector t = *this;
		for (int i = 0; i < MAXN; i++)
			t.e[i] = t.e[i] * a % mod;
		return t;
	}
	vector operator + (vector t)
	{
		for (int i = 0; i < MAXN; i++)
			t.e[i] = (t.e[i] + e[i]) % mod;
		return t;
	}
};
struct matrix {
	vector c[MAXN];
	
	vector operator * (vector &v)
	{
		vector t;
		for (int i = 0; i < MAXN; i++)
			t = t + c[i] * v.e[i];
		return t;
	}
	matrix operator * (matrix &m)
	{
		static matrix t;
	//	for (int i = 0; i < MAXN; i++)
	//		t.c[i] = (*this) * m.c[i];
		for (int i = 0; i < MAXN; i++)
			for (int j = 0; j < MAXN; j++)
			{
				t.c[j].e[i] = 0;
				for (int k = 0; k < MAXN; k++)
					t.c[j].e[i] += c[k].e[i] * m.c[j].e[k] % mod;
				t.c[j].e[i] %= mod;
			}
		return t;
	}
	long long &get(int i, int j) { return c[j].e[i]; }
	void print(int n)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				printf("%lld%c", c[j].e[i], j == n - 1 ? '\n' : ' ');
	}
	static matrix ID()
	{
		static matrix I;
		for (int i = 0; i < MAXN; i++)
			I.get(i, i) = 1;
		return I;
	}
};
void qpow(matrix &A, int x)
{
	if (!x)
	{
		A = matrix::ID();
		return;
	}
	if (x & 1)
	{
		matrix t = A;
		qpow(A, x / 2);
		A = A * A * t;
	}
	else
	{
		qpow(A, x / 2);
		A = A * A;
	}
}

bool streql(char *a, char *b, int len)
{
	for (int i = 0; i < len; i++)
		if (a[i] != b[i])
			return false;
	return true;
}

matrix A;
int N, M, len[10];
char str[10][10];
int _id[10][10][10];

int id(int n, int i, int j)//j<=i
{
	return _id[n][i][j];
	return n * 25 + i * 5 + j;
}
void init()
{
	int tt = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k <= j; k++)
				_id[i][j][k] = tt++;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", str[i]), len[i] = strlen(str[i]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < len[i]; j++)
			for (int k = 0; k <= j; k++)
			{
				if (j == 0)
				{
					for (int s = 0; s < N; s++)
						for (int t = 0; t < N; t++)
							if (len[t] <= len[s] && streql(str[s], str[t], len[t]))
								A.get(id(s, len[s] - 1, len[t] - 1), id(i, j, k))
								+= 1ll + (len[t] != len[s]);
					continue;
				}
				if (k == 0)
				{
					for (int s = 0; s < N; s++)
					{
						if (len[s] <= j && streql(str[i] + len[i] - j, str[s], len[s]))
							A.get(id(i, j - 1, len[s] - 1), id(i, j, k))++;
						else if (len[s] > j && streql(str[i] + len[i] - j, str[s], j))
							A.get(id(s, len[s] - 1, j - 1), id(i, j, k))++;
					}
					continue;
				}
				A.get(id(i, j - 1, k - 1), id(i, j, k))++;
			}
}
void solve()
{
	vector v;
	v.e[id(0, 0, 0)] = 1;
	matrix m = A;
	qpow(m, M);
	v = m * v;
	long long ans = 0;
	for (int i = 0; i < N; i++)
		ans = (ans + v.e[id(i, 0, 0)]) % mod;
	printf("%lld\n", ans);
}

int main()
{
	init();
	solve();

	return 0;
}