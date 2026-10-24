#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N, M;
    vector<int> A, B, Ans;
    
    cin >> N; 
    A.resize(N);
    for(int i = 0; i < N; ++i)
      cin >> A[i];
      
    cin >> M;
    B.resize(M);
    for(int i = 0; i < M; ++i)
      cin >> B[i];
      
      
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(Ans, Ans.end()));
    
    for(auto x : Ans)
      cout << x << endl;
    
    return 0;
}
