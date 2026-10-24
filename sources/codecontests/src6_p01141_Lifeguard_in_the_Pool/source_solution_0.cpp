#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

inline long double add(long double a, long double b){
    return abs(a+b)<(1e-11)*(abs(a)+abs(b)) ? 0.0 : a+b;
}

struct vec{
    long double x,y;
    vec operator-(vec b){
        return (vec){add(x,-b.x),add(y,-b.y)};
    }
    vec operator+(vec b){
        return (vec){add(x,b.x),add(y,b.y)};
    }
    vec operator*(long double d){
        return (vec){x*d,y*d};
    }
    bool operator==(vec b){
        return x==b.x&&y==b.y;
    }
    bool operator!=(vec b){
        return x!=b.x||y!=b.y;
    }
    long double dot(vec v){
        return add(x*v.x,y*v.y);
    }
    long double cross(vec v){
        return add(x*v.y,-y*v.x);
    }
    long double norm(){
        return sqrt(x*x+y*y);
    }
};

int ccw(vec& a, vec& b, vec& c){
    vec ab = b-a, ac = c-a;
    long double o = ab.cross(ac);
    if(o>0) return 1; //CCW
    if(o<0) return -1; //CW
    if(ab.dot(ac)<0){
        return 2; //C-A-B
    }else{
        if(ab.dot(ab)<ac.dot(ac)){
            return -2; //A-B-C
        }else{
            return 0; //A-C-B
        }
    }
}

void print_path(vector<pair<int,vec>>&P);
long double t_sum(vector<pair<int,vec>>&P, long double tg, long double tw);

vec ternarysearch(vec& p0, vec& p1, vec& p2, long double tg, long double tw){
    //???p0??????p2??????????????????p2p3?????????????????£?????????????????§????????????????????????????????????
    long double left=1.0/3.0,right=2.0/3.0;
    long double t,t1,t2;
    vec P1,P2;
    while(true){
        P1=p1*(1-left)+p2*left;
        P2=p1*(1-right)+p2*right;
        t1=(p0-P1).norm()*tw+(p2-P1).norm()*tg;
        t2=(p0-P2).norm()*tw+(p2-P2).norm()*tg;
        if(abs(t1-t2)<1e-11){
            t=(left+right)/2;
            if(1.0-t<1e-8){
                return p2;
            }else if(t<1e-8){
                return p1;
            }else{
                return P1;
            }
        }
        if(t1<t2){
            right=(2*left+right)/3;
            left=2*left-right;
        }else{
            left=(2*right+left)/3;
            right=2*right-left;
        }
    }
}

struct Segment{
    int begin,end;
    vector<int> P;
    Segment(int a, int b){
        begin=a, end=b;
        P.push_back(a);
        P.push_back(b);
    }
};

struct Edge{
    int to;
    long double t;
    Edge(int a, long double b){
        to=a, t=b;
    }
};

struct Point{
    vec v;
    vector<Edge> E;
    Point(vec v){
        this->v=v;
    }
};

long double solve(vector<vec>& v, vec& S, vec& T, long double tg, long double tw){
    int n = v.size();
    vector<Point> V;
    for(int i=0;i<n;i++){
        if((v[i]-S).norm()<1e-8){//S?????????????????????
            V.push_back(Point(S));
            for(int j=i+1;j!=i;j=(j+1)%n){
                V.push_back(Point(v[j]));
            }
            break;
        }else if(!ccw(v[i],v[(i+1)%n],S)){//S??????????????????
            V.push_back(Point(S));
            i=(i+1)%n;
            for(int j=0;j<n;j++){
                V.push_back(Point(v[(i+j)%n]));
            }
            break;
        }
    }
    n=V.size();
    vector<Segment> L;
    for(int i=0;i<V.size();i++){
        L.push_back(Segment(i,(i+1)%n));
    }
    V.push_back(T);
    n=V.size();
    int iT=V.size()-1;
    for(int i=0;i<n;i++){
        for(auto& s:L){
            if(s.begin==i||s.end==i) continue;
            vec M;
            M=ternarysearch(V[i].v,V[s.begin].v,V[s.end].v,tg,tw);
            if(M!=V[s.begin].v&&M!=V[s.end].v){
                V.push_back(M);
                V.back().E.push_back(Edge(i,(V[i].v-M).norm()*tw));
                V[i].E.push_back(Edge(V.size()-1,(V[i].v-M).norm()*tw));
                s.P.push_back(V.size()-1);
            }
            M=ternarysearch(V[i].v,V[s.end].v,V[s.begin].v,tg,tw);
            if(M!=V[s.begin].v&&M!=V[s.end].v){
                V.push_back(M);
                V.back().E.push_back(Edge(i,(V[i].v-M).norm()*tw));
                V[i].E.push_back(Edge(V.size()-1,(V[i].v-M).norm()*tw));
                s.P.push_back(V.size()-1);
            }
        }
    }
    //????§???¢?????????+S+T????£?????????¶
    for(int i=0;i<=iT;i++){
        for(int j=i+2;j<=iT;j++){
            V[i].E.push_back(Edge(j,(V[i].v-V[j].v).norm()*tw));
            V[j].E.push_back(Edge(i,(V[i].v-V[j].v).norm()*tw));
        }
    }

    //????§???¢????????????????????????????????¶???
    for(auto& s:L){
        for(auto& p1:s.P){
            for(auto& p2:s.P){
                if(p1!=p2){
                    V[p1].E.push_back(Edge(p2,(V[p1].v-V[p2].v).norm()*tg));
                    V[p2].E.push_back(Edge(p1,(V[p1].v-V[p2].v).norm()*tg));
                }
            }
        }
    }
    //?§???????0????????????iT?????????????????????
    typedef pair<long double, int> Q;
    priority_queue<Q, vector<Q>, greater<Q>> que;
    long double minimum_time[V.size()];
    fill(minimum_time,minimum_time+V.size(),1e10);
    int s=0;
    minimum_time[s]=0;
    que.push(Q(0,s));
    while(!que.empty()){
        Q q=que.top();
        que.pop();
        int i = q.second;
        if(i==iT) return minimum_time[i];
        if(minimum_time[i]<q.first) continue;
        for(auto& e:V[i].E){
            if(minimum_time[e.to]>minimum_time[i]+e.t){
                minimum_time[e.to]=minimum_time[i]+e.t;
                que.push(Q(minimum_time[e.to],e.to));
            }
        }
    }
    return 0;
}

int main(){
    int n;
    long double tg,tw;
    vec S,T;
    vector<vec> V;

    while(cin >> n, n!=0){
        V.clear();
        for(int i=0;i<n;i++){
            long double x,y;
            cin >> x >> y;
            V.push_back((vec){.x=x,.y=y});
        }
        cin >> tg >> tw;
        cin >> S.x >> S.y;
        cin >> T.x >> T.y;

        cout.precision(8);
        cout << fixed;
        cout << solve(V,S,T,tg,tw) << endl;
    }
    return 0;
}