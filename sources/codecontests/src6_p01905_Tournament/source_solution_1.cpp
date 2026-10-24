#define REP(i,n) for(int i=0; i<(int)(n); i++)

#include <queue>
#include <cstdio>
inline int getInt(){ int s; scanf("%d", &s); return s; }

#include <set>

using namespace std;

int main(){
  const int n = getInt();
  const int m = getInt();

  vector<int> v(n, 1);

  REP(i,m) v[getInt()] = 0;

  int cnt = 0;
  while(v.size() > 1) {
    vector<int> next;
    REP(i,v.size()/2){
      if(v[2 * i] * v[2 * i + 1] != 0) cnt++;
      next.push_back(max(v[2 * i], v[2 * i + 1]));
    }
    v.swap(next);
  }

  printf("%d\n", cnt);
  return 0;
}