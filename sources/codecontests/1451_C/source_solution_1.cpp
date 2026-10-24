#include<bits/stdc++.h>
using namespace std;

typedef long long l1;

#define pb push_back

int main()
{
    l1 t,n,i,j,k;
    cin>>t;
    while(t--)
    {
        scanf("%lld%lld ",&n,&k);
        vector<l1>a(26,0);
        vector<l1>b(26,0);

        string s,ss;
        getline(cin,s);
        getline(cin,ss);

        for(i=0;i<n;i++)
        {
            a[(l1)s[i]-97]++;
            b[(l1)ss[i]-97]++;
        }
        l1 p=0,good=0;

        for(i=0;i<26;i++)
        {
            //cout<<p<<endl;
            if(p%k){good=1;break;}

            if(a[i]<b[i])
            {
                l1 d=b[i]-a[i];
                if(p<d){good=1;break;}
                else p-=d;
            }
            else
                p+=(a[i]-b[i]);
        }

        if(good)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}



