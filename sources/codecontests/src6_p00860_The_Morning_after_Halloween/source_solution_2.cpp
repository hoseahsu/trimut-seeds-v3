#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <cstring>
#include <queue>
#include <map>
#include <list>
#include <cmath>
#include <iomanip>
#define INF 0x3f3f3f3f
#define EPS 10e-5

typedef long long ll;
const int dx[]={-1,0,0,1,0},dy[]={0,1,-1,0,0};
using namespace std;
int w,h,n,ter;
char mps[20][20];
pair<char,char> pos[3];
pair<char,char> tar[3];
bool dp[1<<25];
int ncs[1<<10][5];
int nle[1<<10];
const int queS = 1<<22;
pair<int,int> aps[queS];
int ans,en;
int ecnt = 0,bcnt=0;

void push(const pair<int,int>&a)
{
    aps[ecnt++] = a;
    ecnt%=queS;
}

int solve(){
    int hash = 0,ans=0;
    bcnt = ecnt = 0;
    int sa = 0;
    for(int i=0;i<n;++i){
        hash += pos[i].first<<(i*8+4);
        hash += pos[i].second<<(i*8);
        ans += tar[i].first<<(i*8+4);
        ans += tar[i].second<<(i*8);
    }
    push(make_pair(hash,0));
    while(bcnt!=ecnt){
        pair<int,int> now = aps[bcnt++];
        bcnt%=queS;

        if(now.first==ans) {
            sa = now.second;break;
        }
        if(dp[now.first]) continue;
        dp[now.first] = true;
        if(n==1){
            int u = now.first&0xff;
            for(int i = 0;i<nle[u];++i){
                if(dp[ncs[u][i]]) continue;
                push(make_pair(ncs[u][i],now.second+1));
            }
        }else if(n==2){
            int u = now.first&0xff,v = (now.first>>8)&0xff;
            for(int i=0;i<nle[u];++i)
                for(int j=0;j<nle[v];++j){
                    if(dp[ncs[u][i]+(ncs[v][j]<<8)]||ncs[u][i]==ncs[v][j]
                            ||(ncs[u][i] == v&& ncs[v][j] == u)) continue;
                    push(make_pair(ncs[u][i]|(ncs[v][j]<<8),now.second+1));
                }
        }else{
            int u = now.first&0xff,v = (now.first>>8)&0xff,a = (now.first>>16)&0xff;
            for(int i=0;i<nle[u];++i)
                for(int j=0;j<nle[v];++j)
                    for(int k=0;k<nle[a];++k){
                        if(dp[ncs[u][i]+(ncs[v][j]<<8)+(ncs[a][k]<<16)]||
                                ncs[u][i]==ncs[v][j]||ncs[u][i]==ncs[a][k]
                                ||ncs[v][j]==ncs[a][k]
                                ||(ncs[v][j]==u&&v==ncs[u][i])
                                ||(a==ncs[u][i]&&u==ncs[a][k])
                                ||(ncs[v][j]==a&&v==ncs[a][k])) continue;
                        push(make_pair(ncs[u][i]|(ncs[v][j]<<8)|(ncs[a][k]<<16),now.second+1));
                    }
        }
    }
    return sa;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(~scanf("%d%d%d\n",&w,&h,&n)){
        if(w==0&&h==0&&n==0) break;
        memset(dp,0,sizeof(dp));
        memset(pos,0,sizeof(pos));
        memset(tar,0,sizeof(tar));
        memset(nle,0,sizeof(nle));

        for(int i=0;i<h;++i)
        {
            for(int j=0;j<w;++j)
            {
                scanf("%c",mps[i]+j);
                if(mps[i][j]!='#'&&mps[i][j]!=' '){
                    if(islower(mps[i][j])){
                        pos[mps[i][j]-'a'].first = i;
                        pos[mps[i][j]-'a'].second = j;
                    }else{
                        tar[mps[i][j]-'A'].first = i;
                        tar[mps[i][j]-'A'].second = j;
                        mps[i][j] = ' ';
                    }
                }
            }
            getchar();
        }

        for(int i=1;i<h;++i){
            for(int j=1;j<w;++j){
                if(mps[i][j]!='#'){
                    for(int k=0;k<4;++k){
                        if(mps[i+dy[k]][j+dx[k]]!='#'){
                            ncs[(i<<4)+j][nle[(i<<4)+j]++]
                                    = (((i+dy[k])<<4)+dx[k]+j);
                        }
                    }
                    ncs[(i<<4)+j][nle[(i<<4)+j]++] = (i<<4)+j;
                }
            }
        }
        printf("%d\n",solve());
    }
    return 0;
}

