 
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
constexpr int tv[]={-3,-1,1,3};
constexpr int p10[]={100000000,10000000,1000000,100000,10000,1000,100,10,1};
 
int main(){
    int h,v;
    string a="123456789",b="123456789";
    using data=pair<int,int>;
    
    while(cin>>h>>v, h or v){
        int tc[]={v,h,h,v};
        rep(i,9)cin>>a[i];
        rep(i,9)cin>>b[i];
        int sa=stoi("1"+a)-1000000000,sb=stoi("1"+b)-1000000000;

        unordered_map<int,int> s;

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
                int fx=next/p10[fixed]%10;
                next=next-p10[fixed]*fx+p10[index]*fx;
                if((s.find(next)==s.end() || s[next]<cost-tc[i]) && cost-tc[i]>-2000){
                    q.emplace(cost-tc[i], next);
                    s[next]=cost-tc[i];
                }
            }
        }
    }
}

