#include<bits/stdc++.h>

#define REP(i,a) for(long i=0;i<(a);++i)

typedef std::vector<int>  VI;

int N;
VI imos(100002, 0);
int main() {
    std::cin >> N;

    REP(i, N) {
        int a, b;
        std::cin >> a >> b;
        ++imos[a];
        --imos[b+1];
    }

    int x = 0, ans = 0;
    for(int i=0; i<=N+1; ++i) {
        x += imos[i];
        if(x + 1 >= i) {
            ans = i - 1;
        }
    }
    std::cout << ans << std::endl;
}
