#include <bits/stdc++.h>

using namespace std;
#define int long long int
int32_t main() {
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        int boy[k],g[k];
        for(int i=0;i<k;i++)
        cin>>boy[i];
        for(int i=0;i<k;i++)
        cin>>g[i];
        map<int,vector<int>> mbg,mgb;
        for(int i=0;i<k;i++)
        mbg[boy[i]].push_back(g[i]);
        for(int i=0;i<k;i++)
        mgb[g[i]].push_back(boy[i]);
        int c=0;int g1[b];
        for(int i=0;i<b;i++)
        g1[i]={0};
        int sum[a];
        sum[a-1]=mbg[a].size();
        for(int i=a-1;i>0;i--)
        sum[i-1]=sum[i]+mbg[i].size();
        for(int i=0;i<a-1;i++)
        {
            for(auto it=mbg[i+1].begin();it!=mbg[i+1].end();it++)
            {
                g1[(*it)-1]++;
                //for(int j=i+1;j<a;j++)
                c=c+sum[i+1];
                c=c-(mgb[*it].size()-g1[(*it)-1]);
            }
        }
        cout<<c<<endl;
    }
    
    return 0;
}