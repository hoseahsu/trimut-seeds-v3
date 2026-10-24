#include <stdio.h>
#include <algorithm>
using namespace std;
struct A{int w,d,l,pos;A() {w=d=l=0;}}RB[105];bool operator !=(A a, A b) {return a.w*3+a.d!=b.w*3+b.d;}bool operator <(A a, A b) {return a.w*3+a.d<b.w*3+b.d;}
int main() {
    int N,i,j,l,r,a,b,ans[105];scanf("%d",&N);for (i=0,j=(N*N-N)/2;i<j;i++) {scanf("%d %d %d %d",&l,&r,&a,&b);if (a>b) RB[l].w++,RB[r].l++; else if (a==b) RB[l].d++,RB[r].d++; else RB[l].l++,RB[r].w++;}
    for (i=1;i<=N;i++) RB[i].pos=i;sort(RB+1,RB+N+1);for (l=1,j=1,i=N;i;i--) 
	if (RB[i]!=RB[i-1]) {for (r=0;r<j;r++) ans[RB[i+r].pos]=l;l+=j,j=1;} else j++;for (i=1;i<=N;i++) printf("%d\n",ans[i]);return 0;}