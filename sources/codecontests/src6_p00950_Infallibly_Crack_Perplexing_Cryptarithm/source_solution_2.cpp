#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)N;i++)
#define rep1(i,N) for(int i=1;i<=(int)N;i++)
#define pb push_back
#define all(c) c.begin(),c.end()
#define show(x) cout<<#x<<" "<<x<<endl
using namespace std;
typedef long long ll;
const ll NO=1e15;
ll ex(const string& s,int& it);

ll dig(const string& s,int &it){
	if(s[it]=='0'&&isdigit(s[it+1])) return NO;
	ll x=0;
	while(isdigit(s[it])){
		x=x*2+s[it]-'0';
		it++;
	}
	return x;
}
ll fac(const string& s,int& it){
	if(isdigit(s[it])){
		return dig(s,it);
	}
	if(s[it]=='-'){
		it++;
		ll ret=fac(s,it);
		if(ret==NO) return NO;
		return -ret;
	}
	if(s[it]=='('){
		it++;
		ll ret=ex(s,it);
		if(ret==NO) return NO;
		if(s[it]!=')') return NO;
		it++;
		return ret;
	}
	return NO;
}

ll term(const string& s,int& it){
	ll ret=fac(s,it);
	if(ret==NO) return NO;
	while(s[it]=='*'){
		it++;
		ll x=fac(s,it);
		if(x==NO) return NO;
		ret*=x;
	}
	return ret;
}

ll ex(const string& s,int& it){
	ll ret=term(s,it);
	if(ret==NO) return NO;
	while(s[it]=='+' || s[it]=='-'){
		bool isp=(s[it]=='+');
		it++;
		ll x=term(s,it);
		if(x==NO) return NO;
		if(isp) ret+=x;
		else ret-=x;
	}
	if(s[it]!=')' && s[it]!='$') return NO;
	return ret;
}
bool eq(const string& s){
//	cout<<s<<endl;
	int N=s.size();
	int e=-1;
	rep(i,N){
		if(s[i]=='='){
			if(e==-1) e=i;
			else return 0;
		}
	}
	if(e==-1) return 0;
	int it=0;
	string X=s.substr(0,e)+"$";
	ll x=ex(X,it);
	if(X[it]!='$') x=NO;
	if(x==NO) return 0;
	it=0;
	string Y=s.substr(e+1)+"$";
	ll y=ex(Y,it);
	if(Y[it]!='$') y=NO;
	if(y==NO) return 0;
	return x==y;
}

string S;
string rs="01+-*()=";
vector<char> cs;
int sel[8];
int K;
int ans;
void dfs(int d){
	if(d==K){
		string s=S;
		rep(i,K){
			rep(j,s.size()) if(s[j]==cs[i]) s[j]=rs[sel[i]];
		}
		if(eq(s)) ans++;
		return;
	}
	rep(i,8){
		bool canuse=1;
		rep(j,d) if(sel[j]==i) canuse=0;
		if(!canuse) continue;
		sel[d]=i;
		dfs(d+1);
	}
}
int main(){
	cin>>S;
	rep(i,S.size()) if(isalpha(S[i])){
		cs.pb(S[i]);
	}
	sort(all(cs));
	cs.erase(unique(all(cs)),cs.end());
	K=cs.size();
	if(K>8){
		puts("0");
		return 0;
	}
	dfs(0);
	cout<<ans<<endl;
}