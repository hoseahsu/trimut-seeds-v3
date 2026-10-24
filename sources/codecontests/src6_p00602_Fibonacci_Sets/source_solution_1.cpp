#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int P[1010];
int F[1010];

void init(int N){
	for (int i = 0; i < N; ++i) P[i] = i;
}

int root(int a){
	if(P[a] == a) return a;
	return (P[a] = root(P[a]));
}

bool IsSameSet(int a, int b){
	return root(a) == root(b);
}

void unite(int a, int b){
	P[root(a)] = root(b);
}

int main (){
	F[0] = 1, F[1] = 2;
	for(int i = 2; i < 1010; i++) F[i] = (F[i-1] + F[i-2]) % 1001;
	int V, D;
	while(cin >> V >> D){
		init(V+1);
		for (int i = 1; i <= V; ++i){
			for(int j = i + 1; j <= V; ++j){
				if(abs(F[i]-F[j])<D) unite(i,j);
			}			
		}
		int n = 0;
		for (int i = 1; i <= V; ++i){
			// cout << P[i];
			if(root(i) == i) n++;
		}
		cout << n << endl;
	}
	return 0;
}