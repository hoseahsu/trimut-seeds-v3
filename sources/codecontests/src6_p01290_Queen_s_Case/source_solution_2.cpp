// Enjoy your stay.

#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

int H,W;
char c[32][32];
int a[2][32][32][32][32];
int rest[2][32][32][32][32];
int dy[] = {0,1,0,-1,0};
int dx[] = {1,0,-1,0,0};

typedef pair<int,pair<pair<int,int>,pair<int,int>>> state;

bool ok(int y,int x){return 0<=y && y<H && 0<=x && x<W
	&& (c[y][x] == '.' || c[y][x] == 'E');}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	while(cin>>W>>H && W){
		rep(i,H)cin>>c[i];
		int sqy,sqx,say,sax;
		rep(i,H)rep(j,W){
			if(c[i][j] == 'Q'){
				sqy=i, sqx=j, c[i][j] = '.';
			}
			if(c[i][j] == 'A'){
				say=i, sax=j, c[i][j] = '.';
			}
		}
		memset(a,0,sizeof(a));
		memset(rest,0,sizeof(rest));
		queue<state> Q;
		rep(qi,H)rep(qj,W)rep(ai,H)rep(aj,W)if(ok(qi,qj) && ok(ai,aj)){
			if(qi == ai && qj == aj){
				a[0][qi][qj][ai][aj] = -1;
				Q.push(mp(0,mp(mp(qi,qj),mp(ai,aj))));
			}
			else if(c[qi][qj] == 'E'){
				a[0][qi][qj][ai][aj] = 1;
				Q.push(mp(0,mp(mp(qi,qj),mp(ai,aj))));
			}
			else{
				rep(dir,5){
					int Qi = qi+dy[dir], Qj = qj+dx[dir];
					rest[0][qi][qj][ai][aj] += ok(Qi,Qj);
				}
			}
			rep(dir,5){
				int Ai = ai+dy[dir], Aj = aj+dx[dir];
				rest[1][qi][qj][ai][aj] += ok(Ai,Aj);
			}
		}
		while(sz(Q)){
			state q = Q.front(); Q.pop();
			int p = q.fir;
			int qy = q.sec.fir.fir, qx = q.sec.fir.sec;
			int ay = q.sec.sec.fir, ax = q.sec.sec.sec;
			int res = a[p][qy][qx][ay][ax];
			//cout<<p<<" "<<qy<<" "<<qx<<" "<<ay<<" "<<ax<<" : "<<res<<endl;
			if(p == 0){
				if(qy == sqy && qx == sqx && ay == say && ax == sax){
					if(res == 1)cout<<"Queen can escape."<<endl;
					else cout<<"Army can catch Queen."<<endl;
					goto end;
				}
				rep(dir,5){
					int Ay = ay+dy[dir], Ax = ax+dx[dir];
					if(!ok(Ay,Ax) || a[1][qy][qx][Ay][Ax] != 0)continue;
					if(res == 1){
						rest[1][qy][qx][Ay][Ax]--;
					}
					if(res == -1 || res == 1 && rest[1][qy][qx][Ay][Ax] == 0){
						a[1][qy][qx][Ay][Ax] = -res;
						Q.push(mp(1,mp(mp(qy,qx),mp(Ay,Ax))));
					}
				}
			}
			else{
				rep(dir,5){
					int Qy = qy+dy[dir], Qx = qx+dx[dir];
					if(!ok(Qy,Qx) || a[0][Qy][Qx][ay][ax] != 0)continue;
					if(res == 1){
						rest[0][Qy][Qx][ay][ax]--;
					}
					if(res == -1 || res == 1 && rest[0][Qy][Qx][ay][ax] == 0){
						a[0][Qy][Qx][ay][ax] = -res;
						Q.push(mp(0,mp(mp(Qy,Qx),mp(ay,ax))));
					}
				}
			}
		}
		cout<<"Queen can not escape and Army can not catch Queen."<<endl;
		end:;
	}
}