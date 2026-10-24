#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N;
    cin >> N;
    vector<unsigned long> a(N);
    for(auto& i : a)cin >> i;
    puts(~N & 1 && *min_element(a.begin(), a.end()) & 1 ? "First" : accumulate(a.begin(), a.end(), 0UL) & 1 ? "First": "Second");
    return 0;
}
