#include<iostream>
#include<algorithm>
#define FOR(i,e) for(int i=0;i<(int)(e);i++)
using namespace std;

int main(){
  double pb[100][5001];
  int x,y,z;
  int v[4],e[100],a[100];

  while(cin >> x >> y >> z && (x||y||z)){

    FOR(i,x)cin >> v[i];
    FOR(i,y+1)e[i] = a[i] = 0;
    FOR(i,z){
      int n,m,l;
      cin >> n >> m >> l;
      e[n] = m; a[n] = l;
    }

    FOR(i,y+1)FOR(j,5001)pb[i][j] = 0.0;
    pb[0][0] = 1.0;

    FOR(i,y)FOR(j,5001){
      FOR(k,x){
	if(pb[i][j] == 0.0)continue;
	int next = min(y,i+v[k]),value = j;
	if(e[next] == 1)next = min(y,next+a[next]);
	else if(e[next] == 2)value = j + a[next];
	else if(e[next] == 3)value = max(0,j-a[next]);
	pb[next][value] += pb[i][j]/x;
      }
    }

    double ans = 0.0;
    FOR(i,5001)ans += pb[y][i] * i;
    cout << (int)(ans) << endl;
  }
}