//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define ll long long
const int mod=998244353,inv2=(mod+1)>>1;
inline int fix(int x){return x+((x>>31)&mod);}
inline int add(int x,int y){return fix(x+y-mod);}
inline int dec(int x,int y){return fix(x-y);}
inline int mul(int x,int y){return (ll)x*y%mod;}
inline void ADD(int &x,int y){x=fix(x+y-mod);}
inline void DEC(int &x,int y){x=fix(x-y);}
inline void MUL(int &x,int y){x=(ll)x*y%mod;}
inline int ksm(int x,int r){int ret=1;for(int i=0;(1ll<<i)<=r;i++){if((r>>i)&1)MUL(ret,x);MUL(x,x);}return ret;}
inline int inv(int x){return ksm(x,mod-2);}

const int N=2e5+4;
int n,Q,t,cnt,ans,fac[N],ifac[N];
char s[N],ss[4];
inline void prepare(){
	fac[0]=fac[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<=n;i++)fac[i]=mul(fac[i-1],i);
	ifac[n]=inv(fac[n]);
	for(int i=n-1;i;i--)ifac[i]=mul(ifac[i+1],i+1);
}
inline int C(int x,int y){
	return (x<y||y<0)?0:mul(fac[x],mul(ifac[y],ifac[x-y]));
}
struct node{
	int cnt,t,ans=1;
	inline void cntup(){
		ans=dec(add(ans,ans),C(cnt++,t));
		if(!cnt)ADD(ans,t>=0);
	}
	inline void cntdw(){
		ans=mul(add(ans,C(--cnt,t)),inv2);
		if(cnt<0)ans=0;
	}
	inline void tup(){
		ADD(ans,C(cnt,++t));
	}
	inline void tdw(){
		DEC(ans,C(cnt,t--));
	}
}a,b,c,d;
inline void tup(){a.tup();b.tup();t++;}
inline void tdw(){a.tdw();b.tdw();t--;}
inline void cntup(){a.cntup();b.cntup();c.cntup();d.cntup();c.tup();d.tup();cnt++;}
inline void cntdw(){a.cntdw();b.cntdw();c.cntdw();d.cntdw();c.tdw();d.tdw();cnt--;}
inline void ins(int i,char c){
	if(c=='b'){
//		cerr<<"sdf\n";
		if(i&1)tup();
		else tdw();
	} 
	else if(c=='?'){
//		cerr<<"sdf\n";
		cntup();
		if(i&1)tup();
	}
}
inline void era(int i,char c){
	if(c=='b'){
//		cerr<<"sdf\n"; 
		if(i&1)tdw();
		else tup();
	} 
	else if(c=='?'){
//		cerr<<"sdf\n";
		cntdw();
		if(i&1)tdw();
	}
}
inline void solve(){
	if(cnt==1){
		ans=0;
		for(int i=t&1;i<=cnt;i+=2)ADD(ans,mul(C(cnt,i),abs(i-t)));
	}
	else{
		ans=add(dec(mul(mul(2,fix(t)),a.ans),mul(mul(2,cnt),b.ans)),
			dec(mul(cnt,c.ans),mul(fix(t),d.ans)));
	}
	MUL(ans,inv(ksm(2,cnt)));
	cout<<ans<<"\n"; 
}
int main(){
//	freopen("1.in","r",stdin);
	n=read();Q=read();
	prepare();
	scanf("%s",s+1);
	a.cntdw();b.cntdw();c.cntdw();d.cntdw();//加法公式
	b.cntdw();c.cntdw();b.tdw();c.tdw();// \binom{cnt-1}{i-1} 
	for(int i=1;i<=n;i++)ins(i,s[i]);
	solve();
	for(int x;Q--;){
		x=read();scanf("%s",ss);
		era(x,s[x]);
		s[x]=ss[0];
		ins(x,s[x]);
		solve();
//		cerr<<cnt<<" "<<t<<" "<<a.ans<<" "<<b.ans<<" "<<c.ans<<" "<<d.ans<<"\n";
	}
	return (0-0);
}