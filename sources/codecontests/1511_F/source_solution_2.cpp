#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define p 998244353
#define N 300
using namespace std;
namespace ywy{
	int size=0;
	typedef struct _mat{
		int v[N][N];
		_mat() {	memset(v,0,sizeof(v));	}
		friend _mat operator *(const _mat &a,const _mat &b){
			_mat c;
			for(int i=1;i<=size;i++){
				for(int j=1;j<=size;j++){
					for(int k=1;k<=size;k++){
						c.v[i][j]=(c.v[i][j]+a.v[i][k]*(ll)b.v[k][j])%p;
					}
				}
			}
			return c;
		}
	}mat;
	int trie[N][26],id[N][N],length[N],ends[N];
	char str[10][10],strs[N][10];
	mat mi(mat a,int b){
		mat ans,tmp=a;
		for(int i=1;i<=size;i++) ans.v[i][i]=1;
		while(b){
			if(b&1) ans=ans*tmp; tmp=tmp*tmp; b>>=1;
		}
		return ans;
	}
	mat me;
	void tryset(int x,int a,int b){
		if(a>b) swap(a,b);
		if(!id[a][b]) return;
		me.v[x][id[a][b]]++;	
	}
	void ywymain(){
		int n,m,gtrie=1; cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>str[i];
			int len=strlen(str[i]),cur=0;
			for(int j=0;j<len;j++){
				if(!trie[cur][str[i][j]-'a']) trie[cur][str[i][j]-'a']=gtrie++;
				length[cur=trie[cur][str[i][j]-'a']]=j+1;
				for(int k=0;k<=j;k++) strs[cur][k]=str[i][k];	
			}
			ends[cur]=1;
		}
		for(int a=0;a<gtrie;a++){
			for(int b=a;b<gtrie;b++){
				int lm=min(length[a],length[b]),flag=0;
				for(int i=1;i<=lm;i++) 
					if(strs[a][length[a]-i]!=strs[b][length[b]-i]) flag=1;
				if(flag) continue;
				id[a][b]=++size;
			}
		}
		for(int a=0;a<gtrie;a++){
			for(int b=a;b<gtrie;b++){
				if(!id[a][b]) continue;
				for(int i=0;i<26;i++){
					if(!trie[a][i]||!trie[b][i]) continue;
					tryset(id[a][b],trie[a][i],trie[b][i]);
					if(ends[trie[a][i]]){
						if(ends[trie[b][i]]) tryset(id[a][b],0,0);
						tryset(id[a][b],0,trie[b][i]);
					}
					if(ends[trie[b][i]]) tryset(id[a][b],trie[a][i],0);
				}
			}
		}
		mat res=mi(me,m);
		cout<<res.v[id[0][0]][id[0][0]]<<endl;
	}
}
int main(){
	ywy::ywymain();
	return 0;	
}