#include <algorithm>
#define IN(x,s,g) ((x) >= (s) && (x) < (g))
#define ISIN(x,y,w,h) (IN((x),0,(w)) && IN((y),0,(h)))

#include <queue>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#include <cstdio>
inline int getInt(){ int s; scanf("%d", &s); return s; }

#include <set>

using namespace std;

char b[64][64];
int w, h;

inline int id(int x, int y){
  return y * w + x;
}

int dx[6] = { 0, 1, 1, 0, -1, -1 };
int dy[2][6] = {
  { 1, 1, 0, -1, 0, 1 },
  { 1, 0, -1, -1, -1, 0 }
};

#define REPEX(x, y, xx, yy) \
 for(int _ = 0, xx, yy; (_ < 6) && ((xx = x + dx[_]), (yy = y + dy[x % 2][_]), true); _++)

int memo[64][64];

int dfs(int y, int x, int id){
  int ret = 1;
  memo[y][x] = id;
  REPEX(x, y, xx, yy) if(ISIN(xx, yy, w, h) && b[yy][xx] == b[y][x] && memo[yy][xx] == -1){
    ret += dfs(yy, xx, id);
  }
  return ret;
}

void printBoard(){
  REP(i,h){
    puts(b[h - i - 1]);
  }
}

bool erase(){
  bool ret = false;
  REP(i,h) REP(j,w) memo[i][j] = -1;
  int id = 0;
  vector<int> e(h * w);
  REP(i,h) REP(j,w) if(memo[i][j] == -1 && b[i][j] != '.'){
    const int cnt = dfs(i, j, id);
    if(cnt >= 3){ e[id] = 1; ret = true; }
    id++;
  }
  REP(i,h) REP(j,w) if(memo[i][j] != -1 && e[memo[i][j]])
    b[i][j] = '.';
  // printBoard(); REP(i,h){ REP(j,w) printf("%d ", memo[i][j]); puts(""); }
  return ret;
}

bool canDrop(int x, int y){
  for(int i = 2; i <= 4; i++){
    const int xx = x + dx[i];
    const int yy = y + dy[x % 2][i];
    if(ISIN(xx, yy, w, h) && b[yy][xx] != '.') return false;
  }
  return true;
}

bool drop(){
  bool ret = false;
  REP(i,h - 1){
    const int y = i + 1;
    for(int x = 1; x < w; x += 2){
      if(b[y][x] == '.') continue;
      int yy = y;
      while(yy > 0 && canDrop(x, yy)){ yy--; ret = true; }
      if(y != yy) swap(b[yy][x], b[y][x]);
    }
    for(int x = 0; x < w; x += 2){
      if(b[y][x] == '.') continue;
      int yy = y;
      while(yy > 0 && canDrop(x, yy)){ yy--; ret = true; }
      if(y != yy) swap(b[yy][x], b[y][x]);
    }
  }
  // printf("drop: %d\n", ret);
  return ret;
}

bool rotate(int x, int y){
  REPEX(x, y, xx, yy) if(!ISIN(xx, yy, w, h)) return false;

  for(int i = 0; i < 5; i++){
    const int p = (6 - i) % 6;
    const int q = (5 - i) % 6;
    swap(b[y + dy[x % 2][p]][x + dx[p]],
         b[y + dy[x % 2][q]][x + dx[q]]);
  }

  return true;
}

void process(){
  while(drop() || erase());
}

int main(){
  h = getInt(); w = getInt();
  REP(i,h) scanf("%s", b[h - i - 1]);

  process();
  const int q = getInt();
  REP(_,q){
    const int x = getInt();
    const int y = getInt();
    if(rotate(x, y)) process();
  }

  printBoard();
  return 0;
}
