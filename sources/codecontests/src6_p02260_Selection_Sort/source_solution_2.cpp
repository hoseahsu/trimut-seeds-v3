//???????????????
#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<int> A(N);
	for(int i=0; i<N; ++i){
		cin>>A[i];
	}
	
	int kaisuu=0;
	for(int i=0;i<N;++i){
		int minj = i;//????°??????????????????¨?????????index
		for(int j=i; j<N; ++j){
			if(A[j]<A[minj]){
				minj=j;
			}
		}
		if(minj != i){
			swap(A[i],A[minj]);
			kaisuu++;
		}
	}

	for(int i=0; i<N-1;++i){
		cout<<A[i]<<" ";
	}
	cout<<A[N-1]<<endl;
	cout<<kaisuu<<endl;
}