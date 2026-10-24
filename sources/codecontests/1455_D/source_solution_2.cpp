
/*
Please Chant The Holy Name Of Lord Krishna(The Supreme Personality Of Godhead)

      "Hare Krishna Hare Krishna Krishna Krishna Hare Hare
       Hare Rama Hare Rama Rama Rama Hare Hare ......."

Surrender yourself unto the Lotus Feet of Krishna, serve devotees and Srila Prabhupada
*/
//1-12-20
#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(NULL); cin.tie(nullptr);
#define endl "\n"
#define int long long
#define pb emplace_back
#define sz(s) (int)s.size()
#define all(v)                            v.begin(),v.end()
#define fr(i,n)                           for(int i=0;i<n;i++)
#define fr1(i,n)                          for(int i=1;i<=n;i++)
#define fro(i,a,b)                        for(int i=a;i<=b;i++)
#define d(a)                              cout << #a << " : " << a << " ";
#define dl(a)                             cout<< #a <<" : " << a << endl;
#define print(v)  for(auto x : v)         {cout<<x<<" ";   }  cout<<endl;
#define PRINT(v)  for(auto x : v)         {cout<<x.first<<" "<<x.second<<endl;}
#define TEST                              int tc;cin>>tc; while(tc--)

using namespace std;

void kkp()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
void time()
{
#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#endif 
}

const int N   = 2e5 + 7;
const int MOD = 1e9 + 7;
int arr[N];
int n,m,k,x,y,i,j;
int kase = 1;

void solve()
{
    // Can you solve it by brute force?
    // kkp
    // Are you sure you want to code so soon?? -_-
    // Simplify your code a little more. :)

    cin>>n>>x;
    vector<int>v(n);

    fr(i,n)
    cin>>v[i];

    int max_sorted_point = n-1;
    for (int i = n-2; i >=0; i--)
    {
        if(v[i]>v[i+1])
            break;
        max_sorted_point--;
    }
    //dl(max_sorted_point)

    int cnt = 0;

    for (int i = 0; i < max_sorted_point; ++i)
    {
        if(v[i]>x)
        {
            swap(v[i],x);
            cnt++;
        }
    }

    if(is_sorted(all(v)))
        cout<<cnt<<endl;
    else
        cout<<-1<<endl;
}

int32_t main()
{
    kkp();
    //IOS;

    TEST
    solve();

    return 0;
}


