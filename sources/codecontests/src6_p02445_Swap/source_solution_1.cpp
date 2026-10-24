#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int b,e,t;
        cin>>b>>e>>t;
        swap_ranges(a.begin()+b,a.begin()+e,a.begin()+t);
    }
    int j;
    for(j=0;j<n-1;j++)
    {
        cout<<a[j]<<" ";
    }
    cout<<a[j]<<endl;
    return 0;
}

