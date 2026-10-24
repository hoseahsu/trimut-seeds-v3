#include<bits/stdc++.h>
using namespace std;

int A,B,C,N;
const int MAX = 20000*30;
int d[MAX];
void init(){ memset( d, -1, sizeof( d ) ); }
int find(int a){ return d[a]<0?a:(d[a]=find(d[a])); }
bool merge(int a, int b){
  a = find(a); b = find(b);
  if( a == b ) return false;
  if( d[a] > d[b] ) swap( a, b );
  d[a] += d[b]; d[b] = a;
  return true;
}
bool same(int a,int b){
  return find(a) == find(b);
}

struct P3{
  int x,y,z;
  P3(){}
  P3(int x,int y,int z) : x(x),y(y),z(z) {}
  bool operator<(const P3& p) const {
    if( x == p.x )
      if( y == p.y )
        return z < p.z;
      else
        return y < p.y;
    else
      return x< p.x;
  }
};

int dx[]={ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int dy[]={ 1, 1, 1, 0, 0, 0, 1,-1,-1, 1, 1, 1, 0, 0, 0,-1,-1,-1, 1, 1, 1, 0, 0, 0,-1,-1,-1};
int dz[]={ 1, 0,-1, 1, 0,-1, 1, 0,-1, 1, 0,-1, 0, 1,-1, 1, 0,-1, 1, 0,-1, 1, 0,-1, 1, 0,-1};
int mx[]={ 1,-1, 0, 0, 0, 0};
int my[]={ 0, 0, 1,-1, 0, 0};
int mz[]={ 0, 0, 0, 0, 1,-1};
map<P3,int> id;
set<P3> umes;
map<int,set<int>> divi;
int cnt;
bool used[MAX];
bool ume[MAX];

bool outer(int x,int y, int z ){
  if( x < 0 || x >= A || y < 0 || y >= B || z < 0 || z >= C ) return true;
  return false;
}

bool check( int x,int y,int z, bool f = false ){
  if( id.count( P3( x, y, z ) ) == 0 ) return false;
  int v = id[ P3(x,y,z) ];
  if( used[ v ] ) return false;
  if( f && !ume[ v ] ) return false;
  if( !f && ume[ v ] ) return false;
  return true;
}
/*
void dfs(int x,int y, int z, bool f = false){
  cout << x << " " << y << " " <<z << endl;
  int v = id[ P3(x,y,z) ];
  if( used[ v ] ) return;
  used[ v ] = true;
  int n = 6;
  if( f ) n = 27;
  for(int i=0;i<n;i++){
    int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
    if(!f) nx = x + mx[i], ny = y + my[i], nz = z + mz[i];
    if( check( nx, ny, nz, f ) ) {
      // cout << x << " " << y << " " << z << "  -> " << nx << " " << ny << " " << nz << endl;
      // cout << "merge " << v << " "<< id[P3(nx,ny,nz)] << endl;
      merge( v, id[ P3(nx,ny,nz) ] );
      dfs( nx, ny, nz, f );
    }
  }
}
*/
void bfs(int x,int y,int z, bool f = false ){
  int v = id[P3(x,y,z)];
  if( used[v] ) return;
  queue<P3> q;
  q.push( P3(x,y,z) );
  used[ v ] = true;
  while( !q.empty() ){
    P3 p = q.front(); q.pop();
    x = p.x; y = p.y; z = p.z;
    v = id[ p ];
    int n = 6;
    if( f ) n = 27;
    for(int i=0;i<n;i++){
      int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
      if(!f) nx = x + mx[i], ny = y + my[i], nz = z + mz[i];
      if( check( nx, ny, nz, f ) ) {
        int nv = id[ P3(nx,ny,nz) ];
        merge( v, nv );
        q.push( P3(nx,ny,nz) );
        used[ nv ] = true;
      }
    }
  }
}

int main(){
  cin >> A >> B >> C >> N;
  init();
  for(int i=0;i<N;i++){
    int x,y,z; cin >> x >> y >> z;
    for(int j=0;j<27;j++){
      int nx = x + dx[j], ny = y + dy[j], nz = z + dz[j];
      if( outer( nx, ny, nz ) ) continue;
      if( !id.count( P3( nx,ny,nz) ) ) 
        id[ P3(nx,ny,nz) ] = cnt++;     
    }
    umes.insert( P3(x,y,z) );
    ume[id[P3(x,y,z)]] = true;
  }
  
  for( auto it = id.begin(); it != id.end(); it++ ){
    P3 np = it->first;
    int v = it->second;
    if( ume[v] ) 
      bfs( np.x, np.y, np.z, true );
    else
      bfs( np.x, np.y, np.z );
  }

  for( auto it = umes.begin(); it != umes.end(); it++ ){
    P3 p = *it;
    int v = find( id[p] );
    for(int i=0;i<27;i++){
      int nx = p.x + dx[i], ny = p.y + dy[i], nz = p.z + dz[i];
      if( id.count( P3(nx,ny,nz) ) == 0 ) continue;
      if( umes.count( P3( nx, ny, nz ) ) ) continue;
      //cout << nx << " " << ny << " "<< nz << " = " << find(id[P3(nx,ny,nz)]) << " <= " << v << endl;
      divi[ v ].insert( find( id[ P3(nx,ny,nz) ] ) );
    }
  }

  int res = 1;
  for( auto it = divi.begin(); it != divi.end(); it++ ){
    res += it->second.size()-1;
  }
  cout << res << endl;
  
}