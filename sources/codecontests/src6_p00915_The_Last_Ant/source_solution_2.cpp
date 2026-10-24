//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, L;
  while(cin>>N>>L, N){
	VI d(N), p(N), gp[2];
	REP(i,N){
	  char ch; cin >> ch >> p[i];
	  d[i] = (ch == 'R'? 1: -1);
	  gp[p[i]%2].PB(i);
	}

	int id[2] = {0,0}, ans_t[2] = {0,0};
	for(int g=0;g<2;++g){
	  bool up = true;
	  for(;up;++ans_t[g]){
		up = false;
		for(int i=SZ(gp[g])-1;i>=0;--i){
		  int idx = gp[g][i];
		  int tx = p[idx] + d[idx];
		  if(tx < 0 || tx > L) continue;
		  if(tx == 0 || tx == L){
			p[idx] = tx;
			id[g] = (idx+1) * d[idx];
			continue;
		  }

		  up = true;
		  if(i > 0){
			int pidx = gp[g][i-1];
			if(p[pidx]+2 == p[idx] && d[pidx] == 1 && d[idx] == -1){
			  p[idx]--; d[idx] *= -1;
			  p[pidx]++; d[pidx] *= -1;
			  --i;
			  continue;
			}
		  }
		  p[idx] = tx;
		}
	  }
	}
	if(ans_t[0] < ans_t[1] || (ans_t[0] == ans_t[1] && id[1] < 0))
	  cout << ans_t[1] << " " << abs(id[1]) << endl;
	else
	  cout << ans_t[0] << " " << abs(id[0]) << endl;
  }
  
  return 0;
}