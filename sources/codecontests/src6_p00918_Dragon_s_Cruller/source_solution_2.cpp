 
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
constexpr int tv[]={-3,-1,1,3};
constexpr int p10[]={100000000,10000000,1000000,100000,10000,1000,100,10,1};
constexpr int fact[]={40320,5040,720,120,24,6,2,1};

int my_hash(int f){
    vector<int> v={0,1,2,3,4,5,6,7,8};
    int ret=0;
    rep(i,8){
        auto itr=lower_bound(v.begin(),v.end(),f%10);
        ret+=fact[i]*(itr-v.begin());
        v.erase(itr);
        f/=10;
    }
    return ret;
}


int main(){
    
    int h,v;
    string a="123456789",b="123456789";
    using data=pair<int,int>;
    
    while(cin>>h>>v, h or v){
        vector<int> hm(362880,-10000000);
        int tc[]={v,h,h,v};
        rep(i,9)cin>>a[i];
        rep(i,9)cin>>b[i];
        int sa=stoi("1"+a)-1000000000,sb=stoi("1"+b)-1000000000;

        priority_queue<data> q;
        q.emplace(0,sa);
        
        while(1){
            int cost=q.top().fs;
            int board=q.top().sc;
            if(board==sb){
                cout<<-cost<<endl;
                break;
            }
            q.pop();
            int index=to_string(board).find('0');
            if(index==-1)index=0;
            rep(i,4){
                int fixed=(index+tv[i]+9)%9;
                int next=board;
                int fx=board/p10[fixed]%10;
                next=next+(p10[index]-p10[fixed]) * fx;
                int nc=cost-tc[i];
                int hval=my_hash(next);
                if(hm[hval]<nc){
                    q.emplace(nc, next);
                    hm[hval]=nc;
                }
            }
        }
    }
}

