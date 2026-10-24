#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,X,Y;
    cin >> N >> X >> Y;
    X--;
    Y--;
    vector<int> sum(N,0);
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            sum[min({j-i,abs(j-X)+abs(i-Y)+1,abs(i-X)+abs(j-Y)+1})]++;
        }
    }

    for(int i=1;i<N;i++){
        cout << sum[i] << endl;
    }
}
