#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=4040;
char a[N], b[N];
int lena, lenb;
int na[N][2], nb[N][2];
void parse(char* s, int& len, int nxt[N][2]){
  scanf("%s", s);
  len=strlen(s);
  int tnxt[2];
  tnxt[0]=tnxt[1]=len;
  nxt[len][0]=len;
  nxt[len][1]=len;
  for(int i=len-1; i>=0; i--){
    tnxt[s[i]-'0']=i;
    for(int j=0; j<2; j++)
      nxt[i][j]=tnxt[j];
  }
}
short dp[N][N];
bool tg[N][N];
int DP(int i, int j){
  i=min(i, lena);
  j=min(j, lenb);
  if(i>=lena and j>=lenb) return 1;
  if(tg[i][j]) return dp[i][j];
  int tdp=N;
  for(int d=0; d<2; d++){
    int ni=na[i][d];
    int nj=nb[j][d];
    if(ni>=lena and nj>=lenb)
      tdp=min(tdp, 1);
    else
      tdp=min(tdp, 1+DP(ni+1, nj+1));
  }
  tg[i][j]=true;
  return dp[i][j]=tdp;
}
void con(int i, int j){
  while(true){
    i=min(i, lena);
    j=min(j, lenb);
    if(i>=lena and j>=lenb){
      printf("0");
      return;
    }
    for(int d=0; d<2; d++){
      int ni=na[i][d];
      int nj=nb[j][d];
      if(ni>=lena and nj>=lenb){
        if(dp[i][j] == 1){
          printf("%d", d);
          return;
        }
      }else{
        if(1+DP(ni+1, nj+1) == dp[i][j]){
          printf("%d", d);
          i=ni+1;
          j=nj+1;
          break;
          //con(ni+1, nj+1);
          //return;
        }
      }
    }
  }
}
int main(){
  parse(a, lena, na);
  parse(b, lenb, nb);
  for(int i=lena; i>=0; i--)
    for(int j=lenb; j>=0; j--)
      DP(i, j);
  // int ans=DP(0, 0);
  // cout<<ans<<endl;
  con(0, 0);
  puts("");
}
