#include<cstdio>
#include<vector>
#include<complex>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

typedef double Real;
typedef complex<Real> Point;
typedef pair<Point,Point> Line;
typedef pair<Point,Point> Segment;
typedef vector<Point> Polygon;

const Real eps=1e-7;
const Point NPoint=Point(NAN,NAN);
const Segment NSeg=Segment(NPoint,NPoint);

void print(Point p,char ch='\n'){
	//printf("(%f %f)%c",p.real(),p.imag(),ch);
}

void print(Polygon poly){
	/*if(poly.size()==0){
		printf("[empty]\n");
		return ;
	}
	for(int i=0;i<poly.size();i++){
		print(poly[i],' ');
	}
	printf("\n");*/
}

template<class T> bool eq(T a,T b){
	return abs(a-b)<eps;
}
template<class T> int sgn(T a){
	if(eq(a,0.0)) return 0;
	if(a>0) return 1;
	return -1;
}

bool onSeg(Point a,Point b,Point c){
	return eq(abs(a-b),abs(a-c)+abs(c-b));
}

Real doP(Point a,Point b){
	return (conj(a)*b).real();
}

Real crP(Point a,Point b){
	return (conj(a)*b).imag();
}

Point proj(Point p,Point b){
	return b*doP(p,b)/norm(b);
}

bool isPara_(Point a,Point b){
	return eq(crP(a,b),(Real)0);
}

Point iLL(Line l1,Line l2){
	if(isPara_(l1.second-l1.first,l2.second-l2.first)) return NPoint;
	Point a1=l1.first,b1=l1.second;
	Point a2=l2.first,b2=l2.second;
	Real num=crP(a2-a1,b1-a1);
	Real den=crP(b1-a1,b2-a2);
	return a2+(b2-a2)*(num/den);
}

bool iLS_(Line l,Segment s){
	if(isPara_(l.second-l.first,s.second-s.first)) return false;
	Point p=iLL(l,s);
	if(onSeg(s.first,s.second,p)) return true;
	return false;
}

Point iLS(Line l,Segment s){
	//重なるときは考えなくてよい 
	Point p=iLL(l,s);
	if(isnan(p.real())) return p;
	if(onSeg(s.first,s.second,p)) return p;
	return NPoint;
}

bool iSS_(Segment s1,Segment s2){
	Point p=iLL(s1,s2);
	if(isnan(p.real())) return false;
	if(!onSeg(s1.first,s1.second,p)) return false;
	if(!onSeg(s2.first,s2.second,p)) return false;
	return true;
}

Point iSS(Segment s1,Segment s2){
	if(iSS_(s1,s2)) return NPoint;
	return iLL(s1,s2);
}

Point perp(Line l,Point a){
	Point p=l.first,q=l.second;
	return p+proj(a-p,q-p);
}

Point refl(Line l,Point p){
	Point h=perp(l,p);
	return h*(Real)2-p;
}

Polygon refl(Line l,Polygon poly){
	Polygon res;
	for(int i=0;i<poly.size();i++){
		Point p=refl(l,poly[i]);
		res.push_back(p);
	}
	reverse(res.begin(),res.end());
	return res;
}

Segment refl(Line l,Segment seg){
	seg.first=refl(l,seg.first);
	seg.second=refl(l,seg.second);
	return seg;
}

Line perpBisec(Point p,Point q){
	Point d=q-p;
	Point rot=Point(0,1);
	Point mid=(p+q)/(Real)2;
	Point l1=mid+d*rot;
	Point l2=mid-d*rot;
	return Line(l1,l2);
}

Polygon convCut(Polygon poly,Point a,Point b){
	Polygon res;
	Line l=Line(a,b);
	if(poly.size()==0) return res;
	for(int i=0;i+1<poly.size();i++){
		if(sgn(crP(b-a,poly[i]-a))>=0) res.push_back(poly[i]);
		Segment seg=Segment(poly[i],poly[i+1]);
		if(iLS_(l,seg)){
			Point p=iLL(l,seg);
			if(eq(p,poly[i])) continue;
			if(eq(p,poly[i+1])) continue;
			res.push_back(iLL(l,seg));
		}
	}
	if(res.size()==0) return res;
	if(res.size()<=2){
		res.clear();
		return res;
	}
	res.push_back(res[0]);
	return res;
}

Segment iLPoly(Line l,Polygon poly){
	//1点で交わるとき注意!
	Segment seg=NSeg;
	for(int i=0;i+1<poly.size();i++){
		Segment e=Segment(poly[i],poly[i+1]);
		Point p=iLS(l,e);
		if(isnan(p.real())) continue;
		if(eq(p,poly[i+1])) continue;
		if(isnan(seg.first.real())) seg.first=p;
		else seg.second=p;
	}
	return seg;
}

bool inPoly_(Polygon poly,Point p){//ON is OUT
	bool in=false;
	for(int i=0;i+1<poly.size();i++){
		Point a=poly[i],b=poly[i+1];
		if(onSeg(a,b,p)) return false;
		a-=p,b-=p;
		if(sgn(a.imag()-b.imag())>0) swap(a,b);
		if(sgn(a.imag())<=0&&sgn(b.imag())>0){
			int s=sgn(crP(a,b));
			if(s==-1) in=!in;
		}
	}
	return in;
}

bool inPolyloose_(Polygon poly,Point p){//ON is IN
	bool in=false;
	for(int i=0;i+1<poly.size();i++){
		Point a=poly[i],b=poly[i+1];
		if(onSeg(a,b,p)) return true;
		a-=p,b-=p;
		if(sgn(a.imag()-b.imag())>0) swap(a,b);
		if(sgn(a.imag())<=0&&sgn(b.imag())>0){
			int s=sgn(crP(a,b));
			if(s==-1) in=!in;
		}
	}
	return in;
}	
/*
bool oPolyPoly_(Polygon p1,Polygon p2){
	//この場合は、zero area で重なることがないのでこれでよい 
	//よくなかった 
	//凸性を使っている 
	if(p1.empty()||p2.empty()) return false;
	if(inPoly_(p2,p1[0])) return true;
	if(inPoly_(p1,p2[0])) return true;/*
	for(int i=0;i+1<p1.size();i++){
		for(int j=0;j+1<p2.size();j++){
			Segment s1=Segment(p1[i],p1[i+1]);
			Segment s2=Segment(p2[j],p2[j+1]);
			bool flg=iSS_(s1,s2);
			if(flg) return true;
		}
	}*
	vector<Point> pts;
	for(int i=0;i+1<p1.size();i++){
		for(int j=0;j+1<p2.size();j++){
			Segment s1=Segment(p1[i],p1[i+1]);
			Segment s2=Segment(p2[j],p2[j+1]);
			Point p=iSS(s1,s2);
			if(isnan(p.real())) continue;
			if(eq(p,s1.first)||eq(p,s1.second)) continue;
			if(eq(p,s2.first)||eq(p,s2.second)) continue;
			pts.push_back(p);
		}
	}
	for(int i=0;i+1<p1.size();i++){
		if(inPolyloose_(p2,p1[i])) pts.push_back(p1[i]);
	}
	for(int j=0;j+1<p2.size();j++){
		bool ok=true;
		for(int i=0;i<p1.size();i++){
			if(eq(p1[i],p2[j])) ok=false;
		}
		if(!ok) continue;
		if(inPolyloose_(p1,p2[j])) pts.push_back(p2[j]);
	}
	if(pts.size()==0) return false;
	Point p=0;
	for(int i=0;i<pts.size();i++){
		p+=pts[i];
	}
	p/=(Real)pts.size();
	if(inPoly_(p1,p)==false) return false;
	if(inPoly_(p2,p)==false) return false;
	return true;
//	return false;
}*/

Polygon convCut(Polygon p1,Polygon p2){
	Polygon res=p1;
	for(int i=0;i+1<p2.size();i++){
		if(eq(p2[i],p2[i+1])) continue;
		res=convCut(res,p2[i],p2[i+1]);
	}
	return res;
}

bool oPolyPoly_(Polygon p1,Polygon p2){
	//凸のとき 
	if(p1.size()==0||p2.size()==0) return false;
	Polygon p=convCut(p1,p2);
	Real area=0;
	for(int i=0;i+1<p.size();i++){
		area+=crP(p[i],p[i+1]);
	}
	if(eq(area,(Real)0)) return false;
	else return true;
}

Polygon polys[1200];
Segment conSeg[1200][1200];
int V;

//Polygon old_polys[1200];
Polygon new_polys[1200];
int new_ids[1200];
vector<int> new_papers;
Segment new_conSeg[520][520];

bool folded[1200];

Segment tmp_conSeg[1200];

void process(Point p,Point q,bool last=false){
/*	printf("process\n");
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(isnan(conSeg[i][j].first.real())) printf(".");
			else printf("#");
		}
		printf("\n");
	}*//*
	for(int i=0;i<V;i++){
		print(polys[i]);
	}*/
//	for(int i=0;i<V;i++) old_polys[i]=polys[i];
	for(int i=0;i<V;i++) new_polys[i]=polys[i];
	for(int i=0;i<V;i++) for(int j=0;j<V;j++){
		if(eq(conSeg[i][j].first,conSeg[i][j].second)){
			conSeg[i][j]=NSeg;
		}
	}
	Line l=perpBisec(p,q);//crP(p-l.first,l.second-l.first)>0
	for(int i=0;i<V;i++) tmp_conSeg[i]=iLPoly(l,polys[i]);
	for(int i=0;i<V;i++) for(int j=0;j<V;j++){
		if(i==j) continue;
		if(isnan(conSeg[i][j].first.real())){
			conSeg[i+V][j+V]=NSeg;
			continue;
		}
		Segment seg=conSeg[i][j];
		if(iLS_(l,seg)==false){
			Point tmp=seg.first;
			int s=sgn(crP(tmp-l.first,l.second-l.first));
			if(s==1){
				conSeg[i][j]=NSeg;
				conSeg[i+V][j+V]=seg;
			}else{
				conSeg[i][j]=seg;
				conSeg[i+V][j+V]=NSeg;
			}
		}else{
			Point s=iLL(l,seg);
			Point s1=seg.first,s2=seg.second;
			if(sgn(crP(s1-l.first,l.second-l.first))<0){
				swap(s1,s2);
			}
			conSeg[i+V][j+V]=Segment(s1,s);
			conSeg[i][j]=Segment(s,s2);
			if(eq(s1,s)){
				conSeg[i+V][j+V]=NSeg;
			}
			if(eq(s2,s)){
				conSeg[i][j]=NSeg;
			}
		}
	}
	for(int i=0;i<V;i++){
		Polygon poly=polys[i];
		polys[i]=convCut(poly,l.first,l.second);
		polys[i+V]=convCut(poly,l.second,l.first);
	}
//	printf("separated\n");
/*	for(int i=0;i<V*2;i++){
		print(polys[i]);
	}*/
//	printf("separated\n");
	int st=-1;
	for(int i=V*2-1;i>=V;i--){
		if(inPoly_(polys[i],p)){
			st=i;
			break;
		}
	}
	if(st==-1){
		printf("st=-1\n");
		exit(0);
	}
	for(int i=0;i<V*2;i++) folded[i]=false;
	folded[st]=true;
	queue<int> que;
	que.push(st);
	/*for(int i=0;i<V*2;i++){
		for(int j=0;j<V*2;j++){
			if(isnan(conSeg[i][j].first.real())) printf(".");
			else printf("#");
		}
		printf("\n");
	}*/
	while(!que.empty()){
		int cur=que.front();
		que.pop();
		for(int i=V;i<V*2;i++){
			if(i==cur) continue;
			if(folded[i]) continue;
			if(isnan(conSeg[i][cur].first.real())==false){
				folded[i]=true;
				que.push(i);
				continue;
			}
			if(i<cur) continue;
			bool flg=oPolyPoly_(polys[i],polys[cur]);
		//	if(overlap[i-V][cur-V]&&cur<i){
			if(flg){
				folded[i]=true;
				que.push(i);
			}
		}
	}
/*	printf("folded::");
	for(int i=0;i<V*2;i++){
		if(folded[i]) printf("%d ",i);
	}
	printf("\n");*/
	new_papers.clear();
	for(int i=0;i<V;i++){
	//	if(polys[i].empty()) continue;
		if(folded[i+V]==false){
			//new_polys[i]=old_polys[i];
			new_papers.push_back(i);
		}else{
			if(polys[i].size()>0){
				new_polys[i]=polys[i];
				new_papers.push_back(i);
			}
		}
	}
	for(int i=V*2-1;i>=V;i--){
		if(polys[i].empty()) continue;
		if(folded[i]){
			new_polys[i]=refl(l,polys[i]);
			new_papers.push_back(i);
		}
	}
	for(int i=0;i<V*2;i++){
		new_ids[i]=-1;
	}
	for(int i=0;i<new_papers.size();i++){
		new_ids[new_papers[i]]=i;
	}
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){/*
			if(isnan(conSeg[i][j].first.real())==false&&isnan(conSeg[i+V][j+V].first.real())==false){
				if(folded[i+V]==false&&folded[j+V]==false){
					conSeg[i][j].first=conSeg[i+V][j+V].first;
				}
			}*/
			if(folded[i+V]==false&&folded[j+V]==false){
				if(isnan(conSeg[i+V][j+V].first.real())==false){
					if(conSeg[i][j].first.real()==false){
						conSeg[i][j].first=conSeg[i+V][j+V].first;
					}else{
						conSeg[i][j]=conSeg[i+V][j+V];
					}
				}else{
			//		conSeg[i][j]=conSeg[i+V][j+V];
				}
			}
		}
	}
	if(!last){
		for(int i=0;i<new_papers.size();i++) for(int j=i+1;j<new_papers.size();j++){
			int id1=new_papers[i];
			int id2=new_papers[j];
//			if(id2<V||id1>=V){
			if(id2<V){
				new_conSeg[i][j]=conSeg[id1][id2];
				new_conSeg[j][i]=conSeg[id2][id1];
			}else if(id1>=V){
				Segment tmp=conSeg[id1][id2];
				if(isnan(tmp.first.real())==false){
					tmp=refl(l,tmp);
				}
				new_conSeg[i][j]=tmp;
				new_conSeg[j][i]=tmp;
			}else if(id2-id1==V){
				//Segment seg=iLPoly(l,old_polys[id1]);
				Segment seg=tmp_conSeg[id1];
				new_conSeg[i][j]=seg;
				new_conSeg[j][i]=seg;
			}else{
				new_conSeg[i][j]=NSeg;
				new_conSeg[j][i]=NSeg;
			}
		}
	}
	V=new_papers.size();
	for(int i=0;i<V;i++) polys[i]=new_polys[new_papers[i]];
	if(!last){
		for(int i=0;i<V;i++) for(int j=0;j<V;j++){
			if(i==j) conSeg[i][j]=NSeg;
			else conSeg[i][j]=new_conSeg[i][j];
		}
/*		for(int i=0;i<V;i++) for(int j=0;j<V;j++){
			if(i==j) overlap[i][j]=false;
			else overlap[i][j]=oPolyPoly_(polys[i],polys[j]);
		}*/
	}
}

Point ps[10],qs[10];
Point h;
int N;

void input(){
	scanf("%d",&N);
	if(N==0) exit(0);
	for(int i=0;i<N;i++){
		int px,py,qx,qy;
		scanf("%d%d%d%d",&px,&py,&qx,&qy);
		ps[i]=Point(px,py);
		qs[i]=Point(qx,qy);
	}
	int x,y;
	scanf("%d%d",&x,&y);
	h=Point(x,y);
}

void init(){
	V=1;
	Point p1=Point(0,0);
	Point p2=Point(100,0);
	Point p3=Point(100,100);
	Point p4=Point(0,100);
	for(int i=0;i<1200;i++){
		polys[i].clear();
	//	old_polys[i].clear();
		new_polys[i].clear();
		for(int j=0;j<1200;j++){
			conSeg[i][j]=NSeg;
		//	overlap[i][j]=false;
		}
	}
	for(int i=0;i<520;i++) for(int j=0;j<520;j++){
		new_conSeg[i][j]=NSeg;
	}
	polys[0].push_back(p1);
	polys[0].push_back(p2);
	polys[0].push_back(p3);
	polys[0].push_back(p4);
	polys[0].push_back(p1);
}

void processAll(){
	for(int i=0;i<N;i++){
		Point p=ps[i],q=qs[i];
		if(i==N-1) process(p,q,true);
		else process(p,q);
	}
/*	printf("last V=%d\n",V);
	for(int i=0;i<V;i++){
		print(polys[i]);
	}*/
}

int getNum(){
	int res=0;
	for(int i=0;i<V;i++){
		if(inPoly_(polys[i],h)) res++;
	}
	return res;
}

int main(){
	while(true){
		input();
		init();
		processAll();
		int ans=getNum();
		printf("%d\n",ans);
	//	break;
	}
	return 0;
}