#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(10);
    int ans = 0;
    while(n--){
        string s;
	    cin>>s;
	    for(int j=2;j<s.size();j++){
		    if(s[j-2]=='A'&&s[j-1]=='O'&&s[j]=='R')ans++;
	    }
	    if(s.size()==1&&s[0]=='O')v[9]++;
	    else if(s[0]=='R'){
		    if(s.back()=='A')v[1]++;
		    else if(s.size()>=2&&s[s.size()-2]=='A'&&s.back()=='O')v[2]++;
		    else v[3]++;
    	}
	    else if(s.size()>=2&&s[0]=='O'&&s[1]=='R'){
		    if(s.back()=='A')v[4]++;
    		else if(s.size()>=2&&s[s.size()-2]=='A'&&s.back()=='O')v[5]++;
	    	else v[6]++;
	    }
    	else {
    		if(s.back()=='A')v[7]++;
    		else if(s.size()>=2&&s[s.size()-2]=='A'&&s.back()=='O')v[8]++;
    	}
    }
    while(v[2]>=1&&v[1]+v[2]+v[3]+v[5]+v[8]>=2)--v[2],++ans;
    while(v[4]>=1&&v[4]+v[5]+v[6]+v[1]+v[7]>=2)--v[4],++ans;

    while(v[1]&&v[5]){
        --v[1],--v[5],++ans;
        if(v[5]+v[6]+v[1]+v[7]>=1)++ans;
        else if(v[1]+v[3]+v[5]+v[8]>=1)++ans;
        else ++v[4];
    }
    while(v[1]){
        if(v[1]&&v[6])--v[1],--v[6],++v[3],++ans;
        else if(v[1]&&v[8])--v[1],--v[8],++v[7],++ans;
        else break;
    }
    while(v[5]){
        if(v[5]&&v[3])--v[5],--v[3],++v[6],++ans;
        else if(v[5]&&v[7])--v[5],--v[7],++v[8],++ans;
        else break;
    }
    
    while(v[2]){
        if(v[2]&&v[3])--v[2],++ans;
        else if(v[2]&&v[8])--v[2],++ans;
        else break;
    }
    while(v[4]){
        if(v[4]&&v[6])--v[4],++ans;
        else if(v[4]&&v[7])--v[4],++ans;
        else break;
    }
    
    while(v[3]&&v[8])--v[3],--v[8],++ans;
    while(v[6]&&v[7])--v[6],--v[7],++ans;
    
    while(v[9]){
        if(v[2]&&v[4])--v[2],--v[4],--v[9],++ans;
        else if(v[2]&&v[4])--v[2],--v[4],--v[9],++ans;
        else if(v[2]&&v[7])--v[2],--v[7],--v[9],++ans;
        else if(v[3]&&v[4])--v[3],--v[4],--v[9],++ans;
        else if(v[3]&&v[7])--v[3],--v[7],--v[9],++ans;
        else break;
    }
    while(v[9]){
        if(v[1]&&v[7])--v[1],--v[7],--v[9],++ans;
        else if(v[1]&&v[4])--v[1],--v[4],--v[9],++ans;
        else break;
    }
    while(v[9]){
        if(v[1]&&v[2])--v[1],--v[2],--v[9],++ans;
        else if(v[1]&&v[3])--v[1],--v[3],--v[9],++ans;
        else break;
    }
    while(v[9]){
        if(v[1]>=2)v[1]-=2,--v[9],++ans;
        else break;
    }
    cout<<ans<<endl;
    return 0;
}
