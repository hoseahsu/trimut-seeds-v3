#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){

    int H=1,W;cin>>W;
    vector<vector<ll>> A(H,vector<ll>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>A[i][j];
        }
    }
    
    ll ans=0;
    
    for(int i=0;i<H;i++){
        stack<pair<ll,int>> ST;
        vector<int> L(W),R(W);
        for(int j=0;j<W;j++){
            if(ST.empty()){
                L[j]=0;
                ST.push(make_pair(A[i][j],j));
            }
            else if(ST.top().first<A[i][j]){
                L[j]=ST.top().second+1;
                ST.push(make_pair(A[i][j],j));
            }else if(ST.top().first>=A[i][j]){
                while(!ST.empty()&&ST.top().first>=A[i][j]){
                    ST.pop();
                }
                if(ST.empty()) L[j]=0;
                else L[j]=ST.top().second+1;
                ST.push(make_pair(A[i][j],j));
            }
        }
        reverse(all(A[i]));
        
        while(!ST.empty()) ST.pop();
        
        for(int j=0;j<W;j++){
            if(ST.empty()){
                R[j]=0;
                ST.push(make_pair(A[i][j],j));
            }
            else if(ST.top().first<A[i][j]){
                R[j]=ST.top().second+1;
                ST.push(make_pair(A[i][j],j));
            }else if(ST.top().first>=A[i][j]){
                while(!ST.empty()&&ST.top().first>=A[i][j]){
                    ST.pop();
                }
                if(ST.empty()) R[j]=0;
                else R[j]=ST.top().second+1;
                ST.push(make_pair(A[i][j],j));
            }
            R[j]=W-R[j];
        }
        reverse(all(R));
        reverse(all(A[i]));
        
        for(int j=0;j<W;j++){
            ans=max(ans,A[i][j]*(R[j]-L[j]));
        }
        
        /*for(int j=0;j<W;j++){
            ans=max(ans,A[i][j]*(R[j]-L[j]));
            cout<<R[j];
            cout<<" ";
        }
        cout<<endl;*/
    }
    
    cout<<ans<<endl;
    
}


