#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
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

const int MAX_N = 500;
const int INF = 1 << 30;

/* typedef */

typedef pair<int,int> pii;
typedef map<string,int> msi;
typedef vector<pii> vpii;

/* global variables */

int n, m, nst;
string sstr, pstr, gstr;
int si, pi, gi;
msi sids;
vpii nbrs[MAX_N];
int dists[MAX_N];

/* subroutines */

int sid(string str) {
  msi::iterator mit = sids.find(str);
  if (mit == sids.end()) return (sids[str] = nst++);
  return mit->second;
}

int mindist(int st, int gl) {
  for (int i = 0; i < n; i++) dists[i] = INF;
  dists[st] = 0;

  priority_queue<pii,vector<pii>,greater<pii> > q;
  q.push(pii(0, st));

  while (! q.empty()) {
    pii u = q.top(); q.pop();
    int ud = u.first;
    int ui = u.second;

    if (ud != dists[ui]) continue;
    if (ui == gl) break;

    vpii nbru = nbrs[ui];
    for (vpii::iterator vit = nbru.begin(); vit != nbru.end(); vit++) {
      int vi = vit->first;
      int vd = ud + vit->second;

      if (dists[vi] > vd) {
	dists[vi] = vd;
	q.push(pii(vd, vi));
      }
    }
  }

  return dists[gl];
}

/* main */

int main() {
  for (;;) {
    cin >> n >> m;
    if (n == 0) break;

    sids.clear();
    for (int i = 0; i < n; i++) nbrs[i].clear();
    
    cin >> sstr >> pstr >> gstr;

    nst = 0;
    si = sid(sstr);
    pi = sid(pstr);
    gi = sid(gstr);

    for (int i = 0; i < m; i++) {
      string astr, bstr;
      int di, ti;
      cin >> astr >> bstr >> di >> ti;

      int ai = sid(astr);
      int bi = sid(bstr);
      int d = di / 40 + ti;
      nbrs[ai].push_back(pii(bi, d));
      nbrs[bi].push_back(pii(ai, d));
    }

    int mind = mindist(si, pi) + mindist(pi, gi);
    cout << mind << endl;
  }

  return 0;
}