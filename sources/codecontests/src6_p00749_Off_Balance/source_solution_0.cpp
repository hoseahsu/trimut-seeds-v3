#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
typedef pair<int,int> P;
int w,h,dw[4]={1,0,-1,0},dh[4]={0,1,0,-1};
double eps=1e-8;
bool visited[61][10];
vector<string> vc;
struct st{
	bool ok;
	double wei,g;
};
vector<P> dfs(int hh,int ww,int id){
//	cout << "   " << hh << ww << id << endl;
	visited[hh][ww]=true;
	vector<P> ret;
	ret.push_back(P(hh,ww));
	rep(i,4){
		int nh=hh+dh[i],nw=ww+dw[i];
		if(0<=nw && nw<w && 0<=nh && nh<h && !visited[nh][nw] && vc[nh][nw]==id+'0'){
			vector<P> pl=dfs(nh,nw,id);
			ret.insert(ret.end(),pl.begin(),pl.end());
		}
	}
	return ret;
}
st stable(vector<P> b,double l,double r){
//	cout << "stable" << b[0].fs << " " << b[0].sc << endl;
	double al=0,w=4;
	rep(i,4) al+=b[i].sc;
	rep(i,4){
//		cout << "instable " << b[0].fs << " " << b[0].sc << "  i=" << i << endl;
		if(isdigit(vc[b[i].fs+1][b[i].sc]) && vc[b[i].fs+1][b[i].sc]!=vc[b[i].fs][b[i].sc] && !visited[b[i].fs+1][b[i].sc]){
			int id=vc[b[i].fs+1][b[i].sc]-'0';
//			cout << "id " << id << endl;
			vector<P> nb=dfs(b[i].fs+1,b[i].sc,id);
			double l=100,r=-100;
/*			rep(j,h+1){
				rep(k,w) cout << vc[h-j][k];
				cout << endl;
			}
			cout << nb.size() << endl;*/
			rep(j,4){
//				cout << "j " << j << " " << nb[j].fs << " " << nb[j].sc << endl;
				char c=vc[nb[j].fs-1][nb[j].sc];
				if(isdigit(c) && c!=id+'0') r=max(r,0.5+nb[j].sc),l=min(l,-0.5+nb[j].sc);
			}
//			cout << "end" << endl;
			st s=stable(nb,l,r);
			if(!s.ok) return {false,0,0};
			al+=s.wei*s.g;
			w+=s.wei;
		}
	}
	if(l+eps<al/w && al/w+eps<r){
//		cout << "l=" << l << " , r=" << r << " g=" << al/w << endl;
		return {true,w,al/w};
	}
	else return {false,0,0};
}
int main(){
	while(true){
		cin >> w >> h;
		if(!w) break;
		vc.clear();
		vc.push_back(string(w,'.'));
		rep(i,h){
			string s;
			cin >> s;
			vc.push_back(s);
		}
		reverse(vc.begin(),vc.end());
		int l=100,r=-100;
		rep(j,w) if(isdigit(vc[0][j])) l=min(l,j),r=max(r,j);
//		cout << l << r << endl;
		rep(i,h) rep(j,w) visited[i][j]=0;
		vector<P> f=dfs(0,l,vc[0][l]-'0');
//		cout << f.size() << endl;
		rep(i,h) rep(j,w) visited[i][j]=0;
		cout << (stable(f,-0.5+l,0.5+r).ok ? "" : "UN") << "STABLE\n";
	}
}