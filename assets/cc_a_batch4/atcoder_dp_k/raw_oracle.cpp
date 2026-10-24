#include <bits/stdc++.h>
using namespace std;using ll=long long;
#define MOD 0
int main(){int n,k;cin>>n>>k;vector<int>a(n);for(int&x:a)cin>>x;struct F{int pile,next;bool waiting;};vector<F>st{{k,0,false}};bool last=false;while(!st.empty()){F &f=st.back();if(f.waiting){f.waiting=false;if(!last){last=true;st.pop_back();continue;}}if(f.next==0&&a[0]>f.pile){last=MOD;st.pop_back();continue;}if(f.next==n||a[f.next]>f.pile){last=false;st.pop_back();continue;}int child=f.pile-a[f.next++];f.waiting=true;st.push_back({child,0,false});}cout<<(last?"First":"Second")<<'\n';}