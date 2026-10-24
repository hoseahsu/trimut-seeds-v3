    #include <bits/stdc++.h>

//    #include <boost/multiprecision/cpp_int.hpp>
 #define int long long
 #define inf  1000000007
 #define pa pair<int,int>
 #define ll long long
 #define pal pair<double,double>
 #define ppap pair<pa,int>
  #define PI 3.14159265358979323846
  #define paa pair<int,char>
  #define  mp make_pair
  #define  pb push_back
  #define EPS (1e-10)
                                          
//    int dx[8]={0,1,0,-1,1,1,-1,-1};
  //  int dy[8]={1,0,-1,0,-1,1,1,-1};
                                            using namespace std;
                                   			class pa3{
                                            	public:
                                            	int x;
                                   				int y,z;
                                            	pa3(int x=0,int y=0,int z=0):x(x),y(y),z(z) {}
                                            	bool operator < (const pa3 &p) const{
                                            		if(x!=p.x) return x<p.x;
                                            		if(y!=p.y) return y<p.y;
                                            		 return z<p.z;
                                            		//return x != p.x ? x<p.x: y<p.y;
                                            	}
                                   				bool operator > (const pa3 &p) const{
                                            		if(x!=p.x) return x>p.x;
                                            		if(y!=p.y) return y>p.y;
                                            		 return z>p.z;
                                            		//return x != p.x ? x<p.x: y<p.y;
                                            	}
                                            	bool operator == (const pa3 &p) const{
                                            		return x==p.x && y==p.y && z==p.z;
                                            	}
                                            		bool operator != (const pa3 &p) const{
                                            			return !( x==p.x && y==p.y && z==p.z);
                                            	}
                                            
                                            };
                                            
                                            class pa4{
                                            	public:
                                            	int x;
                                            	int y,z,w;
                                            	pa4(int x=0,int y=0,int z=0,int w=0):x(x),y(y),z(z),w(w) {}
                                            	bool operator < (const pa4 &p) const{
                                            		if(x!=p.x) return x<p.x;
                                            		if(y!=p.y) return y<p.y;
                                            		if(z!=p.z)return z<p.z;
                                            		return w<p.w;
                                            		//return x != p.x ? x<p.x: y<p.y;
                                            	}
                                            	bool operator > (const pa4 &p) const{
                                            		if(x!=p.x) return x>p.x;
                                            		if(y!=p.y) return y>p.y;
                                            		if(z!=p.z)return z>p.z;
                                            		return w>p.w;
                                            		//return x != p.x ? x<p.x: y<p.y;
                                            	}
                                            	bool operator == (const pa4 &p) const{
                                            		return x==p.x && y==p.y && z==p.z &&w==p.w;
                                            	}
                                            		
                                            
                                            };
                                            class pa2{
                                            	public:
                                            	int x,y;
                                            	pa2(int x=0,int y=0):x(x),y(y) {}
                                            	pa2 operator + (pa2 p) {return pa2(x+p.x,y+p.y);}
                                            	pa2 operator - (pa2 p) {return pa2(x-p.x,y-p.y);}
                                            	bool operator < (const pa2 &p) const{
                                            		return y != p.y ? y<p.y: x<p.x;
                                            	}
                                            	bool operator > (const pa2 &p) const{
                                            		return x != p.x ? x<p.x: y<p.y;
                                            	}
                                            	bool operator == (const pa2 &p) const{
                                            		return abs(x-p.x)==0 && abs(y-p.y)==0;
                                            	}
                                            	bool operator != (const pa2 &p) const{
                                            		return !(abs(x-p.x)==0 && abs(y-p.y)==0);
                                            	}
                                            		
                                            
                                            };
                                        

                                            class Point{
                                            	public:
                                            	double x,y;
                                            	Point(double x=0,double y=0):x(x),y(y) {}
                                            	Point operator + (Point p) {return Point(x+p.x,y+p.y);}
                                            	Point operator - (Point p) {return Point(x-p.x,y-p.y);}
                                            	Point operator * (double a) {return Point(x*a,y*a);}
                                            	Point operator / (double a) {return Point(x/a,y/a);}
                                            	double absv() {return sqrt(norm());}
                                            	double norm() {return x*x+y*y;}
                                            	bool operator < (const Point &p) const{
                                            		return x != p.x ? x<p.x: y<p.y;
                                            	}
                                            	bool operator == (const Point &p) const{
                                            		return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
                                            	}
                                            };
                                            typedef Point Vector;
                                     #define pl pair<int,pas>
                                            struct Segment{
                                            Point p1,p2;
                                            };
                                             double dot(Vector a,Vector b){
                                            	return a.x*b.x+a.y*b.y;
                                            }
                                            double cross(Vector a,Vector b){
                                            	return a.x*b.y-a.y*b.x;
                                            }
                                        
                bool parareru(Point a,Point b,Point c,Point d){
                //	if(abs(cross(a-b,d-c))<EPS)cout<<"dd "<<cross(a-b,d-c)<<endl;
                	return abs(cross(a-b,d-c))<EPS;
                }
                double distance_ls_p(Point a, Point b, Point c) {
                  if ( dot(b-a, c-a) < EPS ) return (c-a).absv();
                  if ( dot(a-b, c-b) < EPS ) return (c-b).absv();
                  return abs(cross(b-a, c-a)) / (b-a).absv();
                }
                bool is_intersected_ls(Segment a,Segment b) {
                	if(a.p1==b.p1||a.p2==b.p1||a.p1==b.p2||a.p2==b.p2) return false;
                	if(parareru((a.p2),(a.p1),(a.p1),(b.p2))&&parareru((a.p2),(a.p1),(a.p1),(b.p1))){
                //		cout<<"sss"<<endl;
                		if(dot(a.p1-b.p1,a.p1-b.p2)<EPS) return true;
                		if(dot(a.p2-b.p1,a.p2-b.p2)<EPS) return true;
                		if(dot(a.p1-b.p1,a.p2-b.p1)<EPS) return true;
                		if(dot(a.p1-b.p2,a.p2-b.p2)<EPS) return true;
                		return false;
                	}
                  else return ( cross(a.p2-a.p1, b.p1-a.p1) * cross(a.p2-a.p1, b.p2-a.p1) < EPS ) && ( cross(b.p2-b.p1, a.p1-b.p1) * cross(b.p2-b.p1, a.p2-b.p1) < EPS );
                }
                 
                double segment_dis(Segment a,Segment b){
                	if(is_intersected_ls(a,b))return 0;
                	double r=distance_ls_p(a.p1, a.p2, b.p1);
                	r=min(r,distance_ls_p(a.p1, a.p2, b.p2));
                	r=min(r,distance_ls_p(b.p1, b.p2, a.p2));
                	r=min(r,distance_ls_p(b.p1, b.p2, a.p1));
                	return r;
                }
                Point intersection_ls(Segment a, Segment b) {
                  Point ba = b.p2-b.p1;
                  double d1 = abs(cross(ba, a.p1-b.p1));
                  double d2 = abs(cross(ba, a.p2-b.p1));
                  double t = d1 / (d1 + d2);
                 
                  return a.p1 + (a.p2-a.p1) * t;
                }
                
                                string itos( int i ) {
                                ostringstream s ;
                                s << i ;
                                return s.str() ;
                                }
                                 
                                int gcd(int v,int b){
                                	if(v>b) return gcd(b,v);
                                	if(v==b) return b;
                                	if(b%v==0) return v;
                                	return gcd(v,b%v);
                                }
                 
                                double distans(double x1,double y1,double x2,double y2){
                                	double rr=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                                	return sqrt(rr);
                                	
                                }
                                int mod;
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0ll) {
        x = 1ll;
        y = 0ll;
        return a;
    }
    ll d = extgcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
pa operator+(const pa & l,const pa & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}    
pa operator-(const pa & l,const pa & r) {   
    return {l.first-r.first,l.second-r.second};                                    
} 
                                
                int pr[200010];
                int inv[200010];
                
                int beki(int wa,int rr,int warukazu){
                	if(rr==0) return 1%warukazu;
                	if(rr==1) return wa%warukazu;
                	wa%=warukazu;
                	if(rr%2==1) return ((ll)beki(wa,rr-1,warukazu)*(ll)wa)%warukazu;
                	ll zx=beki(wa,rr/2,warukazu);
                	return (zx*zx)%warukazu;
                }
    double bekid(double w,int r){
    	if(r==0) return 1.0;
    	if(r==1) return w;
    	if(r%2) return bekid(w,r-1)*w;
    	double f=bekid(w,r/2);
    	return f*f;
    }
                
    			int comb(int nn,int rr){
    				int r=pr[nn]*inv[rr];
    				r%=mod;
    				r*=inv[nn-rr];
    				r%=mod;
    				return r;
    			}
                
                void gya(int ert){
                	pr[0]=1;
                	for(int i=1;i<=ert;i++){
                		pr[i]=(pr[i-1]*i)%mod;
                	}
                	inv[ert]=beki(pr[ert],mod-2,mod);
                	
                	for(int i=ert-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
                	
                }
                
              //   cin.tie(0);
    		//	ios::sync_with_stdio(false);
    			//priority_queue<pa3,vector<pa3>,greater<pa3>> pq;            
                 //sort(ve.begin(),ve.end(),greater<int>());
    //mt19937(clock_per_sec);
  //  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()) ;
	   
       
                               //----------------kokomade tenpure------------

struct edge{
	int to,cap,num,moto;
};
vector<edge> ZANYO[100020];
int label[100020];
queue<pa> qu_bfs;
int dokomade[100020];
void add_edge(int s_point,int t_point, int capa){// (s!=t)  s-->t
//	cout<<s_point<<" "<<t_point<<" "<<capa<<endl;
		ZANYO[s_point].pb((edge){t_point,capa,(int)ZANYO[t_point].size(),0});
		ZANYO[t_point].pb((edge){s_point,0,(int)ZANYO[s_point].size()-1,1});
}

void bfs_dinic(int s_point,int N){
	for(int i=0;i<N;i++)label[i]=-1;
	while(qu_bfs.size())qu_bfs.pop();
	qu_bfs.push(mp(s_point,0));
	while(qu_bfs.size()){
		pa z=qu_bfs.front();
		qu_bfs.pop();
		if(label[z.first]>=0)continue;
		label[z.first]=z.second;
		for(auto &v:ZANYO[z.first]){
			if(v.cap==0) continue;
			if(v.cap<0){
				cout<<"error"<<endl;
				exit(0);
			}
			if(label[v.to]>=0) continue;
			
			qu_bfs.push(mp(v.to,z.second+1));
		}
	}
	return;
}

int dfs_dinic(int s_point,int t_point, int ima_flow){
	if(s_point==t_point) return ima_flow;
	while(1){
		if(dokomade[s_point]>=ZANYO[s_point].size()) break;
		int edanum=dokomade[s_point];
		if(ZANYO[s_point][edanum].cap<0){
			cout<<"minus"<<endl;
			exit(0);
		}
		if(ZANYO[s_point][edanum].cap<=0 || label[s_point]+1!=label[ZANYO[s_point][edanum].to] ){
			dokomade[s_point]++;
			continue;
		}
		int W=dfs_dinic(ZANYO[s_point][edanum].to,t_point,min(ZANYO[s_point][edanum].cap,ima_flow));
		if(W>0){
			ZANYO[s_point][edanum].cap-=W;
			ZANYO[ZANYO[s_point][edanum].to][ZANYO[s_point][edanum].num].cap+=W;
			return W;
		}
		dokomade[s_point]++;
	}
	return 0;
}

int max_flow_dinic(int s_point,int t_point,int N){// Nは頂点数:存在する頂点番号が[0,N) (Nは多めにしてOK)
	int jougen=inf*1000000000ll; //容量の最大値
	int ans_flow=0;
	while(1){
	
		bfs_dinic(s_point,N);
		if(label[t_point]==-1) break;
		for(int i=0;i<N;i++)dokomade[i]=0;
		while(1){
			int ima_flow=dfs_dinic(s_point,t_point,jougen+1); 
			if(ima_flow==0)break;
			ans_flow+=ima_flow;
		}
	}
	return ans_flow;
}



int a[100][100];

vector<pa> v1,v2;

int ids[100][100]={};

signed main(){

//			  cin.tie(0);
//			ios::sync_with_stdio(false);
int h,w,W;
	cin>>h>>w>>W;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>a[i][j];
	int id=2;
	for(int i=0;i<h/2;i++)for(int j=0;j<w/2;j++){
				v1.pb({id,W-(a[i*2][j*2]+a[i*2+1][j*2+1]+a[i*2+1][j*2]+a[i*2][j*2+1])});
		ids[i*2][j*2]=id;
		id++;
	}
	
	for(int i=1;i<h/2;i++)for(int j=1;j<w/2;j++){
				v2.pb({id,W-(a[i*2-1][j*2-1]+a[i*2][j*2-1]+a[i*2-1][j*2]+a[i*2][j*2])});
		ids[i*2-1][j*2-1]=id;
		id++;
	}
	int ans=0;
	for(auto v:v1){
		if(v.second<0){
			ans+=v.second;
			add_edge(0,v.first,-v.second);
			
			add_edge(v.first,1,0);
		}
		else{
			add_edge(0,v.first,0);
			
			add_edge(v.first,1,v.second);

		}
	}
	
	for(auto v:v2){
		if(v.second<0){
			ans+=v.second;
	//		cout<<v.first<<endl;
			add_edge(v.first,1,-v.second);
			
			add_edge(0,v.first,0);
		}
		else{
			add_edge(v.first,1,0);
			
			add_edge(0,v.first,v.second);

		}
	}
	
	for(int i=0;i<h;i+=2)for(int j=0;j<w;j+=2){
		for(int k1=-1;k1<=1;k1+=2)for(int k2=-1;k2<=1;k2+=2){
			int xx=i+k1;
			int yy=j+k2;
			if(xx<0||xx>=h || yy<0 || yy>=w) continue;
			if(!ids[xx][yy])continue;
	//		cout<<"  "<<i<<" "<<j<<" "<<xx<<" "<<yy<<endl;
			if(k1==-1 && k2==-1){
				add_edge(ids[i][j],ids[xx][yy],a[i][j]);
			}
			
			if(k1==-1 && k2==1){
				add_edge(ids[i][j],ids[xx][yy],a[i][j+1]);
			}
			
			if(k1==1 && k2==-1){
				add_edge(ids[i][j],ids[xx][yy],a[i+1][j]);
			}
			
			if(k1==1 && k2==1){
				add_edge(ids[i][j],ids[xx][yy],a[i+1][j+1]);
			}
			
		}
	}
	cout<<-ans-max_flow_dinic(0,1,2500)<<endl;
	
	
	return 0;
}
