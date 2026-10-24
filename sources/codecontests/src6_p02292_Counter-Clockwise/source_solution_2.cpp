#include <bits/stdc++.h>
#define eps 1e-9

using namespace std;
typedef double db;
struct P{
    db x, y;
    P(){}
    P(db x, db y) : x(x) , y(y) {}
    P operator - (P a){ return P(x-a.x, y-a.y); }
    db times(P a){ return x*a.y-y*a.x; }
    db dot(P a){ return a.x*x + a.y*y; }
    db len(){ return sqrt(x*x+y*y); }
};
typedef P V;
int sign(db x){ return x<-eps ? -1 : x>eps; }

void cc(V v1, V v2){ //判断v2在v1的哪个方向
    db s = sign( v1.times(v2) );  //利用叉积判顺逆时针
    if(s < 0) printf("CLOCKWISE\n");
    else if(s > 0) printf("COUNTER_CLOCKWISE\n");
    else{
        db d = sign( v1.dot(v2) );  //坑待填：这里是否需要eps？
        if(d<0) printf("ONLINE_BACK\n");
        else{  //用点积判同向异向
            if(v1.len() >= v2.len()) printf("ON_SEGMENT\n");
            else printf("ONLINE_FRONT\n");
        }
    }
}

int main(){
    //freopen("owo.in","r",stdin);
    P p0, p1, p2;
    scanf("%lf%lf%lf%lf", &p0.x, &p0.y, &p1.x, &p1.y);
    V v1 = p1-p0;
    int n;
    cin >> n;
    while(n--){
        scanf("%lf%lf", &p2.x, &p2.y);
        V v2 = p2-p0;
        cc(v1, v2);
    }
    return 0;
}
