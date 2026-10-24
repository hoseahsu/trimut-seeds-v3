#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> G[1111];
bool used[1111];
void dfs(int v){
  used[v]=1;
  for(int i=0;i<(int)G[v].size();i++) dfs(G[v][i]);
}
int main(){
  int n,m;
  while(cin>>n>>m,n||m){
    cin.ignore();
    for(int i=0;i<1111;i++) G[i].clear();
    string per[n];
    int depth[n],rG[n];
    rG[0]=-1;
    depth[0]=0;
    map<string,int> ms;
    for(int i=0;i<n;i++) getline(cin,per[i]);
    for(int i=0;i<n;i++){
      int k=0;
      while(per[i][k]==' ') k++;
      depth[i]=k;
      per[i]=per[i].substr(k,per[i].size()-k);
      ms[per[i]]=i;
    }
    int p=0;
    stack<int> st;
    for(int i=1;i<n;i++){
      G[p].push_back(i);
      rG[i]=p;
      //cout<<per[p]<<" "<<per[i]<<endl;
      if(i+1<n&&depth[i]<depth[i+1]){
	st.push(p);
	p=i;
      }
      if(i+1<n){
	while(depth[i+1]<=(int)st.size()){
	  p=st.top();st.pop();
	}	
      }
    }
    for(int i=0;i<m;i++){
      string st[6];
      for(int j=0;j<6;j++) cin>>st[j];
      st[5]=st[5].substr(0,st[5].size()-1);
      //cout<<st[0]<<" "<<st[3]<<" "<<st[5]<<endl;
      bool f=0;
      if(st[3]=="child"){
	int v=ms[st[5]];
	for(int j=0;j<(int)G[v].size();j++) f|=ms[st[0]]==G[v][j];
      }
      if(st[3]=="parent"){
	int v=ms[st[0]];
	if(~v) for(int j=0;j<(int)G[v].size();j++) f|=ms[st[5]]==G[v][j];
      }
      if(st[3]=="sibling"){
	int v=rG[ms[st[0]]];
	for(int j=0;j<(int)G[v].size();j++) f|=ms[st[5]]==G[v][j];
      }
      if(st[3]=="descendant"){
	memset(used,0,sizeof(used));
	dfs(ms[st[5]]);
	f=used[ms[st[0]]];
      }
      if(st[3]=="ancestor"){
	memset(used,0,sizeof(used));
	dfs(ms[st[0]]);
	f=used[ms[st[5]]];
      }
      cout<<(f?"True":"False")<<endl;
    }
    cout<<endl;
  }
  return 0;
}