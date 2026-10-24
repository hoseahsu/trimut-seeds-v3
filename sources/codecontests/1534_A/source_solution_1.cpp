#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int t;
    cin>>t;
    for(int z=0;z<t;z++){
        int n,m;
        cin>>n>>m;
        
        char arr[n][m];
        char arr1[n][m];
        char arr2[n][m];
        int val=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
                arr1[i][j]=(val==0?'R':'W');
                arr2[i][j]=(val==0?'W':'R');
                if(val==0){
                    val=1;
                }else{
                    val=0;
                }
            }
            if(m%2==0){
                if(val==0){
                    val=1;
                }else{
                    val=0;
                }
            }
        }
        
        bool flag1=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]!='.' && arr[i][j]!=arr1[i][j]){
                    flag1=false;
                }
            }
        }
        
        bool flag2=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]!='.' && arr[i][j]!=arr2[i][j]){
                    flag2=false;
                }
            }
        }
        
        if(flag1){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<arr1[i][j];
                }
            cout<<endl;
            }
        }else if(flag2){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<arr2[i][j];
                }
            cout<<endl;
            }
        }else{
            cout<<"NO"<<endl;
        }
    
        
    }

    return 0;
}
