/*  -*- coding: utf-8 -*-
 *
 * 3110.cc: Many Decimal Integers
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_N = 200000;
const int MOD = 1000000007;

/* typedef */

typedef long long ll;

/* global variables */

int dsums[10 + 1];
char s[MAX_N + 4], t[MAX_N + 4];

/* subroutines */

/* main */

int main() {
  for (int i = 0; i < 10; i++) dsums[i + 1] = dsums[i] + i;

  scanf("%s%s", s, t);
  int n = strlen(s);

  int dp0 = 0, n0 = 1;
  int dp1 = 0, n1 = 0;

  for (int i = 0; i < n; i++) {
    int si = s[i] - '0';
    int tdp0 = (ll)dp0 * 10 % MOD;
    int tdp1 = (ll)dp1 * 10 % MOD;

    if (t[i] != '?') {
      int ti = t[i] - '0';
      int nd0 = (tdp0 + (ll)ti * n0 % MOD) % MOD;
      int nd1 = (tdp1 + (ll)ti * n1 % MOD) % MOD;

      dp1 = nd1;
      if (ti == si)
	dp0 = nd0;
      else if (ti < si) {
	dp1 = (dp1 + nd0) % MOD;
	dp0 = 0;
	n1 = (n1 + n0) % MOD;
	n0 = 0;
      }
      else {
	dp0 = 0;
	n0 = 0;
      }
    }
    else { // t[i] == '?'
      int nd0 = (tdp0 + (ll)si * n0 % MOD) % MOD;
      int nd1 = ((ll)tdp0 * si % MOD + (ll)dsums[si] * n0 % MOD) % MOD;
      int nd2 = ((ll)tdp1 * 10 % MOD + (ll)dsums[10] * n1 % MOD) % MOD;

      dp0 = nd0;
      dp1 = (nd2 + nd1) % MOD;
      n1 = ((ll)n0 * si % MOD + (ll)n1 * 10 % MOD) % MOD;
    }
  }

  printf("%d\n", (dp0 + dp1) % MOD);
  return 0;
}

