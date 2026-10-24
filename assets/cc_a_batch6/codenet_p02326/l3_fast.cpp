#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 1
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int h,w;cin>>h>>w;vector<int>prev(w+1),cur(w+1);int best=0;for(int i=0;i<h;i++){fill(cur.begin(),cur.end(),0);for(int j=1,x;j<=w;j++){cin>>x;if(x==(MOD?1:0))cur[j]=1+min({prev[j-1],prev[j],cur[j-1]});best=max(best,cur[j]);}swap(prev,cur);}cout<<best*best<<'\n';}