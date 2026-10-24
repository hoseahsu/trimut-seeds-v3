#include<cstdio>
const int MaxN=200010;
int N,L,A[MaxN],ch[MaxN][2],stk[MaxN];
struct List{
	int*s,*t,*a,*b,n,sum,sumL;
	void reb(){
		if(!n)n++;
		int*ns=new int[n*3+1];
		if(s)for(int i=1;i<=n;i++)ns[n+i]=a[i];
		a=ns+n;t=a+n*2;b=a+(s?n:--n);s=ns;
	}
	int get(int i){return i>0&&i<=b-a?a[i]:0;}
	void pb(int x){
		if(!s||b==t)reb();*++b=x;
		if(++n>=L-1)sumL+=x;sum+=x;
	}
	void pf(int x){
		if(!s||a==s)reb();*a--=x;
		++n;sum+=x;sumL+=get(L-1);
	}
}V[MaxN][2];
bool fail[MaxN][2];
List mer(List l1,List l2,bool ty=0){
	if(l1.n>l2.n)return mer(l2,l1,1);
	ty?l2.pb(1):l2.pf(1);
	if(ty)for(int i=1;i<=l1.n;i++)l2.pb(l1.a[i]);
	else for(int i=l1.n;i;i--)l2.pf(l1.a[i]);
	return l2;
}
List cont(List l,int d){
	while(d--&&l.n){
		List nl=(List){0,0,0,0,0,0,0};
		for(int i=L;i<=l.n;i+=L){
			int x=0;
			for(int j=0;j<L;j++)x+=l.get(i+j);
			nl.pb(x);
		}
		l=nl;
	}
	return l;
}
long long qry(List&l1,List&l2){
	if(l1.n>l2.n)return qry(l2,l1);
	long long s=0;
	int tmp=l2.sumL;
	for(int i=1;i<=l1.n&&i<L-1;i++)s+=1ll*l1.get(i)*(tmp+=l2.get(L-i-1));
	return s+1ll*l1.sumL*l2.sum;
}
long long dfs(int o){
	long long s=1;
	for(int c=0,x;c<2;c++)if(x=ch[o][c]){
		s+=dfs(x);
		for(int t=0;t<2;t++)V[x][t]=cont(V[x][t],A[o]-A[x]);
		s+=V[x][!c].sumL;
	}
	s+=qry(V[ch[o][0]][1],V[ch[o][1]][0]);
	for(int c=0,x,y;c<2;c++){
		if((x=ch[o][c])&&!V[x][c].n||fail[x][c])fail[o][c]=1,V[o][c]=V[x][c];
		else y=ch[o][!c],fail[o][c]=y&&!V[y][c].n||fail[y][c],V[o][c]=mer(V[x][c],V[y][c]);
	}
	return s;
}
int main(){
	scanf("%d%d",&N,&L);
	int*top=stk;
	for(int i=1;i<=N;i++){
		scanf("%d",A+i);
		for(;top>stk&&A[*top]<A[i];top--)
			ch[i][0]=ch[top[-1]][1]=*top;
		*++top=i;
	}
	for(;top>stk;top--)ch[top[-1]][1]=*top;
	printf("%lld\n",dfs(stk[1]));
}