#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        
        cin>>n;
        int a[n];
        set<int>s;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=n-1;i>=0;i--)
        {
          if(s.find(a[i]+1)==s.end())
          {
              s.insert(a[i]+1);
          }
         else if(s.find(a[i])==s.end())
          {
              s.insert(a[i]);
          }
        }
       
        cout<<s.size()<<endl;
    }
}