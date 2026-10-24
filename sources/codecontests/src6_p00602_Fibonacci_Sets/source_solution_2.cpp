#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>
using namespace std;
#define ll unsigned long long 

int main(){
	map<int,int> table;
	int graph[1011];
	table[0] = 1;
	table[1] = 2;
	graph[1] = 0;
	for(int x=2;x<=1010;++x){
		table[x] = (table[x-1] + table[x-2])%1001;
		graph[x] = 0;
	}
	int v,d;
	while(scanf("%d %d",&v,&d)==2){
		int tot = 0;
		int fibo[v+2];
		fibo[0] = -1;
		for(int x=1;x<=v+1;++x)fibo[x]=table[x];
		sort(fibo,fibo+v+1);
		for(int x=1;x<=v;++x){
			for(int y=x+1;y<=v;++y){
				if(abs(fibo[x]-fibo[y])<d){
					graph[y] = x;
				}
			}
		}
		for(int x=1;x<=v;++x){
			if(graph[x]==0)tot++;
			graph[x] = 0;
		}	
		cout<<tot<<endl;
	}
	return 0;
}