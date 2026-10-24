#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T,class U> using P = pair<T,U>;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

constexpr int inf = 1e9+1;
int ma[4][2010][2010] = {};
int mi[4][2010][2010] = {};
int exist[4][2010] = {};
int A[4][2010][2010] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H,W;
    int M = 0;
    cin >> H >> W;
    for(int i=0;i<H;i++) for(int j=0;j<W;j++){
        cin >> A[0][i][j];
        A[1][W-j-1][i] = A[0][i][j];
        M = max(M,A[0][i][j]);
    }
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) A[2][i][j] = A[0][i][W-j-1];
    for(int i=0;i<W;i++) for(int j=0;j<H;j++) A[3][i][j] = A[1][i][H-j-1];

    for(int t=0;t<4;t++) for(int i=0;i<=max(H,W);i++){
        exist[t][i] = -1;
        for(int j=0;j<=max(H,W);j++){
            ma[t][i][j] = 0;
            mi[t][i][j] = inf;
        }
    }

    auto calc = [&](int H,int W,int t){
        for(int i=0;i<H;i++) for(int j=W-1;j>=0;j--){
            ma[t][i][j] = max(ma[t][i][j+1],A[t][i][j]);
            mi[t][i][j] = min(mi[t][i][j+1],A[t][i][j]);
            if(A[t][i][j]==M) exist[t][i] = max(exist[t][i],j);
        }
    };

    calc(H,W,0);
    calc(W,H,1);
    calc(H,W,2);
    calc(W,H,3);
    
    auto check = [&](int H,int W,int d,int t){
        bool res = false;
        int ma2 = 0,mi2 = inf,pl = W-1;
        bool judge = true;
        for(int i=0;i<H;i++){
            int l = -1;
            for(int j=0;j<=pl;j++){
                if(A[t][i][j]<M-d) break;
                l = j;
            }
            if(l<exist[t][i]){
                judge = false;
                break;
            }
            mi2 = min(mi2,mi[t][i][l+1]);
            ma2 = max(ma2,ma[t][i][l+1]);
            pl = l;
        }
        res |= judge && ma2-mi2<=d;
        ma2 = 0,mi2 = inf,pl = W-1,judge = true;
        for(int i=H-1;i>=0;i--){
            int l = -1;
            for(int j=0;j<=pl;j++){
                if(A[t][i][j]<M-d) break;
                l = j;
            }
            if(l<exist[t][i]){
                judge = false;
                break;
            }
            mi2 = min(mi2,mi[t][i][l+1]);
            ma2 = max(ma2,ma[t][i][l+1]);
            pl = l;
        }
        res |= judge && ma2-mi2<=d;
        return res;
    };

    auto ok = [&](int d){
        bool res = false;
        res |= check(H,W,d,0);
        res |= check(W,H,d,1);
        res |= check(H,W,d,2);
        res |= check(W,H,d,3);
        return res;
    };

    int l = -1,r = M;
    while(l+1<r){
        int m = (l+r)>>1;
        (ok(m)? r:l) = m;
    }
    cout << r << endl;
}
