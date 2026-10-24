#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
 
int n,E,Q;
int cap[5002][5002];
 
bool used[5550];
vector<int>G[5002];
 
void add_edge(int from,int to,int X){
    G[from].push_back(to);
    G[to].push_back(from);
    cap[from][to]=cap[to][from]+=X;
}
 
int dfs(int v,int t,int f){
    if(v==t)return f;
    used[v]=1;
    for(int i=0;i<G[v].size();i++){
        int e=G[v][i];
        if(!(!used[e]&&cap[v][e]>0))continue;
        int d=dfs(e,t,min(f,cap[v][e]));
        if(d){
            cap[v][e]-=d;
            cap[e][v]+=d;
            return d;
        }
    }
    return 0;
}
 
int flow(int s,int t,int lim){
    int fl=0;
    for(;;){
        memset(used,0,sizeof(used));
        int f=dfs(s,t,lim);
        if(!f)return fl;
        fl+=f;
        lim-=f;
    }
}

int A[10000];
int B[10000];
int C[10000];

int main(){
    cin>>n>>E;
    r(i,E){
        int s,t,z;
        cin>>s>>t>>z;
        A[i]=s;
        B[i]=t;
        C[i]=z;
        add_edge(s,t,z);
    }
    int ANS=flow(0,n-1,1e4+2);

    if(ANS==1e4+2){
        cout<<-1<<endl;
        return 0;
    }

    r(i,E){
        if(C[i]!=1)continue;
        int s=A[i];
        int t=B[i];
            if(cap[t][s]==2)swap(s,t);
            if(cap[s][t]==2){
                int x=flow(t,s,1);
                if(!x){
                    flow(n-1,0,1);
                    flow(t,s,1);
                    ANS--;
                    cout<<ANS<<endl;
                    return 0;
                }
            }
    }
    if(ANS==1e4+1){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ANS<<endl;
}
