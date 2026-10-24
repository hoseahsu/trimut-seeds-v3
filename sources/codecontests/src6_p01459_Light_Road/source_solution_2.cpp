#include<bits/stdc++.h>
using namespace std;

struct State{
    int i,j;
    int dir;
    int p;
    int q;
    bool mir;
};
bool operator<(State lhs,State rhs){
    return make_tuple(lhs.i,lhs.j,lhs.dir,lhs.p,lhs.q,lhs.mir)<make_tuple(rhs.i,rhs.j,rhs.dir,rhs.p,rhs.q,rhs.mir);
}
using Field=vector<string>;
int di[]={0,-1,0,1};
int dj[]={1,0,-1,0};
int pd[]={3,2,1,0};
int qd[]={1,0,3,2};

int main(){
    int n,m,a;
    cin>>n>>m>>a;
    Field f(n);
    for(int i=0;i<n;i++){
        cin>>f[i];
    }    
    int inii=-1;
    int inij=-1;
    deque<State> que;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(f[i][j]=='S'){
                que.push_back({i,j,3,a,a,true});
                inii=i;
                inij=j;
            }
        }
    }
    auto isRange=[&](int i,int j){
        return 0<=i && i<n && 0<=j&& j<m && f[i][j]!='#';
    };
    
    set<State> used;
    while(!que.empty()){
        auto st=que.front(); que.pop_front();
        if(f[st.i][st.j]=='S' && st.dir==1) continue;
        if(used.count(st)) continue;
        used.insert(st);
        if(f[st.i][st.j]=='G'){
            cout<<a-st.p+a-st.q<<endl;
            return 0;
        }
        if(isRange(st.i+di[st.dir],st.j+dj[st.dir])){
            State to=st;
            to.i+=di[st.dir];
            to.j+=dj[st.dir];
            to.mir=false;
            que.push_front(to);
        }
        if(st.mir)  continue;
        if(st.p>0){
            State to=st;
            to.p--;
            to.dir=pd[to.dir];
            to.mir=true;
            que.push_back(to);
        }
        if(st.q>0){
            State to=st;
            to.q--;
            to.dir=qd[to.dir];
            to.mir=true;
            que.push_back(to);
        }
    }
    cout<<-1<<endl;
    return 0;
}
