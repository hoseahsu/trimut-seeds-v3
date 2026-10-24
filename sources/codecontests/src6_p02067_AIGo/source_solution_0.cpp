#include <bits/stdc++.h>
using namespace std;

int main(){
    int L;
    string S;
    cin >> L >> S;
    S = "." + S + ".";
    int ans = 0;
    for(int i=1; i<=L; i++){
        if(S[i] != '.') continue;
        bool ng = true;
        for(int d : {-1, 1}) for(int j=i+d; ; j+=d){
            if(S[j] == 'B'){
                break;
            }else if(S[j] == '.'){
                ng = false;
                break;
            }
        }
        if(ng) continue;
        int gain = 0;
        for(int d : {-1, 1}){
            int g = 0;
            for(int j=i+d; ; j+=d){            
                if(S[j] == 'B'){
                    g++;
                }else if(S[j] == '.'){
                    break;
                }else{
                    gain += g;
                    break;
                }
            }
        }
        ans = max(ans, gain);
    }
    cout << ans << endl;
    return 0;
}

