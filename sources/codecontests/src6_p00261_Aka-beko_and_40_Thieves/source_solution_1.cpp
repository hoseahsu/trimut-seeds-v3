#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 10000

int way[7][2] = {};


void calc(char *p){

  int now = 1;

  for(int i=0;p[i]!='\0';i++){
    now = way[now][p[i]-'0'];
  }

  if(now == 6)
    puts("Yes");
  else
    puts("No");

}

int main(){
  char p[SIZE];

  way[1][0] = 2;
  way[1][1] = 3;
  way[2][1] = 4;
  way[3][0] = 2;
  way[4][0] = 5;
  way[4][1] = 6;
  way[5][0] = 6;
  way[5][1] = 3;
  way[6][1] = 2;
  way[6][0] = 3;
  
  while(1){
    scanf("%s",p);
    if(p[0]=='#') break;
    calc(p);
  }
  
  return 0;
}