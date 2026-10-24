#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

#define EPS (1e-10)
#define EQ(a,b) (abs((a)-(b))<EPS)

using namespace std;

int main(){
	int an,bn,r;
	int flyX[100001];
	int flyY[100001];
	int px,py;
	vector<int> energy[10001];
	int sum;
	while(cin>>an>>bn>>r&&!(an==0&&bn==0&&r==0)){
		for(int i = 0; i < 10001; i++){
			energy[i].clear();
		}
		for(int i = 0; i < an; i++){
			cin>>flyX[i]>>flyY[i];
		}
		int infoMinX=10000000;
		int infoMaxX=-1;
		
		for(int i = 0; i < bn; i++){
			cin>>px>>py;
			energy[px].push_back(py);
		}
		for(int i = 0; i < 10001; i++){
			sort(energy[i].begin(),energy[i].end());
		}
		sum=0;
		for(int i = 0; i < an; i++){
			int minx=max(0,flyX[i]-4*r);
			int maxx=min(9999,flyX[i]+4*r);
			for(int j = minx; j <= maxx; j++){
				if(energy[j].empty())
					continue;
				int ovlimit=(int)(sqrt((double)(-((flyX[i]-j)*(flyX[i]-j))+16*r*r))+flyY[i]+EPS);
				double lolimit2=(-sqrt((double)(-((flyX[i]-j)*(flyX[i]-j))+16*r*r))+flyY[i]);
				int lolimit=(int)(lolimit2+EPS);
				if(!EQ(lolimit2,(int)lolimit2)){
					lolimit++;
				}
				sum+=(upper_bound(energy[j].begin(),energy[j].end(),ovlimit)
					-lower_bound(energy[j].begin(),energy[j].end(),lolimit));
			}
		}
		cout<<sum<<endl;
	}

	return 0;
}