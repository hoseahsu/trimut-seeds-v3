#include <bits/stdc++.h>
using namespace std;

int n;
string s;

// 右端からx個の'I'を終端と決め打ったときにx個構成できるか
bool f(int x){
    int icnt=0, ocnt=0, y=0, r=x;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='J'){
            if(ocnt>0){
                y++;
                ocnt--;
            }
        }
        if(s[i]=='O'){
            if(icnt>0){
                ocnt++;
                icnt--;
            }
        }
        if(s[i]=='I'){
            if(r>0){
                icnt++;
                r--;
            }else if(ocnt>0){
                y++;
                ocnt--;
            }
        }
    }
    return y==x;
}

int solve(){
    cin >> n >> s;
    int ok = 0, ng = n/3+1;
    while(abs(ok-ng)>1){
        int mid = (ok+ng)/2;
        if(f(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}

int main(){
    solve();
    return 0;
}

