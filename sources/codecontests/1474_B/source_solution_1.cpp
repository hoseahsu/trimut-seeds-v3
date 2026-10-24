#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const int mod =1e9 + 7;
bool isp[maxn];
void fun(){
    isp[1] = false;
    for(int i = 2;i < maxn;i ++) isp[i] = true;

    for(int i = 2;i < maxn;i ++){
        if(isp[i]){
            for(long long j = 1ll*i*i;j < maxn;j += i){
            isp[j] = false;
            }
        }
        
    }
}
int main(){
    
    
    int cn,d;
    scanf("%d",&cn);
    fun();
    
    while(cn --){
        scanf("%d",&d);
        int b,c;
        for(int i = 1+d;i < maxn;i ++){
            if(isp[i]) {b = i;break;}
        }
        for(int i = b+d;i < maxn;i ++){
            if(isp[i] ) {c= i;break;}
        }
        // printf("%d %d\n",b,c);
        printf("%d\n",b*c);
    }
    
    return 0;
}