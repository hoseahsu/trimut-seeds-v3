#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

#define EPS (1e-9)

// KEXÌÁ@ÅA§®ðÆ­
bool gauss_jordan(const mat&A,const vec &b){
    int n=A.size();
    mat B(n,vec(n+1));
    for(int i = 0; i < n;i++)
        for(int j=0;j<n;j++)
            B[i][j]=A[i][j];
    for(int i = 0; i < n; i++)
        B[i][n]=b[i];
    // eÏÉÚ
    for(int i = 0; i < n; i++){
        // ÅåÌWÌâÎlðàÂàÌðiÔÚÉÁÄ­é
        int piv=-1;
        int val=-1;
        for(int j=i;j<n;j++){
            if(val<abs(B[j][i])){
                piv=j;
                val=abs(B[j][i]);
            }
        }
        // EÓª0ÉÈé©Ç¤©²×é
        if(piv==-1||val<=0)
            continue;
        swap(B[piv],B[i]);
        for(int j = 0; j < n; j++){
            if(i==j)continue;
            int mulnum=B[j][i];
            if(mulnum==1){
                for(int k = i; k <= n; k++)
                    B[j][k]=(B[j][k]+B[i][k])%2;
            }
        }
    }
    vec res(n);
    for(int i = 0; i < n; i++){
        res[i]=B[i][n];
        if(B[i][i]==0){
            if(B[i][n]==1)return false;
        }
    }
    return true;
}
int M,N,D;
int field[101][101];

int main(){

    while(cin>>M>>N>>D&&(M|N|D)){
        for(int i=0;i<N;i++)for(int j=0;j<M;j++)cin>>field[i][j];
        mat A(M*N,vec(M*N));
        vec B(M*N,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(field[i][j])B[i*M+j]=1;
                for(int k=0;k<N;k++){
                    for(int l=0;l<M;l++){
                        // }nb^£
                        int dist=abs(l-j)+abs(i-k);
                        if(dist==D||dist==0)A[i*M+j][k*M+l]=1;
                    }
                }
            }
        }
        bool res=gauss_jordan(A,B);
        if(res)cout<<1<<endl;
        else cout<<0<<endl;
    }

    return 0;
}