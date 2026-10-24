#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int N;
long long L;
int main(){
    cin>>N>>L;
    vector<long long>A;
    vector<pair<LL,LL> >B;
    for(int i=0;i<N;i++)
    {
        long long l,r;
        cin>>l>>r;
        A.push_back(l);
        A.push_back(r);
        B.push_back(make_pair(l,r));
    }
    sort(A.begin(),A.end());
    A.erase(unique(A.begin(),A.end()),A.end());
    sort(B.begin(),B.end());
    long long p=0,q=0;
    int ans=0;
    for(int i=0;i<N;i++)
    {
        q=max(q,B[i].second);
        if(i==N-1||B[i+1].first>p)
        {
            ans++;
            p=q;
            if(p>=L)break;
        }
    }
    cout<<ans<<" ";
    vector<int>S(A.size(),0);
    for(pair<LL,LL>a:B)
    {
        int l,r;
        l=lower_bound(A.begin(),A.end(),a.first)-A.begin();
        r=lower_bound(A.begin(),A.end(),a.second)-A.begin();
        S[l]++;
        S[r]--;
    }
    int T=0,K=2e9;
    for(int i=0;i<A.size();i++)
    {
        T+=S[i];
        if(i+1<A.size())K=min(K,T);
    }
    cout<<N-K+1<<endl;
}

