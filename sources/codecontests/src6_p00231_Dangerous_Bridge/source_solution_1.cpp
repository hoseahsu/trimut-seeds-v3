#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int,int> pi;
#define F first
#define S second
#define MP make_pair
int main(){
    int n,w,l,r,now;
    bool f;
    priority_queue<pi,vector<pi>,greater<pi>>pq;
    while(true){
        scanf("%d",&n);
        if(n==0)return 0;
        while(n--){
            scanf("%d%d%d",&w,&l,&r);
            pq.push(MP(l,w));
            pq.push(MP(r,-w));
        }
        f=true;
        now=0;
        while(!pq.empty()){
            l=pq.top().F;
            now+=pq.top().S;
            pq.pop();
            while(!pq.empty()){
                if(l==pq.top().F){
                    now+=pq.top().S;
                    pq.pop();
                }
                else break;
            }
            if(now>150)f=false;
        }
        if(f)printf("OK\n");
        else printf("NG\n");
        
    }
}
