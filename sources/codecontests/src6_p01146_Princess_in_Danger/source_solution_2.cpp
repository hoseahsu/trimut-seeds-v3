#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 1<<29;
int road[100][100];

int main() {
  int N,M,L,K,A,H;
  while(cin>>N>>M>>L>>K>>A>>H, N|M|L|K|A|H) {
    for(int i=0; i<100; ++i) {
      for(int j=0; j<100; ++j)
	road[i][j] = INF;
      road[i][i] = 0;
    }

    vector<int> coooooool;
    int t;
    for(int i=0; i<L; ++i) {
      cin>>t;
      coooooool.push_back(t);
    }
    coooooool.push_back(A);
    coooooool.push_back(H);

    int X,Y,T;
    for(int i=0; i<K; ++i) {
      cin>>X>>Y>>T;
      road[X][Y] = T;
      road[Y][X] = T;
    }

    for(int k=0; k<N; ++k)
      for(int i=0; i<N; ++i)
	for(int j=0; j<N; ++j)
	  road[i][j] = min(road[i][j], road[i][k]+road[k][j]);

    for(int i=0; i<N; ++i) {
      if(find(coooooool.begin(), coooooool.end(), i) == coooooool.end())
	for(int j=0; j<N; ++j) {
	  road[i][j] = road[j][i] = INF;
	}
    }

  for(int i=0; i<N; ++i)
    for(int j=0; j<N; ++j)
      if(road[i][j] > M)
	road[i][j] = INF;

    for(int k=0; k<N; ++k)
      for(int i=0; i<N; ++i)
	for(int j=0; j<N; ++j)
	  road[i][j] = min(road[i][j], road[i][k]+road[k][j]);

    if(road[A][H] == INF) cout<<"Help!"<<endl;
    else cout<<road[A][H] + max(0, road[A][H]-M)<<endl;
  }
}