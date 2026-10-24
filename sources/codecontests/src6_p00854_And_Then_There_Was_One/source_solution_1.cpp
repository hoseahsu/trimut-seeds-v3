#include <iostream>
#include <vector>
using namespace std;
void ans(int n,int k, int m){
    int i,itr;
    vector<int> world;
    for(i=0;i<n;i++){
        world.push_back(i+1);
    }
    itr=m-1;
    for(i=0;i<n-1;i++){
        world.erase(world.begin()+itr);
        itr=(itr-1+k)%world.size();
    }
    cout << world[0]<<endl;
}

int main(void){
    int n,k,m;
    while(1){
        cin >> n >> k >> m ;
        if(n==0){
            break;
        }
        ans(n,k,m);
    }
}