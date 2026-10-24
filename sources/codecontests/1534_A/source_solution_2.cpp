#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        char A[m][n];
        int pos=-1,count=0;
        char c='.',cc;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>A[i][j];
                if(A[i][j]=='\n'){
                    j--;
                    continue;
                }
                if(!count && A[i][j]!='.'){
                    c=A[i][j];
                    cc=(A[i][j]=='R')?'W':'R';
                    pos=(i+j)%2;
                }
                if(A[i][j]!='.') count++;
            }
        }
        if(count<2){
            if(!count){
                c='R';
                cc='W';
                pos=0;
            }
            cout<<"YES\n";
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(((i+j)%2==pos)) cout<<c;
                    else cout<<cc;
                }
                cout<<"\n";
            }
            continue;
        }

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++) cout<<A[i][j];
        //     cout<<"\n";
        // }
        int flag=true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]!='.'){
                    if(((i+j)%2==pos)){
                        if(A[i][j]!=c){
                            flag=false;
                        }
                    }
                    else if(A[i][j]!=cc) flag=false;

                    if(!flag) break;
                }
            }
            if(!flag) break;
        }
        if(flag){
            cout<<"YES\n";
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if((i+j)%2==pos) cout<<c;
                    else cout<<cc;
                }
                cout<<"\n";
            }
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}