#include <bits/stdc++.h>
using namespace std;

#define RG register int
#define LL long long

template<typename elemType>
inline void Read(elemType &T){
    elemType X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    T=(w?-X:X);
}

int sum[205];
int T,N,M;

int main(){
    Read(T);
    while(T--){
        Read(N);Read(M);
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                int x;Read(x);
                sum[i+j]^=x;
            }
        }
        bool flag=true;
        for(int i=2;i<=N+M;++i)
            if(sum[i]!=0){flag=false;break;}
        if(flag) printf("Jeel\n");
        else printf("Ashish\n");
    }
    return 0;
}