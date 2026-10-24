#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define vi vector<int>
#define pb push_back
#define INF 999999999

int n;
void f(int data[20][20],int size){
    int tmp[20][20];
    rep(i,20)rep(j,20)tmp[i][j]=data[i][j];
    rep(i,size){
        rep(j,size){
            data[i][j] = tmp[size-j-1][i];
        }
    }
}

void turn(int data[20][20],int r,int c,int size,int angle){
    int tmp[20][20];
    for(int y=0,i=r;i<=r+size-1;i++,y++){
        for(int x=0,j=c;j<=c+size-1;j++,x++){
            tmp[y][x] = data[i][j];
        }
    }
    angle/=90;
    rep(i,angle)f(tmp,size);
    
    for(int y=0,i=r;i<=r+size-1;i++,y++){
        for(int x=0,j=c;j<=c+size-1;j++,x++){
            data[i][j] = tmp[y][x];
        }
    }
}

vector<pii> p;
void dfs(int data[20][20],int y,int x,bool used[20][20]){
    p.pb(pii(y,x));
    used[y][x]=true;
    
    int dy[]={1,0,-1,0};
    int dx[]={0,1,0,-1};

    rep(i,4){
        int ddy = y+dy[i];
        int ddx = x+dx[i];
        if( ddx>=0 && ddy>=0 && ddx<n && ddy<n && !used[ddy][ddx] && data[y][x] == data[ddy][ddx]){
            dfs(data,ddy,ddx,used);
        }
    }
}


int main(){
    int m;
    cin>>n>>m;
    int data[20][20];
    rep(i,n)rep(j,n)cin>>data[i][j];
    
    rep(i,m){
        int o;
        cin>>o;
        if(o==0){           //?????¢
            int r,c,size,angle;
            cin>>r>>c>>size>>angle;
            r--,c--;
            turn(data,r,c,size,angle);
        }else if(o==1){     //?????¢
            int r,c,size;
            cin>>r>>c>>size;
            r--,c--;
            for(int i=r;i<=r+size-1;i++){
                for(int j=c;j<=c+size-1;j++){
                    data[i][j] = !data[i][j];
                }
            }
        }else if(o==2){     //????????????
            int r;
            cin>>r;
            r--;
            data[r][n]=data[r][0];
            rep(i,n) data[r][i] = data[r][i+1];
            data[r][n]=0;
        }else if(o==3){     //????????????
            int r;
            cin>>r;
            r--;
            for(int i=n;i>0;i--)data[r][i]=data[r][i-1];
            data[r][0] = data[r][n];
            data[r][n]=0;
        }else if(o==4){     //??¶?????¢
            int r,c;
            cin>>r>>c;
            r--,c--;
            p.clear();
            bool used[20][20]={};
            dfs(data,r,c,used);
            rep(i,p.size()){
                int y=p[i].first,x=p[i].second;
                data[y][x] = !data[y][x];
            }
        }
    }
    
    
    
    rep(i,n){
        rep(j,n){
            if(j!=0)cout<<" ";
            cout<<data[i][j];
        }
        cout<<endl;
    }
}