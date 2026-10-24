#include <cstdio>
#include <iostream>

using namespace std;
     
const int MAX_N = 100001;
     
int N, Q;
int par[MAX_N]; 
bool marked[MAX_N];

void init() {
  for (int i = 0; i <= N; i++) {
    par[i] = i;
  }
}

int search(int x) {
  if (marked[x]) return x;
  else return search(par[x]);
}
  
int main()
{
  marked[1] = true;
  while(1){
    int num;
    char ope;
    long long int ans;
    
    scanf("%d %d", &N, &Q);
    if(N == 0 && Q == 0) break;
    init();
    ans = 0;
    
    for(int i = 2; i <= N; i++){
      scanf("%d", &num);
      par[i] = num;
      marked[i] = false;
    }

    for(int i = 0; i < Q; i++){
      scanf(" %c", &ope);
      scanf("%d", &num);
      if (ope == 'M') {
        marked[num] = true;
      }
      else if(ope == 'Q'){
        ans += search(num);
      }
    }
    
    printf("%lld\n", ans);
  }
  return 0;
}