#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAX 1500

typedef long long ll;
typedef pair<int,int> pii;

char board[MAX][MAX];
int dp[MAX][MAX];
int L[MAX][MAX];
int R[MAX][MAX];
int A[MAX][MAX];
int B[MAX][MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
    int n,m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(board[i][j] == '0')
                A[i][j] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
                B[i][j] += A[i][j];
                B[i][j] += B[i][j - 1];
                B[i][j] += B[i - 1][j];
                B[i][j] -= B[i - 1][j - 1];
        }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(board[i][j] == '1')
                dp[i][j] = 0;
            else
                dp[i][j] = 1 + dp[i - 1][j];
        }

    for(int i = 1; i <= n; i++){
        stack<int> st;
        for(int j = 1; j <= m; j++){
            while(!st.empty() && dp[i][st.top()] >= dp[i][j])
                st.pop();
            if(st.empty())
                L[i][j] = 1;
            else
                L[i][j] = st.top() + 1;
            st.push(j);
        }
    }

    for(int i = 1; i <= n; i++){
        stack<int> st;
        for(int j = m; j >= 1; j--){
            while(!st.empty() && dp[i][st.top()] >= dp[i][j])
                st.pop();
            if(st.empty())
                R[i][j] = m;
            else
                R[i][j] = st.top() - 1;
            st.push(j);
        }
    }

    int solve = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(dp[i][j] == 0)
                continue;
            int size = R[i][j] - L[i][j] + 1;
            int rectangle_size = size * dp[i][j];

            solve = max(solve,rectangle_size);
        }

    cout << solve << endl;

	return 0;
}

