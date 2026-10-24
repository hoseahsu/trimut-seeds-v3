#line 2 "/home/defineprogram/Desktop/Library/template/template.cpp"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define REP(i, n) for (int i = 1; i < n; i++)
#define rev(i, n) for (int i = n - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define P pair<ll, ll>
#define len(s) (ll) s.size()

template <class T, class U>
inline bool chmin(T &a, U b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T, class U>
inline bool chmax(T &a, U b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
constexpr ll inf = 3e18;
#line 2 "main.cpp"

int N,A[1<<17];
int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin>>N;
    rep(i,N)cin>>A[i];
    string s;cin>>s;
    bool plus=false,minus=false,mul=false;
    for(char c:s){
        if(c=='+')plus=true;
        else if(c=='-')minus=true;
        else mul=true;
    }
    if(len(s)==1){
        rep(i,N){
            if(i)cout<<s;
            cout<<A[i];
        }
        cout<<"\n";
    }else if(!mul){
        rep(i,N){
            if(i)cout<<'+';
            cout<<A[i];
        }
        cout<<"\n";
    }else if(!plus){
        rep(i,N){
            if(i&&!A[i])cout<<'-';
            else if(i)cout<<'*';
            cout<<A[i];
        }
        cout<<"\n";
    }else {
        vector<char>ans(N,'+');
        int cur=0;
        while(cur<N){
            if(!A[cur]){cur++;continue;}
            int ri=cur;
            while(ri<N&&A[ri])ri++;
            int multiple=1;
            bool flag=false;
            while(cur<ri&&A[cur]==1)cur++;
            int realri=ri;
            while(cur<ri&&A[ri-1]==1)ri--;
            for(int i=cur;i<ri;i++){
                multiple*=A[i];
                if(multiple>1e6){flag=true;break;}
            }
            if(flag){
                for(int i=cur;i<ri-1;i++)ans[i]='*';
                cur=realri;continue;
            }
            struct S{
                int l,r,sum,mul;
            };
            vector<S>V;
            {
                int i=cur;
                while(i<ri){
                    int j=i;
                    int sum=0,multi=1;
                    while(j<ri&&(A[i]==1)==(A[j]==1)){
                        sum+=A[j];multi*=A[j];j++;
                    }
                    V.push_back({i,j,sum,multi});
                    i=j;
                }
            }

            vector<int>dp(len(V)+1);
            rep(i,len(V)){
                chmax(dp[i+1],dp[i]+V[i].sum);
                int mul__=1;
                for(int j=i;j<len(V);j++){
                    mul__*=V[j].mul;
                    chmax(dp[j+1],dp[i]+mul__);
                }
            }
            int now=len(V);
            while(now>0){
                if(dp[now-1]+V[now-1].sum==dp[now]){
                    now--;continue;
                }
                int mul__=1;
                for(int i=now-1;i>=0;i--){
                    for(int j=V[i].l;j<V[i].r-1;j++)ans[j]='*';
                    mul__*=V[i].mul;
                    if(dp[i]+mul__==dp[now]){
                        now=i;break;
                    }
                    ans[V[i].l-1]='*';
                }
            }
            cur=realri;
        }

        ll sum=0,multiii=A[0];
        REP(i,N){
            if(ans[i-1]=='*')multiii*=A[i];
            else {
                sum+=multiii;multiii=A[i];
            }
        }
        //cout<<sum+multiii<<"\n";
        rep(i,N){
            if(i)cout<<ans[i-1];
            cout<<A[i];
        }
        cout<<"\n";
    }
}
