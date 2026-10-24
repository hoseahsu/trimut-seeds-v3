#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
typedef complex<double> P;
const int V = 6;

bool solve(string &s){
  int v[V][2];
  v[0][0] = 1; v[0][1] = 2;
  v[1][0] = -1; v[1][1] = 3;
  v[2][0] = 1; v[2][1] = -1;
  v[3][0] = 4; v[3][1] = 5;
  v[3][0] = 4; v[3][1] = 5;
  v[4][0] = 5; v[4][1] = 2;
  v[5][0] = 2; v[5][1] = 1;
  int n = 0;
  REP(i, s.length()){
    if(v[n][s[i] - '0'] == -1) return false;
    n = v[n][s[i] - '0'];
  }
  return (n == 5 ? true : false);
}

int main() {
  string s;
  while(cin >>s && s != "#") cout <<(solve(s) ? "Yes" : "No") <<endl;
  return 0;
}