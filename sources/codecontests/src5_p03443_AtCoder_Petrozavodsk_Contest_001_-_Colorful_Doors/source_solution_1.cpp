#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int n;
string str;
int isEdge[222222];
int cou[3];
int pointer[222222];
int ans[222222];
bool used[222222];

bool check(){
	vector<vector<int>> v(222222);
	vector<int> wapu(222222);
	REP(i,2*n){
		v[ans[i]].PB(i);
		if(ans[i] < 1 || ans[i] > n)exit(1);
	}
	for(int i = 1;i <= n;i++){
		wapu[v[i][0]] = v[i][1];
		wapu[v[i][1]] = v[i][0];
	}
	int now = wapu[0];
	while(1){
		used[now] = true;
		now++;
		if(now == 2*n)break;
		now = wapu[now];
	}
	//SHOW1d(used,2*n);
	REP(i,2*n-1){
		if(used[i]){
			if(str[i+1] != '1')return false;
		}
		else{
			if(str[i+1] != '0')return false;
		}
	}
	return true;
}

int main(){

	REP(i,222222)pointer[i] = i;

	cin >> n;

	cin >> str;
	str = '1' + str + '1';

	REP(i,2*n){
		int tmp = 0;
		isEdge[i] = ((str[i] == '1') + (str[i+1] == '1'));
		cou[isEdge[i]]++;
	}

	//SHOW1d(isEdge,2*n);
	//SHOW1d(cou,3);

	if(cou[2] % 2){
		cout << "No" << endl;
		return 0;
	}

	int nowNum = 1;

	if(cou[2] % 4 == 2){
		vector<vector<int>> paths;
		vector<int> path;
		int pla = 0;
		REP(i,2*n){
			if(isEdge[2*n-1-i] == 1){
				pla = 2*n-1-i;
				break;
			}
		}
		for(int i = 0;i < 2*n;i++){
			int place = (i + pla) % (2*n);
	//		cout << "place is " << place << endl;
			if(isEdge[place] == 0){

			}
			else if(isEdge[place] == 1){
				path.PB(place);
				if(path.size() > 1){
					if(path.size() > 2){
						paths.PB(path);
					}
					path.clear();
				}
			}
			else{
				path.PB(place);
			}
		}
		if(paths.size() <= 1){
			cout << "No" << endl;
			return 0;
		}
/*
		REP(i,paths.size()){
			REP(j,paths[i].size()){
				cout << paths[i][j] << " ";
			}
			cout << endl;
		}
*/
		ans[paths[0][1]] = 1;
		ans[paths[1][1]] = 1;
		nowNum++;
		isEdge[paths[0][1]] = -1;
		isEdge[paths[1][1]] = -1;
		swap(pointer[paths[0][0]],pointer[paths[1][0]]);
	}

	vector<int> seica;
	REP(i,2*n){
		if(isEdge[i] == 1)seica.PB(i);
		if(seica.size() == 2){
			ans[pointer[seica[0]]] = nowNum;
			ans[pointer[seica[1]]] = nowNum;
			nowNum++;
			seica.clear();
		}
	}

	REP(i,2*n){
		if(isEdge[pointer[i]] == 2)seica.PB(i);
		if(seica.size() == 4){
			ans[seica[0]] = nowNum;
			ans[seica[1]] = nowNum + 1;
			ans[seica[2]] = nowNum;
			ans[seica[3]] = nowNum + 1;
			nowNum+=2;
			seica.clear();
		}
	}

	REP(i,2*n){
		if(isEdge[i] == 0)seica.PB(i);
		if(seica.size() == 2){
			ans[seica[0]] = nowNum;
			ans[seica[1]] = nowNum;
			nowNum++;
			seica.clear();
		}
	}

	cout << "Yes" << endl;
	REP(i,2*n)cout << ans[i] << ' ';cout << endl;

	return 0;
}
