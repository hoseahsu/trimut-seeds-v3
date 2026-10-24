#include <cstdio>
#include <map>
#define INF 2000000000
#define fi first
#define sec second
using namespace std;
typedef pair<int,int> P;
const int MAX_N = 1 << 21;

int n, q;
P dat[2*MAX_N-1];

void init(int n_){
	n = 1;
	while(n < n_) n *= 2;
	for(int i = 0; i < 2*n-1; i++){
		dat[i].fi = i-n+1;
		dat[i].sec = -1*INF;
	}
}

void update(int k, int a){
	k += n-1;
	if(dat[k].sec == -1*INF) dat[k].sec = a;
	else dat[k].sec += a;
	while(k > 0){
		k = (k-1)/2;
		if(dat[k*2+1].sec > dat[k*2+2].sec){
			dat[k].fi = dat[k*2+1].fi;
			dat[k].sec = dat[k*2+1].sec;
		} else{
			if(dat[k*2+1].sec == dat[k*2+2].sec){
				if(dat[k*2+1].fi < dat[k*2+2].fi){
					dat[k].fi = dat[k*2+1].fi;
					dat[k].sec = dat[k*2+1].sec;
				} else{
					dat[k].fi = dat[k*2+2].fi;
					dat[k].sec = dat[k*2+2].sec;
				}
			} else{
				dat[k].fi = dat[k*2+2].fi;
				dat[k].sec = dat[k*2+2].sec;
			}
		}
	}
}

P query(int a, int b, int k, int l, int r){
	if(r <= a || b <= l) return P(-1*INF,-1*INF);
	if(a <= l && r <= b) return dat[k];
	else{
		P vl = query(a,b,k*2+1,l,(l+r)/2);
		P vr = query(a,b,k*2+2,(l+r)/2,r);
		if(vl.sec > vr.sec){
			return vl;
		} else{
			if(vl.sec == vr.sec){
				if(vl.fi > vr.fi) return vr;
				else return vl;
			} else return vr;
		}
	}
}

int main(){
	scanf("%d%d", &n, &q);
	init(n);
	for(int i = 0; i < q; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		update(a,b);
		P out = query(0,n,0,0,n);
		printf("%d %d\n", out.fi+1, out.sec);
	}
}