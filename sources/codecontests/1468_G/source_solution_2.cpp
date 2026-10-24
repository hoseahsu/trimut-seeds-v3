#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0; i<n; i++)
#define sz(v) (int)(v.size())
#define prin(a) cout << #a << " = " << a << endl
#define prinv(v) cout << #v << " = "; for(auto it : v) cout << it << ", "; cout << endl
#define all(v) (v).begin(),(v).end()

typedef long long ll;

#define rmin(a,b) a = min<ll>(a,b)
#define rmax(a,b) a = max<ll>(a,b)

#define fi first
#define se second

typedef pair<ll,ll> pll;

struct pt{
	ll x, y;
	pt(){}
	pt(ll xx, ll yy){
		x = xx, y = yy;
	}
	
	bool operator == (pt p2){
	    return x==p2.x and y==p2.y;
	}
	
	pt operator - (pt p2){
		return pt(x-p2.x,y-p2.y);
	}
	ll operator * (pt p2){
		return x*p2.x + y*p2.y;
	}
	
	ll operator ^(pt p2){
		return x*p2.y-y*p2.x;
	}
	
	long double mod(){
		return sqrt((long double)(x*x+y*y));
	}
	
	bool operator != (pt p2){
	    return x!=p2.x and y!=p2.y;
	}
};	

/*
Function that checks for intersection between two lines p1-p2 and p3-p4 in 2d
You can alter the function to receive the paremeters of the line: a*x+b*y=c
Returns:
0: No intersection, 1: One intersecao, 2: inifinite intersections
"Pintersection" is the pair of pairs "returned" by reference that represents the irrecductible fraction
of a intersection (if any), that is for examle x=3/4 and y=-1/1
Watch out for overflow, |x|,|y|<=5e5
*/
int line_intersection(pt p1, pt p2, pt p3, pt p4, pair<double,double> &pintersection){
    if(p1==p2 or p3==p4) return 0; //assert(0); //?
    
    ll a1, a2, b1, b2, c1, c2;
    
    fr(cor,2){
        a1 = p1.y-p2.y, b1 = p2.x-p1.x;
	    c1 = p1.x*a1 + p1.y*b1;
	    swap(p1,p3);
	    swap(p2,p4);
	    swap(a1,a2);
	    swap(b1,b2);
	    swap(c1,c2);
    }
	
	ll det = a1*b2-a2*b1;
	
	if(!det){
		if(p1.x*a2+p1.y*b2!=c2) return 0;
		pintersection = {p1.x,p1.y};
		return 2;
	}
	
	double x, y;
	ll num, div, g;
	
	fr(cor,2){
	    if(cor) num = a1*c2-a2*c1; //possible overflow here (8*|x|^3)
	    else num = c1*b2-b1*c2;
	    div = det;
	    //g = __gcd(abs(num),abs(div));
	    //num/=g, div/=g;
	    //if(div<0) div*=-1, num*=-1;
	    x = (double)num/div;//{num,div};
	    swap(x,y);
	}
	
	pintersection = {x,y};
	return 1;
}

const int N = 2e5+10;
pt points[N];

double sq(double x){
	return x*x;
}	

#define prinp(a) cout << #a << " = " << a.x << "," << a.y << endl

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n, h; cin >> n >> h;
	fr(i,n){
		cin >> points[i].x >> points[i].y;
	}
	pt pivo = points[n-1];
	pt po = pivo;
	po.y+=h;
	double ans = 0;
	//prinp(po);
	for(int i = n-2; i>=0; i--){
		pair<double,double> pi;
		int ti = line_intersection(points[i],points[i+1],pivo,po,pi);
		//prin(ti);
		if(ti==0){
			continue;
		} else if(ti==1){
			double dix, diy; tie(dix,diy) = pi;
			//prin(dix);
			//prin(points[i].x);
			//cout << endl;
			
			pt v1 = points[i]-po;
			pt vant = pivo-po;
			if((v1^vant)>0){
				if(dix>points[i].x) ans += sqrt(sq(dix-points[i].x)+sq(diy-points[i].y));
				pivo = points[i];
				//prinp(pivo);
			}
		} else{
			ans += (points[i+1]-points[i]).mod();
		}
	}
	cout << fixed << setprecision(10) << ans << "\n";
}