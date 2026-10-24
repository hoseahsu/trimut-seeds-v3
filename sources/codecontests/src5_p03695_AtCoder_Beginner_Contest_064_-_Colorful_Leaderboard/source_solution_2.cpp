#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int tcount = 0;
    set<int> st;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        if(a>=3200){
            tcount++;
        }else{
            st.insert(a/400);
        }
    }
    cout << max((int)st.size(),1) << " " << st.size() + tcount;
}