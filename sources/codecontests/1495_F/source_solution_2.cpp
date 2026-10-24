#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,i,j,ii,jj,zx,xc,tes,t,f[200009],A[200009],B[200009],rg[200009][20],rgx[200009][20],lf[200009][20],lfx[200009][20],P[200009],pas;
stack <long long> st;
set <long long> s;
set <long long>::iterator it,lft,rgt;
long long uprg(long long q, long long w){
	if(q>=w) return 0;
	long long jm=0;
	long long h=0;
	for(h=18; h>=0; h--){
		if(rg[q][h]!=0&&rg[q][h]<w){
			jm+=rgx[q][h];
			q=rg[q][h];
		}
	}
	jm+=rgx[q][0];
	return jm;
}
long long uplf(long long q, long long w){
	if(w<=q) return 0;
	long long jm=0;
	long long h=0;
	for(h=19; h>=0; h--){
		if(lf[w][h]!=0&&lf[w][h]>q){
			jm+=lfx[w][h];
			w=lf[w][h];
		}
	}
	jm+=lfx[w][0];
	return jm;
}
long long fun(long long q, long long w){
	if(q>=w) return 0;
	long long jm=0;
	long long h=0;
	for(h=18; h>=0; h--){
		if(rg[q][h]!=0&&rg[q][h]<=w){
			jm+=rgx[q][h];
			q=rg[q][h];
		}
	}
	if(q==w) return jm;
	jm+=uplf(q,w);
	return jm;
}
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>tes;
	for(i=1; i<=a; i++) cin>>f[i];
	for(i=1; i<=a; i++) cin>>A[i];
	for(i=1; i<=a; i++) cin>>B[i];
	while(st.size()) st.pop();
	st.push(a+1);
	f[a+1]=a+2;
	for(i=a; i>=1; i--){
		while(st.size()>0&&f[st.top()]<f[i]) st.pop();
		if(st.size()==0){
			
		}else{
			rg[i][0]=st.top();
			rgx[i][0]=min(B[i],A[i]+uprg(i+1,st.top()));
		}
		for(j=1; j<=18; j++){
			rg[i][j]=rg[rg[i][j-1]][j-1];
			rgx[i][j]=rgx[i][j-1]+rgx[rg[i][j-1]][j-1];
		}
		st.push(i);
	}
	while(st.size()) st.pop();
	for(i=1; i<=a; i++){
		while(st.size()>0&&f[st.top()]<f[i]) st.pop();
		if(st.size()==0){
			
		}else{
			lf[i][0]=st.top();
			lfx[i][0]=A[st.top()]+uprg(st.top()+1,i);
		}
		for(j=1; j<=18; j++){
			lf[i][j]=lf[lf[i][j-1]][j-1];
			lfx[i][j]=lfx[i][j-1]+lfx[lf[i][j-1]][j-1];
		}
		st.push(i);
	}
	s.insert(1);
	s.insert(a+1);
	P[1]=fun(1,a+1);
	pas+=P[1];
	for(t=1; t<=tes; t++){
		cin>>c;
		if(c==1){
			cout<<pas<<endl;
			continue;
		}
		it=s.lower_bound(c);
		if(it==s.end()||(*it)!=c){
			P[c]=fun(c,(*it));
			pas+=P[c];
			lft=it;lft--;
			pas-=P[(*lft)];
			P[(*lft)]=fun((*lft),c);
			pas+=P[(*lft)];
			s.insert(c);
		}else{
			lft=it;lft--;
			pas-=P[(*lft)];
			rgt=it;rgt++;
			pas-=P[c];
			P[(*lft)]=fun((*lft),(*rgt));
			pas+=P[(*lft)];
			s.erase(it);
		}
		cout<<pas<<endl;
	}
	P[0]=2*6;
	pas=P[0]+5;
	return 0;
}