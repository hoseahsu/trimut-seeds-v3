#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,old,gene[7];
    while(cin>>n&&n!=0){
        for(int i=0;i<7;i++)gene[i]=0;
        for(int i=0;i<n;i++){
            cin>>old;
            for(int j=1;j<7;j++){
                if(old-j*10<0){
                        gene[j-1]++;
                        break;
                }
                else if(j==6)gene[6]++;
            }
        }
        for(int i=0;i<7;i++)cout<<gene[i]<<endl;
    }
}