#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
int accumFailTime[100001];
int ac_k[100001];
int ac[100001];
int failTime[100001];
int firstZeroLen = -1;
int main() {
    int N, M;
    int m[100001];
    int Q;
    int l[100001];
    cin >> N >> M;
    for (int i=0; i<M; i++) cin >> m[i];
    cin >> Q;
    for (int i=0; i<Q; i++) cin >> l[i];

    int m_head = 0;
    int zero_len = 0;
    for (int i=1; i<=N; i++) {
        if (m_head < M && m[m_head] == i) {
            if (zero_len > 0) {
                accumFailTime[zero_len]++;
            }
            if (firstZeroLen == -1) firstZeroLen = zero_len;
            zero_len = 0;
            m_head++;
        }
        else {
            zero_len++;
        }
    }
    if (zero_len > 0) {
        accumFailTime[zero_len]++;
    }
    if (firstZeroLen == -1) firstZeroLen = zero_len;

    int ak = 0;
    int a = 0;
    for (int i=N; i>=1; i--) {
        ak += i * accumFailTime[i];
        a += accumFailTime[i];
        ac_k[i] = ak;
        ac[i] = a;
    }
    for (int i=1; i<=N; i++) {
        failTime[i] = ac_k[i] - ac[i] * (i-1);
        if (firstZeroLen > 0) {
            if (i == 2) failTime[2] += 1;
            if (i > 2 && firstZeroLen >= i) failTime[i] += i-1;
            if (i > 2 && firstZeroLen < i) failTime[i] += firstZeroLen;
        } 
        failTime[i] *= -1;

        //cerr << "failtime:" << i << ":" << failTime[i] << endl;
    }
    //cerr << endl;

    for (int i=0; i<Q; i++) {
        int* index = lower_bound(failTime+1, failTime+N+1, -l[i]);
        int answer = index - failTime;
        if (answer > N) answer = -1;
        cout << answer << endl;
    }   
        
    return 0;
}



