#include <stdio.h>

int n; long long c[100100], s;

int main()
{
  scanf ("%d",&n);
  for (int i=0,x;i<n;i++){
    scanf ("%d",&x); c[x]++;
    s += x;
  }
  int q; scanf ("%d",&q); while (q--){
int x,y; scanf ("%d %d",&x,&y);
    s -= x * c[x];
    s += y * c[x];
    c[y] += c[x];
    c[x] = 0;
    printf ("%lld\n",s);
  }
	return 0;
}