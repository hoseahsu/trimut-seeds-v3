#include <iostream>
using namespace std;

int ans(int sum, int max, int n, int k, int s){
    if(sum > s) return 0;
    if(k==0){
        if(sum==s){
            return 1;
        }else{
            return 0;
        }
    }
    int count=0;
    for(int i=max+1; i+k-1<=n; i++){
        count += ans(sum+i, i, n, k-1, s);
    }
    return count;
}

int main(){
    while(1){
        int n,k,s;
        cin >> n >> k >> s;
        if(n==0) break;

        cout << ans(0,0,n,k,s) << endl;
    }
    return 0;
}