/*
 * a.cc: 
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

const int ps[5] = {2, 3, 5, 7, 11};

/* typedef */

/* global variables */

int fs[5];

/* subroutines */

/* main */

int main() {
  int n;
  cin >> n;
  //printf("%d\n", 1 << (n - 1));

  for (int k = 1;; k++) {
    int cnt = 0;
    for (int i = 1; i * i <= k; i++)
      if (k % i == 0)
	cnt += (i * i == k) ? 1 : 2;
    if (cnt == n) {
      printf("%d\n", k);
      break;
    }
  }
}