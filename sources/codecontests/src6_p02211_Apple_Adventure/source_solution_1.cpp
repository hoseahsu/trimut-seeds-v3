   #include <bits/stdc++.h>
 
//    #include <boost/multiprecision/cpp_int.hpp>
// #define int long long
 #define inf  1000000007
 #define pa pair<int,int>
 #define ll long long
 #define pal pair<double,double>
 #define ppap pair<pa,int>
  #define PI 3.14159265358979323846
  #define paa pair<int,char>
  #define  mp make_pair
  #define  pb push_back
  #define EPS (1e-8)
                                          
    int dx[8]={0,1,0,-1,1,1,-1,-1};
    int dy[8]={1,0,-1,0,-1,1,1,-1};
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
                                            
 
                      
                                string itos( int i ) {
                                ostringstream s ;
                                s << i ;
                                return s.str() ;
                                }
                                 
                                int gcd(int v,int b){
                                	if(v==0) return b;
                                	if(b==0) return v;
                                	if(v>b) return gcd(b,v);
                                	if(v==b) return b;
                                	if(b%v==0) return v;
                                	return gcd(v,b%v);
                                }
                 
                            
                                int mod;
int extgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = extgcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
pa operator+(const pa & l,const pa & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}    
pa operator-(const pa & l,const pa & r) {   
    return {l.first-r.first,l.second-r.second};                                    
}  
                                
                int pr[10000100];
                int inv[10000010];
                
                int beki(int wa,int rr,int warukazu){
                	if(rr==0) return 1%warukazu;
                	if(rr==1) return wa%warukazu;
                	wa%=warukazu;
                	if(rr%2==1) return ((ll)beki(wa,rr-1,warukazu)*(ll)wa)%warukazu;
                	ll zx=beki(wa,rr/2,warukazu);
                	return (zx*zx)%warukazu;
                }
 
                
    			int comb(int nn,int rr){
    				if(rr<0 || rr>nn || nn<0) return 0;
    				int r=pr[nn]*inv[rr];
    				r%=mod;
    				r*=inv[nn-rr];
    				r%=mod;
    				return r;
    			}
               
                void gya(int ert){
                	pr[0]=1;
                	for(int i=1;i<=ert;i++){
                		pr[i]=((ll)pr[i-1]*i)%mod;
                	}
                		inv[ert]=beki(pr[ert],mod-2,mod);
                	for(int i=ert-1;i>=0;i--){
                		inv[i]=(ll)inv[i+1]*(i+1)%mod;
                	}
                }
                
              //   cin.tie(0);
    		//	ios::sync_with_stdio(false);
    			//priority_queue<pa3,vector<pa3>,greater<pa3>> pq;            
                 //sort(ve.begin(),ve.end(),greater<int>());
 //   mt19937(clock_per_sec);
  //  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()) ;


string s[1020];
map<pa,int> ma;

int dis[22][22]={};
bool vis[1020][1020];
bool sumi[22][1<<22]={};
int dp[1<<20][20];
signed main(){
	
	
cin.tie(0);
ios::sync_with_stdio(false);

	int h,w,k;
	cin>>h>>w>>k;
	int n=0,sx,sy,ex,ey;
	vector<pa> ve;
	for(int i=0;i<h;i++){
		cin>>s[i];
		for(int j=0;j<w;j++){
			char c=s[i][j];
			n+=c=='a';
			if(c=='a'){
				ve.pb(mp(i,j));
			}
			if(c=='s'){
				sx=i,sy=j;
			}
			if(c=='e'){
				ex=i,ey=j;
			}
		}
	}
	ve.pb(mp(sx,sy));
	ve.pb(mp(ex,ey));
	for(int i=0;i<n+2;i++)ma[ve[i]]=i;
	for(int i=0;i<n+2;i++)for(int j=0;j<n+2;j++)dis[i][j]=inf;
	for(int i=0;i<n+2;i++){
		queue<pa3> qu;
		qu.push(pa3(ve[i].first,ve[i].second,0));
		for(int i=0;i<h;i++)for(int j=0;j<w;j++)vis[i][j]=0;
		while(qu.size()){
			pa3 z=qu.front();
			qu.pop();
			if(vis[z.x][z.y])continue;
			vis[z.x][z.y]=1;
			if(s[z.x][z.y]!='.'){
				dis[i][ma[mp(z.x,z.y)]]=z.z;
		//		cout<<i<<" "<<ma[mp(z.x,z.y)]<<"  "<<z.z<<endl;
			}
			for(int r=0;r<4;r++){
				int x=z.x+dx[r];
				int y=z.y+dy[r];
				if(x<0||y<0 || x>=h || y>=w)continue;
				if(s[x][y]=='#')continue;
					if(!vis[x][y])qu.push((pa3){x,y,z.z+1});
			}
		}
	}
	int ans=inf;
	for(int i=1;i<(1<<n);i++){
		
		for(int j=0;j<n;j++)if(i&(1<<j)){
		if(i==(i&(-i))){
			dp[i][j]=dis[j][n];
		//	continue;
		}
		else{
				dp[i][j]=inf;
				for(int h=0;h<n;h++)if(i&(1<<h))if(h!=j)if(dis[j][h]<inf){
					dp[i][j]=min(dp[i][j],dp[i^(1<<j)][h]+dis[j][h]);
				}
			}
		
		if(__builtin_popcount(i)>=k && dis[j][n+1]<inf)ans=min(ans,dis[j][n+1]+dp[i][j]);
	}}
	
	if(ans==inf)cout<<-1<<endl;
else	cout<<ans<<endl;
	
	/*
	priority_queue<pa3,vector<pa3>,greater<pa3>> pq;     
	pq.push(pa3(0,n,0));
	
	while(pq.size()){
		pa3 z=pq.top();
		pq.pop();
		if(sumi[z.y][z.z])continue;
		sumi[z.y][z.z]=1;
	//	cout<<z.y<<" "<<z.z<<" "<<z.x<<endl;
		if(z.y==n+1){
			if(__builtin_popcount(z.z)>=k){
				cout<<z.x<<endl;
				return 0;
			}
		}
		for(int i=0;i<n;i++)if(dis[z.y][i]<inf){
			if(0==(z.z&(1<<i)))	pq.push((pa3){z.x+dis[z.y][i],i,(z.z|(1<<i))&((1<<n)-1)});
		}
		
		for(int i=n+1;i<n+2;i++)if(dis[z.y][i]<inf)if(__builtin_popcount(z.z)>=k){
			pq.push((pa3){z.x+dis[z.y][i],i,z.z});
		}

	}
cout<<-1<<endl;
	*/
	return 0; 
 }
