#include <iostream>

using namespace std;

int N;

void dfs(string s, char mx ){
    if(s.size() == N){
        cout << s << endl;
    }else{
        for(char c = 'a'; c <= mx; c++){
            dfs(s+c, (c == mx) ? (char)(mx+1) : mx);
        }
    }
}

int main(){
    cin >> N;
    dfs("",'a');
    
}